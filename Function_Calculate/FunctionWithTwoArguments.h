#pragma once
#include "CalculateFunction.h"

// Класс функций с двумя аргументами
class FunctionWithTwoArguments :
	public CalculateFunction
{
// Функции(методы)
public:
	FunctionWithTwoArguments();// конструктор по умолчанию
	FunctionWithTwoArguments(function2, string);// конструктор с двумя параметрами
	~FunctionWithTwoArguments();// деструктор по умолчанию
	void setArgument(double, double);// сеттер аргументов
	double calculation();// вычисление функции
};

