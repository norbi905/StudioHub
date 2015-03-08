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
	this->setSelectionBehavior(QAbstractItemView::SelectRows);
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
}