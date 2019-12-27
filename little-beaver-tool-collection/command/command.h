#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
/**
* @file     command.h
* @author   zyb
* @date     2019-12-21 11:25:12
* @brief    抽象命令类,是具体执行的接口
**/
class Command : public QObject
{
    Q_OBJECT
public:
    explicit Command(QObject *parent = nullptr);

    virtual void ExecuteCommand() = 0; //执行命令
};

#endif // COMMAND_H
