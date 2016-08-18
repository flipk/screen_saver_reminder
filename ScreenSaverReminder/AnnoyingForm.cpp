#include "StdAfx.h"
#include "AnnoyingForm.h"

using namespace ScreenSaverReminder;
using namespace System::Drawing;

System::Void AnnoyingForm::start(void)
{
	BackColor = Color::Black;
	Show();
	switch (state) {
		case ANNOY_COLORS:
			fractalTimer->Interval = 500;
			break;
		case SHOW_FRACTALS:
			fractalTimer->Interval = 10;
			break;
		case SHOW_PIXELS:
			fractalTimer->Interval = 1;
			break;
	}
	fractalTimer->Enabled = true;
	fractalBitmap = gcnew Bitmap(this->Width,this->Height);
}

System::Void AnnoyingForm::stop(void)
{
	fractalTimer->Enabled = false;
	Hide();
}

System::Void
AnnoyingForm::fractalTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if (state == ANNOY_COLORS)
	{
		int newCtr = colorCounter + 1;
		switch (colorCounter)
		{
		case 0:
			BackColor = Color::Black;
			break;
		case 1:
			BackColor = Color::Red;
			break;
		case 2:
			BackColor = Color::Yellow;
			break;
		case 3:
			BackColor = Color::Green;
			break;
		case 4:
			BackColor = Color::Blue;
			newCtr = 0;
			break;
		}
		colorCounter = newCtr;
	}
	else if (state == SHOW_FRACTALS)
	{
		// TODO
	}
	else if (state == SHOW_PIXELS)
	{
		System::Drawing::Graphics ^ g = this->CreateGraphics();
		System::Drawing::Graphics ^ bmg = Graphics::FromImage(this->fractalBitmap);

		for (int ctr = 0; ctr < 1000; ctr++)
		{
		Color newColor = Color::FromArgb(rand->Next(255), rand->Next(255), rand->Next(255));
		this->fractalBitmap->SetPixel(rand->Next(this->Width), rand->Next(this->Height), newColor);
//		g->DrawLine(Pens::Red, 10, 10, 11, 11);
		}
		g->DrawImage(this->fractalBitmap, 0, 0);
	}
}
