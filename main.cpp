#include "lexicalAnalysis.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lexicalAnalysis w;
    w.show();
    return a.exec();
}
