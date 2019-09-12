#include "drv_button_x86.h"
#include <conio.h>

uint8_t buttonIsPressed_x86(void)
{
	return (_getch() == '1') ? 1 : 0;
}
