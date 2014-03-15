#include "StdAfx.h"

using namespace Microsoft::Win32;

#define DEFAULT_TIMER_VALUE_MINUTES   10

#define SW_MANUFACTURER_KEY_NAME "Software\\Phillip F Knaack"
#define SW_PROG_KEY_NAME "ScreenSaverReminder"
#define SW_DEST_TIMERVALUE_KEY_NAME "TimerValue"

namespace ScreenSaverReminder {

	int RegistryGetTimerValue(void)
	{
		String ^ retval = nullptr;
		RegistryKey ^ swkey1, ^ swkey2;
		Object ^ value_obj;

		swkey1 = Registry::CurrentUser->OpenSubKey(SW_MANUFACTURER_KEY_NAME,true);
		if (!swkey1)
			swkey1 = Registry::CurrentUser->CreateSubKey(SW_MANUFACTURER_KEY_NAME);
		if (!swkey1)
		{
			MessageBox::Show("Unable to access or create Registry Key!",
				"Initialization Error");
			return DEFAULT_TIMER_VALUE_MINUTES;
		}
		swkey2 = swkey1->OpenSubKey(SW_PROG_KEY_NAME,true);
		if (!swkey2)
			swkey2 = swkey1->CreateSubKey(SW_PROG_KEY_NAME);
		if (!swkey2)
		{
			MessageBox::Show("Unable to access or create Registry Key!",
				"Initialization Error");
			return DEFAULT_TIMER_VALUE_MINUTES;
		}

		value_obj = swkey2->GetValue(SW_DEST_TIMERVALUE_KEY_NAME);
		if (value_obj)
		{
			retval = value_obj->ToString();
			return Int32::Parse(retval);
		}

		// else
		return DEFAULT_TIMER_VALUE_MINUTES;
	}

	void RegistrySetTimerValue(int value)
	{
		RegistryKey ^ swkey1, ^ swkey2;

		swkey1 = Registry::CurrentUser->OpenSubKey(SW_MANUFACTURER_KEY_NAME,true);
		if (swkey1)
			swkey2 = swkey1->OpenSubKey(SW_PROG_KEY_NAME,true);

		if (!swkey1 || !swkey2)
		{
			MessageBox::Show("Cannot open registry keys during write!",
				"Shutdown error");
			return;
		}

		swkey2->SetValue(SW_DEST_TIMERVALUE_KEY_NAME, value.ToString());
	}

};
