#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <random>
#include <QMessageBox>


// TODO: Add score
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
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

    ui->paperButton->setFocus();

    connect(ui->actionHelp, &QAction::triggered,
            this, &MainWindow::onHelpContext);
    connect(ui->action_About, &QAction::triggered,
            this, &MainWindow::onHelpAbout);
    connect(ui->actionAbout_Qt, &QAction::triggered,
            qApp, &QApplication::aboutQt);

    connect(ui->actionTry_again, &QAction::triggered,
            ui->tryAgainButton, &QPushButton::click);
}

void MainWindow::onHelpContext()
{
    QMessageBox d(this);
    d.setText(tr("<h2>What are the rules?</h2>"
                 "<p>The rules are very simple and probably you remember them from your childhood:</p>"
                 "<ul>"
                 "<li>If you choose Rock, you will win against Scissors but lose against Paper.</li>"
                 "<li>If you choose Scissors, you will win against Paper but lose against Rock.</li>"
                 "<li>If you choose Paper, you will win against Rock but lose against Scissors.</li>"
                 "</ul>"
                 "<p>There can be 3 to 5 rounds. The game ends when somebody gets 3 wins. If you want to play again, "
                 "just click “Play again” button after a game is finished.</p>"));

    d.setWindowTitle(tr("Rock Paper Scissors"));

    d.exec();
}

void MainWindow::onHelpAbout()
{
    QMessageBox::about(this, tr("About RockPaperScissors"), tr("<h2>RockPaperScissors</h2>\n"
                                                               "<p>RockPaperScissors is, as the name suggests a scissor stone paper game.</p>\n"
                                                               "<h2>About</h2>\n"
                                                               "<table class=\"table\" style=\"border-style: none;\">\n"
                                                               "<tbody>\n"
                                                               "<tr>\n"
                                                               "<td>Version:</td>\n"
                                                               "<td>%1</td>\n"
                                                               "</tr>\n"
                                                               "<tr>\n"
                                                               "<td>Qt Version:</td>\n"
                                                               "<td>%2</td>\n"
                                                               "</tr>\n"
                                                               "<tr>\n"
                                                               "<td>Homepage:</td>\n"
                                                               "<td><a href=\"https://github.com/software-made-easy/RockPaperScissors\">https://github.com/software-made-easy/RockPaperScissors</a></td>\n"
                                                               "</tr>\n"
                                                               "</tbody>\n"
                                                               "</table>"
                                                               ).arg(QStringLiteral(APP_VERSION), qVersion()));
}

void MainWindow::onInput()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    const QPixmap pixmap = btn->icon().pixmap(60, 60);
    ui->youLabel->setPixmap(pixmap);

    static std::random_device rd; // obtain a random number from hardware
    static std::mt19937 gen(rd()); // seed the generator
    static std::uniform_int_distribution<int> distr(1, 3); // define the range

    const auto i = distr(gen); // generate numbers

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
