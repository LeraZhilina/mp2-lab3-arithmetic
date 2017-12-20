// ���������� ������� � ������� ��� ���������� �������������� ���������
#pragma once

#include <iostream>
#include "stack.h"

using namespace std;

enum LexemType { NUMBER, OPERATOR, LBRACKET, RBRACKET, VARIABLE, UNKNOWN };

const string AllOperators = "(+-*/)";

struct Lexem
{
	LexemType type; //��� �������
	double Val;//��������
	char Op;//��� ��e������ 

	Lexem();
	Lexem(const char c);
	Lexem(const string& str);
	Lexem(const Lexem &t);// ����������� �����������
	Lexem& operator=(const Lexem &t);// ���������� =
									 //void inpVar();

	bool operator==(const Lexem &t) const
	{
		bool res = false;
		if ((type == t.type) && (Op == t.Op) && (Val == t.Val))
			res = true;
		return res;
	}

	~Lexem() { };
};
// ����������� � double ������� stod(): http://www.cplusplus.com/reference/string/stod/
class arithmetic
{
private:
	Lexem* pLex;                                 //������ ������
	std::string expr;                           //���������
	int nLex;                                  //���-�� ������

	Lexem* polishLex; // �������� ������ � ���� ������� ������
	int nPolishLex; // ����� ������ � �������� ������


public:
	void Divition(); // ������� �������� ������ � ��������� �� �� ������ Lexem, ����� �� ���������� �� ���-��.
	void ConvertToPolish(); // ���� - ������ terms, nTerms; ����� - ������ polishTerms, nPolishTerms
	void Clrspace();							//�������� ��������
	bool Check_symbols() const;					//�������� �� ������������ �������
	bool Check_brackets() const;				//�������� �� ������������ ������
	bool Check_opers() const;					//�������� �� ����������� ��������/��������
	bool Check();
	arithmetic(const string& str);
	~arithmetic() { delete[] pLex; }
	double Result(); // ���������� �� �������� ������. ���� - ������ polishlex, nPolishLex, ����� - double �����
	Lexem* GetLexems() { return pLex; }
	int GetNLex() { return nLex; }

	Lexem* GetPolish() { return polishLex; }
	int GetNPolish() { return nPolishLex; }

	void Minus()
	{
		if (expr[0] == '-')
			expr = "0" + expr;
		for (int i = 1; i < expr.length(); i++)
		{
			if ((expr[i - 1] == '(') && (expr[i] == '-'))
				expr.insert(i, "0");
		}
		delete[] pLex;
		pLex = new Lexem[expr.length()];
	}

};