#include"Exception.h"
#include"MyArray.h"


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	string fName = "myFile.txt"; // имя файла для сохранения массива

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

	fstream fout;

	fout.open(fName);

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла на запись!";
	}

	else
	{				
		cout << "Данные успешно записаны в файл!\n";

		fout << arr2 << "\n";		
	}

	fout.close();

	ifstream fin;
	fin.open(fName);
	char buf;

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла на чтение данных!\n";
	}

	else
	{
		cout << "Файл открыт!\n";
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
	//	cout << "Ошибка открытия файла2!";
	//}

	//else
	//{
	//	cout << "Файл открыт!\n";

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

	//arr2[0] = 444;

	cout << arr3;

	cout << endl;
	system("pause");
}