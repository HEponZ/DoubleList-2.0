#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Array<int> arr, arr2, arr_buf;
	int choise, size, grow, index, value;
	int* mas_data;

	enum MENU {
		EXIT = 0,
		GETSIZE, //������ �������
		SETSIZE, //���������� ������
		LAST_INDEX, //���������� ��������� ������
		ISEMPTY, //����?
		DELETE_FREE, //������� ������ ������
		CLEAR, //������� ��
		GET_INDEX, //�������� �� �������
		SET_INDEX, //���������� �� �������
		ADD, //��������
		SUM, //"�������"
		ASSIGN, //����������
		PRINT, //�������
		INSERT_INDEX, //�������� �� �������
		DELETE_INDEX //������� �� �������
	};

	cout << "1 - ������ �������\n2 - ��������� �������\n3 - ��������� ���������� ������\n4 - ����?\n5 - ������� ������ ������\n6 - ��������\n7 - �������� ������� �� �������\n8 - ���������� �� �������\n9 - �������� ��������\n10 - �������� ���� ��������\n11 - ���������� �������\n12 - �������� ������ � �������(�����)\n13 - ������� �������� �� �������� �������\n14 - �������� �������� � �������� �������\n";

	do
	{
		try
		{
			cin >> choise;

			switch (choise)
			{
			case GETSIZE:
				cout << "������ �������: " << arr.GetSize() << "\n";
				break;
			case SETSIZE:
				cout << "������� ������: ";
				cin >> size;
				cout << "������� ��� ������� ��������� �������� ������: ";
				cin >> grow;
				arr.SetSize(size, grow);
				break;
			case LAST_INDEX:
				cout << "��������� ������: " << arr.GetUpperBound() << "\n";
				break;
			case ISEMPTY:
				if (arr.IsEmpty() == true)
				{
					cout << "������ ����\n";
				}
				else
				{
					cout << "������ �� ����\n";
				}
				break;
			case DELETE_FREE:
				arr.FreeExtra();
				break;
			case CLEAR:
				arr.RemoveAll();
				break;
			case GET_INDEX:
				cout << "������� ������: ";
				cin >> index;
				cout << arr.GetAt(index);
				break;
			case SET_INDEX:
				cout << "������� ������: ";
				cin >> index;
				cout << "������� �� ��� ������ ��������: ";
				cin >> value;
				arr.SetAt(index, value);
				break;
			case SUM:
				arr.Append(arr2);
				break;
			case ADD:
				cout << "������� �� ��� ������ ��������: ";
				cin >> value;
				arr.Add(value);
				cout << "������� �� ��� ������ ��������(2): ";
				cin >> value;
				arr2.Add(value);
				break;
			case ASSIGN:
				arr2 = arr;
				break;
			case PRINT:
				mas_data = arr.GetData();
				cout << "������ 1\n";
				print(mas_data, arr);

				mas_data = arr2.GetData();
				cout << "������ 2\n";
				print(mas_data, arr);
				break;
			case INSERT_INDEX:
				cout << "������� ������: ";
				cin >> index;
				cout << "������� �� ��� ������ ��������: ";
				cin >> value;
				arr.InsertAt(index, value);
				break;
			case DELETE_INDEX:
				cout << "������� ������: ";
				cin >> index;
				arr.RemoveAt(index);
				break;
			case EXIT:
				break;
			}
		}
		catch (const out_of_range& range_er)
		{
			cout << range_er.what();
		}
	} while (choise != 0);


	return 0;
}