#include "button.h"
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Button button(nullptr);

    button.setFixedSize(110, 100);
    button.move(800, 400);
    button.show();
    return a.exec();
}
