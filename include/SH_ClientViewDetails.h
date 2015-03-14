/*
SH_ClientViewDetails_h
*/
#ifndef SH_CLIENTVIEWDETAILS_H
#define SH_CLIENTVIEWDETAILS_H

#include "sh_mainwindow.h"

class SH_ClientViewDetails : public SH_ClientView
{
	Q_OBJECT

public:
	SH_ClientViewDetails(QWidget *parent = 0);
	~SH_ClientViewDetails();

private:
protected:
};
#endif // SH_ClientViewDetails_H