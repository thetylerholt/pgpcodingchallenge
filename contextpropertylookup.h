// contextpropertylookup.h
#ifndef CONTEXTPROPERTYLOOKUP_H
#define CONTEXTPROPERTYLOOKUP_H

#include <QObject>
#include <QQmlContext>

/**
 * @brief The ContextPropertyLookup class is a utility class that accepts a QQmlContext
 * and provides functionality to lookup exposed objects by name.
 */
class ContextPropertyLookup : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief ContextPropertyLookup class constructor.
     * @param context QQmlContext (ie engine.rootContext())
     * @param parent [optional] QObject parent class
     */
    explicit ContextPropertyLookup(QQmlContext* context, QObject *parent = nullptr);

    /**
     * @brief getContextProperty Look up an exposed object by name.
     * @param propertyName The object to look up.
     * @return Pointer to the object.
     */
    Q_INVOKABLE QObject* getContextProperty(const QString& propertyName);

private:
    QQmlContext* m_context; // Pointer to the root context (ie engine.rootContext()).
};

#endif // CONTEXTPROPERTYLOOKUP_H
