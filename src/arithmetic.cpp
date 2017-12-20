// ðåàëèçàöèÿ ôóíêöèé è êëàññîâ äëÿ âû÷èñëåíèÿ àðèôìåòè÷åñêèõ âûðàæåíèé
#include <iostream>
#include "arithmetic.h"
#include <string>

Lexem::Lexem()
{
	type = UNKNOWN;
	Val = 0;
}/*-------------------------------------------------------------------------*/

Lexem::Lexem(const char c)
{
	switch (c)
	{
	case '(':
	{
		type = LBRACKET;
		Val = 0;
		Op = '0';
		break;
	}
	case ')':
	{
		type = RBRACKET;
		Val = 0;
		Op = '0';
		break;
	}
	case '+':
	{
		type = OPERATOR;;
		Val = 1;
		Op = '+';
		break;
	}
	case '-':
	{
		type = OPERATOR;;
		Val = 1;
		Op = '-';
		break;
	}
	case '*':
	{
		type = OPERATOR;;
		Val = 2;
		Op = '*';
		break;
	}
	case '/':
	{
		type = OPERATOR;;
		Val = 2;
		Op = '/';
		break;
	}
	default: type = UNKNOWN;
		break;

	}

}

/*-------------------------------------------------------------------------*/

Lexem::Lexem(const string& str)
{
	Val = stod(str);
	type = NUMBER;
	Op = '0';
}/*-------------------------------------------------------------------------*/

Lexem::Lexem(const Lexem &t)
{
	Val = t.Val;
	type = t.type;
	Op = t.Op;
}/*-------------------------------------------------------------------------*/

Lexem& Lexem::operator=(const Lexem &t)
{
	Val = t.Val;
	type = t.type;
	Op = t.Op;
	return *this;
}/*-------------------------------------------------------------------------*/
 /*void Lexem::inpVar()
 {
 cout << "Input VARIABLE " << Op << " : ";
 cin >> Val;
 cout << endl;
 }*/


arithmetic::arithmetic(const string& str)
{
	pLex = new Lexem[str.length()];
	expr = str;
	nLex = 0;
}/*-------------------------------------------------------------------------*/

void arithmetic::Divition()
{
	for (int i = 0; i < expr.length(); i++)
	{
		char c = expr[i];
		if ((c == '*') || (c == '/') || (c == '+') || (c == '-') || (c == ')') || (c == '('))
		{
			Lexem OPER(c);
			pLex[nLex] = OPER;
			nLex++;
		}
		else
			if (isdigit(c))
			{
				string Num;
				int j = i;
				int t = expr.length();
				while ((j < t) && ((isdigit(expr[j])) || expr[j] == '.'))
				{
					j++;
				}
				Num = expr.substr(i, j - i);
				pLex[nLex] = Lexem(Num);
				nLex++;
				i = j - 1;
			}
			else
				if (c >= 97 && c <= 122 || c >= 65 && c <= 90)
				{
					pLex[nLex] = Lexem(c);
					nLex++;
				}
				else
					if (c != ' ')
					{
						pLex[nLex].type = UNKNOWN;
						nLex++;
					}

	}
}/*-------------------------------------------------------------------------*/

void arithmetic::Clrspace()
{
	unsigned int i = 0;
	while (i <= expr.length())
	{
		if (expr[i] == ' ')
			expr.erase(i, 1);
		else i++;
	}
}/*-------------------------------------------------------------------------*/


void arithmetic::ConvertToPolish()
{
	TStack<Lexem> st;
	polishLex = new Lexem[nLex];
	int j = 0;

	for (int i = 0; i < nLex; i++)
	{

		if (pLex[i].type == NUMBER || pLex[i].type == VARIABLE)
			polishLex[j++] = pLex[i];

		if (pLex[i].type == LBRACKET)
			st.Push(pLex[i]);

		if (pLex[i].type == RBRACKET)
		{
			while (st.Peek().type != LBRACKET)
				polishLex[j++] = st.Pop();
			st.Pop();
		}


		if (pLex[i].type == OPERATOR)
		{
			if (st.IsEmpty())
			{
				st.Push(pLex[i]);
			}
			else
			{
				Lexem t = st.Peek();
				while (!st.IsEmpty() && t.Val >= pLex[i].Val)
				{
					t = st.Pop();
					polishLex[j++] = t;
					if(!st.IsEmpty())
					 t = st.Peek();
				}
				st.Push(pLex[i]);
			}
		}

	}


	while (!st.IsEmpty())
	{
		Lexem t = st.Pop();
		polishLex[j++] = t;
	}
	nPolishLex = j;
}/*-------------------------------------------------------------------------*/

bool arithmetic::Check_symbols() const
{
	bool res = true;

	for (int i = 0; i < nLex; i++)
	{
		if (pLex[i].type == UNKNOWN)
		{
			cout << "  " << "UNKNOWN symbol" << endl;
			res = false;
		}
		if ((pLex[i].type == VARIABLE) && (pLex[i + 1].type == VARIABLE))
		{
			cout << "UNKNOWN SYMBOL in " << i << endl;
			res = false;
		}
	}
	return res;
}/*-------------------------------------------------------------------------*/

bool arithmetic::Check_opers() const
{
	bool res = true;
	LexemType cur = pLex[0].type;
	LexemType next = cur;

	for (int i = 0; i<(nLex - 1); i++)
	{
		next = pLex[i + 1].type;
		if ((cur == NUMBER || cur == VARIABLE) && (next == NUMBER || next == VARIABLE || next == LBRACKET))
		{
			cout << "\n" << "Operations error" << endl;
			res = false;
		}

		if (cur == OPERATOR && (next == OPERATOR || next == RBRACKET))
		{
			cout << "\n" << "Operations error" << endl;
			res = false;
		}
		if (cur == RBRACKET && (next != OPERATOR && next != RBRACKET))
		{
			cout << "\n" << "Operations error" << endl;
			res = false;
		}
		if (cur == LBRACKET && ((pLex[i + 1].type != NUMBER) || (pLex[i + 1].type !=RBRACKET) || pLex[i + 1].Op != '-'))
		{
			cout << "  " << "Operations error" << endl;
			return false;
		}
		cur = next;
	}
	if (next == LBRACKET || next == OPERATOR)
	{
		cout << "\n" << "Operations error" << endl;
		res = false;
	}
	if (pLex[0].type != NUMBER &&  pLex[0].type != VARIABLE  &&  pLex[0].type != LBRACKET   &&    pLex[0].Val != 2)
	{
		cout << "\n" << "Operations error" << endl;
		res = false;
	}
	return res;
}/*-------------------------------------------------------------------------*/

bool arithmetic::Check_brackets() const
{
	bool res = true;
	int p = 0;
	for (int i = 0; i < nLex; i++)
	{
		if (pLex[i].type == LBRACKET)
			p++;

		if (pLex[i].type == RBRACKET)
			p--;
	}

	if (p != 0)
	{
		cout << "\n" << "Brackets error" << endl;
		res = false;
	}
	return res;
}/*-------------------------------------------------------------------------*/

bool arithmetic::Check()
{
	bool res;
	if (expr.length() > 0)
	{
		bool sim, op, br;

		sim = Check_symbols();
		op = Check_opers();
		br = Check_brackets();
		res = (sim && op && br);
	}
	else
	{
		cout << "This string is empty";
		res = false;
	}
	return res;
}/*-------------------------------------------------------------------------*/


double arithmetic::Result()
{
	TStack<double> st;
	double res = 0;


	for (int i = 0; i < nPolishLex; i++)
	{

		if (polishLex[i].type == NUMBER)
		{
			st.Push(polishLex[i].Val);

		}
		if (polishLex[i].type == OPERATOR)
		{
			double l = st.Pop();
			double r = st.Pop();

			switch (polishLex[i].Op)
			{
			case '+':
				res = l + r;
				break;
			case '-':
				res = r - l;
				break;
			case '*':
				res = l * r;
				break;
			case '/':
				res = l / r;
				break;
			}
			st.Push(res);
		}
	}
	return st.Pop();

}/*-------------------------------------------------------------------------*/