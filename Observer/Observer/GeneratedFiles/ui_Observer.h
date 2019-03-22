/********************************************************************************
** Form generated from reading UI file 'Observer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBSERVER_H
#define UI_OBSERVER_H

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

class Ui_ObserverClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ObserverClass)
    {
        if (ObserverClass->objectName().isEmpty())
            ObserverClass->setObjectName(QStringLiteral("ObserverClass"));
        ObserverClass->resize(600, 400);
        menuBar = new QMenuBar(ObserverClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ObserverClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ObserverClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ObserverClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ObserverClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ObserverClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ObserverClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ObserverClass->setStatusBar(statusBar);

        retranslateUi(ObserverClass);

        QMetaObject::connectSlotsByName(ObserverClass);
    } // setupUi

    void retranslateUi(QMainWindow *ObserverClass)
    {
        ObserverClass->setWindowTitle(QApplication::translate("ObserverClass", "Observer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ObserverClass: public Ui_ObserverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBSERVER_H
