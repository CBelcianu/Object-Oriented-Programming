/********************************************************************************
** Form generated from reading UI file 'Lab12GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB12GUI_H
#define UI_LAB12GUI_H

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

class Ui_Lab12GUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab12GUIClass)
    {
        if (Lab12GUIClass->objectName().isEmpty())
            Lab12GUIClass->setObjectName(QStringLiteral("Lab12GUIClass"));
        Lab12GUIClass->resize(600, 400);
        menuBar = new QMenuBar(Lab12GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lab12GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab12GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lab12GUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab12GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lab12GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab12GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lab12GUIClass->setStatusBar(statusBar);

        retranslateUi(Lab12GUIClass);

        QMetaObject::connectSlotsByName(Lab12GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab12GUIClass)
    {
        Lab12GUIClass->setWindowTitle(QApplication::translate("Lab12GUIClass", "Lab12GUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab12GUIClass: public Ui_Lab12GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB12GUI_H
