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
	QString	dbError;
	QString	getDBError();

private:
	QSqlDatabase	db;

	bool	loggedIn;
	void	setLoggedIn(bool state);
	bool	connectToDatabase(QString username, QString password);

protected:
};

#endif // SH_User.h