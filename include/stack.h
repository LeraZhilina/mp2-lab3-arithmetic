// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

#include <iostream>

using namespace std;
//Шаблон Стека
template<class sType>
class TStack
{
private:
	int Size;	//Размер стека
	int Top;	//Индекс последнего занятого в stMem
	sType* StMem;//Указатель на первый эл-т стека

public:
	TStack(int s = 1000);// Конструктор без параметров
	TStack(const TStack<sType> &s);// Конструктор копирования
	~TStack();			
	int GetSize() { return Size;}//Размер стека
	int GetTop() { return Top+1;}//Индекс последнего занятого в stMem
	void Push(const sType &a);// Положить элемент на вершину стека
	sType Pop();// Доступ к вершине стека с удалением 
	sType Peek() const;	// Доступ к вершине стека без удаления
	bool IsEmpty() const { return Top == -1; };// Стек пуст
	void Clean(); //очистка стека
	bool operator==(const TStack &st) const; //перегрузка сравнения
	TStack & operator=(const TStack &st); //перегрузка присваивания
};
//Реализация шаблона стека
template<class sType> // Конструктор без параметров
TStack<sType>::TStack(int s) : Size(s)
{
	if (s >= 0)
	{
		Top = -1;
		StMem = new sType[Size];
	}
	else
		throw "error,negative length";
}/*-------------------------------------------------------------------------*/

template<class sType>			// Деструктор
TStack<sType>::~TStack()
{
	delete[] StMem;
}/*-------------------------------------------------------------------------*/

template<class sType>			// Конструктор копирования
TStack<sType>::TStack(const TStack<sType> &s)
{
	Size = s.Size;
	StMem = new sType[Size];
	for (int i = 0; i < Top + 1; i++)
		StMem[i] = s.StMem[i];

} /*-------------------------------------------------------------------------*/

template<class sType> // Положить элемент на вершину стека
void TStack<sType>::Push(const sType &a)
{
	if (Top==Size-1)
	{
		Size *= 2;
		sType* temp = new sType[Size];
		for (int i = 0; i < Top + 1; i++)
			temp[i] = StMem[i];
		delete[] StMem;
		StMem = temp;

	}
	StMem[++Top] = a;
}/*-------------------------------------------------------------------------*/

template<class sType> // Доступ к вершине стека c удаленем
sType TStack<sType>::Pop()
{
	if (!IsEmpty())
		return StMem[Top--];
	else
		throw 0;
}/*-------------------------------------------------------------------------*/

template<class sType> // Доступ к вершине стека без удаления
sType TStack<sType>::Peek() const
{
	if (!IsEmpty())
		return StMem[Top];
	else
		throw 0;
}/*-------------------------------------------------------------------------*/
template<class sType>
void TStack<sType>::Clean() //очистка стека
{
	Top = -1;
}/*-------------------------------------------------------------------------*/

template<class sType>
TStack<sType> & TStack<sType>::operator=(const TStack &st) //перегрузка =
{
	if (this != &st)
	{
		if (Size != st.Size)
		{
			delete[] stMem;
			stMem = new sType[st.Size];
		}
		Size = st.Size;
		Top = st.Top;
		for (int i = 0; i<Top; i++)
			stMem[i] = st.stMem[i];
	}
	return *this;
}

/*-------------------------------------------------------------------------*/

template <class sType>
bool TStack<sType>::operator==(const TStack &st) const  //перегрузка ==
{
	if (this != &st)
	{
		if ((Size == st.Size) && (Top == st.Top))
		{
			for (int i = 0; i<Top; i++)
				if (stMem[i] != st.stMem[i])
					return false;
			return true;
		}
		else
			return false;
	}
	return true;
}

/*-------------------------------------------------------------------------*/
