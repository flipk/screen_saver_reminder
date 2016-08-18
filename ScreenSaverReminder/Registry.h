#pragma once

#include "Form1.h"

namespace ScreenSaverReminder {

	typedef enum { ANNOY_COLORS, SHOW_FRACTALS, SHOW_PIXELS } annoyingState_t;

	int RegistryGetTimerValue(void);
	annoyingState_t RegistryGetAnnoyState(void);
	void RegistrySetTimerValue(int value);
	void RegistrySetAnnoyState(annoyingState_t state);

};
