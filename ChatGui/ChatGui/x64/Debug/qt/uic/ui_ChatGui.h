/********************************************************************************
** Form generated from reading UI file 'ChatGui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATGUI_H
#define UI_CHATGUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatGuiClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *LeftFrame;
    QVBoxLayout *verticalLayout;
    QFrame *FChatQt;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QProgressBar *progressBar_5;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QFrame *frame_4;
    QPushButton *CreateNewButton;
    QProgressBar *progressBar_2;
    QScrollArea *ChatHistoryFrame;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressBar;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *DeleteButton;
    QPushButton *RenameButton;
    QProgressBar *progressBar_3;
    QFrame *RightFrame;
    QVBoxLayout *verticalLayout_4;
    QFrame *ChatFrame;
    QVBoxLayout *verticalLayout_5;
    QScrollArea *TestMessageScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QFrame *SendMessageFrame_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QPushButton *SendButton;

    void setupUi(QMainWindow *ChatGuiClass)
    {
        if (ChatGuiClass->objectName().isEmpty())
            ChatGuiClass->setObjectName(QString::fromUtf8("ChatGuiClass"));
        ChatGuiClass->resize(916, 783);
        ChatGuiClass->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color:#191a1b;\n"
"}\n"
"\n"
"QWidget{\n"
"background-color:#191a1b;\n"
"}"));
        centralWidget = new QWidget(ChatGuiClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LeftFrame = new QFrame(centralWidget);
        LeftFrame->setObjectName(QString::fromUtf8("LeftFrame"));
        LeftFrame->setMaximumSize(QSize(240, 16777215));
        LeftFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 33, 36);\n"
"border-radius:15px;"));
        LeftFrame->setFrameShape(QFrame::StyledPanel);
        LeftFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(LeftFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        FChatQt = new QFrame(LeftFrame);
        FChatQt->setObjectName(QString::fromUtf8("FChatQt"));
        FChatQt->setMaximumSize(QSize(16777215, 70));
        FChatQt->setFrameShape(QFrame::StyledPanel);
        FChatQt->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(FChatQt);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(FChatQt);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(0, 133, 255);"));

        horizontalLayout_6->addWidget(label, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(FChatQt);

        progressBar_5 = new QProgressBar(LeftFrame);
        progressBar_5->setObjectName(QString::fromUtf8("progressBar_5"));
        progressBar_5->setMaximumSize(QSize(16777215, 3));
        progressBar_5->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QProgressBar::chunk {\n"
"  background-color: #384456;\n"
"}\n"
""));
        progressBar_5->setValue(100);
        progressBar_5->setTextVisible(false);

        verticalLayout->addWidget(progressBar_5);

        frame_3 = new QFrame(LeftFrame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(100, 30));
        frame_3->setMaximumSize(QSize(16777215, 38));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 57, 61);\n"
"border-radius:15px;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(label_2, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(frame_3);

        frame_4 = new QFrame(LeftFrame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMinimumSize(QSize(100, 25));
        frame_4->setMaximumSize(QSize(16777215, 35));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        CreateNewButton = new QPushButton(frame_4);
        CreateNewButton->setObjectName(QString::fromUtf8("CreateNewButton"));
        CreateNewButton->setGeometry(QRect(0, 0, 240, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CreateNewButton->sizePolicy().hasHeightForWidth());
        CreateNewButton->setSizePolicy(sizePolicy1);
        CreateNewButton->setMinimumSize(QSize(100, 25));
        CreateNewButton->setFont(font1);
        CreateNewButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(0, 133, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"background-color:#0865c5;\n"
"}"));

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

        verticalLayout->addWidget(frame_4);

        progressBar_2 = new QProgressBar(LeftFrame);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setMaximumSize(QSize(16777215, 3));
        progressBar_2->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QProgressBar::chunk {\n"
"  background-color: #384456;\n"
"}\n"
""));
        progressBar_2->setValue(100);
        progressBar_2->setTextVisible(false);

        verticalLayout->addWidget(progressBar_2);

        ChatHistoryFrame = new QScrollArea(LeftFrame);
        ChatHistoryFrame->setObjectName(QString::fromUtf8("ChatHistoryFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ChatHistoryFrame->sizePolicy().hasHeightForWidth());
        ChatHistoryFrame->setSizePolicy(sizePolicy2);
        ChatHistoryFrame->setMaximumSize(QSize(16777215, 99999));
        ChatHistoryFrame->setStyleSheet(QString::fromUtf8(""));
        ChatHistoryFrame->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 240, 514));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ChatHistoryFrame->setWidget(scrollAreaWidgetContents_3);

        verticalLayout->addWidget(ChatHistoryFrame);

        progressBar = new QProgressBar(LeftFrame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximumSize(QSize(16777215, 3));
        progressBar->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QProgressBar::chunk {\n"
"  background-color: #384456;\n"
"}\n"
""));
        progressBar->setValue(100);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        frame = new QFrame(LeftFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        DeleteButton = new QPushButton(frame);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(DeleteButton->sizePolicy().hasHeightForWidth());
        DeleteButton->setSizePolicy(sizePolicy3);
        DeleteButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(0, 133, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"background-color:#0865c5;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ChatGui/Icon/trash-2.svg"), QSize(), QIcon::Normal, QIcon::On);
        DeleteButton->setIcon(icon);
        DeleteButton->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(DeleteButton);

        RenameButton = new QPushButton(frame);
        RenameButton->setObjectName(QString::fromUtf8("RenameButton"));
        sizePolicy1.setHeightForWidth(RenameButton->sizePolicy().hasHeightForWidth());
        RenameButton->setSizePolicy(sizePolicy1);
        RenameButton->setMinimumSize(QSize(100, 25));
        RenameButton->setFont(font1);
        RenameButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(0, 133, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"}\n"
"QPushButton::hover{\n"
"background-color:#0865c5;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ChatGui/Icon/pen (1).png"), QSize(), QIcon::Normal, QIcon::On);
        RenameButton->setIcon(icon1);
        RenameButton->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(RenameButton);


        verticalLayout->addWidget(frame, 0, Qt::AlignBottom);

        progressBar_3 = new QProgressBar(LeftFrame);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setMaximumSize(QSize(16777215, 3));
        progressBar_3->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QProgressBar::chunk {\n"
"  background-color: #384456;\n"
"}\n"
""));
        progressBar_3->setValue(100);
        progressBar_3->setTextVisible(false);

        verticalLayout->addWidget(progressBar_3);


        horizontalLayout->addWidget(LeftFrame);

        RightFrame = new QFrame(centralWidget);
        RightFrame->setObjectName(QString::fromUtf8("RightFrame"));
        RightFrame->setStyleSheet(QString::fromUtf8("background-color:#18191a;\n"
"border-radius:15px;"));
        RightFrame->setFrameShape(QFrame::StyledPanel);
        RightFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(RightFrame);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        ChatFrame = new QFrame(RightFrame);
        ChatFrame->setObjectName(QString::fromUtf8("ChatFrame"));
        ChatFrame->setStyleSheet(QString::fromUtf8("background-color: #18191a;"));
        ChatFrame->setFrameShape(QFrame::StyledPanel);
        ChatFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(ChatFrame);
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        TestMessageScrollArea = new QScrollArea(ChatFrame);
        TestMessageScrollArea->setObjectName(QString::fromUtf8("TestMessageScrollArea"));
        TestMessageScrollArea->setStyleSheet(QString::fromUtf8(""));
        TestMessageScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 616, 675));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setAlignment(Qt::AlignTop);
        verticalLayout_2->setAlignment(Qt::AlignTop);
        TestMessageScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(TestMessageScrollArea);


        verticalLayout_4->addWidget(ChatFrame);

        SendMessageFrame_2 = new QFrame(RightFrame);
        SendMessageFrame_2->setObjectName(QString::fromUtf8("SendMessageFrame_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(SendMessageFrame_2->sizePolicy().hasHeightForWidth());
        SendMessageFrame_2->setSizePolicy(sizePolicy4);
        SendMessageFrame_2->setMaximumSize(QSize(16777215, 300));
        SendMessageFrame_2->setStyleSheet(QString::fromUtf8("background-color:#18191a;"));
        SendMessageFrame_2->setFrameShape(QFrame::StyledPanel);
        SendMessageFrame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(SendMessageFrame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textEdit = new QTextEdit(SendMessageFrame_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy5);
        textEdit->setMinimumSize(QSize(0, 0));
        textEdit->setMaximumSize(QSize(16777215, 300));
        QFont font2;
        font2.setPointSize(12);
        textEdit->setFont(font2);
        textEdit->setStyleSheet(QString::fromUtf8("background-color:#1f2023;\n"
"color: rgb(255, 255, 255);\n"
"border-radius:12px;"));

        horizontalLayout_2->addWidget(textEdit);

        SendButton = new QPushButton(SendMessageFrame_2);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        SendButton->setMinimumSize(QSize(30, 30));
        SendButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:#0085ff;\n"
"border-radius:15px;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"background-color:#0865c5;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ChatGui/Icon/send.svg"), QSize(), QIcon::Normal, QIcon::On);
        SendButton->setIcon(icon2);
        SendButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(SendButton);


        verticalLayout_4->addWidget(SendMessageFrame_2);


        horizontalLayout->addWidget(RightFrame);

        ChatGuiClass->setCentralWidget(centralWidget);

        retranslateUi(ChatGuiClass);

        QMetaObject::connectSlotsByName(ChatGuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChatGuiClass)
    {
        ChatGuiClass->setWindowTitle(QApplication::translate("ChatGuiClass", "ChatGui", nullptr));
        label->setText(QApplication::translate("ChatGuiClass", "ChatQT", nullptr));
        label_2->setText(QApplication::translate("ChatGuiClass", "Chats", nullptr));
        CreateNewButton->setText(QApplication::translate("ChatGuiClass", "+ New Chat  ", nullptr));
        DeleteButton->setText(QString());
        RenameButton->setText(QString());
        SendButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatGuiClass: public Ui_ChatGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATGUI_H
