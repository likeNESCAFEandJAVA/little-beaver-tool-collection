#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QKeyEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void executeCMD(const char *cmd, char *result);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
private slots:
    void on_pushButton_clicked();

    void on_actionCommand_triggered();

    void on_actionGui_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
