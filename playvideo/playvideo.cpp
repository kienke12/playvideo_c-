#include "playvideo.h"


PlayVideo::PlayVideo(QWidget *parent)
    : QWidget(parent)
{
    Videoplay video;

    QPalette pal;
    videoWidget.setPalette(pal);
    videoWidget.setAutoFillBackground(true);

    play.setIcon(style()->standardPixmap(QStyle::SP_MediaPlay));

    hboxlayout1.addWidget(&videoWidget);
    hboxlayout2.addWidget(&play);
    layout.setLayout(&hboxlayout1);
    layout.setLayout(&hboxlayout2);

    //hboxlayout.addWidget(&play);

    QWidget* tab1 = new QWidget();
    QWidget* tab2 = new QWidget();
    model = new QStandardItemModel;
    tabWidget.addTab(tab1, "video");
    tabWidget.addTab(tab2, "music");
    tabWidget.setMaximumWidth(200);

    vboxlayout1.setContentsMargins(0, 0, 0, 3);
    vboxlayout1.setSpacing(3);

    hboxlayout.addWidget(&tabWidget);
    hboxlayout.addWidget(&layout); 

    QTableView* table1 = video.cre_table(model);
    QVBoxLayout* tab1Layout = new QVBoxLayout(tab1);
    tab1Layout->addWidget(table1);

    vboxlayout1.addLayout(&hboxlayout);
   
    setLayout(&vboxlayout1);

    connect(table1, &QTableView::clicked, this, &PlayVideo::openVid);
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

PlayVideo::~PlayVideo()
{
}

