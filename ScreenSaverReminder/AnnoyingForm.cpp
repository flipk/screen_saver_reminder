#include "StdAfx.h"
#include "AnnoyingForm.h"

using namespace ScreenSaverReminder;

System::Void AnnoyingForm::annoyingFormToggle(void)
{
	int newCtr = colorCounter + 1;
	switch (colorCounter)
	{
	case 0:
		this->BackColor = System::Drawing::Color::Black;
		break;
	case 1:
		this->BackColor = System::Drawing::Color::Red;
		break;
	case 2:
		this->BackColor = System::Drawing::Color::Yellow;
		break;
	case 3:
		this->BackColor = System::Drawing::Color::Green;
		break;
	case 4:
		this->BackColor = System::Drawing::Color::Blue;
		newCtr = 0;
		break;
	}
	colorCounter = newCtr;
}
