// тесты для вычисления арифметических выражений
#include "arithmetic.h"
#include "gtest.h"
#include "sstream"
using namespace std;
TEST(arithmethic, can_divice_expression)
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

	//bool res = true;
	//for (int i = 0; i < expr.GetNLex(); i++)
	//	if (cmp != src)
	//		res = false;

//	EXPECT_EQ(true, res);
}

TEST(arithmethic, can_divice_expression2)
{
	arithmetic expr("2+3");
	expr.Divition();
	expr.ConvertToPolish();
	Lexem* src = expr.GetPolish();
	int k = expr.GetNPolish();
	Lexem cmp[3];
	cmp[0] = Lexem("2");
	cmp[1] = Lexem("3");
	cmp[2] = Lexem('+');

	EXPECT_EQ(cmp[0], src[0]);
	EXPECT_EQ(cmp[1], src[1]);
	EXPECT_EQ(cmp[2], src[2]);
}

//TEST(arithmetic, can_transform_to_rpn)
//{
//	arithmetic expr("(71-8)*(4-2)"); //71 8 - 4 2-*
//	Lexem src[11];
//	expr.ConvertToPolish();
//	Lexem cmp[11];
//	cmp[0] = Lexem("71");
//	cmp[1] = Lexem("8");
//	cmp[2] = Lexem("-");
//	cmp[3] = Lexem("4");
//	cmp[4] = Lexem("2");
//	cmp[5] = Lexem("-");
//	cmp[6] = Lexem("*");
//	bool res = true;
//	for (int i = 0; i < 11; i++)
//		if (cmp != src)
//		{
//			res = false;
//		}
//	EXPECT_EQ(true, res);
//}