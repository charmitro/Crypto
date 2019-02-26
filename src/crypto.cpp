// TODO: ADD ABOUT INFO.
#include "crypto.h"

Absolute::Absolute(const wxString &title)
  : wxFrame(NULL, -1, "Crypto", wxDefaultPosition, wxSize(700, 450))
{
  
  wxPanel *panel = new wxPanel(this, -1);
  //MENU
  menubar = new wxMenuBar();  
  fileMenu = new wxMenu();
  fileMenu->Append(wxID_ABOUT, _T("&About"));
  fileMenu->Append(wxID_EXIT, _T("&Exit"));
  menubar->Append(fileMenu, _T("&File"));
  SetMenuBar(menubar);
  
  //ENCRYPTION BUTTON
  encb = new wxButton(this, BUTTON1, wxT("ENCRYPT"), wxPoint(175, 110), wxSize(350, 30), 0);
  encb->SetBackgroundColour(*wxBLACK);
  encb->SetForegroundColour(*wxYELLOW);
  //DECRYPTION BUTTON
  decb = new wxButton(this, BUTTON2, wxT("DECRYPT"), wxPoint(175, 250), wxSize(350, 30), wxOK, wxDefaultValidator, wxButtonNameStr);
  decb->SetBackgroundColour(*wxBLACK);
  decb->SetForegroundColour(*wxYELLOW);
  //DIFFICULTY BUTTON
  difb = new wxButton(this, BUTTON3, wxT(""), wxPoint(52, 10), wxSize(20, 20), wxOK, wxDefaultValidator, wxButtonNameStr);
  difb->SetBackgroundColour(*wxBLACK);
  
  //ENCRYPT STRING BOX
  enc = new wxTextCtrl(this, -1, wxT("Enter string to encrypt..."), wxPoint(175, 5), wxSize(350, 100), wxTE_MULTILINE);
  //DECRYPT STRING BOX
  dec = new wxTextCtrl(this, -1, wxT(""), wxPoint(175, 145), wxSize(350, 100), wxTE_MULTILINE);
  //KEY DIFFICULTY W/ LABEL
  diflabel = new wxStaticText(this, -1, "KEY: ", wxPoint(0, 10), wxSize(30, 20));
  difbox = new wxTextCtrl(this, -1, _T("2"), wxPoint(31, 10), wxSize(20, 20), wxTE_MULTILINE);
  //SHA RESULT STRING BOX W/ LABEL
  shalabel = new wxStaticText(this, -1, "SHA256 HASHCODE FOR THE NONECRYPTED TEXT", wxPoint(183, 280), wxSize(350, 50));
  shabox = new wxTextCtrl(this, -1, _T(""), wxPoint(175, 300), wxSize(350, 50), wxTE_MULTILINE);
  // SetSizerAndFit(topsizer);
}

//EVENTS
BEGIN_EVENT_TABLE(Absolute, wxFrame)
EVT_BUTTON(BUTTON1, Absolute::OnPressE)
EVT_BUTTON(BUTTON2, Absolute::OnPressD)
EVT_BUTTON(BUTTON3, Absolute::SetDif)
EVT_MENU(wxID_EXIT, Absolute::OnExit)
EVT_MENU(wxID_ABOUT, Absolute::OnAbout)
END_EVENT_TABLE()

//SET KEY(DIFFICULTY)
void Absolute::SetDif(wxCommandEvent &event)
{
  wxString diff(difbox->GetValue());
  dif = wxAtoi(diff);
}

//ENCRYPT TEXT INSIDE ENCRYPTION BOX
void Absolute::OnPressE(wxCommandEvent &event)
{
  //BASIC STRING ENCRYPTION BASED ON KEY DIFFICULTY
  wxString peos(enc->GetValue());
  string s = string(peos.mb_str());
  int n = s.length();
  char text[n];
  
  strcpy(text, s.c_str());

  for (int i = 0; (i < n + 1 && text[i] != '\0'); i++)
  {
    text[i] = text[i] + dif;
  }
  wxString p = wxString::FromUTF8(text);

  //SHA256 CODE OF THE STRING
  unsigned char digest[SHA256_DIGEST_LENGTH];
  const char* stringtest = s.c_str();

  SHA256_CTX ctx;
  SHA256_Init(&ctx);
  SHA256_Update(&ctx, stringtest, strlen(stringtest));
  SHA256_Final(digest, &ctx);

  char mdString[SHA256_DIGEST_LENGTH*2 + 1];
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
      sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }

  shabox->SetValue(mdString);
  dec->SetValue(p);
}

//DECRYPT TEXT INSIDE DECRYPTION BOX
void Absolute::OnPressD(wxCommandEvent &event)
{
  wxString mouni(dec->GetValue());
  string s = string(mouni.mb_str());
  int n = s.length();
  char text[n];

  strcpy(text, s.c_str());
  for (int i = 0; (i < n + 1 && text[i] != '\0'); i++)
  {
    text[i] = text[i] - dif;
  }

  wxString d = wxString::FromUTF8(text);
  enc->SetValue(d);
}
//ABOUT
void Absolute::OnAbout(wxCommandEvent &event)
{
  wxMessageBox(wxT("Crypto"), wxT("Title"));
}
//EXIT
void Absolute::OnExit(wxCommandEvent &event)
{
  Close(true);
}

