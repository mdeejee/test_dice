#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include <QString>
#include "enums.h"


class Sensor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(Enums::SensorType sensorType READ getSensorType WRITE setSensorType NOTIFY sensorTypeChanged)
    Q_PROPERTY(Enums::StateType stateType READ getStateType WRITE setStateType NOTIFY stateTypeChanged)
    Q_PROPERTY(int signalStrength READ getSignalStrength WRITE setSignalStrength NOTIFY signalStrengthChanged)

public:
    explicit Sensor(QObject* parent = nullptr) : QObject(parent) {}

    QString getName() const { return name; }
    void setName(const QString& value) {
        if (name != value) {
            name = value;
            emit nameChanged();
        }
    }

    Enums::SensorType getSensorType() const { return sensorType; }
    void setSensorType(Enums::SensorType value) {
        if (sensorType != value) {
            sensorType = value;
            emit sensorTypeChanged();
        }
    }

    Enums::StateType getStateType() const { return stateType; }
    void setStateType(Enums::StateType value) {
        if (stateType != value) {
            stateType = value;
            emit stateTypeChanged();
        }
    }

    int getSignalStrength() const { return signalStrength; }
    void setSignalStrength(int value) {
        if (signalStrength != value) {
            signalStrength = value;
            emit signalStrengthChanged();
        }
    }

signals:
    void nameChanged();
    void sensorTypeChanged();
    void stateTypeChanged();
    void signalStrengthChanged();

private:
    QString name;
    Enums::SensorType sensorType;
    Enums::StateType stateType;
    int signalStrength;
};


#endif // SENSOR_H
