#ifndef PLAYVIDEO_H
#define PLAYVIDEO_H

#include "tableview.h"
#include "slider.h"

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include <QMessageBox>
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
#include <QVector>
#include <QDesktopWidget>

class PlayVideo : public QWidget
{
    Q_OBJECT

public:
    PlayVideo(QWidget *parent = nullptr);
    ~PlayVideo();
    
public slots:
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
    void removeTab();
    void addLink();
    void deleteLink(const QModelIndex& index);
    void backBtnadd();
    void backBtndelete();
    
private:
    QTableView tableVid;
    QMediaPlayer mediaPlayer;   
    QVideoWidget videoWidget;
    QStandardItemModel* modelvid;
    QStandardItemModel* modelAudio; 
    QVBoxLayout vboxLayout, volumeLayout, addVBox, removeQVBox;
    QHBoxLayout hboxLayoutvid, hboxLayoutbtn, layoutButton;
    QTabWidget tabWidget;
    QToolButton play, sound, fastForward, reWind, addTab1, removeTab1;
    Slider slider;
    QSlider volumeSlider;
    QWidget* volumeWidget;
    QLabel volumeLabel, timeLabel;
    QPoint m_previousPos, oldPos, newPos;
    QTime duraTiontime, positiontime;
    QString format;
    QToolButton addButton, cancelButton, removeButton, cancelButton1;
    QLineEdit textLine;
    QWidget addWid, deleteWidget;
    QVector<QString> videoList;

protected:
    void resizeEvent(QResizeEvent* event) override;
    void moveEvent(QMoveEvent* event) override;
    void changeEvent(QEvent* event) override;
}; 

#endif
