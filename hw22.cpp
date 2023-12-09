#include <iostream>
using namespace std;

class Stack
{
	static const int SIZE = 10; // количество элементов в стеке (при желании можно поменять)

	int ar[SIZE]; // обычно реализуется как статический массив
	int index = 0; // индекс, по которому будет добавляться очередной новый элемент
	// также индекс можно воспринимать как количество элементов, которые были добавлены в стек на данный момент

public:
	void Clear()
	{
		index = 0;
	}

	bool IsEmpty() const
	{
		return index == 0;
	}

	bool IsFull() const
	{
		return index == SIZE;
	}

	int GetCount() const
	{
		return index;
	}

	void Push(int value)
	{
		if (!IsFull())
		{
			ar[index++] = value;
		}
		else
		{
			throw "Stack overflow!";
		}
	}

	int Pop()
	{
		if (!IsEmpty())
		{
			return ar[--index];
		}
		else
		{
			throw "Stack is empty!";
		}
	}

	int Peek() const
	{
		if (!IsEmpty())
		{
			return ar[index - 1];
		}
		else
		{
			throw "Error";
		}
	}

	bool Contains(int value) const
	{
		for (int i = 0; i < index; ++i)
		{
			if (ar[i] == value)
			{
				return true;
			}
		}
		return false;
	}

};

int main()
{
	Stack st; // создаём "пустой" стек

	// до тех пор, пока стек не заполнился
	while (!st.IsFull())
		st.Push(rand() % 90 + 10); // добавляем элемент на вершину стека

	// проверяем, пустой ли стек
	if (st.IsEmpty())
	{
		cout << "Stack is empty\n";
	}
	else
	{
		cout << "Stack is not empty\n";
	}

	// проверяем, переполнен ли стек
	if (st.IsFull())
	{
		cout << "Stack is full\n";
	}
	else
	{
		cout << "Stack is not full\n";
	}

	// получаем количество элементов в стеке
	int count = st.GetCount();
	cout << "Count of elements in stack: " << count << "\n";

	// проверяем, содержится ли какой-то элемент в стеке
	if (st.Contains(20))
	{
		cout << "Stack contains 20\n";
	}
	else
	{
		cout << "Stack does not contain 20\n";
	}

	// получаем верхний элемент стека
	int top = st.Peek();
	cout << "Top element in stack: " << top << "\n";

	// до тех пор, пока в стеке есть какие-либо значения
	while (!st.IsEmpty())
		cout << st.Pop() << "  "; // извлечь значение и показать на экране
}