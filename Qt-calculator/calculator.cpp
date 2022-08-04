#include "calculator.h"
#include "ui_calculator.h"
#include <QDebug>

double firstNum;
QString label_1_disp = "";
bool isUserTypingSecondNum = false;

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);

    connect(ui->button_0, SIGNAL(released()), this, SLOT(on_digit_pressed()));
    connect(ui->button_1, SIGNAL(released()), this, SLOT(on_digit_pressed()));
    connect(ui->button_2, SIGNAL(released()), this, SLOT(on_digit_pressed()));
    connect(ui->button_3, SIGNAL(released()), this, SLOT(on_digit_pressed()));
    connect(ui->button_4, SIGNAL(released()), this, SLOT(on_digit_pressed()));
    connect(ui->button_5, SIGNAL(released()), this, SLOT(on_digit_pressed()));
    connect(ui->button_6, SIGNAL(released()), this, SLOT(on_digit_pressed()));
    connect(ui->button_7, SIGNAL(released()), this, SLOT(on_digit_pressed()));
    connect(ui->button_8, SIGNAL(released()), this, SLOT(on_digit_pressed()));
    connect(ui->button_9, SIGNAL(released()), this, SLOT(on_digit_pressed()));

    connect(ui->button_plus_minus, SIGNAL(released()), this, SLOT(unary_operation()));
    connect(ui->button_percent, SIGNAL(released()), this, SLOT(unary_operation()));
    connect(ui->button_reciprocol, SIGNAL(released()), this, SLOT(unary_operation()));

    connect(ui->button_cancel, SIGNAL(released()), this, SLOT(clear_operation()));

    connect(ui->button_add, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_sub, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_multiply, SIGNAL(released()), this, SLOT(binary_operation()));
    connect(ui->button_divide, SIGNAL(released()), this, SLOT(binary_operation()));

    connect(ui->button_equal_to, SIGNAL(released()), this, SLOT(on_button_equal_to_released()));

    ui->button_add->setCheckable(true);
    ui->button_sub->setCheckable(true);
    ui->button_multiply->setCheckable(true);
    ui->button_divide->setCheckable(true);
}

calculator::~calculator()
{
    delete ui;
}

void calculator::on_digit_pressed()
{
    double labelNum;
    QString newLabel;
    QPushButton* button = (QPushButton*) sender();
    if((ui->button_add->isChecked() || ui->button_sub->isChecked() ||
        ui->button_multiply->isChecked() || ui->button_divide->isChecked()) && (!isUserTypingSecondNum))
    {
        firstNum = (ui->label_2->text()).toDouble();
        labelNum = (button->text()).toDouble();
        isUserTypingSecondNum = true;
        newLabel = QString::number(labelNum, 'g', 16);
    }
    else
    {
        if(ui->label_2->text() == "0")
        {
            newLabel = button->text();
        }
        else
        {
           labelNum = (ui->label_2->text() + button->text()).toDouble();

           newLabel = QString::number(labelNum, 'g', 16);
        }
    }

    ui->label_2->setText(newLabel);

}

void calculator::unary_operation()
{
    double labelNumber = 0.0;
    QString newLabel;
    QPushButton* button =(QPushButton*) sender();

    if(button->text() == "+/-")
    {
        labelNumber = ui->label_2->text().toDouble();
        labelNumber = labelNumber * (-1);
        newLabel = QString::number(labelNumber, 'g', 16);
        ui->label_2->setText(newLabel);
    }
    else if(button->text() == '%')
    {
        labelNumber = ui->label_2->text().toDouble();
        labelNumber = labelNumber / 100;
        newLabel = QString::number(labelNumber, 'g', 16);
        ui->label_2->setText(newLabel);
    }
    else if(button->text() == "1/x")
    {
        labelNumber = ui->label_2->text().toDouble();
        labelNumber = 1 / labelNumber;
        newLabel = QString::number(labelNumber, 'g', 16);
        ui->label_2->setText(newLabel);
    }
}

void calculator::clear_operation()
{
    ui->button_add->setChecked(false);
    ui->button_sub->setChecked(false);
    ui->button_multiply->setChecked(false);
    ui->button_divide->setChecked(false);

    label_1_disp = "";
    isUserTypingSecondNum = false;

    ui->label_2->setText("0");
    ui->label_1->setText("0");
}
void calculator::binary_operation()
{
    QPushButton* button = (QPushButton*) sender();
    firstNum = ui->label_2->text().toDouble();
    label_1_disp = QString::number(firstNum, 'g', 16) + button->text();
    button->setChecked(true);
}

void calculator::on_button_equal_to_released()
{
    double result;
    double secondNum;
    QString newLabel;
    QString new_num="";

    secondNum = (ui->label_2->text()).toDouble();
    new_num = QString::number(secondNum, 'g', 16);


    if(ui->button_add->isChecked())
    {
        ui->label_1->setText(label_1_disp + QString::number(secondNum, 'g', 16) + " =");
        result = firstNum + secondNum;
        newLabel = QString::number(result, 'g', 16);
        ui->label_2->setText(newLabel);
        ui->button_add->setChecked(false);
    }
    else if(ui->button_sub->isChecked())
    {
        ui->label_1->setText(label_1_disp + QString::number(secondNum, 'g', 16) + " =");
        result = firstNum - secondNum;
        newLabel = QString::number(result, 'g', 16);
        ui->label_2->setText(newLabel);
        ui->button_sub->setChecked(false);
    }
    else if(ui->button_multiply->isChecked())
    {
        ui->label_1->setText(label_1_disp + QString::number(secondNum, 'g', 16) + " =");
        result = firstNum * secondNum;
        newLabel = QString::number(result, 'g', 16);
        ui->label_2->setText(newLabel);
        ui->button_multiply->setChecked(false);
    }
    else if(ui->button_divide->isChecked())
    {
        if(secondNum != 0)
        {
            ui->label_1->setText(label_1_disp + QString::number(secondNum, 'g', 16) + " =");
            result = firstNum / secondNum;
            newLabel = QString::number(result, 'g', 16);
            ui->label_2->setText(newLabel);
            ui->button_divide->setChecked(false);
        }
        else
        {
            ui->label_2->setText("Cannot Devide By Zero");
        }
    }
    isUserTypingSecondNum = false;
}

