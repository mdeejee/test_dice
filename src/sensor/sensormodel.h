#ifndef SENSOR_MODEL_H
#define SENSOR_MODEL_H

#include <QAbstractListModel>
#include <QTimer>
#include "sensor.h"

class SensorModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum SensorRoles {
        NameRole = Qt::UserRole + 1,
        SensorTypeRole,
        StateTypeRole,
        SignalStrengthRole,
    };

    SensorModel(QObject* parent = nullptr) : QAbstractListModel(parent)
    {
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return sensors.size();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (index.row() < 0 || index.row() >= sensors.size())
            return QVariant();

        const Sensor* sensor = sensors.at(index.row());
        if (role == NameRole)
            return sensor->getName();
        else if (role == SensorTypeRole)
            return static_cast<int>(sensor->getSensorType());
        else if (role == StateTypeRole)
            return static_cast<int>(sensor->getStateType());
        else if (role == SignalStrengthRole)
            return sensor->getSignalStrength();

        return QVariant();
    }

    QHash<int, QByteArray> roleNames() const override {
        QHash<int, QByteArray> roles;
        roles[NameRole] = "name";
        roles[SensorTypeRole] = "sensorType";
        roles[StateTypeRole] = "stateType";
        roles[SignalStrengthRole] = "signalStrength";
        return roles;
    }

    void addSensor(Sensor* sensor) {
        beginInsertRows(QModelIndex(), sensors.size(), sensors.size());
        sensors.append(sensor);
        endInsertRows();
    }

    Q_INVOKABLE void generateRandom() {
        beginResetModel();
        sensors.clear();

        int numberOfSensors = QRandomGenerator::global()->bounded(5, 11);

        for (int i = 0; i < numberOfSensors; ++i) {
            Sensor* sensor = new Sensor();
            sensor->setName("Sensor " + QString::number(i + 1));
            sensor->setSensorType(static_cast<Enums::SensorType>(QRandomGenerator::global()->bounded(4)));
            sensor->setStateType(static_cast<Enums::StateType>(QRandomGenerator::global()->bounded(3)));
            sensor->setSignalStrength(QRandomGenerator::global()->bounded(0, 101));
            sensors.append(sensor);
        }
        endResetModel();    
    }

public slots:

    void updateDatas()
    {
        auto n = sensors.size();
        for(auto index = 0; index< n; ++index)
        {
            Enums::StateType newStateType = static_cast<Enums::StateType>(QRandomGenerator::global()->bounded(0, 3));
            sensors[index]->setStateType(newStateType);
            sensors[index]->setSignalStrength(QRandomGenerator::global()->bounded(0, 101));
            emit dataChanged(createIndex(index, 0), createIndex(index, 0), {SignalStrengthRole, StateTypeRole});
        }
    }

private:

    QVector<Sensor*> sensors;
};


#endif // SENSOR_MODEL_H
