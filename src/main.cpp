#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "src/sensor/sensormodel.h"

#define QMLURI "ChordApp"
#define QMLVERSIONMAJOR 1
#define QMLVERSIONMINOR 0

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    app.setOrganizationName("DICE_TEST");
    app.setOrganizationDomain("DICE_TEST");

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = QLocale(locale).name();
        if (translator.load(":/translations/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    engine.addImportPath(":/imports");

    SensorModel sensorModel{};
    sensorModel.generateRandom();

    engine.rootContext()->setContextProperty("sensorModel", &sensorModel);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    return app.exec();
}
