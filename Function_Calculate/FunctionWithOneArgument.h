#pragma once
#include "CalculateFunction.h"

//  Класс функций с одним аргументом
class FunctionWithOneArgument :
	public CalculateFunction
{
// Функции(методы)
public:
	FunctionWithOneArgument();// конструктор по умолчанию
	FunctionWithOneArgument(function1, string);// конструктор с двумя параметрами
	~FunctionWithOneArgument();// деструктор по умолчанию
};

