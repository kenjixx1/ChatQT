#include "ChatGui.h"
#include "Session.h"
#include <iostream>
#include <qdebug.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <qscrollbar.h>
#include <qtimer.h>
#include <qtextedit.h>
#include <qfontmetrics.h>
#include <qinputdialog.h>
#include "chatframe.h"

ChatGui::ChatGui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.verticalLayout_2->setAlignment(Qt::AlignTop);
    ChatFrame* FirstPage = new ChatFrame();
    ui.StackedChatFrame->addWidget(FirstPage);
    ui.StackedChatFrame->setCurrentWidget(FirstPage);
    CurrentChatFrame = FirstPage;
    CurrentChatFrame->AddFMessage("What can I help you with?", 0);
	current_session = nullptr; 
    const char* dbPath = "chatHistory.db"; // Path to database
    int rc;


	// Check if the database file exists and create tables else open the database
	if (!QFile::exists(dbPath)) {
        rc = sqlite3_open(dbPath, &db);
		createDataBase(rc);
    }
    else {
		rc = sqlite3_open(dbPath, &db);
    }

        qApp->setStyleSheet(R"(
QScrollBar:vertical {
    background: transparent;
    width: 8px;
    margin: 0px;
}

QScrollBar::handle:vertical {
    background: #0c6ee9;
    border-radius: 4px;
    min-height: 20px;
}

QScrollBar::add-line:vertical,
QScrollBar::sub-line:vertical {
    height: 0px;
}

QScrollBar::add-page:vertical,
QScrollBar::sub-page:vertical {
    background: none;
}

)");




    DeactiveSS = "QPushButton{\n""background-color:#2aa5ff;\n""color: rgb(255, 255, 255);\n""border-radius:0px;\n""}\n""QPushButton::hover{\n""background-color:#0865c5;\n"
            "}";

    //QMessageBox::information(nullptr, "Message", "ClickEd");

    connect(ui.textEdit, &QTextEdit::textChanged, this, [=] {
        QTextDocument* doc = ui.textEdit->document();
        QFontMetrics matric(ui.textEdit->font());

        int currentline = doc->blockCount();
        int height = matric.lineSpacing();
        int pad = 10;

        int min = 1;
        int max = 6;

        int visline = qMin(qMax(currentline, min), max);
        int newheight = visline * height + pad;
        ui.textEdit->setFixedHeight(newheight);

		//QMessageBox::information(nullptr, "Message", QString::number(currentline));

		QTextCursor cursor = ui.textEdit->textCursor();
		int cursorPos = cursor.position();

		cursor.movePosition(QTextCursor::StartOfLine,QTextCursor::MoveAnchor);
		int startOfLine = cursor.position();
        cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
        QString currentLineText = cursor.selectedText();

		
        QString text = ui.textEdit->toPlainText();
        int width = ui.textEdit->width();
		int currentWidth = matric.horizontalAdvance(currentLineText);
		if (currentWidth > width * 0.9) {
            ui.textEdit->insertPlainText("\n");
            ui.textEdit->moveCursor(QTextCursor::End);
		}
		
        
        
        });

}

ChatGui::~ChatGui()
{}

void ChatGui::on_CreateNewButton_clicked() {
    ChatFrame* chat = new ChatFrame();
    ui.StackedChatFrame->addWidget(chat);
    ui.StackedChatFrame->setCurrentWidget(chat);
    current_session = nullptr;
    CurrentChatFrame = chat;
    CurrentChatFrame->AddFMessage("What Can I help you with?", 0);
    string res;
	
    //AddMessage("What can I help you with?", 0);
    
}

void ChatGui::ClearLayout(QLayout* layout) {
    QLayoutItem* obj;
    while ((obj = layout->takeAt(0)) != nullptr) {
        if (QWidget* widget = obj->widget()) {
            widget->setParent(0);
        }
    }
}

void ChatGui::on_DeleteButton_clicked() {
    if (current_session != nullptr) {
        deleteSession();
        // remove the page
        ui.StackedChatFrame->removeWidget(CurrentChatFrame);
		    delete CurrentChatFrame;
        ChatFrame* newpage = new ChatFrame();
        ui.StackedChatFrame->addWidget(newpage);
        ui.StackedChatFrame->setCurrentWidget(newpage);
        CurrentChatFrame = newpage;
        CurrentChatFrame->AddFMessage("What can I help you with?", 0);
    }
    current_session = nullptr;
    
}

void ChatGui::on_SendButton_clicked() {
    //Binding Button
    if (current_session == nullptr) {
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        Session* TempTest;
        string something;
        TempTest = new Session(sessions.size(), "Kenji", something, 0, "", ui.scrollAreaWidgetContents_3);
        connect(TempTest, &Session::selected, this, &ChatGui::sessionSelected);
        ui.verticalLayout_2->addWidget(TempTest, 0, Qt::AlignTop);
		sessions.push_back(TempTest);
        connect(TempTest->button, &QPushButton::clicked, this, [=]() {
            // Handle button click
            sessionSelected(TempTest, 0);
            });
		current_session = TempTest;

        /*connect(TempTest, &QPushButton::clicked, this, &::ChatGui::ActiveButton_Click);
        int size = clist.Size();
        TempTest->setProperty("ChatId", clist.GetMyID());
        int id = clist.GetMyID();
        QString name = "ChatID:" + QString::number(id);
        TempTest->setText(name);
        clist.AddList(TempTest);
        ActiveButton = TempTest;
        clist.SetActive(id);*/


    }
    QString message = ui.textEdit->toPlainText();
    if (!message.isEmpty()) {
        CurrentChatFrame->AddFMessage(message, 1);
        ui.textEdit->clear();
        ui.textEdit->setFocus();
    }
    
}

void ChatGui::on_RenameButton_clicked() {
    if (current_session != nullptr) {
        QInputDialog* inputDialog = new QInputDialog(this);
        inputDialog->setWindowTitle("Styled Input");
        inputDialog->setLabelText("Chat Name:");
        inputDialog->setInputMode(QInputDialog::TextInput);
        inputDialog->resize(300, 150);
        inputDialog->setStyleSheet(R"(
    QInputDialog{
        background-color:#18191a;
        color:#ffffff;
}

    QLabel{
        color:#ffffff;
       }
    QPushButton{
        background-color:#0f85fd;
        color:#ffffff;
        border-radius:12px;
        padding: 8px 10px;
    }
    QLineEdit{
        color: white;
        border: 1px solid #1f2023;
        padding: 4px;
        border-radius: 4px;
     }
)");
            
            
            
            
            
           

        if (inputDialog->exec() == QDialog::Accepted) {
            QString input = inputDialog->textValue();
			current_session->changeName(input.toStdString());
        }
    }
}


void ChatGui::AddMessage(QString message, bool sender) {
	CurrentChatFrame->AddFMessage(message, sender);
}

int ChatGui::getCurrentIndex() {
	if (current_session == nullptr) {
		return 0;
	}

    int index{ 0 };
	for (const auto& session : sessions) {
        index++;
		if (session->getID() == current_session->getID()) {
			return index;
		}
	}
}

void ChatGui::sessionSelected(Session* session, int page) {
	//current_session->deactivate();
    current_session = session;
    ui.StackedChatFrame->setCurrentIndex(getCurrentIndex()+1);
    
    
	if (current_session->getLoadSize() > current_session->getHistorySize()) {
		loadConversation();
	}

	// Change stacked widget to the conversation page
}

// Get AI response from the current session
string ChatGui::getAIResponse(const string& userMessage) {
	string response = current_session->getResponse(userMessage);
	updateMessages(current_session->getID(), userMessage, response);
    return response;
}

// Create the database and tables if they do not exist
void ChatGui::createDataBase(int rc) {
    const char* sessions = R"(
        CREATE TABLE IF NOT EXISTS sessions (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        history_size INTEGER NOT NULL
        );
    )";
    createTable(rc, sessions);

    const char* messages = R"(
        CREATE TABLE IF NOT EXISTS messages (
        session_id INTEGER NOT NULL,
        user TEXT NOT NULL,
        system TEXT NOT NULL,
        FOREIGN KEY (session_id) REFERENCES sessions(id) ON DELETE CASCADE
        );
    )";
    createTable(rc, messages);
}

// Update messages in the database
void ChatGui::updateMessages(int id, const string& user, const string& system) {
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO messages (session_id, user, system) VALUES (?, ?, ?);";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (checkQuery(rc)) {
        sqlite3_finalize(stmt);
        return;
    }

    //Bind the data
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_bind_text(stmt, 2, user.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, system.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        qDebug() << "Failed to insert the messages: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt);
}

// Create a new session in the database
int ChatGui::addSessionRow() {
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO messages (name, history_size) VALUES (?, 0);";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (checkQuery(rc)) {
        sqlite3_finalize(stmt);
        return 0;
    }

    sqlite3_bind_text(stmt, 1, "", -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        qDebug() << "Failed to insert the messages: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt);

	return sqlite3_last_insert_rowid(db); // Get the ID of the last inserted row
}

// Change the name of a session in the database
void ChatGui::updateSessionName(int id, const string& name) {
    sqlite3_stmt* stmt;
    const char* sql = "UPDATE sessions SET name = ? WHERE id = ?;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (checkQuery(rc)) {
        sqlite3_finalize(stmt);
        return;
    }

    //Bind the data
    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, id);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        qDebug() << "Failed to insert the messages: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt);
}

// Update the history size of a session in the database
void ChatGui::updateHistorySize(int id, int size) {
    sqlite3_stmt* stmt;
    const char* sql = "UPDATE sessions SET hisotory_size = ? WHERE id = ?;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (checkQuery(rc)) {
        sqlite3_finalize(stmt);
        return;
    }

    //Bind the data
    sqlite3_bind_int(stmt, 1, size);
    sqlite3_bind_int(stmt, 2, id);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        qDebug() << "Failed to insert the messages: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt);
}

// Load all sessions from the database          
void ChatGui::loadSessions() {
	sqlite3_stmt* stmt;
	const char* sql = "SELECT id, name, history_size FROM sessions;";
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	if (checkQuery(rc)) {
		sqlite3_finalize(stmt);
		return;
	}
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		int id = sqlite3_column_int(stmt, 0);
		const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		int history_size = sqlite3_column_int(stmt, 2);

        string temp;
		Session* session = new Session(id, name, temp, history_size, "", ui.scrollAreaWidgetContents_3);
		connect(session, &Session::selected, this, &ChatGui::sessionSelected);
        sessions.push_back(session); 

		// Add sessions and connect
	}
	sqlite3_finalize(stmt);
}

// Load the conversation history for the current session
void ChatGui::loadConversation() {
	sqlite3_stmt* stmt;
	const char* sql = "SELECT user, system FROM messages WHERE session_id = ?;";
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	if (checkQuery(rc)) {
		sqlite3_finalize(stmt);
		return;
	}
	sqlite3_bind_int(stmt, 1, current_session->getID());

	int his_track = countMessages() - current_session->getLoadSize(); // Track when to push messages into history (for AI)
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		const char* user = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
		const char* system = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		AddMessage(QString::fromStdString(user), 1);
		AddMessage(QString::fromStdString(system), 0);
		
        if (his_track <= 0) {
			current_session->addHistory(user, 1);
			current_session->addHistory(system, 0);
        }

		his_track--;
	}
	sqlite3_finalize(stmt);
}

// Delete a session from the database
void ChatGui::deleteSession() {
	sqlite3_stmt* stmt;
	const char* sql = "DELETE FROM sessions WHERE id = ?;";
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	if (checkQuery(rc)) {
		sqlite3_finalize(stmt);
		return;
	}
	sqlite3_bind_int(stmt, 1, current_session->getID());
	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE) {
		qDebug() << "Failed to delete the session: " << sqlite3_errmsg(db) << endl;
	}
	sqlite3_finalize(stmt);
}

// Count the number of messages in the current session
int ChatGui::countMessages() {
	sqlite3_stmt* stmt;
	const char* sql = "SELECT COUNT(*) FROM messages WHERE session_id = ?;";
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	if (checkQuery(rc)) {
		sqlite3_finalize(stmt);
		return 0;
	}
	sqlite3_bind_int(stmt, 1, current_session->getID());
	int count = 0;
	if (sqlite3_step(stmt) == SQLITE_ROW) {
		count = sqlite3_column_int(stmt, 0);
	}
	sqlite3_finalize(stmt);
	return count;
}

// Check if the query was successful
bool ChatGui::checkQuery(int rc) {
	if (rc != SQLITE_OK) {
		qDebug() << "SQL error:" << sqlite3_errmsg(db);
		return false;
	}
	return true;
}

// Create a table in the database
void ChatGui::createTable(int rc, const char* sql) {
	rc = sqlite3_exec(db, sql, nullptr, 0, &errMsg);
	if (rc != SQLITE_OK) {
		qDebug() << "SQL error:" << errMsg;
		sqlite3_free(errMsg);
	}
}