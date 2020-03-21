#pragma once
#include <iostream>
#include <locale>
#include <math.h>
#include <string>
using namespace std;
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
	double a, b; //������������, � - ������ �����, � - ��� ������ �����.
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
		cout << "����������� �����: " << a;
		if (b < 0) cout << b << "i" << endl;
		else cout << "+" << b << "i" << endl;
	}
	int In()
	{
		cout << "������� �:";
		cin >> a;
		cout << "\n������� b";
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
		return sqrt(sum); //�����������, ��� ����� �� ����� ������ ����
	}
	void Out()
	{
		cout << "�������� �������: ";
		for (int i = 0; i < kol; i++)
		{
			cout << mas[i] << " ";
		}
	}
	int In()
	{
		cout << "������� " << kol << " ��������� ������� " << endl;
		for (int i = 0; i < kol; i++)
		{
			cout << "������� " << i << " ������� ������� ";
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
		double *mas_sum = new double[n]; //������� ������ ���� ����� ������
		for (int i = 0; i < n; i++)//�������� ��� ��������, ����� �� ���������� ����� � �������
		{
			mas_sum[i] = 0;
		}
		for (int i = 0; i < n; i++) //������� ���������� �����
		{
			for (int j = 0; j < m; j++)
			{
				mas_sum[i] += mas[i][j];
			}
		}
		double max = mas_sum[0];
		for (int i = 1; i < n; i++) //���� ���������� ������� ������� ���������� ����
		{
			if (mas_sum[i] > max) max = mas_sum[i];
		}
		delete[] mas_sum;//������� ������, ������� ������

		return max; //���������� ���������� ����� � ������
		
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
		cout << "������� �������� �������:";
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