#include <iostream>
#include <locale>
#include <math.h>
#include <string>
#include "Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
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

	Norma *A = new Complex_number(3, 6);
	cout << "Norma A(Complex_number) is " << A->Find_Norm() << endl;
	A->Out();
	cout << "\n\n";

	Norma *B = new Vector(5);
	B->In();
	cout << "\nNorma B(Vector) is " << B->Find_Norm() << endl;
	B->Out();
	cout << "\n\n";

	Norma *C = new Matrix(2, 3);
	C->In();
	cout << "\nNorma C(Matrix) is " << C->Find_Norm() << endl;
	C->Out();

	system("pause");
}