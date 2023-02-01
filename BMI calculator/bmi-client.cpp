#include "bmi.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BMI myBMI;

    myBMI.show();

    return a.exec();
}
