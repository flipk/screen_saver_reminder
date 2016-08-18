#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Registry.h"

namespace ScreenSaverReminder {

	/// <summary>
	/// Summary for AnnoyingForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AnnoyingForm : public System::Windows::Forms::Form
	{
	public:
		AnnoyingForm(void)
		{
			InitializeComponent();
			colorCounter = 0;
			rand = gcnew System::Random;
		}
	public: 

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AnnoyingForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		annoyingState_t state;
		int colorCounter;
		System::Drawing::Bitmap  ^fractalBitmap;
		System::Random ^rand;




		System::ComponentModel::IContainer^  components;
		System::Windows::Forms::Timer^  fractalTimer;




		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->fractalTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// fractalTimer
			// 
			this->fractalTimer->Interval = 10;
			this->fractalTimer->Tick += gcnew System::EventHandler(this, &AnnoyingForm::fractalTimer_Tick);
			// 
			// AnnoyingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(465, 403);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AnnoyingForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"PFK Screen Saver Reminder -- YOUR SCREEN SAVER IS ABOUT TO ACTIVATE";
			this->TopMost = true;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);

		}
#pragma endregion

public:
	System::Void start(void);
	System::Void stop(void);
	System::Void setAnnoyingState(annoyingState_t _state) {
		state = _state;
	}
private:
	System::Void fractalTimer_Tick(System::Object^  sender, System::EventArgs^  e);
	};
}
