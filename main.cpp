#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include<QtMultimedia/QMediaPlayer>
#include<ActiveQt/QAxObject>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    QPixmap pixmap("444.jpg");
    QSplashScreen splash(pixmap);
    splash.show();

    for(long index=0;index<=100000000;index++);

    MainWindow w;
    w.show();

///////////////
    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl("http://media.shanbay.com/audio/us/hello.mp3"));
    player->play();

    QAxObject *speech= new QAxObject();
    speech->setControl("SAPI.SpVoice");
    speech->dynamicCall("Speak(QString,uint)","good",1);//这里换成中文也可以



    splash.finish(&w);
    return app.exec();



}
