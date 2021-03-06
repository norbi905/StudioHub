/*
SH_MySqlConnector.cpp
*/

#include "include\SH_MySqlConnector.h"

/*
Constructor
*/
SH_MySqlConnector::SH_MySqlConnector()
{

}

/*
Destructor
*/
SH_MySqlConnector::~SH_MySqlConnector()
{

}

/*
connectToDatabase
*/
bool SH_MySqlConnector::connectToDatabase(QString username, QString password)
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("mysqlserver");
	db.setDatabaseName("studiohub");
	db.setUserName(username);
	db.setPassword(password);

	if (!db.open())
	{
		QSqlError error;
		error = db.lastError();
		dbError.append(error.text());
		return true;
	}

	return true;
}

/*
getDBError
*/
QString SH_MySqlConnector::getDBError()
{
	return dbError;
}