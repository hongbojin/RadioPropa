#ifndef _CHECK_H
#define _CHECK_H

#include "dint/cvector.h"

void CheckIndex(const int lowerLimit, const int upperLimit, const int i,
		const char* functionName);
void DumpArray(const dCVector* pVector);

#endif