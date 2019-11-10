#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->output->setReadOnly(true);
    ui->input->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->input){
        if(event->type() == QEvent::KeyPress)//回车键
                {
                     QKeyEvent *k = static_cast<QKeyEvent *>(event);
                     if(k->key() == Qt::Key_Return||k->key()==Qt::Key_Enter)
                     {
                         ui->output->append(ui->input->toPlainText());
                         ui->input->setText(" a");
                         ui->input->clear();
                         qDebug()<<"hello";

                     }
                }
    }
    return QMainWindow::eventFilter(watched,event);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_actionCommand_triggered()
{
//    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentWidget(ui->input);
}
