#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("../ressources/splash_linucut.png");
    QSplashScreen splash(pixmap);

    splash.show();
    splash.showMessage("");
    a.processEvents();
    MainWindow w;
    w.show();
    splash.finish(&w);

    return a.exec();
}
