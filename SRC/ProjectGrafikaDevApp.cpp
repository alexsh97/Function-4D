//---------------------------------------------------------------------------
//
// Name:        ProjectGrafikaDevApp.cpp
// Author:      Shadoba
// Created:     15.06.2017 14:21:27
// Description: 
//
//---------------------------------------------------------------------------

#include "ProjectGrafikaDevApp.h"
#include "ProjectGrafikaDevDlg.h"

IMPLEMENT_APP(ProjectGrafikaDevDlgApp)

bool ProjectGrafikaDevDlgApp::OnInit()
{
	ProjectGrafikaDevDlg* dialog = new ProjectGrafikaDevDlg(NULL);
	SetTopWindow(dialog);
	dialog->Show(true);		
	return true;
}
 
int ProjectGrafikaDevDlgApp::OnExit()
{
	return 0;
}
