#include "main.h"
#include "crypto.h"
#include <wx-3.1/wx/slider.h>




IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
  Absolute *absolute = new Absolute(wxT("Absolute"));
  absolute->Show(true);


  return true;

}
