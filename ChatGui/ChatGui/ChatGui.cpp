#include "ChatGui.h"
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
    QLabel* bubble = new QLabel("Hello, how are you?");
    bubble->setStyleSheet(
        "background-color: #0078D7;"
        "color: white;"
        "padding: 8px;"
        "border-radius: 10px;"
    );
    bubble->setWordWrap(true);
    qDebug() << "Hello\n\n\n\n";
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

}

ChatGui::~ChatGui()
{}

void ChatGui::on_CreateNewButton_clicked() {
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
        on_CreateNewButton_clicked();

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
