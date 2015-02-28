/*
SH_LogInDialog
*/

#ifndef SH_LOGINDIALOG_H
#define SH_LOGINDIALOG_H

#include "qdialog.h"
#include "qlabel.h"
#include "qpushbutton.h"

#include "sh_mainwindow.h"

class SH_LogInDialog : public QDialog
{
	Q_OBJECT

public:
	SH_LogInDialog(QWidget *parent);
	~SH_LogInDialog();

private:
	// Mouse key press/movement
	void	mousePressEvent(QMouseEvent *event);
	void	mouseMoveEvent(QMouseEvent *event);
	int		mouseClick_X_Coord;
	int		mouseClick_Y_Coord;

	void		createButtons();

	QLabel		*logInTitle;
	QPushButton	*logInButton;
	QPushButton	*cancelButton;

protected:
};

#endif // SH_LogInDialog