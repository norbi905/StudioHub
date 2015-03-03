/*
SH_User
*/

#ifndef SH_USER_H
#define SH_USER_H

#include <QtSql>
#include <qmessagebox.h>

#include "sh_mainwindow.h"

class SH_User
{

public:
	SH_User(QString username, QString password, QString access);
	~SH_User();

	bool	isLoggedIn();
	void	setLoggedIn(bool state);

private:
	bool	loggedIn;
	

protected:
};

#endif // SH_User.h