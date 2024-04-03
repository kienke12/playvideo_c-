#include "tableview.h"

Videoplay::Videoplay() {}

QTableView* Videoplay::creTableVideo(QStandardItemModel* model, QVector<QString>* video, int lenght)
{
    QTableView* table1 = new QTableView;
    table1->setModel(model);
    table1->model()->setHeaderData(0, Qt::Horizontal, "link");
    
    model->setRowCount(lenght);
    model->setColumnCount(1);
    for (int row = 0; row < model->rowCount(); ++row) {
        table1->setRowHeight(row, 60);
    }
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            for (int i = 0; i < video->length(); i++) {
                QModelIndex index = model->index(row, column);
                QUrl link(video->at(row));
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

