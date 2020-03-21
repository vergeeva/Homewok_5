#pragma once
#include <iostream>
#include <locale>
#include <math.h>
#include <string>
using namespace std;
//Домашнее задание 5
//
//Тема: Множественное наследование, виртуальные функции и абстрактные классы.
//	Вариант 2.
//	1. Создать абстрактный базовый класс «Норма» с виртуальной функцией вычисления нормы.
//	2. Создать производные классы : «Комплексное число», «Вектор», 
//	«Матрица» на основе double данных.В каждом классе переопределить 
//	функцию вычисления нормы.Норма комплексного числа, это его модуль.Норма вектора, 
//	это квадратный корень из суммы его элементов.Норма матрицы, это наибольшее значение из сумм элементов строк.
//	3. Выполнить проверку для каждого вида производного объекта.
class Norma
{
public:
	virtual double Find_Norm() = 0;
	virtual void Out() = 0;
	virtual int In() = 0;
};

class Complex_number : public Norma
{
private: 
	double a, b; //коэффициенты, а - просто число, б - при мнимой части.
public:
	Complex_number(double a, double b)
	{
		this->a = a;
		this->b = b;
	}
	double Find_Norm()
	{
		return (sqrt(pow(a, 2) + pow(b, 2)));
	}
	void Out()
	{
		cout << "комплексное число: " << a;
		if (b < 0) cout << b << "i" << endl;
		else cout << "+" << b << "i" << endl;
	}
	int In()
	{
		cout << "Введите а:";
		cin >> a;
		cout << "\nВведите b";
		cin >> b;
		return 1;
	}
};

class Vector : public Norma
{
private:
	double *mas;
	int kol;
public:
	Vector(int kol)
	{
		this->kol = kol;
		mas = new double(kol);
	}
	~Vector()
	{
		delete[] mas;
	}

	double Find_Norm()
	{
		double sum = 0;
		for (int i = 0; i < kol; i++)
		{
			sum += mas[i];
		}
		return sqrt(sum); //Предполагая, что сумма не будет меньше нуля
	}
	void Out()
	{
		cout << "элементы вектора: ";
		for (int i = 0; i < kol; i++)
		{
			cout << mas[i] << " ";
		}
	}
	int In()
	{
		cout << "Введите " << kol << " элементов вектора " << endl;
		for (int i = 0; i < kol; i++)
		{
			cout << "Введите " << i << " элемент вектора ";
			cin >> mas[i];
		}
		return 1;
	}
};

class Matrix : public Norma
{
private:
	int n, m;
	double **mas;
public:
	Matrix(int n, int m)
	{
		this->n = n;
		this->m = m;
		mas = new double *[n];
		for (int i = 0; i < n; i++)
		{
			mas[i] = new double[m];
		}
	}
	double Find_Norm()
	{
		double *mas_sum = new double[n]; //создаем массив сумм строк матриц
		for (int i = 0; i < n; i++)//обнуляем все элементы, чтобы не складывать мусор с числами
		{
			mas_sum[i] = 0;
		}
		for (int i = 0; i < n; i++) //считаем построчные суммы
		{
			for (int j = 0; j < m; j++)
			{
				mas_sum[i] += mas[i][j];
			}
		}
		double max = mas_sum[0];
		for (int i = 1; i < n; i++) //Ищем наибольший элемент массива построчных сумм
		{
			if (mas_sum[i] > max) max = mas_sum[i];
		}
		delete[] mas_sum;//очищаем память, которую заняли

		return max; //возвращаем наибольшую сумму в строке
		
	}
	void Out()
	{
		cout << " Matrix is " << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
	}
	int In()
	{
		cout << "Введите значения матрицы:";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mas[i][j];
			}
		}
		return 1;
	}
};