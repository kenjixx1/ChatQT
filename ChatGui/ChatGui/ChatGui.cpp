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

ChatGui::ChatGui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

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
        });
    AddMessage("What can I help you with?", 0);

}

ChatGui::~ChatGui()
{}

void ChatGui::on_CreateNewButton_clicked() {
    AddMessage("What can I help you with?", 0);
    
}




void ChatGui::ActiveButton_Click() {
    QObject* Sender = sender();
    QPushButton* button = qobject_cast<QPushButton*>(Sender);
    int id = button->property("ChatId").toInt();
    //QMessageBox::information(nullptr, "Message", "ID:"+QString::number(id));
    clist.SetActive(id);
    ActiveButton = clist.GetButtonByID(id);
    ClearLayout(ui.verticalLayout_3);

}

void ChatGui::ClearLayout(QLayout* layout) {
    QLayoutItem* obj;
    while ((obj = layout->takeAt(0)) != nullptr) {
        if (QWidget* widget = obj->widget()) {
            widget->setParent(0);
        }
    }
}

void ChatGui::LoadChatHistory() {
    ClearLayout(ui.verticalLayout_2);
    for (int i = 0; i < clist.Size(); i++) {
        ui.verticalLayout_2->addWidget(clist.GetButton(i),0, Qt::AlignTop);
    }
}



void ChatGui::on_DeleteButton_clicked() {
    if (ActiveButton != nullptr) {
        int id = ActiveButton->property("ChatId").toInt();
        clist.Remove(id);
        LoadChatHistory();
    }
    ActiveButton = nullptr;
    
}

void ChatGui::on_SendButton_clicked() {
    
    if (ActiveButton == nullptr) {
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        QPushButton* TempTest;
        TempTest = new QPushButton(ui.scrollAreaWidgetContents_3);
        TempTest->setFont(font1);
        TempTest->setStyleSheet(DeactiveSS);

        TempTest->setMinimumSize(QSize(100, 25));
        ui.verticalLayout_2->addWidget(TempTest, 0, Qt::AlignTop);

        connect(TempTest, &QPushButton::clicked, this, &::ChatGui::ActiveButton_Click);
        int size = clist.Size();
        TempTest->setProperty("ChatId", clist.GetMyID());
        int id = clist.GetMyID();
        QString name = "ChatID:" + QString::number(id);
        TempTest->setText(name);
        clist.AddList(TempTest);
        ActiveButton = TempTest;
        clist.SetActive(id);


    }
    QString message = ui.textEdit->toPlainText();
    if (!message.isEmpty()) {
        AddMessage(message, 1);
        ui.textEdit->clear();
        ui.textEdit->setFocus();
    }
    
}

void ChatGui::on_RenameButton_clicked() {
    if (ActiveButton != nullptr) {
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
            ActiveButton->setText(input);
        }
    }
}


void ChatGui::AddMessage(QString message, bool sender) {
    //Bot=0 User=1 :D
    QFrame* tempFrame = new QFrame(ui.scrollAreaWidgetContents_3);
    tempFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    tempFrame->setStyleSheet(QString::fromUtf8("background-color:#1f2023;"));
    tempFrame->setFrameShape(QFrame::StyledPanel);



    QHBoxLayout* layout = new QHBoxLayout(tempFrame);
    layout->setSpacing(6);
    layout->setContentsMargins(10, 10, 10, 10);

    
    
    QFont font;
    font.setPointSize(14);

    QLabel* text = new QLabel(message);
    text->setMaximumWidth(ui.TestMessageScrollArea->width()*0.8);
    text->setFont(font);
    text->setTextInteractionFlags(Qt::TextBrowserInteraction);
    text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
    
    QTimer::singleShot(10, this, [=]() {
        if (text->width() > ui.TestMessageScrollArea->width() * 0.7) {
            text->setMinimumWidth(ui.TestMessageScrollArea->width() * 0.5);
            text->setWordWrap(true);
            //QMessageBox::information(nullptr, "Y", "Text:" + QString::number(text->width()) + "|| Frame:" + QString::number(ui.TestMessageScrollArea->width() * 0.7));
            
        }
        else {
            //QMessageBox::information(nullptr, "X", "Text:" + QString::number(text->width()) + "|| Frame:" + QString::number(ui.TestMessageScrollArea->width() * 0.7));
            text->setWordWrap(false);
        }
        }
    );
    
    
    if (sender) {
        layout->addStretch();
        layout->addWidget(text,0,Qt::AlignCenter);
        ui.verticalLayout_3->addWidget(tempFrame, 0, Qt::AlignRight);
    }
    else {
        layout->addWidget(text, 0, Qt::AlignCenter);
        layout->addStretch();
        ui.verticalLayout_3->addWidget(tempFrame, 0, Qt::AlignLeft);
        
    }
    //QMessageBox::information(nullptr, "Height", QString::number(ui.TestMessageScrollArea->verticalScrollBar()->maximum()));

    QTimer::singleShot(10, this, [=]() {
        QScrollBar* scrollbar = ui.TestMessageScrollArea->verticalScrollBar();
        scrollbar->setValue(ui.TestMessageScrollArea->verticalScrollBar()->maximum()-1);
        }
    );
}

void ChatGui::sessionSelected(Session* session, int page) {
	current_session = session;
    
	if (current_session->getLoadSize() < current_session->getHistorySize()) {
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
void ChatGui::addSessionRow() {
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO messages (name, history_size) VALUES (?, 0);";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (checkQuery(rc)) {
        sqlite3_finalize(stmt);
        return;
    }

    sqlite3_bind_text(stmt, 1, "", -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        qDebug() << "Failed to insert the messages: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_finalize(stmt);
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
		sessions.push_back(new Session(id, name, temp, history_size)); // Will add parent widget later

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