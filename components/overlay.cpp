#include "overlay.h"
 
void drawoverlay(unsigned font, int health, int ultcharge, int kills, int boss)
{
	char buffer[64] = { 0 };
	
	char buffer1[64] = { 0 };

	char buffer2[64] = { 0 };
	char buffer3[64] = { 0 };
	char buffer4[64] = { 0 };
	sprintf_s(buffer, "Score: %d", kills);
	sfw::drawString(font, buffer, 100, 850, 20, 20);

	sprintf_s(buffer1, "health: %d / 100", health);
	sfw::drawString(font, buffer1, 1200, 850, 20, 20);

	if (ultcharge >= 30 && ultcharge < 45)
	{
		sprintf_s(buffer2, "Ultimate level 1 ready");
		sfw::drawString(font, buffer2, 550, 850, 20, 20,0,0, MAGENTA);
	}
	if (ultcharge >= 45 && ultcharge < 60)
	{
		sprintf_s(buffer3, "Ultimate level 2 ready");
		sfw::drawString(font, buffer3, 550, 850, 20, 20, 0,0,GREEN);
	}
	if (ultcharge >= 60)
	{
		sprintf_s(buffer4, "Ultimate level 3 ready");
		sfw::drawString(font, buffer4, 550, 850, 20, 20, 0,0,RED);
	}


}
