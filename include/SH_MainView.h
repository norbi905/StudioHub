/*
SH_MainView
*/

#ifndef SH_MAINVIEW_H
#define SH_MAINVIEW_H

#include "qwidget.h"
#include "qtextedit.h"

#include "sh_mainwindow.h"

// forward declare class
class SH_MainWindow;

class SH_MainView : public QTextEdit
{
	Q_OBJECT

public:
	SH_MainView(QWidget *parent = 0);
	~SH_MainView();

	void	addMessage(QString message);

private:

protected:
};

#endif // SH_MainView