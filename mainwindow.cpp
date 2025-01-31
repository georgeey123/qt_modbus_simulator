#include "mainwindow.h"
#include <QRandomGenerator>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *readButton = new QPushButton("Read Register", centralWidget);
    registerValueField = new QLineEdit(centralWidget);
    registerValueField->setReadOnly(true);
    statusLabel = new QLabel("Status: Ready", centralWidget);

    layout->addWidget(readButton);
    layout->addWidget(registerValueField);
    layout->addWidget(statusLabel);

    connect(readButton, &QPushButton::clicked, this, &MainWindow::readRegister);
}

void MainWindow::readRegister() {
    int simulatedValue = QRandomGenerator::global()->bounded(0, 10000);
    registerValueField->setText(QString::number(simulatedValue));
    statusLabel->setText("Status: Read Success");
}
