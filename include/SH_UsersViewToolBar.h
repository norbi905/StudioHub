/*
SH_UsersViewToolBar
*/

#ifndef SH_USERSVIEWTOOLBAR_H
#define SH_USERSVIEWTOOLBAR_H

#include "qpushbutton.h"
#include "qicon.h"

#include "include\SH_mainwindow.h"

// forward declare class
class SH_MainToolBar;

class SH_UsersViewToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_UsersViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent);
	~SH_UsersViewToolBar();

private:
	QIcon			*addUserIcon;
	QIcon			*removeUserIcon;

	QPushButton		*addUser;
	QPushButton		*removeUser;
	QPushButton		*buttonThree;


protected:
signals :
		void userViewAddUserClicked();
		void userViewRemoveUserClicked();

private slots :
		void	mainToolBarUsersViewPressed();
		void	addUserClicked();
		void	removeUserClicked();
};
#endif // SH_UsersViewToolBar