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
#include <qstackedlayout.h>
#include "qsplitter.h"
//#include "ui_sh_mainwindow.h"

#include "SH_MainToolBar.h"
#include "SH_MainViewToolBar.h"
#include "SH_ProjectViewToolBar.h"
#include "SH_UsersViewToolBar.h"
#include "SH_CalendarViewToolBar.h"
#include "SH_LogInDialog.h"
#include "SH_User.h"
#include "SH_MySqlConnector.h"
#include "SH_ProjectListView.h"
#include "SH_MainView.h"
#include "SH_UsersView.h"
#include "SH_CalendarView.h"
#include "SH_UsersViewDetails.h"


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
class SH_MainView;
class SH_UsersView;
class SH_CalendarView;
class SH_UsersViewDetails;

class SH_MainWindow : public QWidget
{
	Q_OBJECT

public:
	// constructor/destructor
	SH_MainWindow(QWidget *parent = 0);
	~SH_MainWindow();

	void				userRequestedLogOff(QWidget	*parent);

private:
	//Ui::SH_MainWindowClass ui;
 
	// create main and additional toolbars
	SH_MainToolBar			*mainToolBar;
	SH_MainViewToolBar		*mainViewToolBar;
	SH_ProjectViewToolBar	*projectViewToolBar;
	SH_UsersViewToolBar		*usersViewToolBar;
	SH_CalendarViewToolBar	*calendarViewToolBar;

	//create views
	SH_ProjectListView		*projectListView;
	SH_MainView				*mainView;
	SH_UsersView			*usersView;
	SH_UsersViewDetails		*usersViewDetails;
	SH_CalendarView			*calendarView;

	SH_LogInDialog		*logInDialogWindow;
	SH_User				*mainUser;

	SH_MySqlConnector	*mySqlConnector;

	QStackedLayout		*leftStackedLayout;
	QGridLayout			*mainLayout;

	// split the users view 2 qwidets so it's resizable
	QSplitter			*usersViewSplitter;

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
		void			usersTreeClickedItem(QModelIndex index);

	signals:
		// needed to connect SH_UsersView with SH_UsersViewDisplay so that when a user clicks on a tree item the SH_UsersViewDisplay can act accordingly and display selected item
		void usersTreeViewClickedItem(QModelIndex index);
};

#endif // SH_MAINWINDOW_H
