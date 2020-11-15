#include <QApplication>
#include <QtWidgets>
#include <QWebEngineView>
#include "MainWdg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMainWdg mainWdg;
    //mainWdg.show();
    //mainWdg.setVisible(false);
    return a.exec();
}
