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
			fractalTimer->Interval = 100; // TODO
			break;
		case SHOW_PIXELS:
			fractalTimer->Interval = 100;
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
		default:
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
//		System::Drawing::Graphics ^ bmg = Graphics::FromImage(this->fractalBitmap);
//		g->DrawPolygon(Pens::Red, cli::array<system::drawing::point,1> ^ points);

#if 0
		for (int ctr = 0; ctr < 30000; ctr++)
		{
			Color newColor;
			if ((colorCounter & 7) == 0)
				newColor = Color::FromArgb(rand->Next(255), rand->Next(255), rand->Next(255));
			else
				newColor = Color::Black;
			colorCounter ++;
			this->fractalBitmap->SetPixel(rand->Next(this->Width), rand->Next(this->Height), newColor);
		}
		g->DrawImage(this->fractalBitmap, 0, 0);
#else
		this->SuspendLayout();
		for (int ctr = 0; ctr < 1000; ctr++)
		{
			int x = rand->Next(this->Width);
			int y = rand->Next(this->Height);
#if 0
			System::Drawing::Brush ^ br =
				gcnew System::Drawing::SolidBrush(
				    Color::FromArgb(
					    rand->Next(255), rand->Next(255), rand->Next(255)));
			g->FillRectangle(br, x, y, 1, 1);
#else
			System::Drawing::SolidBrush  br(Color::FromArgb(
			    rand->Next(255), rand->Next(255), rand->Next(255)));
			g->FillRectangle(%br, x, y, 1, 1);
#endif
		}
		this->ResumeLayout(false);
#endif

	}
}
