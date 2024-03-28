/********************************************************************************
** Form generated from reading UI file 'playvideo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYVIDEO_H
#define UI_PLAYVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playvideoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *playvideoClass)
    {
        if (playvideoClass->objectName().isEmpty())
            playvideoClass->setObjectName(QString::fromUtf8("playvideoClass"));
        playvideoClass->resize(600, 400);
        menuBar = new QMenuBar(playvideoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        playvideoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(playvideoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        playvideoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(playvideoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        playvideoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(playvideoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        playvideoClass->setStatusBar(statusBar);

        retranslateUi(playvideoClass);

        QMetaObject::connectSlotsByName(playvideoClass);
    } // setupUi

    void retranslateUi(QMainWindow *playvideoClass)
    {
        playvideoClass->setWindowTitle(QApplication::translate("playvideoClass", "playvideo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playvideoClass: public Ui_playvideoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYVIDEO_H
