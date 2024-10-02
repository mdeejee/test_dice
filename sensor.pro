##############################################################
# Project
##############################################################
QT += core quick

CONFIG += c++17 windeployqt

DEFINES += QT_DEPRECATED_WARNINGS

##############################################################
# Files
##############################################################

include($$PWD/sensor.pri)

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = \
    $$PWD/imports \

QML_DESIGNER_IMPORT_PATH =

## Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin

##############################################################
# Deploy
##############################################################

CONFIG( release, debug|release ) {
    isEmpty(TARGET_EXT) {
        win32 {
            TARGET_CUSTOM_EXT = .exe
        }
        macx {
            TARGET_CUSTOM_EXT = .app
        }
    } else {
        TARGET_CUSTOM_EXT = $${TARGET_EXT}
    }

    win32 {
        DEPLOY_COMMAND = $$[QT_INSTALL_BINS]/windeployqt
    }
    macx {
        DEPLOY_COMMAND = $$[QT_INSTALL_BINS]/macdeployqt
    }

    QMAKE_POST_LINK += $${DEPLOY_COMMAND} "--qmldir $${PWD}" $${OUT_PWD}/release/$${TARGET}$${TARGET_CUSTOM_EXT}
    !isEmpty(target.path): INSTALLS += target
}
