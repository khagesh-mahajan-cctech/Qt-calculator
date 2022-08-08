#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();

private:
    Ui::calculator *ui;

private slots:
    void on_digit_pressed();
    void unary_operation();
    void clear_operation();
    void binary_operation();
    void on_button_decimal_released();
    void bracket_pressed();
    void on_button_equal_to_released();
};
#endif // CALCULATOR_H
