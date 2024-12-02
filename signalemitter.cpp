#include "signalemitter.h"

// Construct the object, initialize member variables, and connect timer signal to the updateValue port.
SignalEmitter::SignalEmitter(QObject *parent)
    : QObject(parent), m_id(""), m_val(0), m_minVal(0), m_maxVal(100) {
    connect(&m_timer, &QTimer::timeout, this, &SignalEmitter::updateValue);
}

// Destructor
SignalEmitter::~SignalEmitter() {}

// Get id
QString SignalEmitter::getId() const {
    return m_id;
}

// Set id
void SignalEmitter::setId(const QString& id) {
    if (m_id != id) {
        m_id = id;
    }
}

// Get current val
unsigned int SignalEmitter::getVal() const {
    return m_val;
}

// Set val and emit valChanged signal
void SignalEmitter::setVal(unsigned int val) {
    if (m_val != val) {
        m_val = val;
        emit valChanged(m_val);
    }
}

// Set the timer interval
void SignalEmitter::setTimerInterval(int seconds) {
    m_timer.setInterval(seconds * 1000); // QTimer counts in milliseconds so multiply by 1000
    m_timer.start();
}

// Set the range of values that can be generated
void SignalEmitter::setValueRange(unsigned int minVal, unsigned int maxVal) {
    m_minVal = minVal;
    m_maxVal = maxVal;
}

// Generate a random val, update the member variable, and log the change to the console
void SignalEmitter::updateValue() {
    unsigned int newValue = QRandomGenerator::global()->bounded(m_minVal, m_maxVal + 1);
    setVal(newValue);
    qDebug() << m_id << "value changed to" << newValue;
}
