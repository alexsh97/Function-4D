//---------------------------------------------------------------------------
//
// Name:        ProjectGrafikaDevApp.h
// Author:      Shadoba
// Created:     15.06.2017 14:21:27
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __PROJECTGRAFIKADEVDLGApp_h__
#define __PROJECTGRAFIKADEVDLGApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class ProjectGrafikaDevDlgApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
