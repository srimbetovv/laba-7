#include <iostream>
#include <Windows.h>

using namespace std;

const int LR = 0;
const int RR = 2147483647;

int inNum(int lr, int rr);
bool isNumNumeric();
bool isNumRangeCorrect(int num, int left_range, int right_range);

template <class T>
class Vector
{
public:
	~Vector() { while (Size) pop_front(); }

	void push_front(const int val)
	{
		Head = new Arr(val, Head);
		Size++;
	}
	void pop_front()
	{
		Arr* temp = Head;
		Head = Head;
		delete temp;
		Size--;
	}
	void Find(const int val)
	{
		Arr* temp = Head;
		bool ready = true;

		while (temp != nullptr)
		{
			if (temp->Val == val)
			{
				cout << "Элемент найден: " << temp->Val << endl;
				ready = false;
			}
			temp = temp->Next;
		}
		if (ready) cout << "Такого элемента нету!" << endl;
	}
	void print()
	{
		Arr* temp = Head;
		while (temp != nullptr)
		{
			cout << temp->Val << endl;
			temp = temp->Next;
		}
	}

	/*ostream& operator <<(ostream& out, Vector<T>& vector)
	{
		if (vector.Head == nullptr) out << "Список пуст";
		else
		{
			while (vector.Head != nullptr)
			{
				out << vector.Head->Val << endl;
				vector.Head = vector.Head->Next;
			}
		}
		return out;
	}*/

	bool operator ==(Vector<T>& arr)
	{
		Arr* arr1 = Head;
		Arr* arr2 = arr.Head;
		int len1 = 0, len2 = 0;
		while (arr1 != nullptr)
		{
			len1++;
			arr1 = arr1->Next;
		}
		while (arr2 != nullptr)
		{
			len2++;
			arr2 = arr2->Next;
		}
		return len1 == len2;
	}

private:
	class Arr
	{
	public:
		int Val;
		Arr* Next;

		Arr(const int val, Arr* next = nullptr)
		{
			Val = val;
			Next = next;
		}
	};

	Arr* Head = nullptr;
	int Size = 0;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Vector<int> arr1;
	Vector<int> arr2;

	int choice = int();
	bool ready = true;

	while (ready)
	{
		cout << "= = = = = Меню = = = = =" <<
			"\n\t1. Добавить в начало 1 список" <<
			"\n\t2. Добавить в начало 2 список" <<
			"\n\t3. Удаление первого элемента из 1 списка" <<
			"\n\t4. Удаление первого элемента из 2 списка" <<
			"\n\t5. Найти элемент из 1 списка" <<
			"\n\t6. Найти элемент из 2 списка" <<
			"\n\t7. Просмотр 1 список" <<
			"\n\t8. Просмотр 2 список" <<
			"\n\t9. Сравнить списки" <<
			"\n\t0. Выход" <<
			endl;
		cout << "Выберите: ";
		choice = inNum(0, 9);
		switch (choice)
		{
		case 0: ready = false; break;
		case 1:
			cout << "Введите элемент: ";
			choice = inNum(LR, RR);
			arr1.push_front(choice);
			break;
		case 2:
			cout << "Введите элемент: ";
			choice = inNum(LR, RR);
			arr2.push_front(choice);
			break;
		case 3: arr1.pop_front(); break;
		case 4: arr2.pop_front(); break;
		case 5:
			cout << "Введите элемент: ";
			choice = inNum(LR, RR);
			arr1.Find(choice);
			break;
		case 6:
			cout << "Введите элемент: ";
			choice = inNum(LR, RR);
			arr1.Find(choice);
			break;
		case 7: arr1.print(); break;
		case 8: arr2.print(); break;
		case 9:
			if (arr1 == arr2) cout << "Количество элементов в списках одинаковы!" << endl;
			else cout << "Количество элементов в списках разные!" << endl;
			break;
		}
	}

	return 0;
}

int inNum(int lr, int rr)
{
	int num;
	int vol = 1;

	while (true)
	{
		cin >> num;
		if (isNumNumeric() && isNumRangeCorrect(num, lr, rr)) return num;
		cout << "Некорректный ввод! Введите числа в дипазоне от " << lr << " по " << rr << ": ";
	}
}
bool isNumNumeric()
{
	if (cin.get() == '\n') return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
}
bool isNumRangeCorrect(int num, int lr, int rr) { return (lr <= num && num <= rr); }
