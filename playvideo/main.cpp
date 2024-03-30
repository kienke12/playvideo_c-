#include "playvideo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlayVideo w;
    w.show();
    return a.exec();
}
