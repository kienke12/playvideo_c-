#ifndef ACTION_H
#define ACTION_H

#include <QObject>
#include <QWidget>
#include <QToolButton>
#include <QLineEdit >
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QUrl>

class Action : public QWidget
{
    Q_OBJECT
public:
    Action();
    void addTab();
    void remove();
    void addLink(QStandardItemModel*);

private:
   
    
};

#endif // SLIDER_H
#pragma once