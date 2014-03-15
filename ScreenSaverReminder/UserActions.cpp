
#include "stdafx.h"
#include "Form1.h"
#include "Registry.h"

using namespace System::Runtime::InteropServices; 

[StructLayout(LayoutKind::Explicit,Size=8)]
value struct LASTINPUTINFO
{
	[FieldOffset(0)]
	int cbSize;
	[FieldOffset(4)]
	int dwTime;
};

namespace SysWin32
{
	[DllImport("user32.dll",CharSet = CharSet::Unicode)]
	extern bool GetLastInputInfo(LASTINPUTINFO* plii);
};

using namespace ScreenSaverReminder;

System::Void
Form1::notifyIconClicked(System::Object^  sender, System::EventArgs^  e)
{
	this->Visible = true;
}

System::Void
Form1::hideButtonClicked(System::Object^  sender, System::EventArgs^  e)
{
	this->Visible = false;
}

System::Void
Form1::reminderDurationChanged(System::Object^  sender, System::EventArgs^  e)
{
	int v = System::Decimal::ToInt32(this->reminderDurationBox->Value);
	this->resetTimerValue = this->currentTimerValue = v * 120;
	this->updateNotifyText(v);
	this->updateNotifyIcon();
	RegistrySetTimerValue(v);
}

System::Void
Form1::updateNotifyText(int minutes)
{
	this->notifyIcon1->Text = "Screen Saver Reminder (" + 
		minutes.ToString() + " minutes)";
}

System::Void
Form1::exitButtonClicked(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}

System::Void
Form1::timerTicked(System::Object^  sender, System::EventArgs^  e)
{
	LASTINPUTINFO inputTime;
	inputTime.cbSize = 8;
	bool result = SysWin32::GetLastInputInfo(&inputTime);
	if (this->lastMovementTick != inputTime.dwTime)
	{
		this->currentTimerValue = this->resetTimerValue;
	}
	else
	{
		// we don't care if this goes negative.
		this->currentTimerValue --;
	}
	this->lastMovementTick = inputTime.dwTime;
	this->updateNotifyIcon();
}

System::Void
Form1::updateNotifyIcon(void)
{
	int v = this->currentTimerValue;
	int m8 = this->resetTimerValue / 8;
	System::Drawing::Icon ^ ico = this->ico0;
	if (v < 120)
	{
		if ((v & 1) == 0)
			ico = this->ico8;
		else
			ico = this->ico0;
	}
	else if (v <= (m8*1))
		ico = this->ico7;
	else if (v <= (m8*2))
		ico = this->ico6;
	else if (v <= (m8*3))
		ico = this->ico5;
	else if (v <= (m8*4))
		ico = this->ico4;
	else if (v <= (m8*5))
		ico = this->ico3;
	else if (v <= (m8*6))
		ico = this->ico2;
	else if (v <= (m8*7))
		ico = this->ico1;
	this->notifyIcon1->Icon = ico;
}
