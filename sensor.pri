##############################################################
# Files
##############################################################

HEADERS += \
    $$PWD/src/sensor/sensormodel.h \
    $$PWD/src/sensor/enums.h \
    $$PWD/src/sensor/sensor.h \

SOURCES += \
    $$PWD/src/main.cpp \
    $$PWD/src/sensor/sensorappregistertypes.cpp

RESOURCES += \
    $$PWD/qml/main.qml \    
    $$PWD/imports/Theme/Theme.qml \
    $$PWD/imports/Theme/qmldir \
    $$PWD/translations/en_US.qm \

lupdate_only{
    SOURCES += \
        $$PWD/qml/*.qml \
        $$PWD/qml/imports/*.qml \
}

TRANSLATIONS += \
    $$PWD/translations/en_US.ts \
