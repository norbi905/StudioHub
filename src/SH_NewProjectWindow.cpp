/*
SH_NewProjectWindow.cpp
*/

#include "include\SH_NewProjectWindow.h"

/*
Constructor
*/
SH_NewProjectWindow::SH_NewProjectWindow(QWidget *parent, Qt::WindowFlags f)
	: QDialog(parent)
{
	setWindowFlags(Qt::Tool);
	setMinimumSize(400, 300);

	addProjectButton	= new QPushButton("Add");
	cancelProjectButton = new QPushButton("Cancel");

	mainLayout			= new QVBoxLayout(this);
	mainScrollArea		= new QScrollArea(this);
	placeholderWidget	= new QWidget(mainScrollArea);
	newLayout			= new QGridLayout(mainScrollArea);

	mainScrollArea->setWidgetResizable(true);
	newLayout->setAlignment(Qt::AlignTop);

	projectInfoLayout	= new QGridLayout();
	projectInfoBox		= new QGroupBox("Project info", mainScrollArea);
	projectNameLabel	= new QLabel("Project name: ");
	projectNameLineEdit = new QLineEdit();
	clientLabel			= new QLabel("Client: ");
	clientComboBox		= new QComboBox();
	projectInfoBox->setMaximumHeight(150);

	projectInfoLayout->addWidget(projectNameLabel,0,0);
	projectInfoLayout->addWidget(projectNameLineEdit,0,1);
	projectInfoLayout->addWidget(clientLabel, 1, 0);
	projectInfoLayout->addWidget(clientComboBox, 1, 1);
	projectInfoBox->setLayout(projectInfoLayout);

	newLayout->addWidget(projectInfoBox);
	placeholderWidget->setLayout(newLayout);
	mainScrollArea->setWidget(placeholderWidget);

	mainLayout->addWidget(mainScrollArea);
	mainLayout->addWidget(addProjectButton,0,0);
	mainLayout->addWidget(cancelProjectButton);	

	setLayout(mainLayout);

	createSignals();
}

/*
Destructor
*/
SH_NewProjectWindow::~SH_NewProjectWindow()
{

}

/*
createSignals
*/
void SH_NewProjectWindow::createSignals()
{
	connect(addProjectButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelProjectButton, SIGNAL(clicked()), this, SLOT(reject()));
}

/*
getProjectName
*/
QString SH_NewProjectWindow::getProjectName()
{
	return projectNameLineEdit->text();
}