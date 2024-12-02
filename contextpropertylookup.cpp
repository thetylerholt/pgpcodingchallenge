#include "contextpropertylookup.h"

// Helper class to look up context properties by name and return a pointer to the original object.
ContextPropertyLookup::ContextPropertyLookup(QQmlContext* context, QObject *parent)
    : QObject(parent), m_context(context) {}

QObject* ContextPropertyLookup::getContextProperty(const QString& propertyName) {
    return m_context->contextProperty(propertyName).value<QObject*>();
}
