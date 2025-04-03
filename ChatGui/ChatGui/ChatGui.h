#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatGui.h"
#include "chatlist.h"

class ChatGui : public QMainWindow
{
    Q_OBJECT

public:
    ChatGui(QWidget *parent = nullptr);
    ~ChatGui();

private slots:
    void on_CreateNewButton_clicked();
    void ActiveButton_Click();
    void on_DeleteButton_clicked();
    void ClearLayout(QLayout* layout);
    void LoadChatHistory();
    void on_SendButton_clicked();
    void AddMessage(QString message,bool sender);
    void on_RenameButton_clicked();

private:
    QPushButton* ActiveButton;
    QString DeactiveSS;
    ChatList clist;
    Ui::ChatGuiClass ui;
};
