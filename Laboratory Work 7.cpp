#include<iostream>
#include <string>
#include <map>
#include <stack>
#include <queue> 

using namespace std;

/*
1.Создать стек из целых чисел. Определить среднее арифметическое четных значений
элеметов этого стека. Организовать промотр данных стека.

2.Создать очередь строковых значений. Реализовать операции добавления (push) и удаления 
(pop) элементов из очереди. Добавить в нее строки "abc", "fx", "glc", "hi", "gogo". 
Удалить один элемент из очереди, затем добавить строку "" и распечатать содержимое стека.

3.Дана последовательность скобок вида "(", ")", "[" , "]", "{", "}". Определить является ли 
заданная строка правильным скобочным выражением.
*/

void Basic_level()
{
	stack<int> st({ 1,2,3,-9});
	double avar = 0;
	int cifra = 0;
	bool chetniy = true;
	while (!st.empty())
	{
		chetniy = !chetniy;
		if (chetniy == true)
		{
			avar += st.top();
			cifra += 1;
		}
		cout << st.top() << " ";
		st.pop();
	}
	avar = avar / cifra;
	cout << "\nAvarage: " << avar << endl;
}

void Middle_level()
{
	queue <string> q;

	int m;
	string a;

	q.push("abc");
	q.push("fx");
	q.push("glc");
	q.push("hi");
	q.push("gogo");

	cout << "The first element is given" << endl;
	for (int i = 0; i < 1; i++)
		q.pop();

	q.push("the end");

	cout << "Queue after changes: " << endl;
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void High_Level()
{
	string str;
	cout << "Enter string:" << "\n";
	cin >> str;
	map<char, char> mp{ { '(', ')' }, { '[', ']' }, { '{', '}'} };
	stack<char> stk;
	int i = 0;
	for (i = 0; i < str.size(); ++i)
	{
		if ('(' == str[i] || '[' == str[i] || '{' == str[i])
		{
			stk.push(str[i]);
		}
		else if (!stk.empty())
		{
			char c = stk.top();
			stk.pop();
			if (mp[c] != str[i])
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	cout << (i == str.size() && stk.empty() ? "Right" : "Wrong") << "\n";
}

int main()
{
	int n;
	cout << "Enter task number: (1 - basic level| 2 - middle level| 3 - high level)" << endl;
	cin >> n;

	if (n == 1)
	{
		Basic_level();
	}
	else if (n == 2)
	{
		Middle_level();
	}
	else if (n == 3)
	{
		High_Level();
	}
	else
	{
		cout << "There is no such task!" << endl;
	}

	system("pause");
	return 0;
}