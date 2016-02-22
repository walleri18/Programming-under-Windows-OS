#include "FunctionWithOneArgument.h"

// конструктор по умолчанию
FunctionWithOneArgument::FunctionWithOneArgument()
{
}

// конструктор с двумя параметрами
FunctionWithOneArgument::FunctionWithOneArgument(function1 releaseFunction, string nameFunction) : CalculateFunction(releaseFunction, nameFunction)
{
}

FunctionWithOneArgument::~FunctionWithOneArgument()
{
}
#include "stdafx.h"