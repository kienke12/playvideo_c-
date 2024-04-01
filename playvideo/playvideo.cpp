#include "playvideo.h"


PlayVideo::PlayVideo(QWidget *parent)
    : QWidget(parent)
{

    Videoplay video;

    QSplitter* splitter = new QSplitter(Qt::Horizontal, this);

    volumeSlider.setMaximum(100);
    volumeSlider.setMinimum(0);
    volumeSlider.setValue(mediaPlayer.volume());
    volumeLayout.addWidget(&volumeSlider);
    volumeLayout.addWidget(&sound);
    volumeWidget.setLayout(&volumeLayout); 
    volumeSlider.setAutoFillBackground(true);
    volumeSlider.hide();

    play.setIcon(style()->standardPixmap(QStyle::SP_MediaPause));
    sound.setIcon(style()->standardPixmap(QStyle::SP_MediaVolume));
    fastForward.setIcon(style()->standardPixmap(QStyle::SP_MediaSeekForward));
    reWind.setIcon(style()->standardPixmap(QStyle::SP_MediaSeekBackward));

    hboxLayout1.addWidget(&videoWidget);
    hboxLayout2.addWidget(&reWind);
    hboxLayout2.addWidget(&play);
    hboxLayout2.addWidget(&fastForward);
    hboxLayout2.addWidget(&slider);
    hboxLayout2.addWidget(&volumeWidget);
    hboxLayout2.addWidget(&timeLabel);
    hboxLayout2.addSpacing(5);
    hboxLayout2.setSpacing(10);
    
    timeLabel.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeLabel.setText("hh:mm:ss");

    QVBoxLayout* buttonLayout = new QVBoxLayout;
    buttonLayout->addLayout(&hboxLayout1);
    buttonLayout->addLayout(&hboxLayout2);

    QWidget* buttonWidget = new QWidget;
    buttonWidget->setLayout(buttonLayout);

    QWidget* tab1 = new QWidget();
    QWidget* tab2 = new QWidget();
    model = new QStandardItemModel;
    modelAudio = new QStandardItemModel;
    tabWidget.addTab(tab1, "video");
    tabWidget.addTab(tab2, "music");
    tabWidget.setMinimumWidth(100);

    vboxLayout.setContentsMargins(0, 0, 0, 3);
    vboxLayout.setSpacing(3);

    splitter->addWidget(&tabWidget);
    splitter->addWidget(buttonWidget);
    QList<int> sizes = { 150, 350 };
    splitter->setSizes(sizes);

    QTableView* videoTable = video.creTableVideo(model);
    QVBoxLayout* tab1Layout = new QVBoxLayout(tab1);
    addTab1.setIcon(QIcon("C:/Users/VCCorp/source/repos/playvideo/icon/add.png"));
    removeTab1.setIcon(QIcon("C:/Users/VCCorp/source/repos/playvideo/icon/remove.png"));
    layoutButton.addWidget(&addTab1);
    layoutButton.addWidget(&removeTab1);
    tab1Layout->addLayout(&layoutButton);
    tab1Layout->addWidget(videoTable);

    QTableView* audioTable = video.creTableAudio(modelAudio);
    QVBoxLayout* tab2Layout = new QVBoxLayout(tab2);
    //tab2Layout->addWidget(&addTab2);
    tab2Layout->addWidget(audioTable);

    vboxLayout.addWidget(splitter);
    setLayout(&vboxLayout);

    // connect video
    connect(videoTable, &QTableView::clicked, this, &PlayVideo::openVid);
    connect(audioTable, &QTableView::clicked, this, &PlayVideo::openAudio);

    connect(&play, &QToolButton::clicked, this, &PlayVideo::playVid);
    connect(&fastForward, &QToolButton::clicked, this, &PlayVideo::skipForward);
    connect(&reWind, &QToolButton::clicked, this, &PlayVideo::skipBackward);

    connect(&sound, &QToolButton::clicked, this, &PlayVideo::soundClick);
    connect(&volumeSlider, &QSlider::sliderMoved, this, &PlayVideo::soundPlay);

    connect(&mediaPlayer, &QMediaPlayer::durationChanged, &slider, &Slider::setMaximum);
    connect(&mediaPlayer, &QMediaPlayer::positionChanged, &slider, &Slider::setValue);
    connect(&slider, &Slider::sliderMoved, &mediaPlayer, &QMediaPlayer::setPosition);
    connect(&slider, &Slider::pressedSlider, &mediaPlayer, &QMediaPlayer::setPosition);
    connect(&tabWidget, SIGNAL(sliderMoved(int)), this, SLOT(OnVolumeSliderMoved(int)));

    connect(&mediaPlayer, &QMediaPlayer::durationChanged, this, &PlayVideo::timeDuration);
    connect(&mediaPlayer, &QMediaPlayer::positionChanged, this, &PlayVideo::timePosition);
    
    connect(&addTab1, &QToolButton::clicked, this, &PlayVideo::addTab);

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
    if (volumeSlider.isHidden())
    {
        
        volumeSlider.show();
    }
    else
    {
        volumeSlider.hide();
    }
}

void PlayVideo::soundPlay(int value)
{
    mediaPlayer.setVolume(value);
    volumeLabel.setText(QString::number(mediaPlayer.volume()));
}

void PlayVideo::timeDuration(qint64 duration)
{
    duration = duration / 1000;
    duraTiontime = QTime((duration / 3600) % 1000, (duration / 60) % 60, duration % 60);

    if (duration < 3600) format = "mm:ss";
    else format = "hh:mm:ss";
}

void PlayVideo::timePosition(qint64 position)
{
    position /= 1000;
    positiontime = QTime((position / 3600) % 1000, (position / 60) % 60, position % 60);
    timeLabel.setText(positiontime.toString(format) + "/" + duraTiontime.toString(format));
}

void PlayVideo::skipForward(qint64 newPosition)
{
    newPosition = (mediaPlayer.position()+15000);
    qint64 duration = mediaPlayer.duration();
    newPosition = qMin(newPosition, duration);

    mediaPlayer.setPosition(newPosition);
}

void PlayVideo::skipBackward(qint64 newPosition)
{
    newPosition = (mediaPlayer.position() - 15000);
    qint64 duration = mediaPlayer.duration();
    newPosition = qMin(newPosition, duration);

    mediaPlayer.setPosition(newPosition);
}

void PlayVideo::addTab()
{   
    QWidget* addWidget = new QWidget();
    addVBox.addWidget(&textLine);
    addVBox.addWidget(&addButton);
    addWidget->setLayout(&addVBox);
    addWidget->setAutoFillBackground(true);
    addWidget->show();
}

void PlayVideo::remove()
{
}

void PlayVideo::addLink(QStandardItemModel*)
{
}

PlayVideo::~PlayVideo()
{
}

