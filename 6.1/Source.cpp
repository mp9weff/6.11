//рекурсивний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Change(int* p, const int size) 
{
	for (int i = 0; i <= size; i++)
	{
		if(p[i] % 2 == 0 && p[i] > 0)
			p[i] = 0;
	}
}
int Number(int* p, const int size)
{
	int n = 0;
	for (int i = 0; i <= size; i++) 
	{
		if(p[i] % 2 == 0 && p[i] > 0)
			n++;

	}
	return n;
}
void Create(int* p, const int size, const int Low, const int High, int i)
{
	p[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(p, size, Low, High, i + 1);
}
void Print(int* p, const int size, int i)
{
	cout << "p[" << setw(2) << i << " ] = " << setw(4) << p[i] << endl;
	if (i < size - 1)
		Print(p, size, i + 1);
	else
		cout << endl;
}
int Sum(int* p, const int size, int i)
{
	if (i < size)
	{
		if (p[i] % 2 == 0 && p[i] > 0)
			return p[i] + Sum(p, size, i + 1);
		else
			return Sum(p, size, i + 1);
	}
	else
		return 0;
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 24;
	int p[n];
	int Low = -10;
	int High = 14;
	Create(p, n, Low, High, 0);
	Print(p, n, 0);
	cout << "S = " << Sum(p, n, 0) << endl;
	int number = Number(p, n);
	cout << "Numbers: " << endl;
	cout << number;
	Change(p, n);


	return 0;
}
