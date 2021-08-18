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
	catch (const int ex)
	{
		cout << ex;
	}

	catch (const exception &ex)
	{
		cout << ex.what();
	}

	cout << "\n-------------------------------------\n\n";

	ofstream fout;
	fout.exceptions(ofstream::badbit | ofstream::failbit);
	try
	{
		fout.open(fName);
		cout << "Данные успешно записаны в файл!\n";

		fout << arr2 << "\n";
		fout.close();
	}

	catch (const ofstream::failure& ex)
	{
		cout << "Ошибка!" << endl;
		cout << ex.what() << endl; //описание ошибки exception
		cout << ex.code() << endl;	//стандартный код ошибки fstream	
	}	
	

	cout << "\n-------------------------------------\n\n";
	
	//Тестирование открытие файла на считывание данных используя стандартный exception fstream

	ifstream fin;

	fin.exceptions(ifstream::badbit | ifstream::failbit);

	char buf;	

	try
	{
		fin.open(fName);
		cout << "Файл открыт!\n";
		for (size_t i = 0; i < arr3.GetSize(); i++)
		{
			fin >> buf;
			arr3[i] = buf;
		}
		cout << "Данные успешно считаны!\n";

		cout << arr3;

		fin.close();
	}
	catch (const ifstream::failure & ex)
	{
		cout << "Ошибка!" << endl;
		cout << ex.what() << endl; //описание ошибки exception
		cout << ex.code() << endl;	//стандартный код ошибки fstream	
	}
	cout << "\n-------------------------------------\n\n";
	
	//Тестирование throw несуществующего индекса массива
	// <0 throw index
	// >= size throw MyException() -> class MyException: public exception

	try
	{
		cout << arr2[991];
	}
	catch (const int ex)
	{
		cout << ex;
	}	

	catch (MyException& ex)
	{
		cout << ex.what() << " ";
		cout << ex.GetErrorCode();
	}

	catch (exception& ex)
	{
		cout << ex.what() << " ";
	}

	cout << endl;
	system("pause");
}