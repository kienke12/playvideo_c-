#include "playvideo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlayVideo w;
    w.resize(500, 250);
    w.show();
    return a.exec();
}
