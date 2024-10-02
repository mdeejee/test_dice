#include <QQmlEngine>
#include <QCoreApplication>
#include "sensormodel.h"

#define MODULE "DICE_TEST"
#define VERSION_MAJOR 1
#define VERSION_MINOR 0

void sensorAppRegisterTypes()
{
    qmlRegisterType<Sensor>(MODULE, VERSION_MAJOR, VERSION_MINOR, "Sensor");
    qmlRegisterUncreatableType<Enums>(MODULE, VERSION_MAJOR, VERSION_MINOR, "Enums", "UncreatableType.");    
    qmlRegisterType<SensorModel>(MODULE, VERSION_MAJOR, VERSION_MINOR, "SensorModel");
}

Q_COREAPP_STARTUP_FUNCTION(sensorAppRegisterTypes)


