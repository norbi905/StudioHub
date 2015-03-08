/*
SH_UsersView
*/

#include "include\SH_UsersView.h"

/*
Constructor
*/
SH_UsersView::SH_UsersView(QWidget *parent)
	: QTreeView(parent)
{

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
	//userNameTableModel = model;
	this->setModel(model);
}