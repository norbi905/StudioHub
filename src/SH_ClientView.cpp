/*
SH_ClientView.cpp
*/

#include "include\SH_ClientView.h"

/*
Constructor
*/
SH_ClientView::SH_ClientView(QWidget *parent)
	: QTreeView(parent)
{
	this->setSortingEnabled(true);

	contextAddClient	= new QAction("Add Client...", this);
	contextDeleteClient = new QAction("Delete Client", this);

	connect(contextAddClient, SIGNAL(triggered()), this, SLOT(addClientClicked()));
	connect(contextDeleteClient, SIGNAL(triggered()), this, SLOT(deleteClientClicked()));

	clientWindow = new SH_NewClientWindow(this);
	clientWindow->hide();
}

/*
Destructor
*/
SH_ClientView::~SH_ClientView()
{

}

/*
contextMenuEvent
*/
void SH_ClientView::contextMenuEvent(QContextMenuEvent *event)
{
	QMenu contextMenu(this);
	contextMenu.addAction(contextAddClient);
	contextMenu.addAction(contextDeleteClient);

	contextMenu.exec(event->globalPos());
}

/*
setClientViewTableModel
*/
void SH_ClientView::setClientViewTableModel(QSqlTableModel *model)
{
	this->setModel(model);

	// HACK FIXME
	this->sortByColumn(0, Qt::DescendingOrder);
	this->sortByColumn(0, Qt::AscendingOrder);
}

/*
addClientClicked
*/
void SH_ClientView::addClientClicked()
{
	clientWindow->show();
	int result = clientWindow->exec();
	if (result == QDialog::Accepted)
	{
		QSqlQuery query;
		query.exec("INSERT INTO clients (name) VALUES ('" + clientWindow->getClientName() + "')");
		this->sortByColumn(0, Qt::DescendingOrder);
		this->sortByColumn(0, Qt::AscendingOrder);
	}
	else
	{
		clientWindow->close();
	}
}

/*
deleteClientClicked
*/
void SH_ClientView::deleteClientClicked()
{
	QMessageBox::StandardButton confirmation;
	confirmation = QMessageBox::question(this, "Delete Client?", "Are you sure you want to delete " + this->currentIndex().data(Qt::DisplayRole).toString(), QMessageBox::Yes | QMessageBox::No);
	if (confirmation == QMessageBox::Yes)
	{
		model()->removeRow(this->currentIndex().row());
		this->sortByColumn(0, Qt::DescendingOrder);
		this->sortByColumn(0, Qt::AscendingOrder);
	}
	else
	{

	}
}