/*
SH_User
*/

#ifndef SH_USER_H
#define SH_USER_H

#include <QtSql>
#include <qmessagebox.h>

#include "sh_mainwindow.h"

class SH_User : public QObject
{

	Q_OBJECT

public:
	SH_User();
	SH_User(QString username, QString password, QString access);
	~SH_User();

	bool	isLoggedIn();
	void	setLoggedIn(bool state);

	void	setUsername(QString username);
	void	setAccess(QString access);
	QString	getUsername();
	QString	getAccess();

private:
	bool	loggedIn;

	QString	userName;
	QString userAccess;
	

protected:
};

#endif // SH_User.h