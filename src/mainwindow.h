#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QPixmap;
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onInput();

private:
    Ui::MainWindow *ui;

    QPixmap paperIcon;
    QPixmap rockIcon;
    QPixmap scissourcsIcon;

};
#endif // MAINWINDOW_H
