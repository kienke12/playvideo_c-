#pragma once
#include "playvideo.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QScrollArea>
#include <QPushButton>
#include <QUrl>
#include <QHeaderView>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QGridLayout>
#include <QDesktopServices>
#include <QMediaPlayer>
#include <QFile>
#include <QMediaPlaylist>

class Videoplay : public QObject
{
public:
	Videoplay();
	QTableView * creTableVideo(QStandardItemModel* );
	QTableView* creTableAudio(QStandardItemModel* );
};
#pragma once
