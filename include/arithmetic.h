// ���������� ������� � ������� ��� ���������� �������������� ���������
#pragma once

#include <iostream>
#include "stack.h"

using namespace std;

enum LexemType { NUMBER, OPERATOR, LBRACKET, RBRACKET, VARIABLE,UNKNOWN };

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
	~arithmetic() { delete[] pLex;}
	double Result(); // ���������� �� �������� ������. ���� - ������ polishlex, nPolishLex, ����� - double �����
	
	
};
