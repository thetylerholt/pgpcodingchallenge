// configloader.h
#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include <QString>
#include <QList>
#include <QVariant>
class SignalEmitter;
class QJsonArray;


/**
 * @brief The ConfigLoader class parses JSON configuration files and extracts
 * configuration data for both the frontend and backend of the program.
 */
class ConfigLoader
{
public:
    /**
     * @brief loadBackendConfig Process a backend configuration file.
     * @param filepath Relative path to the config file.
     * @return QList of SignalEmitter objects.
     */
    static QList<SignalEmitter*> loadBackendConfig(const QString& filepath);

    /**
     * @brief loadFrontendConfig Process a frontend configuration file.
     * @param filepath Relative path to the config file.
     * @return QList of QVariantMaps containing configuration data.
     */
    static QList<QVariantMap> loadFrontendConfig(const QString& filepath);

private:
    /**
     * @brief readJson Helper function that accepts a filepath, opens/closes
     * a file, and prepares JSON for use.
     * @param filepath Relative path to the config file.
     * @return QJsonArray containing JSON data from filepath.
     */
    static QJsonArray readJson(const QString& filepath);
};

#endif // CONFIGLOADER_H
