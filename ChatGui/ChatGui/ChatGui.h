#pragma once

#include <QtWidgets/QMainWindow>
#include <sqlite3.h>
#include <qdebug.h>
#include <qfile.h>
#include "ui_ChatGui.h"
#include "chatlist.h"
#include "Session.h"

class ChatGui : public QMainWindow
{
   Q_OBJECT

public:
   ChatGui(QWidget *parent = nullptr);
   ~ChatGui();

   void createDataBase(int rc);
   void updateMessages(int id, const string& user, const string& system);
   void newSession();
   void changeSessionName(int id, const string& name);
   void updateHistorySize(int id, int size);
   bool checkQuery(int rc);
   void createTable(int rc, const char* sql);
   string getAIResponse(const string& userMessage);

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
   Session current_session;
   sqlite3* db;
   char* errMsg = 0;
};
