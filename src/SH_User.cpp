/*
SH_User.cpp
*/

#include "qdebug.h"

#include "include\SH_User.h"

/*
Constructor
*/
SH_User::SH_User() 
	: QObject()
{

}

SH_User::SH_User(QString username, QString password, QString access)
	: QObject()
{
	
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
setUsername
*/
void SH_User::setUsername(QString username)
{
	userName = username;
}

/*
setAccess
*/
void SH_User::setAccess(QString access)
{
	userAccess = access;
}

/*
getUsername
*/
QString SH_User::getUsername()
{
	return userName;
}

QString SH_User::getAccess()
{
	return userAccess;
}