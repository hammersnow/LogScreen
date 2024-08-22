/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jul 31 00:01:14 2024
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QComboBox *eds;
    QComboBox *log;
    QPushButton *pushButton;
    QTextBrowser *cikti;
    QLabel *label_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1521, 743);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(107, 107, 107);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 111, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);\n"
"border-radius:10"));
        label->setFrameShape(QFrame::Box);
        eds = new QComboBox(centralWidget);
        eds->setObjectName(QString::fromUtf8("eds"));
        eds->setGeometry(QRect(10, 50, 111, 31));
        eds->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);"));
        log = new QComboBox(centralWidget);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(150, 50, 141, 31));
        log->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 50, 80, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);"));
        cikti = new QTextBrowser(centralWidget);
        cikti->setObjectName(QString::fromUtf8("cikti"));
        cikti->setGeometry(QRect(10, 100, 1501, 601));
        cikti->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);\n"
"border-radius:10\n"
""));
        cikti->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1370, 710, 131, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setPointSize(6);
        font1.setItalic(false);
        label_2->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Log Screen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<table style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">MV3D</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        eds->clear();
        eds->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ED01", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED03", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED04", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED05", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED06", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED09", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ED28", 0, QApplication::UnicodeUTF8)
        );
        log->clear();
        log->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Machine Fault", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Bhs Log", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Hvps Arc", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Flow Switch", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Bad Detectors", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Array Test", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Otk", 0, QApplication::UnicodeUTF8)
        );
        pushButton->setText(QApplication::translate("MainWindow", "Ok", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:6pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">Ekrem Gokberk Iscan</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
