/*
SH_User.cpp
*/

#include "qdebug.h"

#include "include\SH_User.h"

/*
Constructor
*/
SH_User::SH_User(QString username, QString password, QString access)
{
	//loggedIn = connectToDatabase(username, password);
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