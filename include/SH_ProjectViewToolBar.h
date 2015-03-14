/*
SH_ProjectViewToolBar
*/

#ifndef SH_PROJECTVIEWTOOLBAR_H
#define SH_PROJECTVIEWTOOLBAR_H

#include "qpushbutton.h"

#include "include\SH_mainwindow.h"

// forward declare class
class SH_MainToolBar;

class SH_ProjectViewToolBar : public QToolBar
{
	Q_OBJECT

public:
	SH_ProjectViewToolBar(SH_MainToolBar *mainToolBar, QWidget *parent);
	~SH_ProjectViewToolBar();

private:
	QPushButton		*addProjectButton;
	QPushButton		*deleteProjectButton;
	QPushButton		*buttonThree;

	QIcon			*addProjectIcon;
	QIcon			*deleteProjectIcon;


protected:
	signals :
		void projectViewAddProjectClicked();
		void projectViewDeleteProjectClicked();

	private slots :
		void	mainToolBarProjectViewPressed();
		void addProjectClicked();
		void deleteProjectClicked();
};
#endif // SH_ProjectViewToolBar