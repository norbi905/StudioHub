/*
SH_NewProjectWindow_H
*/
#ifndef SH_NEWPROJECTWINDOW_H
#define SH_NEWPROJECTWINDOW_H

#include <qdialog.h>
#include <qscrollarea.h>
#include <qgridlayout.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>

class SH_NewProjectWindow : public QDialog
{
	Q_OBJECT

public:
	SH_NewProjectWindow(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~SH_NewProjectWindow();

private:
	QVBoxLayout	*mainLayout;
	QScrollArea	*mainScrollArea;
	QWidget		*placeholderWidget;
	QGridLayout *newLayout;

	// project info box
	QGridLayout	*projectInfoLayout;
	QGroupBox	*projectInfoBox;
	QLabel		*projectNameLabel;
	QLineEdit	*projectNameLineEdit;
	
protected:
};

#endif //SH_NewProjectWindow_H