#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QPixmap;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onInput();
    void onHelpContext();
    void onHelpAbout();

private:
    Ui::MainWindow *ui;

    QPixmap paperIcon;
    QPixmap rockIcon;
    QPixmap scissourcsIcon;

};
#endif // MAINWINDOW_H
