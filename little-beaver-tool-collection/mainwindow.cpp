#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <getopt.h>
#include <windows.h>
#define Printf(x) ui->output->append(x)
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    char *cc=new char[1024];
    ui->output->setReadOnly(true);
    //    ui->input->installEventFilter(this);
    connect(ui->input,&QTextEdit::textChanged,[=](){

        if(ui->input->toPlainText().contains("\n")&&ui->input->toPlainText()!="\n"){
            QString str=ui->input->toPlainText().mid(0,ui->input->toPlainText().indexOf("\n"));
            Printf(str);
            //            char *cc=str.toLatin1().data();
            //            char *res=new char[1024*10];
            ////            executeCMD(cc,res);

            //            qDebug()<<"命令: "<<QString(cc)<<"\n";
            //            qDebug()<<"结果集: "<<QString::fromLocal8Bit(res);

            //            Printf(QString::fromLocal8Bit(res));
            ui->input->setText("");
        }
    });

}
void MainWindow::executeCMD(const char *cmd, char *result)
{
    char buf_ps[1024];
    char ps[1024]={0};
    FILE *ptr;
    strcpy(ps, cmd);
    if((ptr=popen(ps, "r"))!=NULL)
    {
        while(fgets(buf_ps, 1024, ptr)!=NULL)
        {
            strcat(result, buf_ps);
            if(strlen(result)>1024)
                break;
        }
        pclose(ptr);
        ptr = NULL;
        qDebug()<<"success!!";
    }
    else
    {
        qDebug()<<"error!!"<<ps;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    //    if(watched==ui->input){
    //        if(event->type() == QEvent::KeyPress)//回车键
    //        {
    //            QKeyEvent *k = static_cast<QKeyEvent *>(event);
    //            if(k->key() == Qt::Key_Return||k->key()==Qt::Key_Enter&&ui->input->toPlainText()!="")
    //            {
    //                ui->output->append(ui->input->toPlainText());
    //                ui->input->setText(" a");
    //                qDebug()<<"hello";

    //            }
    //        }
    //    }
    return QMainWindow::eventFilter(watched,event);
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"辅助开启";
    HWND AppWnd;
    QString ClassName( "" );
    QString AppName( "bbb" );

    LPCWSTR App = reinterpret_cast <LPCWSTR>(ClassName.data());
    LPCWSTR AppCaption = reinterpret_cast <LPCWSTR>(AppName.data());

    AppWnd= ::FindWindow( NULL, AppCaption);
    qDebug()<<AppWnd;
SetForegroundWindow(AppWnd);
//    ::mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE,300*65535/1600,300*65535/900,0,0);
//    QApplication::sendEvent(gameWindow,clickEvent);


//    QDesktopWidget *desktop = QApplication::desktop();
//    Qrect screen = desktop->screenGeometry();
//    int screenWidth = screen.width();
//    int screenHeight = screen.height();
}

void MainWindow::on_actionCommand_triggered()
{
    //    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::on_actionGui_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}
