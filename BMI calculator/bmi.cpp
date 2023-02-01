#include "bmi.h"

#include <cmath>

/*Functions for BMI operations*/
void BMI::calculateBMI()
{
    QString heightStr = height->text();
    QString weightStr = weight->text();
    bool OKH, OKW;
    double H = heightStr.toDouble(&OKH);
    double W = weightStr.toDouble(&OKW);
    double BMI;

    if (!OKH || !OKW)
    {
        errmess = new QErrorMessage(this);
        errmess->showMessage("Error! Please enter valid number");
    }
    else {
        BMI = W / pow(H, H);
        output->display(BMI);
    }

}

void BMI::clearBMI()
{
    height->clear();
    weight->clear();
    output->display(0.0);
}

/*Default constructor for BMI Calculator
 * initialize a widget which prompt  user
 * for height & weight then return BMI
*/

BMI::BMI()
{


    setWindowTitle("BMI Calculator");

    QGridLayout* layout = new QGridLayout(this);

    QLabel* inputHeight = new QLabel("Enter height (in metres): ");
    height = new QLineEdit();
    QLabel* inputWeight = new QLabel("Enter weight (in kgs): ");
    weight = new QLineEdit();

    QPushButton* calculate = new QPushButton("Calculate");
    QLabel* BMI = new QLabel("BMI \nBody Mass Index");

    output = new QLCDNumber();
    output->setDecMode();
    output->setSegmentStyle(QLCDNumber::Filled);
    output->setDigitCount(8);

    QPushButton* clear = new QPushButton("Clear All");

    layout->addWidget(inputHeight, 1, 0);
    layout->addWidget(height, 1, 1);
    layout->addWidget(inputWeight, 0, 0);
    layout->addWidget(weight, 0, 1);
    layout->addWidget(calculate, 2, 1);
    layout->addWidget(BMI, 3, 0);
    layout->addWidget(output, 3, 1);
    layout->addWidget(clear, 4, 1);

    this->setLayout(layout);
    connect(calculate, SIGNAL(clicked()), this, SLOT(calculateBMI()));
    connect (clear,SIGNAL(clicked()), this, SLOT(clearBMI()));
}


