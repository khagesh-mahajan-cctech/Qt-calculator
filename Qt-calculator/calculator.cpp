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
}

calculator::~calculator()
{
    delete ui;
}

void calculator::on_digit_pressed()
{
    QPushButton* button = (QPushButton*) sender();
    ui->label_2->setText(button->text());
}

