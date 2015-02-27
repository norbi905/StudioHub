/********************************************************************************
** Form generated from reading UI file 'sh_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SH_MAINWINDOW_H
#define UI_SH_MAINWINDOW_H

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

class Ui_SH_MainWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SH_MainWindowClass)
    {
        if (SH_MainWindowClass->objectName().isEmpty())
            SH_MainWindowClass->setObjectName(QStringLiteral("SH_MainWindowClass"));
        SH_MainWindowClass->resize(600, 400);
        menuBar = new QMenuBar(SH_MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SH_MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SH_MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SH_MainWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SH_MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SH_MainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SH_MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SH_MainWindowClass->setStatusBar(statusBar);

        retranslateUi(SH_MainWindowClass);

        QMetaObject::connectSlotsByName(SH_MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SH_MainWindowClass)
    {
        SH_MainWindowClass->setWindowTitle(QApplication::translate("SH_MainWindowClass", "SH_MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class SH_MainWindowClass: public Ui_SH_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SH_MAINWINDOW_H
