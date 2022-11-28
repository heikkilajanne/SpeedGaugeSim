#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <sstream>
#include <thread>
#include <backend.h>
#include <reader.h>
using namespace std;

int i = 0;
int j = 0;
int add = 1;
int currSpeed;
int speedValueCount = 0;
float avgSpeed = 0.0f;
int timeperspeed[180];

//Reader::Reader(QObject *parent) :
//    QObject(parent)
//{
//}

//QString Reader::speed()
//{
//    return m_speed;
//}

//void Reader::setSpeed(const QString &speed)
//{
//    if (speed == m_speed)
//        return;

//    m_speed = speed;
//    emit speedChanged();
//}


void calculate(){
     std::string line;
     while(std::getline(std::cin, line)) // read from std::cin
     {
     //std::cout << "Speed: " << line << " km/h " << endl;
     //std::cout << samples[i];
     cin >> currSpeed;
     i = currSpeed;
     timeperspeed[i] += add;
     speedValueCount+=currSpeed;
     j++;
     avgSpeed = speedValueCount/j;
     cout << "Current speed: " << currSpeed << "km/h || Times at this speed: " << timeperspeed[i] << " || Average speed: " << avgSpeed << endl;
     std::this_thread::sleep_for(50ms);
     QString s = QString::number(currSpeed);
//     Reader::setSpeed(s);
     }
 }

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


//    QString gui = "GUI";
//    QString cli = "CLI";
//    char choice[2];

//    cout << endl << "Hello!\n" << endl;

//    cout << "Run Application in CLI or GUI mode" <<endl; cout << "(Type CLI or GUI)" << endl;
//        cin >> choice;

//        if(choice == cli){
//            cout << "Youre running simulation in CLI mode" << endl;

//            system(".\\speed_simulation | .\\speedGauge");

//        }
//        if (choice == gui){
//            cout << "You're running simulation in GUI mode "<< endl;
//            engine.load(url);
//        }

    engine.load(url);
    //std::thread t1(&calculate);
    std::thread worker(calculate);

    return app.exec();
}
