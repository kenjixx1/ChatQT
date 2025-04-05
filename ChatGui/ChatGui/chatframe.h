#pragma once
#include <qwidget.h>
#include <qframe.h>
#include <qlabel.h>
#include <qboxlayout.h>
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
#include <qscrollarea.h>
#include <qtextboundaryfinder.h>




//
class ChatFrame :public QWidget {
    Q_OBJECT
    

public:
	explicit ChatFrame(QWidget* parent = nullptr) {

        page = new QWidget();
        pagelayout = new QVBoxLayout(this);
        pagelayout->setSpacing(6);
        pagelayout->setContentsMargins(11, 11, 11, 11);
        scrollarea = new QScrollArea(page);
        scrollarea->setWidgetResizable(true);
        content = new QWidget();
        messagelayout = new QVBoxLayout(content);
        messagelayout->setContentsMargins(11, 11, 11, 11);
		messagelayout->setAlignment(Qt::AlignBottom);
        scrollarea->setWidget(content);
        pagelayout->addWidget(scrollarea);

        


	}
	~ChatFrame() {
		delete content;
		delete scrollarea;
		delete pagelayout;
	}

    QString wrapTextBasedOnLanguage(const QString& text, const QFontMetrics& fm, int maxWidth) {
        QString wrappedText;
        QString currentLine;
        bool isEnglish;

        for (QChar c : text) {
        	if (c.unicode() > 127) {
        		isEnglish = false;
        		break;
        	}
        	else {
       		isEnglish = true;
            }
        }
        

        if (isEnglish) {
            // English: Wrap at spaces (manually skip empty parts)
            QStringList words = text.split(' ', QString::SkipEmptyParts); 
            for (const QString& word : words) {
                QString testLine = currentLine.isEmpty() ? word : currentLine + " " + word;
                if (fm.horizontalAdvance(testLine) <= maxWidth) {
                   currentLine = testLine;
                }
                else {
                    if (!currentLine.isEmpty()) {
                        wrappedText += currentLine + "\n";
                    }
                    currentLine = word;
                }
            }
        }
        else {
            // Non-English: Wrap at grapheme boundaries
            QTextBoundaryFinder boundaryFinder(QTextBoundaryFinder::Grapheme, text);
            int startPos = 0;
            while (startPos < text.length()) {
                boundaryFinder.setPosition(startPos);
                int endPos = boundaryFinder.toNextBoundary();
                if (endPos == -1) break;

                QString grapheme = text.mid(startPos, endPos - startPos);
                QString testLine = currentLine + grapheme;

                if (fm.horizontalAdvance(testLine) <= maxWidth) {
                    currentLine = testLine;
               }
                else {
                    if (!currentLine.isEmpty()) {
                        wrappedText += currentLine + "-\n";
                    }
                    currentLine = grapheme;
               }
                startPos = endPos;
            }
        }

        if (!currentLine.isEmpty()) {
            wrappedText += currentLine;
       }

        return wrappedText;
    }

    //--------------------------------//
	void AddFMessage(QString message,bool sender) {
        ////Bot=0 User=1 :D
        bool isEnglish;
		//QMessageBox::information(nullptr, "Language Detection", message);
        QFrame* TextFrame = new QFrame(content);
        TextFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        TextFrame->setStyleSheet(QString::fromUtf8("background-color:#1f2023;"));
        TextFrame->setFrameShape(QFrame::StyledPanel);
		

        QHBoxLayout* TextLayout = new QHBoxLayout(TextFrame);
        TextLayout->setSpacing(6);
        TextLayout->setContentsMargins(10, 10, 10, 10);

        QFont font;
        font.setPointSize(14);
		int maxWidth = scrollarea->width() * 0.7;
        QFontMetrics fm(font);
        QStringList words = message.split(' ');
        QString result;
        QString currentLine;

		result = wrapTextBasedOnLanguage(message, fm, maxWidth);


        QLabel* text = new QLabel(result);
        text->setMaximumWidth(scrollarea->width() * 0.8);
        text->setFont(font);
        text->setTextInteractionFlags(Qt::TextBrowserInteraction);
        text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        text->setStyleSheet(QString::fromUtf8("color:#ffffff;"));
        
        
		int lineCount = text->text().count('\n') + 1;
		

        QTimer::singleShot(10, this, [=]() {
 
            if (text->width() > scrollarea->width() * 0.7) 
            {
                text->setMinimumWidth(scrollarea->width() * 0.7);
                text->setWordWrap(false);
            }
            else 
            {
                text->setWordWrap(false);
            }
            });

        if (sender) {
            TextLayout->addWidget(text,0,Qt::AlignCenter);
    
            messagelayout->addWidget(TextFrame, 0, Qt::AlignRight);
        }
        else {
            TextLayout->addWidget(text, 0, Qt::AlignCenter);
            messagelayout->addWidget(TextFrame, 0, Qt::AlignLeft);
        }

        QTimer::singleShot(10, this, [=]() {
            QScrollBar* scrollbar = scrollarea->verticalScrollBar();
            scrollbar->setValue(scrollarea->verticalScrollBar()->maximum() - 1);
        });
        //QMessageBox::information(nullptr, "Language Detection", message);

	}
private:
    QWidget* content;
    QVBoxLayout* pagelayout;
    QVBoxLayout* messagelayout;
    QScrollArea* scrollarea;
    int id;

public:
    QWidget* page;

	void operator=(QWidget* other) {
		this->page = other;

	}
};


