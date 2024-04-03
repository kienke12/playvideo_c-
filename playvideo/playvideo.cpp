#include "playvideo.h"

PlayVideo::PlayVideo(QWidget* parent)
    : QWidget(parent)
{
    Videoplay video;
    videoList = { "https://samplelib.com/lib/preview/mp4/sample-5s.mp4",
                        "https://cdn.pixabay.com/vimeo/689949805/nhung-am-may-111179.mp4?width=640&hash=e19845a3e57fc7219de28645b3eec02d67d6b86e",
                        "https://cdn.pixabay.com/vimeo/891655462/vach-a-192066.mp4?width=1280&hash=11491b2537a7651dfc6c1637d6302f8719d01248",
                        "https://file-examples.com/storage/fe8ab7064b6605ee7a3c723/2017/04/file_example_MP4_480_1_5MG.mp4" };
    int lenght = videoList.length();

    QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
   
    volumeWidget.setWindowFlag(Qt::ToolTip);
    volumeSlider.setMaximum(100);
    volumeSlider.setValue(mediaPlayer.volume());
    volumeLayout.addWidget(&volumeLabel);
    volumeLayout.addWidget(&volumeSlider);
    volumeLayout.addWidget(&sound);
    volumeWidget.setLayout(&volumeLayout);
    volumeLabel.setText(QString::number(mediaPlayer.volume()));
    volumeLayout.setMargin(2);
    volumeWidget.setMaximumHeight(100);
    //volumeWidget.setFixedHeight(150);
    volumeLabel.hide();
    volumeSlider.hide();
    volumeLabel.hide();

    play.setIcon(style()->standardPixmap(QStyle::SP_MediaPause));
    sound.setIcon(style()->standardPixmap(QStyle::SP_MediaVolume));
    fastForward.setIcon(style()->standardPixmap(QStyle::SP_MediaSeekForward));
    reWind.setIcon(style()->standardPixmap(QStyle::SP_MediaSeekBackward));

    hboxLayout1.addWidget(&videoWidget);
    hboxLayout2.addWidget(&reWind);
    hboxLayout2.addWidget(&play);
    hboxLayout2.addWidget(&fastForward);
    hboxLayout2.addWidget(&slider);
    hboxLayout2.addWidget(&sound );
    hboxLayout2.addWidget(&timeLabel);
    hboxLayout2.addSpacing(5);
    hboxLayout2.setSpacing(10);
    
    QWidget* placeholder = new QWidget();
    placeholder->setFixedHeight(50); 
    placeholder->setLayout(&hboxLayout2);
        
    timeLabel.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeLabel.setText("hh:mm:ss");

    QVBoxLayout* buttonLayout = new QVBoxLayout;
    buttonLayout->addLayout(&hboxLayout1);
    buttonLayout->addWidget(placeholder);
    QWidget* buttonWidget = new QWidget;
    buttonWidget->setLayout(buttonLayout);

    QWidget* tab1 = new QWidget();
    QWidget* tab2 = new QWidget();
    modelvid = new QStandardItemModel;
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

    QTableView* videoTable = video.creTableVideo(modelvid, &videoList, lenght);
    QVBoxLayout* tab1Layout = new QVBoxLayout(tab1);
    addTab1.setIcon(QIcon("C:/Users/VCCorp/source/repos/playvideo/icon/add.png"));
    removeTab1.setIcon(QIcon("C:/Users/VCCorp/source/repos/playvideo/icon/remove.png"));
    layoutButton.addWidget(&addTab1);
    layoutButton.addWidget(&removeTab1);
    tab1Layout->addLayout(&layoutButton);
    tab1Layout->addWidget(videoTable);

    QTableView* audioTable = video.creTableAudio(modelAudio);
    QVBoxLayout* tab2Layout = new QVBoxLayout(tab2);
    tab2Layout->addWidget(audioTable);

    vboxLayout.addWidget(splitter);
    setLayout(&vboxLayout);

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
    connect(&addButton, &QToolButton::clicked, this, &PlayVideo::addLink);
    connect(&cancelButton, &QToolButton::clicked, this, &PlayVideo::backBtnadd);
    connect(&cancelButton1, &QToolButton::clicked, this, &PlayVideo::backBtndelete);
    connect(&removeTab1, &QToolButton::clicked, this, &PlayVideo::removeTab);

    connect(&mediaPlayer, &QMediaPlayer::mediaStatusChanged, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            mediaPlayer.setPosition(0);
            mediaPlayer.play(); 
            mediaPlayer.pause();
            videoWidget.show();
        }
    });
}

void PlayVideo::openVid(const QModelIndex& index) {
    if (index.isValid() && index.column() == 0) {
        QStandardItem* item = modelvid->itemFromIndex(index);
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
    else {
        mediaPlayer.play();
        play.setIcon(style()->standardPixmap(QStyle::SP_MediaPause));
    }
}

void PlayVideo::soundClick()
{
    if (volumeSlider.isHidden())
    {
        volumeWidget.move(x() + sound.x()+190, y() + size().height() - 120);
        volumeLabel.show();
        volumeSlider.show();
        volumeWidget.show();
    }
    else
    {
        volumeLabel.hide();
        volumeSlider.hide();
        volumeWidget.hide();
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
    qDebug() << duration;
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
    QHBoxLayout* setButton = new QHBoxLayout();
    addWid.setWindowFlag(Qt::ToolTip);
    addButton.setText("add");
    cancelButton.setText("Cancel");
    addVBox.addWidget(&textLine);
    setButton->addWidget(&addButton);
    setButton->addWidget(&cancelButton);
    addVBox.addLayout(setButton);
    addWid.setLayout(&addVBox);
    addWid.setAutoFillBackground(true);
   
    addWid.show();
}

void PlayVideo::removeTab()
{    
    //removeWidget.setWindowFlag(Qt::ToolTip);
    QTableView* table = new QTableView;
    table->setModel(modelvid);
    table->model()->setHeaderData(0, Qt::Horizontal, "link");
    modelvid->setColumnCount(1);
    modelvid->setRowCount(videoList.length());
    for (int row = 0; row < modelvid->rowCount(); ++row) {
        for (int column = 0; column < modelvid->columnCount(); ++column) {
            for (int i = 0; i < videoList.length(); i++) {
                QModelIndex index = modelvid->index(row, column);
                QUrl link(videoList.at(row));
                modelvid->setData(index, link);
                modelvid->setData(index, link, Qt::UserRole);
            }
        }
    }
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(table, &QTableView::clicked, this, &PlayVideo::deleteLink);
    cancelButton1.setText("cancel");
    removeQVBox.addWidget(table);
    removeQVBox.addWidget(&cancelButton1);
    deleteWidget.setLayout(&removeQVBox);
    deleteWidget.setAutoFillBackground(true);
    deleteWidget.show();
}

void PlayVideo::addLink()
{
    QString text = textLine.text();
    videoList.push_back(text);
    modelvid->setRowCount(videoList.length());
    for (int row = 0; row < modelvid->rowCount(); ++row) {
        for (int column = 0; column < modelvid->columnCount(); ++column) {
            for (int i = 0; i < videoList.length(); i++) {
                QModelIndex index = modelvid->index(row, column);
                QUrl link(videoList.at(row));
                
                modelvid->setData(index, link);
                modelvid->setData(index, link, Qt::UserRole);
            }
        }
    }
    textLine.setText("");
    addWid.hide();
}

void PlayVideo::deleteLink(const QModelIndex& index)
{
    videoList.remove(index.row());
    modelvid->setRowCount(videoList.length());
    for (int row = 0; row < modelvid->rowCount(); ++row) {
        for (int column = 0; column < modelvid->columnCount(); ++column) {
            for (int i = 0; i < videoList.length(); i++) {
                QModelIndex index = modelvid->index(row, column);
                QUrl link(videoList.at(row));
                modelvid->setData(index, link);
                modelvid->setData(index, link, Qt::UserRole);
            }
        }
    }
    deleteWidget.hide();
}

void PlayVideo::backBtndelete()
{
    deleteWidget.hide();
}

void PlayVideo::backBtnadd()
{
    textLine.setText("");
    addWid.hide();
}

PlayVideo::~PlayVideo()
{
}

