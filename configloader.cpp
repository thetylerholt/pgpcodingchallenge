#include "configloader.h"
#include "signalemitter.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>


// Helper function: Read and parse a JSON array from a file.
QJsonArray ConfigLoader::readJson(const QString& filepath) {
    // Open file and check that it opened correctly.
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open configuration file:" << filepath;
        return QJsonArray();
    }

    // Read the file to an array.
    QByteArray data = file.readAll();
    file.close();

    // Exctract JSON data from the array.
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        qWarning() << "Configuration file is not a valid JSON array:" << filepath;
        return QJsonArray();
    }

    return doc.array();
}

// Parse backend configuration files and return a list of SignalEmitters.
QList<SignalEmitter*> ConfigLoader::loadBackendConfig(const QString& filepath) {
    QList<SignalEmitter*> signalEmitters;

    // Read JSON from file using helper function.
    QJsonArray array = readJson(filepath);
    if (array.isEmpty()) return signalEmitters;

    // Iterate through the JSON data and create SignalEmitters.
    for (const QJsonValue& value : array) {
        QJsonObject obj = value.toObject();
        SignalEmitter* emitter = new SignalEmitter;

        emitter->setId(obj["id"].toString());
        emitter->setTimerInterval(obj["sec"].toInt());
        emitter->setValueRange(obj["min"].toInt(), obj["max"].toInt());

        signalEmitters.append(emitter);
    }

    return signalEmitters;
}

// Parse frontend configuration files and return a list of variant maps.
QList<QVariantMap> ConfigLoader::loadFrontendConfig(const QString& filepath) {
    QList<QVariantMap> configs;

    // Read JSON from file using helper function.
    QJsonArray array = readJson(filepath);
    if (array.isEmpty()) return configs;

    // Iterate through the JSON data and create maps.
    for (const QJsonValue& value : array) {
        QJsonObject obj = value.toObject();
        QVariantMap map;

        map["id"] = obj["id"].toString();
        map["x"] = obj["x"].toInt();
        map["y"] = obj["y"].toInt();
        map["color"] = obj["color"].toString();
        map["dataSource"] = obj["dataSource"].toString();

        configs.append(map);
    }

    return configs;
}
