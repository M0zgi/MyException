#include"Exception.h"
#include"MyArray.h"


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	string fName = "myFile.txt"; // ��� ����� ��� ���������� �������

	MyArray <char> arr2(1);
	MyArray <char> arr3(8);
	try
	{
		MyArray <char> arr(8);
		arr.FillArray();
		cout << arr;
		
		arr2 = arr;
	}
	catch (int ex)
	{
		cout << ex;
	}

	catch (const char* ex)
	{
		cout << ex;
	}

	//fstream fout;

	//fout.open(fName);

	//if (!fout.is_open())
	//{
	//	cout << "������ �������� ����� �� ������!";
	//}

	//else
	//{				
	//	cout << "������ ������� �������� � ����!\n";

	//	fout << arr2 << "\n";		
	//}

	//fout.close();

	ifstream fin;
	fin.open(fName);
	char buf;

	if (!fin.is_open())
	{
		cout << "������ �������� ����� �� ������ ������!\n";
	}

	else
	{
		cout << "���� ������!\n";
		for (size_t i = 0; i < arr3.GetSize(); i++)
		{
			fin >> buf;
			arr3[i] = buf;
		}
	}

	//ifstream fin;

	//fin.open(fName);

	//if (!fin.is_open())
	//{
	//	cout << "������ �������� �����2!";
	//}

	//else
	//{
	//	cout << "���� ������!\n";

	//		string buf;
	//		int i = 0;

	//		//fin >> arr3;

	//		while (!fin.eof())
	//		{
	//			//buf="";
	//			//getline(fin, buf);
	//			fin >> arr3;
	//			// = buf;
	//			//cout << buf << " ";
	//			//arr3[i] = buf;
	//			
	//		}		
	//}

	//fin.close();

	//arr2[0] = '2';

	cout << arr3;

	cout << endl;
	system("pause");
}