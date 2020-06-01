#include <iomanip>
#include <iostream>

using namespace std;

//���������� �������� ������� � �������� ����������� ���������
void sort(int** matrix, int column, int size)
{
	//���������� ��������� �������� �������
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

//��������� ����� �������
void proc_matrix(int** matrix, int n, int m)
{
	for (int i = 0; i < m; ++i)
	{
		//������������� [i] �������, � ������� n �����
		sort(matrix, i, n);
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "�����: ������ ���� ����������" << endl;
	cout << "��������� ��� ������ � �������� � ������� �������" << endl;

	int n, m;
	cout << "������� ���������� �����: ";
	cin >> n;
	cout << "������� ���������� ��������: ";
	cin >> m;

	int** matrix = new int*[n];//������� (��������� �� ������)

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];//�������� ������ ��� ������
		for (int j = 0; j < m; j++)
		{
			cout << "Matr[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}

	cout << "�� ����� �������\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	//��������� �������
	proc_matrix(matrix, n, m);

	cout << "���������������\n";
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
