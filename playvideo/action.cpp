#include "action.h"

void Action::addTab()
{
	addWidget.setAutoFillBackground(true);
	addVBox.addWidget(&textLine);
	addVBox.addWidget(&addButton);
}

void Action::remove()
{
}

void Action::addLink(QStandardItemModel * model)
{
	QString text = textLine.text();
	QUrl link(text);
	int row = model->rowCount();
	QModelIndex index = model->index(row, 1);
	model->setData(index, link);

}
