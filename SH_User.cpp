/*
SH_User.cpp
*/

#include "SH_User.h"
#include "qdebug.h"

/*
Constructor
*/
SH_User::SH_User(QString username, QString password, QString access)
{
	loggedIn = connectToDatabase(username, password);
}

/*
Destructor
*/
SH_User::~SH_User()
{

}

/*
isLoggedIn()
returns state of loggedIn
*/
bool SH_User::isLoggedIn()
{
	return loggedIn;
}

/*
setLoggedIn()
sets loggedIn bool
*/
void SH_User::setLoggedIn(bool state)
{
	loggedIn = state;
}

/*
connectToDatabase
*/
bool SH_User::connectToDatabase(QString username, QString password)
{
	//QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath());
    db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("mysqlserver");
	db.setDatabaseName("studiohub");
	db.setUserName("root");
	db.setPassword("root");

	if (!db.open())
	{
		QSqlError error;
		error = db.lastError();
		dbError.append(error.text());
		bool driver = QSqlDatabase::isDriverAvailable("QMYSQL");
		if (driver)
			dbError.append(" MYSQL DRIVER AVAILABLE");
		else if (!driver)
			dbError.append(" MYSQL DRIVER NOT AVAILABLE");
		
		return false;
	}
	
	return true;
}

QString SH_User::getDBError()
{
	return dbError;
}
