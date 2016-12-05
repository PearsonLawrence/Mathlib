#include "randomfunctions.h"

float randRange(int start, int end)
{
	
    return rand() % (end - start + 1) + start;
}
