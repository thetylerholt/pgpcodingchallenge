#include "configloader.h"
#include "signalemitter.h"
#include "contextpropertylookup.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QVariantList>
#include <QVariantMap>
#include <QList>

const QString BACKEND_CONFIG_FILE = "backend_5.json";
const QString FRONTEND_CONFIG_FILE = "frontend.json";

int main(int argc, char *argv[]) {
    // Initialize the application.
    QGuiApplication app(argc, argv);

    // Initialize the QML engine.
    QQmlApplicationEngine engine;

    // Handle QML loading errors
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // Print current working directory for debugging config file.
    qDebug() << "Current working directory:" << QDir::currentPath();

    // Parse backend configuration file to create SignalEmitters.
    QList<SignalEmitter*> signalEmitters = ConfigLoader::loadBackendConfig(BACKEND_CONFIG_FILE);
    if (signalEmitters.isEmpty()) {
        qWarning() << "No SignalEmitter instances created. Check the backend configuration file.";
    }

    // Expose each SignalEmitter to QML.
    for (SignalEmitter* emitter : signalEmitters) {
        if (!emitter->getId().isEmpty()) {
            emitter->setParent(&engine);  // Transfer ownership to the engine for memory handling.
            engine.rootContext()->setContextProperty(emitter->getId(), emitter);
        } else {
            qWarning() << "SignalEmitter instance has an invalid or empty id.";
        }
    }

    // Parse frontend configuration file to extract data as a list of maps.
    QList<QVariantMap> frontendConfigs = ConfigLoader::loadFrontendConfig(FRONTEND_CONFIG_FILE);
    if (frontendConfigs.isEmpty()) {
        qWarning() << "No frontend configuration data found, check the frontend configuration file.";
    }

    // Expose the configuration data to QML.
    engine.rootContext()->setContextProperty("frontendConfigs", QVariant::fromValue(frontendConfigs));

    // Create and expose a context lookup utility.
    ContextPropertyLookup lookup(engine.rootContext());
    engine.rootContext()->setContextProperty("propertyLookup", &lookup);

    engine.loadFromModule("pgpcodingchallenge", "Main");
    if (engine.rootObjects().isEmpty()) {
        qDebug() << "Failed to load QML file.";
        return -1;
    }

    return app.exec();
}
