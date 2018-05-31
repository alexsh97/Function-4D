///-----------------------------------------------------------------
///
/// @file      ProjectGrafikaDevDlg.h
/// @author    Shadoba
/// Created:   15.06.2017 14:21:27
/// @section   DESCRIPTION
///            ProjectGrafikaDevDlg class declaration
///
///------------------------------------------------------------------

#ifndef __PROJECTGRAFIKADEVDLG_H__
#define __PROJECTGRAFIKADEVDLG_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/filedlg.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/sizer.h>
////Header Include End

#include <vector>

////Dialog Style Start
#undef ProjectGrafikaDevDlg_STYLE
#define ProjectGrafikaDevDlg_STYLE wxFULL_REPAINT_ON_RESIZE | wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class ProjectGrafikaDevDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		ProjectGrafikaDevDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("ProjectGrafikaDev"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = ProjectGrafikaDevDlg_STYLE);
		virtual ~ProjectGrafikaDevDlg();
		void LoadButtonClick(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void SaveButtonClick(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void DrawButtonClick(wxCommandEvent& event);
		void SliderUpdateUI(wxUpdateUIEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *SaveButton;
		wxFileDialog *SaveFileDialog;
		wxFileDialog *OpenFileDialog;
		wxTextCtrl *zText;
		wxTextCtrl *yText;
		wxTextCtrl *xText;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxSlider *Slider;
		wxStaticBoxSizer *WxStaticBoxSizer2;
		wxButton *DrawButton;
		wxBoxSizer *WxBoxSizer9;
		wxBoxSizer *WxBoxSizer8;
		wxBoxSizer *WxBoxSizer7;
		wxStaticBoxSizer *WxStaticBoxSizer1;
		wxButton *LoadButton;
		wxBoxSizer *WxBoxSizer6;
		wxBoxSizer *WxBoxSizer5;
		wxBoxSizer *WxBoxSizer4;
		wxPanel *Panel;
		wxBoxSizer *WxBoxSizer3;
		wxBoxSizer *WxBoxSizer2;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_SAVEBUTTON = 1023,
			ID_ZTEXT = 1022,
			ID_YTEXT = 1021,
			ID_XTEXT = 1020,
			ID_WXSTATICTEXT3 = 1019,
			ID_WXSTATICTEXT2 = 1018,
			ID_WXSTATICTEXT1 = 1017,
			ID_SLIDER = 1016,
			ID_DRAWBUTTON = 1013,
			ID_LOADBUTTON = 1008,
			ID_PANEL = 1004,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
	    void Draw();
	    void DataM();
	    int nsize;
	    int przyp;
        double _X,_Y,_Z;
        double a,b;
        int os1,os2,os3;
        wxBitmap MemoryBitmap;
        std::vector<std::vector<double> > DataMap;
        std::vector<std::vector<double> > Function;
        bool fileLoaded;                            // mowi czy plik jest wczytany
};

#endif
