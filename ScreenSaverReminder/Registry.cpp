#include "StdAfx.h"

using namespace Microsoft::Win32;

#define DEFAULT_TIMER_VALUE_MINUTES   10
#define DEFAULT_ANNOYSTATE ANNOY_COLORS

#define SW_MANUFACTURER_KEY_NAME "Software\\Phillip F Knaack"
#define SW_PROG_KEY_NAME "ScreenSaverReminder"
#define SW_DEST_TIMERVALUE_KEY_NAME "TimerValue"
#define SW_ANNOYSTATE_KEY_NAME "AnnoyState"

namespace ScreenSaverReminder {

	RegistryKey ^ _RegistryGetKey(void)
	{
		RegistryKey ^ swkey1, ^ swkey2;
		swkey1 = Registry::CurrentUser->OpenSubKey(SW_MANUFACTURER_KEY_NAME,true);
		if (!swkey1)
			swkey1 = Registry::CurrentUser->CreateSubKey(SW_MANUFACTURER_KEY_NAME);
		if (!swkey1)
		{
			MessageBox::Show("Unable to access or create Registry Key!",
				"Initialization Error");
			return nullptr;
		}
		swkey2 = swkey1->OpenSubKey(SW_PROG_KEY_NAME,true);
		if (!swkey2)
			swkey2 = swkey1->CreateSubKey(SW_PROG_KEY_NAME);
		if (!swkey2)
		{
			MessageBox::Show("Unable to access or create Registry Key!",
				"Initialization Error");
			return nullptr;
		}
		return swkey2;
	}

	int RegistryGetTimerValue(void)
	{
		RegistryKey ^ swkey = _RegistryGetKey();
		if (swkey)
		{
			Object ^ value_obj = swkey->GetValue(SW_DEST_TIMERVALUE_KEY_NAME);
			if (value_obj)
			{
				System::String ^ retval = value_obj->ToString();
				return Int32::Parse(retval);
			}
		}
		return DEFAULT_TIMER_VALUE_MINUTES;
	}

	annoyingState_t RegistryGetAnnoyState(void)
	{
		RegistryKey ^ swkey = _RegistryGetKey();
		if (swkey)
		{
			Object ^ value_obj = swkey->GetValue(SW_ANNOYSTATE_KEY_NAME);
			if (value_obj)
			{
				System::String ^ retval = value_obj->ToString();
				Int32 v = Int32::Parse(retval);
				switch (v) {
					case 0:
						return ANNOY_COLORS;
					case 1:
						return SHOW_FRACTALS;
					case 2:
						return SHOW_PIXELS;
					default:
						return DEFAULT_ANNOYSTATE;
				}
			}
		}
		return DEFAULT_ANNOYSTATE;
	}

	void RegistrySetTimerValue(int value)
	{
		RegistryKey ^ swkey = _RegistryGetKey();
		if (swkey)
			swkey->SetValue(SW_DEST_TIMERVALUE_KEY_NAME, value.ToString());
	}

	void RegistrySetAnnoyState(annoyingState_t state)
	{
		RegistryKey ^ swkey = _RegistryGetKey();
		if (swkey)
		{
			int v = 0;
			switch (state) {
				case ANNOY_COLORS:
					v = 0;
					break;
				case SHOW_FRACTALS:
					v = 1;
					break;
				case SHOW_PIXELS:
					v = 2;
					break;
			}
			swkey->SetValue(SW_ANNOYSTATE_KEY_NAME, v.ToString());
		}
	}
};
