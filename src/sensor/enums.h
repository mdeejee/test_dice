#ifndef ENUMS_H
#define ENUMS_H

#include <QtCore>

class Enums
{
    Q_GADGET

public :

    enum class SensorType
    {
        SensorType_Anemometer,
        SensorType_Compass,
        SensorType_GPS,
        SensorType_Gyro
    };

    enum class StateType
    {
        StateType_Nominal,
        StateType_Warning,
        StateType_Error,
    };

    Q_ENUM(SensorType)
    Q_ENUM(StateType)
};

#endif // ENUMS_H
