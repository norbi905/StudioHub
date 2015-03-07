/*
SH_UsersView
*/

#ifndef SH_USERSVIEW_H
#define SH_USERSVIEW_H

#include "qtableview.h"
#include "sh_mainwindow.h"

class SH_UsersView : public QTableView
{
	Q_OBJECT

public:
	SH_UsersView(QWidget *parent = 0);
	~SH_UsersView();

private:

protected:

};

#endif // SH_UsersView