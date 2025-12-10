#include <QApplication>
#include "ui/MainWindow.h"
#include "storage/ProfileRepository.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProfileRepository::instance().init();
    MainWindow w;
    w.show();
    return a.exec();
}