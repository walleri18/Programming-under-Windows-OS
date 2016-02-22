#include "CalculateFunction.h"

// конструктор по умолчанию
CalculateFunction::CalculateFunction()
{
}

// конструктор с двум¤ параметрами
CalculateFunction::CalculateFunction(function1 releaseFunction, string nameFunction) : nameFunction(nameFunction)
{
	this->releaseFunction1 = releaseFunction;
}

// конструктор с двумя параметрами
CalculateFunction::CalculateFunction(function2 releaseFunction, string nameFunction) : nameFunction(nameFunction)
{
	this->releaseFunction2 = releaseFunction;
}

// деструктор по умолчанию
CalculateFunction::~CalculateFunction()
{
}

// сеттер аргумента
void CalculateFunction::setArgument(double argument1, double argument2)
{
	this->argument1 = argument1;
	this->argument2 = argument2;
}

// вычисление функции
double CalculateFunction::calculation()
{
	return this->releaseFunction1(this->argument1);
}
#include "stdafx.h"