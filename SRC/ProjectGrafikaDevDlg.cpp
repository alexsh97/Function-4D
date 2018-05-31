///-----------------------------------------------------------------
///
/// @file      ProjectGrafikaDevDlg.cpp
/// @author    Mucha Bart³omiej, Aleksandr Shaforostov, Mi³osz Œwierad
/// Created:   15.06.2017 14:21:27
/// @section   DESCRIPTION
///            ProjectGrafikaDevDlg class implementation Liczymy na Zaliczenie
///
///------------------------------------------------------------------

#include "ProjectGrafikaDevDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include <wx/image.h>
#include <wx/msgdlg.h>
////Header Include End
#include "fromFile.h"
#include <vector>
#include <fstream>
#include <cmath>

//----------------------------------------------------------------------------
// ProjectGrafikaDevDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(ProjectGrafikaDevDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(ProjectGrafikaDevDlg::OnClose)
	EVT_BUTTON(ID_SAVEBUTTON,ProjectGrafikaDevDlg::SaveButtonClick)
	
	EVT_UPDATE_UI(ID_SLIDER,ProjectGrafikaDevDlg::SliderUpdateUI)
	EVT_BUTTON(ID_DRAWBUTTON,ProjectGrafikaDevDlg::DrawButtonClick)
	EVT_BUTTON(ID_LOADBUTTON,ProjectGrafikaDevDlg::LoadButtonClick)
END_EVENT_TABLE()
////Event Table End

ProjectGrafikaDevDlg::ProjectGrafikaDevDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

ProjectGrafikaDevDlg::~ProjectGrafikaDevDlg()
{
} 

void ProjectGrafikaDevDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer1->Add(WxBoxSizer3, 1, wxALIGN_LEFT | wxALIGN_RIGHT | wxALIGN_TOP | wxEXPAND | wxALL, 5);

	Panel = new wxPanel(this, ID_PANEL, wxPoint(5, 5), wxSize(400, 400));
	WxBoxSizer3->Add(Panel, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer2->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer5, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxALL, 5);

	LoadButton = new wxButton(this, ID_LOADBUTTON, _("Load File"), wxPoint(5, 5), wxSize(75, 25), 0, wxDefaultValidator, _("LoadButton"));
	WxBoxSizer4->Add(LoadButton, 0, wxALIGN_TOP | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer1_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("Floating Vector"));
	WxStaticBoxSizer1 = new wxStaticBoxSizer(WxStaticBoxSizer1_StaticBoxObj, wxVERTICAL);
	WxBoxSizer5->Add(WxStaticBoxSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	WxStaticBoxSizer1->Add(WxBoxSizer7, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	WxStaticBoxSizer1->Add(WxBoxSizer8, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	WxStaticBoxSizer1->Add(WxBoxSizer9, 0, wxALIGN_CENTER | wxALL, 5);

	DrawButton = new wxButton(this, ID_DRAWBUTTON, _("Draw"), wxPoint(10, 107), wxSize(75, 25), 0, wxDefaultValidator, _("DrawButton"));
	WxStaticBoxSizer1->Add(DrawButton, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer2_StaticBoxObj = new wxStaticBox(this, wxID_ANY, _("State"));
	WxStaticBoxSizer2 = new wxStaticBoxSizer(WxStaticBoxSizer2_StaticBoxObj, wxHORIZONTAL);
	WxBoxSizer6->Add(WxStaticBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	Slider = new wxSlider(this, ID_SLIDER, 0, 0, 100, wxPoint(10, 20), wxSize(150, 45), wxSL_HORIZONTAL | wxSL_AUTOTICKS | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, _("Slider"));
	Slider->SetRange(0,100);
	Slider->SetValue(0);
	WxStaticBoxSizer2->Add(Slider, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("X"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText1"));
	WxBoxSizer7->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Y"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText2"));
	WxBoxSizer8->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Z"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText3"));
	WxBoxSizer9->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	xText = new wxTextCtrl(this, ID_XTEXT, _("1"), wxPoint(26, 5), wxSize(40, 19), 0, wxDefaultValidator, _("xText"));
	WxBoxSizer7->Add(xText, 0, wxALIGN_CENTER | wxALL, 5);

	yText = new wxTextCtrl(this, ID_YTEXT, _("0"), wxPoint(26, 5), wxSize(40, 19), 0, wxDefaultValidator, _("yText"));
	WxBoxSizer8->Add(yText, 0, wxALIGN_CENTER | wxALL, 5);

	zText = new wxTextCtrl(this, ID_ZTEXT, _("0"), wxPoint(26, 5), wxSize(40, 19), 0, wxDefaultValidator, _("zText"));
	WxBoxSizer9->Add(zText, 0, wxALIGN_CENTER | wxALL, 5);

	OpenFileDialog =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);

	SaveFileDialog =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	SaveButton = new wxButton(this, ID_SAVEBUTTON, _("Capture\n Picture"), wxPoint(5, 40), wxSize(75, 32), 0, wxDefaultValidator, _("SaveButton"));
	WxBoxSizer4->Add(SaveButton, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("ProjectGrafikaDev"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	Panel->SetWindowStyle(wxSHAPED);
	MemoryBitmap=wxBitmap(400,400);
	SaveFileDialog->SetWildcard("JPG files(*.jpg)|*.jpg|PNG files(*.png)|*.png|BMP files(*.bmp)|*.bmp");
	OpenFileDialog->SetWildcard("Text files (*.txt)|*.txt");
	fileLoaded = 0;
}

/*
 Destruktor glownego dialogu*/
void ProjectGrafikaDevDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 LoadButtonClick*/
void ProjectGrafikaDevDlg::LoadButtonClick(wxCommandEvent& event)
{
	if (OpenFileDialog->ShowModal()==wxID_OK)
    {
        std::ifstream in;
        in.open(OpenFileDialog->GetPath().ToAscii());

        if (!in.good())
        {
            wxLogError("Cannot open file '%s'.", OpenFileDialog->GetPath());
            return;
        }

        if (in.is_open())
        {
            fromFile(in, Function, fileLoaded);
            fileLoaded = 1;
        }
        in.close();
    }  
}

/*
 Funckja interpoluj¹ca metod¹ Sheparda*/
double Shepard(std::vector<std::vector<double> > & d, float x, float y, int os1, int os2, int os3, double SliderState,int p)
{
    double wk,L=0,M=0;
    int N = d[0].size();
    if( p <= 3)
    {
        for(int i = 0;i < N;++i)
        {
                wk=1./(pow((x-d[os1][i]),2)+pow((y-d[os2][i]),2));
                L += d[3][i]*wk;
                M += wk;
        }
        return L/M;
    }
}

/*
 Funkcja rysujaca w Panelu i uzupelniajaca MemoryBitmap */
void ProjectGrafikaDevDlg::Draw()
{
////////Tworzy narzedzia do obs³ugi grafiki w Panelu i MemoryBitmapie
    wxMemoryDC memDC;
    memDC.SelectObject(MemoryBitmap);
    memDC.SetBackground(*wxWHITE_BRUSH);
    memDC.Clear();
    memDC.SetPen(*wxBLACK_PEN);
    memDC.SetBrush(*wxTRANSPARENT_BRUSH);
    wxClientDC dc(Panel);

    int N=Function[0].size();
////////wyznacza spektrum kolorow
    double tmp,min1,max1;
    min1 = max1 = Function[3][0];
    for(int i=1; i<N;i++)
    {
        max1=std::max(max1, Function[3][i]);
        min1=std::min(min1, Function[3][i]);
    }
    max1-=max1*0.03;//pierwiastek z dwóch
    min1-=min1*0.03;

    int R,G,B;
    double value;

/////////////Uzupelnia MemoryBitmap
    for(int i=0;i<=400;++i)
        {
            for(int j=0;j<=400;++j)
            {
                value = Shepard(DataMap,i*b/400.0 + a,j*b/400.0 + a, os1, os2, os3, Slider->GetValue()*b/10,przyp);

                    R=255-((value-min1)/(max1-min1))*255;
                    G=0;
                    B=((value-min1)/(max1-min1))*255;

                if (R < 0) R = 0;
                if (R > 255) R = 255;
                if (G < 0) G = 0;
                if (G > 255) G = 255;
                if (B < 0) B = 0;
                if (B > 255) B=255;
                memDC.SetPen(wxPen(wxColour(R,G,B)));
                memDC.DrawPoint(i,j);
            }
        }
////////Pobiera wielkosc Panelu, rozciaga MemoryBitmape 
////////na maksymalna mo¿liw¹ powierchnie Panelu
    wxSize Panelsize = Panel->GetSize();   
    int size = std::min( Panelsize.GetWidth(),Panelsize.GetHeight())  ;     
    dc.StretchBlit(0,0,size,size,&memDC,0,0,400,400);
    memDC.SelectObject(wxNullBitmap);
}

/*
 SaveButtonClick*/
void ProjectGrafikaDevDlg::SaveButtonClick(wxCommandEvent& event)
{
	wxInitAllImageHandlers();	

	if (SaveFileDialog->ShowModal()==wxID_OK)
    {
        MemoryBitmap.ConvertToImage().SaveFile(SaveFileDialog->GetPath());
    }
}

/*
DrawButtonClick*/
void ProjectGrafikaDevDlg::DrawButtonClick(wxCommandEvent& event)
{
	wxString str = xText->GetValue();
    str.ToDouble(&_X);
    str =  yText->GetValue();
    str.ToDouble(&_Y);
    str = zText->GetValue();
    str.ToDouble(&_Z);
    a = Function[0][0];
    b = Function[0][Function[0].size()-2];
    if(_X)
    {
        przyp = 1;
        os3 = 0;
        os1 = 1;
        os2 = 2;
        if(_Y)
        {
           przyp++;
           os2 = 1;
           os1 = 2;     
        }
        else if(_Z)
        {
            przyp++;
            os2 = 2;
            os1 = 1;
        }
    }
    else
    {
        if(_Y)
        {
          przyp = 1;
          os3 = 1;
          os1 = 0;
          os2 = 2;
          if(_Z)
          {
             przyp++;      
          }   
        }
        else
        {
          przyp = 1;
          os3 = 2;
          os1 = 0;
          os2 = 1;   
        }   
    }
 
    DataM();
    Draw();
}

/*
 SliderUpdateUI*/
void ProjectGrafikaDevDlg::SliderUpdateUI(wxUpdateUIEvent& event)
{
    if(fileLoaded) DataM ();
}
/*
 Uzupelnia dany przekroj wzgledem Floating Vectora */
void ProjectGrafikaDevDlg::DataM()
{
    if(fileLoaded) 
    {
        for(int i=0; i<DataMap.size(); i++)DataMap[i].clear();
        DataMap.clear();
    }
    DataMap.resize(4);
    
    int N = Function[0].size();
    int S=Slider->GetValue()*b/100.;
    
     if(przyp == 1 || przyp == 3)
     {
        for(int i=0;i<N;i++)
        {
            if(Function[os3][i] == S)
            {
                DataMap[os1].push_back(Function[os1][i]);
                DataMap[os2].push_back(Function[os2][i]);
                DataMap[os3].push_back(S);
                DataMap[3].push_back(Function[3][i]);  
            }
        }    
      }
      else
      {
        if(przyp == 2)
        {
            double mind = sqrt(S/2 *S/2 + S/2*S/2);
            for(int i=0;i<N;i++)
            {
                double d = sqrt(pow(Function[os2][i],2)+pow(Function[os3][i],2));
                if(d<=S && d>=mind)
                {
                    DataMap[os1].push_back(Function[os1][i]);
                    DataMap[os2].push_back(Function[os2][i]);
                    DataMap[os3].push_back(Function[os3][i]);
                    DataMap[3].push_back(Function[3][i]);    
                }
            }    
        }     
      }
}



