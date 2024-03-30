#ifndef TEST_H
#define TEST_H

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

private:
    QMediaPlayer mediaPlayer;   
    QVideoWidget videoWidget;
    QStandardItemModel* model;
    QStandardItemModel* modelAudio;

    QVBoxLayout vboxLayout;
    QHBoxLayout hboxLayout1, hboxLayout2, hboxLayout;

    QTabWidget tabWidget;

    QToolButton play, sound;
    QWidget layout;

    Slider slider;
    QSlider volumeSlider;
    QWidget volumeWidget;
    QVBoxLayout volumeLayout;
    QLabel volumeLabel;

    QPoint m_previousPos;
};

#endif
