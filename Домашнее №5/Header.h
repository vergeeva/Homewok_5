#pragma once
#include <iostream>
#include <locale>
#include <math.h>
#include <string>
using namespace std;
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
	double a, b; //êîýôôèöèåíòû, à - ïðîñòî ÷èñëî, á - ïðè ìíèìîé ÷àñòè.
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
		cout << "êîìïëåêñíîå ÷èñëî: " << a;
		if (b < 0) cout << b << "i" << endl;
		else cout << "+" << b << "i" << endl;
	}
	int In()
	{
		cout << "Ââåäèòå à:";
		cin >> a;
		cout << "\nÂâåäèòå b";
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
		return sqrt(sum); //Ïðåäïîëàãàÿ, ÷òî ñóììà íå áóäåò ìåíüøå íóëÿ
	}
	void Out()
	{
		cout << "ýëåìåíòû âåêòîðà: ";
		for (int i = 0; i < kol; i++)
		{
			cout << mas[i] << " ";
		}
	}
	int In()
	{
		cout << "Ââåäèòå " << kol << " ýëåìåíòîâ âåêòîðà " << endl;
		for (int i = 0; i < kol; i++)
		{
			cout << "Ââåäèòå " << i << " ýëåìåíò âåêòîðà ";
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
		double *mas_sum = new double[n]; //ñîçäàåì ìàññèâ ñóìì ñòðîê ìàòðèö
		for (int i = 0; i < n; i++)//îáíóëÿåì âñå ýëåìåíòû, ÷òîáû íå ñêëàäûâàòü ìóñîð ñ ÷èñëàìè
		{
			mas_sum[i] = 0;
		}
		for (int i = 0; i < n; i++) //ñ÷èòàåì ïîñòðî÷íûå ñóììû
		{
			for (int j = 0; j < m; j++)
			{
				mas_sum[i] += mas[i][j];
			}
		}
		double max = mas_sum[0];
		for (int i = 1; i < n; i++) //Èùåì íàèáîëüøèé ýëåìåíò ìàññèâà ïîñòðî÷íûõ ñóìì
		{
			if (mas_sum[i] > max) max = mas_sum[i];
		}
		delete[] mas_sum;//î÷èùàåì ïàìÿòü, êîòîðóþ çàíÿëè

		return max; //âîçâðàùàåì íàèáîëüøóþ ñóììó â ñòðîêå
		
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
		cout << "Ââåäèòå çíà÷åíèÿ ìàòðèöû:";
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
