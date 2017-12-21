// тесты для вычисления арифметических выражений
#include "arithmetic.h"
#include "gtest.h"
#include "sstream"
using namespace std;
TEST(arithmethic, can_divice_expression_1)
{
	arithmetic expr("2+3");
	expr.Divition();
	Lexem cmp[11];
	Lexem* src = expr.GetLexems();
	cmp[0] = Lexem("2");
	cmp[1] = Lexem('+');
	cmp[2] = Lexem("3");
	EXPECT_EQ(cmp[0], src[0]);
	EXPECT_EQ(cmp[1], src[1]);
	EXPECT_EQ(cmp[2], src[2]);
}

TEST(arithmethic, can_convert_to_polish_1)
{
	arithmetic expr("2+3");
	expr.Divition();
	expr.ConvertToPolish();
	Lexem* src = expr.GetPolish();
	Lexem cmp[3];
	cmp[0] = Lexem("2");
	cmp[1] = Lexem("3");
	cmp[2] = Lexem('+');

	EXPECT_EQ(cmp[0], src[0]);
	EXPECT_EQ(cmp[1], src[1]);
	EXPECT_EQ(cmp[2], src[2]);
}


TEST(arithmethic, can_devide_expression_2)
{
	arithmetic expr("-85+12+(-2.2/^)");
	Lexem cmp[11];
	Lexem* p = expr.GetLexems();
	cmp[0] = Lexem('-');
	cmp[1] = Lexem("85");
	cmp[2] = Lexem ('+');
	cmp[3] = Lexem("12");
	cmp[4] = Lexem('+');
	cmp[5] = Lexem('(');
	cmp[6] = Lexem('-');
	cmp[7] = Lexem("2.2");
	cmp[8] = Lexem('/');
	cmp[9] = Lexem('^');
	cmp[10] = Lexem(')');
	bool res = true;
	for (int i = 0; i < expr.GetNLex(); i++)
		if (cmp[i] != p[i])
			res = false;
	EXPECT_EQ(true, res);
}

TEST(arithmethic, can_convert_to_polish_2)
{
	arithmetic expr("7.1+(6*8-(45-3*2)/2)"); //7.1 6 8 * 45 3 2 * - 2 / - +
	Lexem cmp[13];
	expr.Divition();
	expr.ConvertToPolish();
	Lexem* p = expr.GetPolish();
	cmp[0] = Lexem("7.1");
	cmp[1] = Lexem("6");
	cmp[2] = Lexem("8");
	cmp[3] = Lexem('*');
	cmp[4] = Lexem("45");
	cmp[5] = Lexem("3");
	cmp[6] = Lexem("2");
	cmp[7] = Lexem('*');
	cmp[8] = Lexem('-');
	cmp[9] = Lexem("2");
	cmp[10] = Lexem('/');
	cmp[11] = Lexem('-');
	cmp[12] = Lexem('+');
	bool res = true;
	for (int i = 0; i < expr.GetNPolish(); i++)
		if (cmp[i] != p[i])
			res = false;
	EXPECT_EQ(true, res);
}
TEST(arithmethic, can_devide_expression_with_minus_3)
{
	arithmetic expr("-1+(48/2.1-4)");
	Lexem cmp[11];
	expr.Minus();
	Lexem* p = expr.GetLexems();
	cmp[0] = Lexem("0");
	cmp[1] = Lexem('-');
	cmp[2] = Lexem("1");
	cmp[3] = Lexem('+');
	cmp[4] = Lexem('(');
	cmp[5] = Lexem("48");
	cmp[6] = Lexem('/');
	cmp[7] = Lexem("2.1");
	cmp[8] = Lexem('-');
	cmp[9] = Lexem("4");
	cmp[10] = Lexem(')');
	bool res = true;
	for (int i = 0; i < expr.GetNLex(); i++)
		if (cmp[i] != p[i])
			res = false;
	EXPECT_EQ(true, res);
}

TEST(arithmethic, can_convert_to_polish__whit_minus_3)
{
	arithmetic expr("-92.58*(145+21*(3.0406-21.24))"); //0 92.58 145 21 3.0406 21.24 - * + * -
	Lexem cmp[13];
	expr.Minus();
	expr.Divition();
	expr.ConvertToPolish();
	Lexem* p = expr.GetPolish();
	cmp[0] = Lexem("0");
	cmp[1] = Lexem("92.58");
	cmp[2] = Lexem("145");
	cmp[3] = Lexem("21");
	cmp[4] = Lexem("3.0406");
	cmp[5] = Lexem("21.24");
	cmp[6] = Lexem('-');
	cmp[7] = Lexem('*');
	cmp[8] = Lexem('+');
	cmp[9] = Lexem('*');
	cmp[10] = Lexem('-');
	bool res = true;
	for (int i = 0; i < expr.GetNPolish(); i++)
		if (cmp[i] != p[i])
			res = false;
	EXPECT_EQ(true, res);
}
TEST(arithmethic, can_devide_expression_with_minus_4)
{
	arithmetic expr("(8741 - 1478)*((-1) * (0.8741 + 0.1478))"); 
	Lexem cmp[20];
	expr.Minus();
	expr.Divition();
	Lexem* p = expr.GetLexems();
	cmp[0] = Lexem('(');
	cmp[1] = Lexem("8741");
	cmp[2] = Lexem('-');
	cmp[3] = Lexem("1478");
	cmp[4] = Lexem(')');
	cmp[5] = Lexem('*');
	cmp[6] = Lexem('(');
	cmp[7] = Lexem('(');
	cmp[8] = Lexem("0");
	cmp[9] = Lexem('-');
	cmp[10] = Lexem("1");
	cmp[11] = Lexem(')');
	cmp[12] = Lexem('*');
	cmp[13] = Lexem('(');
	cmp[14] = Lexem("0.8741");
	cmp[15] = Lexem('+');
	cmp[16] = Lexem("0.1478");
	cmp[17] = Lexem(')');
	cmp[18] = Lexem(')');
	bool res = true;
	for (int i = 0; i < expr.GetNLex(); i++)
		if (cmp[i] != p[i])
			res = false;
	EXPECT_EQ(true, res);
}
