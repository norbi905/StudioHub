/*
SH_UsersViewToolBar
*/

#ifndef SH_USERSVIEWTOOLBAR_H
#define SH_USERSVIEWTOOLBAR_H

#include "qpushbutton.h"

#include "include\SH_mainwindow.h"

// forward declare class
class SH_MainToolBar;

class SH_UsersViewToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_UsersViewToolBar(SH_MainToolBar *mainToolBar);
	~SH_UsersViewToolBar();

private:
	QPushButton		*buttonOne;
	QPushButton		*buttonTwo;
	QPushButton		*buttonThree;


protected:
	private slots :
		void	mainToolBarUsersViewPressed();
};
#endif // SH_UsersViewToolBar