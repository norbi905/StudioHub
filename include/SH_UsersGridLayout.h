/*
SH_UsersGridLayout_H
*/

#ifndef SH_USERSGRIDLAYOUT_H
#define SH_USERSGRIDLAYOUT_H

#include "qgridlayout.h"

class SH_UsersGridLayout : public QGridLayout
{
public:
	SH_UsersGridLayout(QWidget *parent = 0);
	~SH_UsersGridLayout();

	void addWidget(QWidget *parent);
	void deleteWidget(QWidget *parent);

	void setMaxColumnCount(int count);

private:
	int	maxColumnCount;

protected:
};

#endif // SH_UsersGridLayout_H