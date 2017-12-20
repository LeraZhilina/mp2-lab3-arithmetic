// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������

#include <iostream>

using namespace std;
//������ �����
template<class sType>
class TStack
{
private:
	int Size;	//������ �����
	int Top;	//������ ���������� �������� � stMem
	sType* StMem;//��������� �� ������ ��-� �����

public:
	TStack(int s = 1000);// ����������� ��� ����������
	TStack(const TStack<sType> &s);// ����������� �����������
	~TStack();			
	int GetSize() { return Size;}//������ �����
	int GetTop() { return Top+1;}//������ ���������� �������� � stMem
	void Push(const sType &a);// �������� ������� �� ������� �����
	sType Pop();// ������ � ������� ����� � ��������� 
	sType Peek() const;	// ������ � ������� ����� ��� ��������
	bool IsEmpty() const { return Top == -1; };// ���� ����
	void Clean(); //������� �����
	bool operator==(const TStack &st) const; //���������� ���������
	TStack & operator=(const TStack &st); //���������� ������������
};
//���������� ������� �����
template<class sType> // ����������� ��� ����������
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

template<class sType>			// ����������
TStack<sType>::~TStack()
{
	delete[] StMem;
}/*-------------------------------------------------------------------------*/

template<class sType>			// ����������� �����������
TStack<sType>::TStack(const TStack<sType> &s)
{
	Size = s.Size;
	StMem = new sType[Size];
	for (int i = 0; i < Top + 1; i++)
		StMem[i] = s.StMem[i];

} /*-------------------------------------------------------------------------*/

template<class sType> // �������� ������� �� ������� �����
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

template<class sType> // ������ � ������� ����� c ��������
sType TStack<sType>::Pop()
{
	if (!IsEmpty())
		return StMem[Top--];
	else
		throw 0;
}/*-------------------------------------------------------------------------*/

template<class sType> // ������ � ������� ����� ��� ��������
sType TStack<sType>::Peek() const
{
	if (!IsEmpty())
		return StMem[Top];
	else
		throw 0;
}/*-------------------------------------------------------------------------*/
template<class sType>
void TStack<sType>::Clean() //������� �����
{
	Top = -1;
}/*-------------------------------------------------------------------------*/

template<class sType>
TStack<sType> & TStack<sType>::operator=(const TStack &st) //���������� =
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
bool TStack<sType>::operator==(const TStack &st) const  //���������� ==
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
