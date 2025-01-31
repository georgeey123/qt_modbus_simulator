#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Modbus Register Simulator");
    window.resize(300, 150);
    window.show();
    return app.exec();
}
