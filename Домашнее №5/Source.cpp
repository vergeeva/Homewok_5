#include <iostream>
#include <locale>
#include <math.h>
#include <string>
#include "Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
//�������� ������� 5
//
//����: ������������� ������������, ����������� ������� � ����������� ������.
//	������� 2.
//	1. ������� ����������� ������� ����� ������ � ����������� �������� ���������� �����.
//	2. ������� ����������� ������ : ������������ �����, �������, 
//	�������� �� ������ double ������.� ������ ������ �������������� 
//	������� ���������� �����.����� ������������ �����, ��� ��� ������.����� �������, 
//	��� ���������� ������ �� ����� ��� ���������.����� �������, ��� ���������� �������� �� ���� ��������� �����.
//	3. ��������� �������� ��� ������� ���� ������������ �������.

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