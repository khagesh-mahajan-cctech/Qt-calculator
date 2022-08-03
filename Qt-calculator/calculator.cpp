#include "calculator.h"
#include "ui_calculator.h"

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
}

calculator::~calculator()
{
    delete ui;
}

void calculator::on_digit_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    if(ui->label_2->text() == "0")
    {
        ui->label_2->setText(button->text());
    }
    else
    {
        ui->label_2->setText(ui->label_2->text() + button->text());
    }
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
}
