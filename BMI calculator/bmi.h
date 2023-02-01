#ifndef BMI_H
#define BMI_H

#include <QErrorMessage>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QWidget>




class BMI : public QWidget
{
    Q_OBJECT

public:
    BMI();


public slots:
    void calculateBMI();
    void clearBMI();

private:
    QLineEdit* height;
    QLineEdit* weight;
    QErrorMessage* errmess;
    QLCDNumber* output;
};

#endif // BMI_H
