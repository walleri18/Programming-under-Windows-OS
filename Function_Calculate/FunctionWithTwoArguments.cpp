#pragma once
#include "FunctionWithTwoArguments.h"

// конструктор с двумя параметрами
FunctionWithTwoArguments::FunctionWithTwoArguments(function2 releaseFunction) : CalculateFunction(releaseFunction)
{
}

double FunctionWithTwoArguments::calculation()
{
	return releaseFunction2(argument1, argument2);
}
#include "stdafx.h"