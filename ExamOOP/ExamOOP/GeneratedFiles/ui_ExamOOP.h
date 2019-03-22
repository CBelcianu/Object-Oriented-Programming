/********************************************************************************
** Form generated from reading UI file 'ExamOOP.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMOOP_H
#define UI_EXAMOOP_H

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

class Ui_ExamOOPClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamOOPClass)
    {
        if (ExamOOPClass->objectName().isEmpty())
            ExamOOPClass->setObjectName(QStringLiteral("ExamOOPClass"));
        ExamOOPClass->resize(600, 400);
        menuBar = new QMenuBar(ExamOOPClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ExamOOPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamOOPClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ExamOOPClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ExamOOPClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ExamOOPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ExamOOPClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ExamOOPClass->setStatusBar(statusBar);

        retranslateUi(ExamOOPClass);

        QMetaObject::connectSlotsByName(ExamOOPClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExamOOPClass)
    {
        ExamOOPClass->setWindowTitle(QApplication::translate("ExamOOPClass", "ExamOOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamOOPClass: public Ui_ExamOOPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMOOP_H
