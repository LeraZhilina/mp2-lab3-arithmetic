// объявление функций и классов для вычисления арифметических выражений
#pragma once

#include <iostream>
#include "stack.h"

using namespace std;

enum LexemType { NUMBER, OPERATOR, LBRACKET, RBRACKET, VARIABLE,UNKNOWN };

const string AllOperators = "(+-*/)";

struct Lexem
{
	LexemType type; //имя объекта
	double Val;//значение
	char Op;//для опeратора 

	Lexem();
	Lexem(const char c);
	Lexem(const string& str);
	Lexem(const Lexem &t);// конструктор копирования
	Lexem& operator=(const Lexem &t);// перегрузка =
	//void inpVar();
	~Lexem() { };
};
// конвертация в double функция stod(): http://www.cplusplus.com/reference/string/stod/
class arithmetic
{
private:
	Lexem* pLex;                                 //массив лексем
	std::string expr;                           //выражение
	int nLex;                                  //кол-во лексем

	Lexem* polishLex; // польская запись в виде массива термов
	int nPolishLex; // число термов в польской записи

	
	public:
	void Divition(); // обходим входнуюю строку и разбиваем ее на массив Lexem, здесь же определяем их кол-во.
	void ConvertToPolish(); // вход - массив terms, nTerms; выход - массив polishTerms, nPolishTerms
	void Clrspace();							//Удаление пробелов
	bool Check_symbols() const;					//Проверка на недопустимые символы
	bool Check_brackets() const;				//Проверка на соответствие скобок
	bool Check_opers() const;					//Проверка на пропущенные операции/операнды
	bool Check();
	arithmetic(const string& str);
	~arithmetic() { delete[] pLex;}
	double Result(); // вычисление по польской записи. Вход - массив polishlex, nPolishLex, выход - double ответ
	
	
};
