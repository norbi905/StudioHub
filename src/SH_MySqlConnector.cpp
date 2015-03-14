/*
SH_MySqlConnector.cpp
*/

#include "include\SH_MySqlConnector.h"

/*
Constructor
*/
SH_MySqlConnector::SH_MySqlConnector()
	: QObject()
{
	userNameTable	= NULL;
	projectTable	= NULL;
	clientTable		= NULL;
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
		return false;
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

/*
getUserNameTable
*/
QSqlTableModel *SH_MySqlConnector::getUserNameTable()
{
	if (userNameTable == NULL)
	{
		userNameTable = new QSqlTableModel(this, db);
		userNameTable->setTable("users");
		userNameTable->select();
	}

	return userNameTable;
}

/*
getProjectTable
*/
QSqlTableModel *SH_MySqlConnector::getProjectTable()
{
	if (projectTable == NULL);
	{
		projectTable = new QSqlTableModel(this, db);
		projectTable->setTable("projects");
		projectTable->select();
	}
	return projectTable;
}

/*
getClientTable
*/
QSqlTableModel *SH_MySqlConnector::getClientTable()
{
	if (clientTable == NULL);
	{
		clientTable = new QSqlTableModel(this, db);
		clientTable->setTable("clients");
		clientTable->select();
	}
	return clientTable;
}