#include <iomanip>
#include <iostream>

using namespace std;

//сортировка заданной колонки с заданным количеством элементов
void sort(int* column, int size)
{
	//Сортировка пузырьком заданной колонки
	bool sorted;
	do
	{
		sorted = true;
		for (int i = 1; i < size; ++i)
		{
			if (column[i] < column[i - 1])
			{
				swap(column[i], column[i - 1]);
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
		int* column = new int[n];
		// скопировать колонку
		for (int j = 0; j < n; j++)
		{
			column[j] = matrix[j][i];
		}
		// отсортировать колонку
		sort(column, n);

		// переписать её обратно
		for (int j = 0; j < n; j++)
		{
			matrix[j][i] = column[j];
		}
		delete [] column;
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

	int** matrix = new int*[n]; //матрица (указатель на строки)

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m]; //выделяем память под строку
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
