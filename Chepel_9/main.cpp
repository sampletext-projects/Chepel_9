#include <iomanip>
#include <iostream>

using namespace std;

//сортировка заданной колонки с заданным количеством элементов
void sort(int** matrix, int column, int size)
{
	//Сортировка пузырьком заданной колонки
	bool sorted;
	do
	{
		sorted = true;
		for (int i = 1; i < size; ++i)
		{
			if (matrix[i][column] < matrix[i - 1][column])
			{
				swap(matrix[i][column], matrix[i - 1][column]);
				sorted = false;
			}
		}
	}
	while (!sorted);
}

//обработка целой матрицы
void proc_matrix(int** matrix, int n, int m)
{
	for (int i = 0; i < m; ++i)
	{
		//отсортировать [i] колонку, в которой n строк
		sort(matrix, i, n);
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Автор: Чепель Егор Максимович" << endl;
	cout << "Программа для работы с матрицей с помощью функций" << endl;

	int n, m;
	cout << "Введите количество строк: ";
	cin >> n;
	cout << "Введите количество столбцов: ";
	cin >> m;

	int** matrix = new int*[n];//матрица (указатель на строки)

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];//выделяем память под строку
		for (int j = 0; j < m; j++)
		{
			cout << "Matr[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}

	cout << "Вы ввели матрицу\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	//обработка матрицы
	proc_matrix(matrix, n, m);

	cout << "Отсортированная\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	system("pause");

	return 0;
}
