#include <wx-3.1/wx/wx.h>
#include <wx-3.1/wx/menu.h>
#include <wx-3.1/wx/slider.h>
#include <wx-3.1/wx/wxprec.h>
#include <openssl/sha.h>
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Absolute : public wxFrame
{
public:
  Absolute(const wxString &title);
private:
  int dif = 2;//KEY OR DIFFICULTY

  wxMenuBar *menubar;
  wxMenu *fileMenu, *helpMenu;

  wxButton *encb, *decb;
  wxButton *difb;
  //ENCRYPTION, DECRYPTION, DIFFICULTY AND HASH TEXT BOXES.
  wxTextCtrl *enc, *dec, *difbox, *shabox;
  wxString *test;

  //WHEN PRESS, ENCRYPT AND PLACE SHA256 HASHCODE IN HASHBOX.
  void OnPressE(wxCommandEvent &event);
  //WHEN PRESS, DECRYPT
  void OnPressD(wxCommandEvent &event);
  //WHEN PRESS, CHANGE KEY DIFFICULTY
  void SetDif(wxCommandEvent &event);

  DECLARE_EVENT_TABLE()
};

enum
{
  BUTTON1 = 1 //ENCRYPTION BUTTON
};
enum
{
  BUTTON2 = 2 //DECRYPTION BUTTON
};
enum
{
  BUTTON3 = 3 //SET KEY BUTTON
};
