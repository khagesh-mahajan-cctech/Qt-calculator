#define CATCH_CONFIG_MAIN
#include "calculator.h"
#include "catch.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calculator w;
    w.show();
    Catch::Session().run(argc,argv);
    return a.exec();
}
