/*
	SH_MainWindow.cpp
*/

#include "include\sh_mainwindow.h"

/*
Constructor
*/
SH_MainWindow::SH_MainWindow(QWidget *parent)
	: QWidget(parent)
{
	/* Setup main window
	::FramelessWindowHint - We dont want any window frames
	*/
	setWindowFlags(Qt::FramelessWindowHint);

	setMinimumSize(1280, 1024);
	
	contextQuitAction	= NULL;

	mainToolBar			= new SH_MainToolBar(this);
	mainViewToolBar		= new SH_MainViewToolBar(mainToolBar, this);
	projectViewToolBar	= new SH_ProjectViewToolBar(mainToolBar, this);
	usersViewToolBar	= new SH_UsersViewToolBar(mainToolBar, this);
	calendarViewToolBar = new SH_CalendarViewToolBar(mainToolBar, this);

	logInDialogWindow	= new SH_LogInDialog(parent);
	mainUser			= new SH_User();
	mySqlConnector		= new SH_MySqlConnector();

	mainLayout			= new QGridLayout(this);
	leftStackedLayout	= new QStackedLayout(this);

	// create connectors
	connect(mainToolBar, SIGNAL(logOffRequested()), this, SLOT(userRequestedLogOff()));
	connect(mainToolBar, SIGNAL(quitRequested()), this, SLOT(quitApplication()));
	connect(mainToolBar, SIGNAL(mainViewPressed()), this, SLOT(mainToolBarMainViewPressed()));
	connect(mainToolBar, SIGNAL(projectViewPressed()), this, SLOT(mainToolBarProjectViewPressed()));
	connect(mainToolBar, SIGNAL(usersViewPressed()), this, SLOT(mainToolBarUsersViewPressed()));
	connect(mainToolBar, SIGNAL(calendarViewPressed()), this, SLOT(mainToolBarCalendarViewPressed()));

	connect(mainToolBar, SIGNAL(mainViewPressed()), leftStackedLayout, SLOT(mainToolBarMainViewPressed()));
	connect(mainToolBar, SIGNAL(projectViewPressed()), leftStackedLayout, SLOT(mainToolBarProjectViewPressed()));
	connect(mainToolBar, SIGNAL(usersViewPressed()), leftStackedLayout, SLOT(mainToolBarUsersViewPressed()));
	connect(mainToolBar, SIGNAL(calendarViewPressed()), leftStackedLayout, SLOT(mainToolBarCalendarViewPressed()));

	// create view
	projectListView = new SH_ProjectListView(this);
	projectListView->hide();
	mainView		= new SH_MainView(this);
	mainView->hide();
	
	
	usersViewDetails = new SH_UsersViewDetails();
	usersViewDetails->hide();
	usersView = new SH_UsersView(usersViewDetails);
	usersView->hide();
	calendarView	= new SH_CalendarView(this);
	calendarView->hide();

	usersViewSplitter = new QSplitter(this);
	usersViewSplitter->addWidget(usersView);
	usersViewSplitter->addWidget(usersViewDetails);
	usersViewSplitter->setStretchFactor(0, 0.5);
	usersViewSplitter->setStretchFactor(1, 3.5);

	
	// connection so when user selects a user from treeview the usersviewdetails updates based on who is selected
	connect(usersView, SIGNAL(clicked(QModelIndex)), usersViewDetails, SLOT(usersTreeViewClickedItem(QModelIndex)));

	

	// make connections for usersViewToolBar with userView class
	connect(usersViewToolBar, SIGNAL(userViewAddUserClicked()), usersView, SLOT(addUserClicked()));
	connect(usersViewToolBar, SIGNAL(userViewRemoveUserClicked()), usersView, SLOT(removeUserClicked()));

	//ui.setupUi(this);
	//this->show();
	
	mainLayout->addWidget(mainToolBar, 0, 0, 1, 2);
	mainLayout->addWidget(mainViewToolBar, 1, 0);
	mainLayout->addWidget(projectViewToolBar,1, 0);
	mainLayout->addWidget(usersViewToolBar, 1, 0);
	mainLayout->addWidget(calendarViewToolBar, 1, 0);

	//mainLayout->addWidget(usersViewDetails, 2, 1);
	mainLayout->addWidget(usersViewSplitter);

	leftStackedLayout->addWidget(mainView);
	leftStackedLayout->addWidget(projectListView);
	//leftStackedLayout->addWidget(usersView);
	leftStackedLayout->addWidget(usersViewSplitter);
	leftStackedLayout->addWidget(calendarView);

	mainLayout->addLayout(leftStackedLayout, 2, 0);
	
	setLayout(mainLayout);

	initiateLogIn(parent);
}

/*
Destructor
*/
SH_MainWindow::~SH_MainWindow()
{
	delete mySqlConnector;
	delete mainUser;
	delete logInDialogWindow;
	delete mainToolBar;
	delete mainViewToolBar;
	delete projectViewToolBar;
	delete usersViewToolBar;
	delete calendarViewToolBar;

	delete projectListView;
	delete mainView;

	delete contextQuitAction;
}

/*
MousePressEvent
*/
void SH_MainWindow::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event);

	mouseClick_X_Coord = event->x();
	mouseClick_Y_Coord = event->y();
}

/*
MouseMoveEvent
*/
void SH_MainWindow::mouseMoveEvent(QMouseEvent *event)
{
	QWidget::mouseMoveEvent(event);

	move(event->globalX() - mouseClick_X_Coord, event->globalY() - mouseClick_Y_Coord);
}

/*
createContextActions
*/
void SH_MainWindow::createContextActions()
{
	if (contextQuitAction == NULL)
	{
		contextQuitAction = new QAction(tr("&Quit"), this);
		contextQuitAction->setShortcut(QKeySequence::Quit);
		contextQuitAction->setStatusTip("Quit application");
		connect(contextQuitAction, SIGNAL(triggered()), this, SLOT(quitApplication()));
	}
}

/*
displayApplication
*/
void SH_MainWindow::displayApplication(QWidget *parent	)
{
	mainToolBar->usernameLabel->setText(mainUser->getUsername());
	
	projectViewToolBar->hide();
	usersViewToolBar->hide();
	calendarViewToolBar->hide();
	mainToolBar->show();
	mainViewToolBar->show();

	// we want the main view button to be selected
	mainToolBar->resetToolBarButtons();

	leftStackedLayout->setCurrentIndex(0);
}

/*
contextMenuEvent
This gets called when a user right clicks anywhere within the application space and a context menu pops up
*/
void SH_MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
	QMenu	contextMenu(this);
	contextMenu.addAction(contextQuitAction);
	contextMenu.exec(event->globalPos());
}

/*
quitApplication
This gets called when a user right clicks and selects quit from the context menu
*/
void SH_MainWindow::quitApplication()
{
	//QApplication::quit();
	exit(0);
}

/*
initiateLogIn
*/
void SH_MainWindow::initiateLogIn(QWidget *parent)
{
	int result = logInDialogWindow->exec();

	if (result == QDialog::Accepted)
	{
		QString	username = logInDialogWindow->getUsername();
		QString password = logInDialogWindow->getPassword();
		
		bool connected = mySqlConnector->connectToDatabase(username, password);
		if (connected)
		{
			mainView->addMessage("Connected as: " + username);
			createContextActions();
			
			//set-up user
			mainUser->setUsername(username);
			mainUser->setAccess("S");

			//set-up users list view
			usersView->setUserNameTableModel(mySqlConnector->getUserNameTable());

			mainUser->setLoggedIn(true);

			displayApplication(parent);

			
		}
		else
		{
			mainView->addMessage(mySqlConnector->getDBError());
			initiateLogIn(parent);
		}
	}

	if (result == QDialog::Rejected)
	{
		exit(0);
	}	
}

/*
userRequestedLogOff
*/
void SH_MainWindow::userRequestedLogOff()
{
	mainToolBar->hide();
	mainViewToolBar->hide();
	projectViewToolBar->hide();
	usersViewToolBar->hide();
	calendarViewToolBar->hide();

	// get rid of all views
	projectListView->hide();
	mainView->hide();
	usersView->hide();
	usersViewDetails->hide();
	calendarView->hide();

	initiateLogIn(this);
}

/*
mainToolBarMainViewPressed
*/
void SH_MainWindow::mainToolBarMainViewPressed()
{
	mainViewToolBar->show();
	projectViewToolBar->hide();
	usersViewToolBar->hide();
	calendarViewToolBar->hide();

	leftStackedLayout->setCurrentIndex(0);
	usersViewDetails->hide();
}

/*
mainToolBarProjectViewPressed
*/
void SH_MainWindow::mainToolBarProjectViewPressed()
{
	mainViewToolBar->hide();
	projectViewToolBar->show();
	usersViewToolBar->hide();
	calendarViewToolBar->hide();

	leftStackedLayout->setCurrentIndex(1);
	usersViewDetails->hide();
}

/*
mainToolBarUsersViewPressed
*/
void SH_MainWindow::mainToolBarUsersViewPressed()
{
	mainViewToolBar->hide();
	projectViewToolBar->hide();
	usersViewToolBar->show();
	calendarViewToolBar->hide();

	leftStackedLayout->setCurrentIndex(2);
	usersViewSplitter->show();
	usersView->show();
	usersViewDetails->show();
}

/*
mainToolBarCalendarViewPressed
*/
void SH_MainWindow::mainToolBarCalendarViewPressed()
{
	mainViewToolBar->hide();
	projectViewToolBar->hide();
	usersViewToolBar ->hide();
	calendarViewToolBar->show();

	leftStackedLayout->setCurrentIndex(3);
	usersViewDetails->hide();
}

void SH_MainWindow::usersTreeClickedItem(QModelIndex index)
{
	emit usersTreeViewClickedItem(index);
}