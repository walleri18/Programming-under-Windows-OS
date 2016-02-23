#pragma once
#include "FunctionWithOneArgument.h"
#include "FunctionWithTwoArguments.h"

enum {
	ACOS, ASIN, ATAN, ATAN2, CEIL, COS, COSH, EXP, FABS, FLOOR, FMOD, LOG, LOG10, POW, SIN, SINH, SQRT, TAN, TANH
};

struct Function
{
	CalculateFunction::function1 releaseFunction1;// указатель на функцию первого типа с одним аргументом
	CalculateFunction::function2 releaseFunction2;// указатель на функцию второго типа с двумя аргументами
	
} function[] = 
{
	{ acos, NULL },
	{ asin, NULL },
	{ atan, NULL },
	{ NULL, atan2 },
	{ ceil, NULL },
	{ cos, NULL },
	{ cosh, NULL },
	{ exp, NULL },
	{ fabs, NULL },
	{ floor, NULL },
	{ NULL, fmod },
	{ log, NULL },
	{ log10, NULL },
	{ NULL, pow },
	{ sin, NULL },
	{ sinh, NULL },
	{ sqrt, NULL },
	{ tan, NULL },
	{ tanh, NULL },
};