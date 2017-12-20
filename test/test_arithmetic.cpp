// тесты для вычисления арифметических выражений
#include "arithmetic.h"
#include "gtest.h"
#include "sstream"
using namespace std;
TEST(arithmethic, can_divice_expression)
{
	arithmetic expr("7-2*4*(35-4)");
	Lexem cmp[11];
	Lexem* src = expr.GetLexems();
	cmp[0] = Lexem("7");
	cmp[1] = Lexem("-");
	cmp[2] = Lexem("2");
	cmp[3] = Lexem("*");
	cmp[4] = Lexem("4");
	cmp[5] = Lexem("*");
	cmp[6] = Lexem("(");
	cmp[7] = Lexem("35");
	cmp[8] = Lexem("-");
	cmp[9] = Lexem("4");
	cmp[10] = Lexem(")");
	bool res = true;
	for (int i = 0; i < expr.GetNLex(); i++)
		if (cmp != src)
			res = false;

	EXPECT_EQ(true, res);
	ASSERT_NO_THROW(expr = arithmetic(""));
	EXPECT_EQ(0, expr.GetNLex());
}
TEST(arithmetic, can_transform_to_rpn)
{
	arithmetic expr("(71-8)*(4-2)"); //71 8 - 4 2-*
	Lexem src[11];
	expr.ConvertToPolish();
	Lexem cmp[11];
	cmp[0] = Lexem("71");
	cmp[1] = Lexem("8");
	cmp[2] = Lexem("-");
	cmp[3] = Lexem("4");
	cmp[4] = Lexem("2");
	cmp[5] = Lexem("-");
	cmp[6] = Lexem("*");
	bool res = true;
	for (int i = 0; i < 11; i++)
		if (cmp != src)
		{
			res = false;
		}
	EXPECT_EQ(true, res);
}