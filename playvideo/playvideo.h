#ifndef PLAYVIDEO_H
#define PLAYVIDEO_H

#include "tableview.h"
#include "slider.h"

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QTableView>
#include <QToolButton>
#include <QLabel>
#include <QSplitter>
#include <QSizePolicy>
#include <QTime> 
#include <QIcon>
#include <QLineEdit>

class PlayVideo : public QWidget
{
    Q_OBJECT

public:
    PlayVideo(QWidget *parent = nullptr);
    ~PlayVideo();
    
private:
    void openVid(const QModelIndex& index);
    void openAudio(const QModelIndex& index);
    void playVid();
    void soundClick();
    void soundPlay(int value);
    void timeDuration(qint64);
    void timePosition(qint64);
    void skipForward(qint64);
    void skipBackward(qint64);
    void addTab();
    void remove();
    void addLink(QStandardItemModel*);

private:
    QMediaPlayer mediaPlayer;   
    QVideoWidget videoWidget;
    QStandardItemModel* model;
    QStandardItemModel* modelAudio; 
    
    QVBoxLayout vboxLayout;
    QHBoxLayout hboxLayout1, hboxLayout2, hboxLayout, layoutButton;

    QTabWidget tabWidget;

    QToolButton play, sound, fastForward, reWind, addTab1, removeTab1;
    QWidget layout;

    Slider slider;

    QSlider volumeSlider;
    QWidget volumeWidget;
    QVBoxLayout volumeLayout;
    QLabel volumeLabel, timeLabel;

    QPoint m_previousPos;

    QTime duraTiontime, positiontime;
    QString format;

   
    QToolButton addButton;
    QLineEdit textLine;
    QVBoxLayout addVBox;
   
};

#endif
