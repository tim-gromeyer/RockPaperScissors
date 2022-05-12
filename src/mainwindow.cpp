#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <random>
#include <QDebug>
#include <QShortcut>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tryAgainButton->setText(QLatin1String());
    ui->tryAgainButton->setEnabled(false);

    paperIcon = ui->paperButton->icon().pixmap(60, 60);
    rockIcon = ui->rockButton->icon().pixmap(60, 60);
    scissourcsIcon = ui->scissourcsButton->icon().pixmap(60, 60);

    connect(ui->paperButton, &QPushButton::clicked,
            this, &MainWindow::onInput);
    connect(ui->rockButton, &QPushButton::clicked,
            this, &MainWindow::onInput);
    connect(ui->scissourcsButton, &QPushButton::clicked,
            this, &MainWindow::onInput);

    QShortcut *shortcut = new QShortcut(QKeySequence::Quit, this);
    QObject::connect(shortcut, &QShortcut::activated,
                     qApp, &QApplication::quit);

    ui->paperButton->setFocus();
}

void MainWindow::onInput()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    const QPixmap pixmap = btn->icon().pixmap(60, 60);
    ui->youLabel->setPixmap(pixmap);

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 3); // define the range

    const int i = distr(gen); // generate numbers

    switch (i) {
    case 1:
        ui->computerLabel->setPixmap(paperIcon);
        break;
    case 2:
        ui->computerLabel->setPixmap(rockIcon);
        break;
    case 3:
        ui->computerLabel->setPixmap(scissourcsIcon);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
