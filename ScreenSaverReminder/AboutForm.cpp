#include "StdAfx.h"
#include "AboutForm.h"

using namespace ScreenSaverReminder;

System::Void
Form1::aboutButtonClicked(System::Object^  sender, System::EventArgs^  e)
{
	aboutForm->Show();
}

System::Void
AboutForm::dismissButtonClicked(System::Object^  sender, System::EventArgs^  e)
{
	Hide();
}
