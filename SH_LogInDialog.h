/*
SH_LogInDialog
*/

#ifndef SH_LOGINDIALOG_H
#define SH_LOGINDIALOG_H

#include "qdialog.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qaction.h"
#include "qlineedit.h"

#include "sh_mainwindow.h"

class SH_LogInDialog : public QDialog
{
	Q_OBJECT

public:
	SH_LogInDialog(QWidget *parent, Qt::WindowFlags f=0);
	~SH_LogInDialog();

	QString	getUsername();
	QString getPassword();

private:
	// Mouse key press/movement
	void	mousePressEvent(QMouseEvent *event);
	void	mouseMoveEvent(QMouseEvent *event);
	int		mouseClick_X_Coord;
	int		mouseClick_Y_Coord;

	void		createButtons();
	void		createActions();
	void		createSignals();
	void		createEditBox();
	void		createLabels();

	QLabel		*usernameLabel;
	QLabel		*passwordLabel;

	QPushButton	*logInButton;
	QPushButton	*cancelButton;

	QAction		*logInAction;
	QAction		*cancelAction;

	QLineEdit	*usernameEditBox;
	QLineEdit	*passwordEditBox;

protected:

};

#endif // SH_LogInDialog