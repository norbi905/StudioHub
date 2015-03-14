/*
SH_UsersView
*/

#include "include\SH_UsersView.h"
#include "include\SH_UsersViewDetails.h"

/*
Constructor
*/
SH_UsersView::SH_UsersView(QWidget *parent)
	: QTreeView(parent)
{
	this->setSortingEnabled(true);
	this->setAlternatingRowColors(true);
	contextAddUser		= new QAction("Add User...", this);
	contextDeleteUser	= new QAction("Delete User", this);

	connect(contextAddUser, SIGNAL(triggered()), this, SLOT(addUserClicked()));
	connect(contextDeleteUser, SIGNAL(triggered()), this, SLOT(removeUserClicked()));
}

/*
Destructor
*/
SH_UsersView::~SH_UsersView()
{

}

/*
contextMenuEvent
*/
void SH_UsersView::contextMenuEvent(QContextMenuEvent *event)
{
	QMenu contextMenu(this);
	contextMenu.addAction(contextAddUser);
	contextMenu.addAction(contextDeleteUser);

	contextMenu.exec(event->globalPos());
}

/*
setUserNameTableModel
*/
void SH_UsersView::setUserNameTableModel(QSqlTableModel *model)
{
	this->setModel(model);
	this->setColumnHidden(1, true);
	this->setColumnHidden(2, true);	

	// for some reason, not sure why....when a user logs-off and another logs in, the treeview does not display the table properly...a quick hack by changing sorting order it appears to be displaying it fine
	this->sortByColumn(0, Qt::DescendingOrder);
	this->sortByColumn(0, Qt::AscendingOrder);
}

void SH_UsersView::addUserClicked()
{
	addNewUserWindow = new SH_NewUserWindow(this);
	int result = addNewUserWindow->exec();
	if (result == QDialog::Accepted)
	{
		QSqlQuery query;
		query.exec("INSERT INTO users (name) VALUES ('" + addNewUserWindow->getUserName() + "')");
		query.exec("UPDATE users SET access = '" + addNewUserWindow->getUserAccess() + "', password = '" + addNewUserWindow->getUserPassword() + "' WHERE name = '" + addNewUserWindow->getUserName() + "'");
		this->sortByColumn(0, Qt::DescendingOrder);
		this->sortByColumn(0, Qt::AscendingOrder);
	}
	else
	{
		addNewUserWindow->close();
	}
}

void SH_UsersView::removeUserClicked()
{
	QMessageBox::StandardButton confirmation;
	confirmation = QMessageBox::question(this, "Delete user?", "Are you sure you want to delete " + this->currentIndex().data(Qt::DisplayRole).toString(), QMessageBox::Yes | QMessageBox::No);
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