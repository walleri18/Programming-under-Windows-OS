#pragma once
#include "FunctionWithOneArgument.h"
#include "FunctionWithTwoArguments.h"

enum {
	ACOS, ASIN, ATAN, ATAN2, CEIL, COS, COSH, EXP, FABS, FLOOR, FMOD, LOG, LOG10, POW, SIN, SINH, SQRT, TAN, TANH
};

struct Function
{
	string name;// имя функции
	CalculateFunction::function1 releaseFunction1;// указатель на функцию первого типа с одним аргументом
	CalculateFunction::function2 releaseFunction2;// указатель на функцию второго типа с двумя аргументами
	
} function[20] = 
{
	{ "acos", acos, NULL },
	{ "asin", asin, NULL },
	{ "atan", atan, NULL },
	{ "atan2", NULL, atan2 },
	{ "ceil", ceil, NULL },
	{ "cos", cos, NULL },
	{ "cosh", cosh, NULL },
	{ "exp", exp, NULL },
	{ "fabs", fabs, NULL },
	{ "floor", floor, NULL },
	{ "fmod", NULL, fmod },
	{ "log", log, NULL },
	{ "log10", log10, NULL },
	{ "pow", NULL, pow },
	{ "sin", sin, NULL },
	{ "sinh", sinh, NULL },
	{ "sqrt", sqrt, NULL },
	{ "tan", tan, NULL },
	{ "tanh", tanh, NULL },
};