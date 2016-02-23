#pragma once
#include "CalculateFunction.h"

// Класс функций с двумя аргументами
class FunctionWithTwoArguments :
	public CalculateFunction
{
// Функции(методы)
public:
	FunctionWithTwoArguments(function2);
	double calculation();// вычисление функции
};

