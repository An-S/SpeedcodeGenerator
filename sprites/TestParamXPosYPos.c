#include <stdint.h>

int16_t internal_xpos = -32767;
int16_t internal_ypos = -32767;

void __fastcall__ SetCoordinates(uint8_t ypos, int16_t xpos){
	internal_xpos = xpos;
	internal_ypos = ypos;
}
