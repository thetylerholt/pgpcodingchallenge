#ifndef SIGNALEMITTER_H
#define SIGNALEMITTER_H

#include <QObject>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>

/**
 * @brief The SignalEmitter class contains a randomly generated value that updated
 * periodically and emits a signal.
 */
class SignalEmitter : public QObject {
    Q_OBJECT
    Q_PROPERTY(unsigned int val READ getVal WRITE setVal NOTIFY valChanged)

public:
    /**
     * @brief SignalEmitter Constructor.
     * @param parent [optional] QObject parent.
     */
    explicit SignalEmitter(QObject *parent = nullptr);

    /**
     * Destructor.
     */
    ~SignalEmitter();

    /**
     * @brief getId
     * @return QString id.
     */
    QString getId() const;

    /**
     * @brief setId
     * @param id
     */
    void setId(const QString& id);

    /**
     * @brief getVal
     * @return unsigned int value.
     */
    Q_INVOKABLE unsigned int getVal() const;

    /**
     * @brief setVal and emit a signal.
     * @param value
     */
    void setVal(unsigned int val);

    /**
     * @brief setTimerInterval
     * @param seconds
     */
    void setTimerInterval(int seconds);

    /**
     * @brief setValueRange
     * @param minVal
     * @param maxVal
     */
    void setValueRange(unsigned int minVal, unsigned int maxVal);

signals:
    void valChanged(unsigned int newVal); // Emits a signal when val changes.

public slots:
    void updateValue(); // Generates a new val when triggered.

private:
    QString m_id;          // Identifier.
    unsigned int m_val;    // Current value.
    unsigned int m_minVal; // Minimum value.
    unsigned int m_maxVal; // Maximum value.
    QTimer m_timer;        // Timer, value changes when it times out.
};

#endif // SIGNALEMITTER_H
