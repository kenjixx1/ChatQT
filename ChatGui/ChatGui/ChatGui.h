#pragma once

#include <QtWidgets/QMainWindow>
#include <sqlite3.h>
#include <qdebug.h>
#include <qfile.h>
#include "ui_ChatGui.h"
#include "chatlist.h"
#include "Session.h"
#include "chatframe.h"

class ChatGui : public QMainWindow
{
   Q_OBJECT

public:
   ChatGui(QWidget *parent = nullptr);
   ~ChatGui();

   int getCurrentIndex();
   void createDataBase(int rc);
   void updateMessages(int id, const string& user, const string& system);
   int addSessionRow();
   void updateSessionName(int id, const string& name);
   void updateHistorySize(int id, int size);
   bool checkQuery(int rc);
   void createTable(int rc, const char* sql);
   string getAIResponse(const string& userMessage);
   void sessionSelected(Session* session, int page);
   void loadSessions();
   void loadConversation();
   void deleteSession();
   int countMessages();

private slots:
   void on_CreateNewButton_clicked();
   void on_DeleteButton_clicked();
   void ClearLayout(QLayout* layout);
   void on_SendButton_clicked();
   void AddMessage(QString message,bool sender);
   void on_RenameButton_clicked();

private:
   QString DeactiveSS;
   Ui::ChatGuiClass ui;
   vector<Session*> sessions;
   Session* current_session;
   sqlite3* db;
   char* errMsg = 0;
   ChatFrame* CurrentChatFrame;
   ChatFrame* DefaultChatFrame;
};
