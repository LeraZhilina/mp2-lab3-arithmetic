// тесты для стека

#include "stack.h"
#include <gtest.h>
// ТИПИЗИРОВАННЫЕ ТЕСТЫ
// https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md#typed-tests
// sample: https://github.com/google/googletest/blob/master/googletest/samples/sample6_unittest.cc



//типизированный класс
template <class T>
class StackTest : public testing::Test {
protected:
	TStack<T> st1;
	TStack<T> st2;
	TStack<T> st3;

public:
	StackTest() : st1(10), st2(10), st3(20)
	{

		for (int i = 0; i < 10; i++)
			st1.Push((T)(i));
		for (int i = 0; i < 10; i++)
			st2.Push((T)(i));
		for (int i = 0; i < 20; i++)
			st3.Push((T)(i));
	}

	virtual ~StackTest() {}

};
// список типов, которые хотим протестировать
typedef ::testing::Types<int, double, char> MyTypes;
// связываем класс и типы
TYPED_TEST_CASE(StackTest, MyTypes);
//тесты
TYPED_TEST(StackTest, can_create_stack)
{
	ASSERT_NO_THROW(st1);
}
TYPED_TEST(StackTest, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-10));
}
/*TYPED_TEST(StackTest, can_create_copied_stack)
{
	ASSERT_NO_THROW(TStack<(int)T> st1(st2));
}*/
TYPED_TEST(StackTest, can_push_element)
{
	EXPECT_EQ(10, st1.GetTop());
}
TYPED_TEST(StackTest, can_get_size)
{
	EXPECT_EQ(10, st1.GetSize());
	EXPECT_EQ(20, st3.GetSize());
}
/*TYPED_TEST(StackTest, copied_stack_is_equal_to_source_one)
{
	TStack st(st2);
	EXPECT_EQ(st, st2);
}*/
TYPED_TEST(StackTest, can_check_emptiness)
{
	EXPECT_NE(true, st1.IsEmpty());
}
TYPED_TEST(StackTest, can_clean_stack)
{
	st1.Clean();
	EXPECT_EQ(true, st1.IsEmpty());
}

TYPED_TEST(StackTest, can_pop_element)
{
	TStack<int> st(2);
	st.Push(1);
	st.Push(2);
	st.Pop();
	EXPECT_EQ(1, st.GetTop());
}
