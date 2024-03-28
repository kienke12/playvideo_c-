#ifndef TEST_H
#define TEST_H

#include "tableview.h"

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QTableView>
#include <QToolButton>

class PlayVideo : public QWidget
{
    Q_OBJECT

public:
    PlayVideo(QWidget *parent = nullptr);
    ~PlayVideo();
    
private:
    void openVid(const QModelIndex& index);

private:
    QMediaPlayer mediaPlayer;
    QMediaPlaylist mediaplaylist;
    QVideoWidget videoWidget;
    QMediaPlaylist playlist;
    QStandardItemModel* model;

    QVBoxLayout vboxlayout1, vboxlayout2;
    QHBoxLayout hboxlayout1, hboxlayout2, hboxlayout;

    QTabWidget tabWidget;

    QToolButton play;
    QWidget layout;
};

#endif
