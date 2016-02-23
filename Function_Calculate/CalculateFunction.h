#pragma once
#include <cmath>

using namespace std;

// Абстрактный общий класс для функций
class CalculateFunction
{
// Данные
public:
	typedef double (*function1) (double);
	typedef double (*function2) (double, double);
protected:	
	double argument1;// аргумент номер 1
	double argument2;// аргумент номер 2

	function1 releaseFunction1;// указатель на функцию
	function2 releaseFunction2;// указатель на функцию
	
// Функции(методы)
public:
	CalculateFunction();// конструктор по умолчанию
	CalculateFunction(function1);
	CalculateFunction(function2);
	virtual ~CalculateFunction();// деструктор по умолчанию
	virtual void setArgument(double, double);// сеттер аргумента
	virtual double calculation();// вычисление функции
};

