#include "FunctionWithTwoArguments.h"

// конструктор по умолчанию
FunctionWithTwoArguments::FunctionWithTwoArguments()
{
}

// конструктор с двумя параметрами
FunctionWithTwoArguments::FunctionWithTwoArguments(function2 releaseFunction, string nameFunction) : CalculateFunction(releaseFunction, nameFunction)
{
}

FunctionWithTwoArguments::~FunctionWithTwoArguments()
{
}

double FunctionWithTwoArguments::calculation()
{
	return releaseFunction2(argument1, argument2);
}
#include "stdafx.h"