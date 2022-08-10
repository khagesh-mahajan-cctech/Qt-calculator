#include "calculator.h"
#include "ui_calculator.h"
#include "inf_to_post.h"
#include "logic.h"
#include <QDebug>

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);

    connect(ui->button_0, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_1, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_2, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_3, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_4, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_5, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_6, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_7, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_8, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_9, SIGNAL(released()), this, SLOT(set_text()));

    connect(ui->button_plus_minus, SIGNAL(released()), this, SLOT(unary_operation()));
    connect(ui->button_percent, SIGNAL(released()), this, SLOT(unary_operation()));
    connect(ui->button_reciprocol, SIGNAL(released()), this, SLOT(unary_operation()));

    connect(ui->button_cancel, SIGNAL(released()), this, SLOT(clear_operation()));

    connect(ui->button_add, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_sub, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_multiply, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_divide, SIGNAL(released()), this, SLOT(set_text()));

    connect(ui->button_left_bracket, SIGNAL(released()), this, SLOT(set_text()));
    connect(ui->button_right_bracket, SIGNAL(released()), this, SLOT(set_text()));

}

calculator::~calculator()
{
    delete ui;
}

void calculator::set_text()
{
    QPushButton* button = (QPushButton*) sender();
    ui->label_2->setText(ui->label_2->text() + ' ' + button->text());
    ui->label_1->setText(ui->label_2->text());
}

//void calculator::on_digit_pressed()
//{
//    QPushButton* button = (QPushButton*) sender();
//    std::string expression;
//    if(ui->label_2->text() == "0")
//    {
//        expression = button->text().toStdString();
//    }
//    else
//    {
//        expression = (ui->label_2->text() + button->text()).toStdString();
//    }
//    ui->label_2->setText(QString::fromStdString(expression));

//}

void calculator::unary_operation()
{
    double labelNumber = 0.0;

    QPushButton* button =(QPushButton*) sender();

    std::string btn = (button->text()).toStdString();
    std::string text = (ui->label_2->text()).toStdString();
    labelNumber = unaryOperation(btn, text);

    ui->label_2->setText(QString::number(labelNumber, 'g', 16));
}

void calculator::clear_operation()
{
    ui->label_2->setText("0");
    ui->label_1->setText("0");
}
//void calculator::binary_operation()
//{
//    QPushButton* button = (QPushButton*) sender();
//    ui->label_2->setText(ui->label_2->text() +' ' + button->text());
//}

void calculator::on_button_decimal_released()
{
    if(!(ui->label_2->text().contains('.')))
    {
        ui->label_2->setText(ui->label_2->text() + '.');
    }
}


//void calculator::bracket_pressed()
//{
//    QPushButton* button = (QPushButton*) sender();
//    ui->label_2->setText(ui->label_2->text() +' '+ button->text());
//}

void calculator::on_button_equal_to_released()
{
//    qDebug() << ui->label_2->text();
    ui->label_1->setText(ui->label_2->text());
    std::string expression = ui->label_2->text().toStdString();

    double result = evaluate(expression);
    ui->label_2->setText(QString::number(result, 'g', 16));
}


void calculator::on_button_backspace_released()
{
    QString text = ui->label_2->text();
    text.chop(1);
    text = text.trimmed();
    ui->label_2->setText(text);
    ui->label_1->setText(text);
}

