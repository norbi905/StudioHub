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
}

/*
Destructor
*/
SH_UsersView::~SH_UsersView()
{

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