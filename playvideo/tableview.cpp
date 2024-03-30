#include "tableview.h"

Videoplay::Videoplay() {}

QTableView* Videoplay::creTableVideo(QStandardItemModel* model)
{
    QTableView* table1 = new QTableView;
    table1->setModel(model);
    table1->model()->setHeaderData(0, Qt::Horizontal, "link");
    QString video[] = { "https://samplelib.com/lib/preview/mp4/sample-5s.mp4",
                        "https://cdn.pixabay.com/vimeo/689949805/nhung-am-may-111179.mp4?width=640&hash=e19845a3e57fc7219de28645b3eec02d67d6b86e",
                        "https://cdn.pixabay.com/vimeo/891655462/vach-a-192066.mp4?width=1280&hash=11491b2537a7651dfc6c1637d6302f8719d01248",
                        "https://file-examples.com/storage/fe8ab7064b6605ee7a3c723/2017/04/file_example_MP4_480_1_5MG.mp4" };
    model->setRowCount(sizeof(video) / sizeof(video[0]));
    model->setColumnCount(1);
    for (int row = 0; row < model->rowCount(); ++row) {
        table1->setRowHeight(row, 60);
    }
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            for (int i = 0; i < video->length(); i++) {
                QModelIndex index = model->index(row, column);
                QUrl link(video[row]);
                model->setData(index, link);
                model->setData(index, link, Qt::UserRole);
            }
        }
    }
    table1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    
    table1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    return table1;
}

QTableView* Videoplay::creTableAudio(QStandardItemModel* modelAudio)
{
    QTableView* table = new QTableView;
    table->setModel(modelAudio);
    table->model()->setHeaderData(0, Qt::Horizontal, "link");
    QString audio[] = { 
                        "https://file-examples.com/storage/fe17d655216606dd89d5226/2017/11/file_example_MP3_700KB.mp3",
                        "https://samplelib.com/lib/preview/mp3/sample-9s.mp3",
                        "https://samplelib.com/lib/preview/mp3/sample-15s.mp3",
                        "https://samples-files.com/samples/Audio/mp3/sample-file-3.mp3" };
    modelAudio->setRowCount(sizeof(audio) / sizeof(audio[0]));
    modelAudio->setColumnCount(1);
    for (int row = 0; row < modelAudio->rowCount(); ++row) {
        table->setRowHeight(row, 60);
    }
    for (int row = 0; row < modelAudio->rowCount(); ++row) {
        for (int column = 0; column < modelAudio->columnCount(); ++column) {
            for (int i = 0; i < audio->length(); i++) {
                QModelIndex index = modelAudio->index(row, column);
                QUrl link(audio[row]);
                modelAudio->setData(index, link);
                modelAudio->setData(index, link, Qt::UserRole);
            }
        }
    }
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    return table;
}

