#include "playvideo.h"


PlayVideo::PlayVideo(QWidget *parent)
    : QWidget(parent)
{
    Videoplay video;

    QPalette pal;
    videoWidget.setPalette(pal);
    videoWidget.setAutoFillBackground(true);

    play.setIcon(style()->standardPixmap(QStyle::SP_MediaPause));
    sound.setIcon(style()->standardPixmap(QStyle::SP_MediaVolume));

    hboxLayout1.addWidget(&videoWidget);
    hboxLayout2.addWidget(&play);
    hboxLayout2.addWidget(&slider);
    hboxLayout2.addWidget(&sound);
    hboxLayout2.addSpacing(5);
    hboxLayout2.setSpacing(10);

    QVBoxLayout* buttonLayout = new QVBoxLayout;
    buttonLayout->addLayout(&hboxLayout1);
    buttonLayout->addLayout(&hboxLayout2);

    QWidget* tab1 = new QWidget();
    QWidget* tab2 = new QWidget();
    model = new QStandardItemModel;
    modelAudio = new QStandardItemModel;
    tabWidget.addTab(tab1, "video");
    tabWidget.addTab(tab2, "music");
    tabWidget.setFixedSize(200, 250);

    vboxLayout.setContentsMargins(0, 0, 0, 3);
    vboxLayout.setSpacing(3);

    hboxLayout.addWidget(&tabWidget);
    hboxLayout.addLayout(buttonLayout);

    QTableView* videoTable = video.creTableVideo(model);
    QVBoxLayout* tab1Layout = new QVBoxLayout(tab1);
    tab1Layout->addWidget(videoTable);
    QTableView* audioTable = video.creTableAudio(modelAudio);
    QVBoxLayout* tab2Layout = new QVBoxLayout(tab2);
    tab2Layout->addWidget(audioTable);

    vboxLayout.addLayout(&hboxLayout);
    setLayout(&vboxLayout);

    volumeWidget.setWindowFlag(Qt::ToolTip);
    volumeLayout.addWidget(&volumeLabel, 0, Qt::AlignHCenter);
    volumeLayout.addWidget(&volumeSlider, 0, Qt::AlignHCenter);
    volumeWidget.setLayout(&volumeLayout);
    volumeLayout.setMargin(2);

    volumeSlider.setMaximum(100);
    volumeSlider.setValue(mediaPlayer.volume());
    volumeLabel.setText(QString::number(mediaPlayer.volume()));

    // connect video
    connect(videoTable, &QTableView::clicked, this, &PlayVideo::openVid);
    connect(&play, &QToolButton::clicked, this, &PlayVideo::playVid);
    connect(audioTable, &QTableView::clicked, this, &PlayVideo::openAudio);

    connect(&sound, &QToolButton::clicked, this, &PlayVideo::soundClick);
    connect(&volumeSlider, &QSlider::sliderMoved, this, &PlayVideo::soundPlay);

    connect(&mediaPlayer, &QMediaPlayer::durationChanged, &slider, &Slider::setMaximum);
    connect(&mediaPlayer, &QMediaPlayer::positionChanged, &slider, &Slider::setValue);
    connect(&slider, &Slider::sliderMoved, &mediaPlayer, &QMediaPlayer::setPosition);
    connect(&slider, &Slider::pressedSlider, &mediaPlayer, &QMediaPlayer::setPosition);

    connect(&tabWidget, SIGNAL(sliderMoved(int)), this, SLOT(OnVolumeSliderMoved(int)));

}

void PlayVideo::openVid(const QModelIndex& index) {
    if (index.isValid() && index.column() == 0) {
        QStandardItem* item = model->itemFromIndex(index);
        if (item) {
            QVariant data = item->data(Qt::UserRole);
            if (data.canConvert<QUrl>()) {
                mediaPlayer.setVideoOutput(&videoWidget);
                QUrl url = data.value<QUrl>();
                mediaPlayer.setMedia(url);
                mediaPlayer.play();
                videoWidget.show();
            }
        }
    }
}

void PlayVideo::openAudio(const QModelIndex& index) {
    if (index.isValid() && index.column() == 0) {
        QStandardItem* item = modelAudio->itemFromIndex(index);
        if (item) {
            QVariant data = item->data(Qt::UserRole);
            if (data.canConvert<QUrl>()) {
                mediaPlayer.setVideoOutput(&videoWidget);
                QUrl url = data.value<QUrl>();
                mediaPlayer.setMedia(url);
                mediaPlayer.play();
                videoWidget.show();
            }
        }
    }
}

void PlayVideo::playVid()
{
    QMediaPlayer::State playerState = mediaPlayer.state();
    if(playerState == QMediaPlayer::PlayingState)
    {
        mediaPlayer.pause();
        play.setIcon(style()->standardPixmap(QStyle::SP_MediaPlay));
    }
    else if(playerState == QMediaPlayer::PausedState){
        mediaPlayer.play();
        play.setIcon(style()->standardPixmap(QStyle::SP_MediaPause));
    }
}

void PlayVideo::soundClick()
{
    if (volumeWidget.isHidden())
    {
        volumeWidget.move(x() + sound.x(), y() + size().height() - 110);
        volumeWidget.show();
    }
    else
    {
        volumeWidget.hide();
    }
}

void PlayVideo::soundPlay(int value)
{
    mediaPlayer.setVolume(value);
    volumeLabel.setText(QString::number(mediaPlayer.volume()));
}

void PlayVideo::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton) { 
        QPoint delta = event->pos() - m_previousPos; 
        QSize newSize = size() + QSize(delta.x(), delta.y());
        resize(newSize); 
    }
    m_previousPos = event->pos(); 
    
}

PlayVideo::~PlayVideo()
{
}

