/*
	SH_MainWindow.h
*/

#ifndef SH_MAINWINDOW_H
#define SH_MAINWINDOW_H

#include <qsql.h>
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <qmenu.h>
#include <qtoolbar.h>
#include "ui_sh_mainwindow.h"

#include "SH_MainToolBar.h"
#include "SH_MainViewToolBar.h"
#include "SH_ProjectViewToolBar.h"
#include "SH_UsersViewToolBar.h"
#include "SH_CalendarViewToolBar.h"
#include "SH_LogInDialog.h"
#include "SH_User.h"
#include "SH_MySqlConnector.h"
#include "SH_ProjectListView.h"

// forward declare classes
class SH_MainToolBar;
class SH_MainViewToolBar;
class SH_ProjectViewToolBar;
class SH_UsersViewToolBar;
class SH_CalendarViewToolBar;
class SH_LogInDialog;
class SH_User;
class SH_MySqlConnector;
class SH_ProjectListView;

class SH_MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	// constructor/destructor
	SH_MainWindow(QWidget *parent = 0);
	~SH_MainWindow();

	//void				userRequestedLogOff(QWidget	*parent);

private:
	Ui::SH_MainWindowClass ui;
 
	// create main and additional toolbars
	SH_MainToolBar			*mainToolBar;
	SH_MainViewToolBar		*mainViewToolBar;
	SH_ProjectViewToolBar	*projectViewToolBar;
	SH_UsersViewToolBar		*usersViewToolBar;
	SH_CalendarViewToolBar	*calendarViewToolBar;

	//create views
	SH_ProjectListView		*projectListView;


	SH_LogInDialog		*logInDialogWindow;
	SH_User				*mainUser;
	SH_MySqlConnector	*mySqlConnector;

	QAction				*contextQuitAction;
	
	void				createContextActions();
	void				displayApplication(QWidget *parent);
	void				initiateLogIn(QWidget *parent);

	// Mouse key press/movement
	void				mousePressEvent(QMouseEvent *event);
	void				mouseMoveEvent(QMouseEvent *event);
	int					mouseClick_X_Coord;
	int					mouseClick_Y_Coord;
	
protected:
	// right click context menu
	void				contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;

	private slots:
		void			quitApplication();
		void			userRequestedLogOff();
		void			mainToolBarMainViewPressed();
		void			mainToolBarProjectViewPressed();
		void			mainToolBarUsersViewPressed();
		void			mainToolBarCalendarViewPressed();
};

#endif // SH_MAINWINDOW_H
