// реализация пользовательского приложения
#pragma once
#include <iostream>
#include "arithmetic.h"
#include <string>
using namespace std;

int main()
{
	string Exp;
	int p = 1;
	int a;
	cout << "CALCULATE\n";
	cout << "Choose:\n";
	while (p == 1)
	{
		cout << "1.Enter expretion\n";
		cout << "2.Good buy\n";
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
		{
			cout << "I'm listening:\n";
			cin >> Exp;
			arithmetic A(Exp);
			A.Clrspace();
			A.Divition();
			if (A.Check() == true)
			{
				A.ConvertToPolish();
				double res = A.Result();
				cout << '=' << res << endl;
			}
		}
		break;
		case 2: p = 0;
			break;

		}
	}
}