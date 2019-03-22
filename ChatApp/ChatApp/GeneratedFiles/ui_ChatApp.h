/********************************************************************************
** Form generated from reading UI file 'ChatApp.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATAPP_H
#define UI_CHATAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatAppClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatAppClass)
    {
        if (ChatAppClass->objectName().isEmpty())
            ChatAppClass->setObjectName(QStringLiteral("ChatAppClass"));
        ChatAppClass->resize(600, 400);
        menuBar = new QMenuBar(ChatAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ChatAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ChatAppClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ChatAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ChatAppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ChatAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChatAppClass->setStatusBar(statusBar);

        retranslateUi(ChatAppClass);

        QMetaObject::connectSlotsByName(ChatAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChatAppClass)
    {
        ChatAppClass->setWindowTitle(QApplication::translate("ChatAppClass", "ChatApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatAppClass: public Ui_ChatAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATAPP_H
