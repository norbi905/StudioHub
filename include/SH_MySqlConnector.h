/*
SH_MySqlConnector.h
*/

#ifndef SH_MYSQLCONNECTOR_H
#define SH_MYSQLCONNECTOR_H

#include <QtSql>

#include "include\sh_mainwindow.h"
#include "include\sh_user.h"

// forward declare class
class SH_User;

class SH_MySqlConnector
{
public:
	SH_MySqlConnector();
	~SH_MySqlConnector();

	// string to store any errors that the mysql returns
	QString			dbError;
	QString			getDBError();
	
	bool			connectToDatabase(QString username, QString password);

private:
	SH_User			*user;

	// the database
	QSqlDatabase	db;
	

protected:
};

#endif // SH_MYSQLCONNECTOR_H