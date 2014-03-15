#pragma once

#include "AboutForm.h"
#include "Registry.h"

namespace ScreenSaverReminder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			int v = RegistryGetTimerValue(); // minutes
			this->reminderDurationBox->Value = v;
			this->resetTimerValue = this->currentTimerValue = v * 120;
			updateNotifyText(v);
			lastMovementTick = 0;
			System::Reflection::Assembly ^ ass = System::Reflection::Assembly::GetExecutingAssembly();
//		array<String^>^ names = ass->GetManifestResourceNames();
			String^ pxResName = ass->GetName()->Name + ".ssrResources";
			System::Resources::ResourceManager ^mgr =
				gcnew System::Resources::ResourceManager(pxResName, ass);

			this->ico0 = cli::safe_cast<System::Drawing::Icon^>(mgr->GetObject("Icon0"));
			this->ico1 = cli::safe_cast<System::Drawing::Icon^>(mgr->GetObject("Icon1"));
			this->ico2 = cli::safe_cast<System::Drawing::Icon^>(mgr->GetObject("Icon2"));
			this->ico3 = cli::safe_cast<System::Drawing::Icon^>(mgr->GetObject("Icon3"));
			this->ico4 = cli::safe_cast<System::Drawing::Icon^>(mgr->GetObject("Icon4"));
			this->ico5 = cli::safe_cast<System::Drawing::Icon^>(mgr->GetObject("Icon5"));
			this->ico6 = cli::safe_cast<System::Drawing::Icon^>(mgr->GetObject("Icon6"));
			this->ico7 = cli::safe_cast<System::Drawing::Icon^>(mgr->GetObject("Icon7"));
			this->ico8 = cli::safe_cast<System::Drawing::Icon^>(mgr->GetObject("Icon8"));

			aboutForm = gcnew AboutForm;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int currentTimerValue;
		int resetTimerValue;
		int lastMovementTick;
		System::Drawing::Icon^ ico0;
		System::Drawing::Icon^ ico1;
		System::Drawing::Icon^ ico2;
		System::Drawing::Icon^ ico3;
		System::Drawing::Icon^ ico4;
		System::Drawing::Icon^ ico5;
		System::Drawing::Icon^ ico6;
		System::Drawing::Icon^ ico7;
		AboutForm ^aboutForm;

	private: System::Windows::Forms::Button^  aboutButton;

			 System::Drawing::Icon^ ico8;
		System::Void updateNotifyIcon(void);
		System::Void updateNotifyText(int minutes);

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::Button^  hideButton1;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::NumericUpDown^  reminderDurationBox;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->hideButton1 = (gcnew System::Windows::Forms::Button());
			this->reminderDurationBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->aboutButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->reminderDurationBox))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Reminder Duration (minutes)";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timerTicked);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"Screen Saver Reminder";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->Click += gcnew System::EventHandler(this, &Form1::notifyIconClicked);
			// 
			// hideButton1
			// 
			this->hideButton1->Location = System::Drawing::Point(94, 52);
			this->hideButton1->Name = L"hideButton1";
			this->hideButton1->Size = System::Drawing::Size(75, 23);
			this->hideButton1->TabIndex = 3;
			this->hideButton1->Text = L"Hide";
			this->hideButton1->UseVisualStyleBackColor = true;
			this->hideButton1->Click += gcnew System::EventHandler(this, &Form1::hideButtonClicked);
			// 
			// reminderDurationBox
			// 
			this->reminderDurationBox->Location = System::Drawing::Point(179, 14);
			this->reminderDurationBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {60, 0, 0, 0});
			this->reminderDurationBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->reminderDurationBox->Name = L"reminderDurationBox";
			this->reminderDurationBox->Size = System::Drawing::Size(61, 20);
			this->reminderDurationBox->TabIndex = 2;
			this->reminderDurationBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->reminderDurationBox->ThousandsSeparator = true;
			this->reminderDurationBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->reminderDurationBox->ValueChanged += gcnew System::EventHandler(this, &Form1::reminderDurationChanged);
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(175, 52);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(75, 23);
			this->exitButton->TabIndex = 4;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &Form1::exitButtonClicked);
			// 
			// aboutButton
			// 
			this->aboutButton->Location = System::Drawing::Point(13, 52);
			this->aboutButton->Name = L"aboutButton";
			this->aboutButton->Size = System::Drawing::Size(75, 23);
			this->aboutButton->TabIndex = 5;
			this->aboutButton->Text = L"About";
			this->aboutButton->UseVisualStyleBackColor = true;
			this->aboutButton->Click += gcnew System::EventHandler(this, &Form1::aboutButtonClicked);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(260, 90);
			this->ControlBox = false;
			this->Controls->Add(this->aboutButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->reminderDurationBox);
			this->Controls->Add(this->hideButton1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->ShowInTaskbar = false;
			this->Text = L"Screen Saver Reminder";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->reminderDurationBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void notifyIconClicked(System::Object^  sender, System::EventArgs^  e);
private: System::Void hideButtonClicked(System::Object^  sender, System::EventArgs^  e);
private: System::Void reminderDurationChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void exitButtonClicked(System::Object^  sender, System::EventArgs^  e);
private: System::Void timerTicked(System::Object^  sender, System::EventArgs^  e);
private: System::Void aboutButtonClicked(System::Object^  sender, System::EventArgs^  e);
};
}
