#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <cstring>
#include <unordered_map>
#pragma warning(disable : 4996) // Позволяет использовать "strtok", которая в последних версиях VS помечена как устаревшая (исп. в задании 3)
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////

void Calculator()
{                                                                                       // Задание 1
	char zn;
	double a, b;
	cout << "Введите пример: ";
	cin >> a >> zn; "'+' || '-' || '*' || '/'"; cin >> b;

	if (!a)                                                                                // Проверка на ввод первой переменной
    {
	    cout << "Ошибка! Вы ввели недопустимое значение первой переменной!\n\a";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> a >> zn; "'+' || '-' || '*' || '/'"; cin >> b;
	}
	if (!b)                                                                                // Проверка на ввод первой переменной
	{
	    cout << "Ошибка! Вы ввели недопустимое значение второй переменной!\n\a";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> a >> zn; "'+' || '-' || '*' || '/'"; cin >> b;
	}

    if (((zn) == !(zn)) || ((zn != '+') && (zn != '-') && (zn != '*') && (zn != '/')))     // Проверка на ввод знака
    {
	    cout << "Ошибка! Вы ввели НЕ математимеский символ!\n\a";
	    cin.clear();
	    cin.ignore(256, '\n');
	    cin >> a >> zn; "'+' || '-' || '*' || '/'"; cin >> b;
	}

	switch (zn)                                                                          // Калькулятор
	{
	   case '+': cout << "Ответ: " << a + b << "\n";
	   break;
	   case '-': cout << "Ответ: " << a - b << "\n";
	   break;
	   case '*': cout << "Ответ: " << a * b << "\n";
	   break;
	   case '/':
	   if (b == 0)
	   {
	    cout << "Ошибка! На 0 делить нельзя!\a\n";
	   }
	   else
	   {
		 cout << "Ответ: " << a / b << "\n";
		 break;
	   }
	}
	
	system("pause");
}

void Basic_Working_Conditions_Of_The_Calculator()
{
	cin.ignore(256, '\n');
	while (cin.get() == '\n')                                               // Проверка на пустую строку
	{
		cout << "Ошибка! Пустая строка!\a";
	}

	while ((cin.get() != '\n'))                                            // При отсутствии '\n' (пустой строки) запускается калькулятор
	{
		Calculator();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void The_Main_Choice2()                                                                // Меню основного выбора     Задание 2
{
	cout << "1. Основные действия со строками, введенными через консоль\n";
	cout << "2. Чтение строк из файла\n";
	cout << "\n";
	
}


void Functional_String()                                                           // Меню выбора действий с введенными строками    Задание 2
{
	cout << "Что необходимо сделать со строками?\n";
	cout << "1. Преобразование введенной строки в верхний регистр\n";
	cout << "2. Преобразование введенной строки в нижний регистр\n";
	cout << "3. Конкантенация введенных строк\n";
	cout << "4. Вывод строк в файл\n";
	cout << "5. Возвращение к основному выбору\n";
	cout << "\n";
}

void String_Processing()
{
	int x, z;
	string s, s1, s2, s3;
	The_Main_Choice2();

	cin >> x; "1 || 2";

	if (x != 1 && x != 2)
	{
		cout << "Ошибка выбора!\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> x; "1 || 2";
	}

	if (x == 1)
	{
		
		Functional_String();
		cin >> z;
		while (z >= 1 && z <= 5)
		{
			switch (z)
			{
			  case 1: cout << "Введите строку:\n";
				cin >> s;
				transform(s.begin(), s.end(), s.begin(), ::toupper);
				cout << "Результат:" << s << "\n\n";
				The_Main_Choice2();
				cin.clear();
				cin.ignore(256, '\n');
				cin >> x; "1 || 2";
				break;

			  case 2: cout << "Введите строку:\n";                                  // Преобразование введенной строки в нижний регистр
				cin >> s;
				transform(s.begin(), s.end(), s.begin(), ::tolower);
				cout << "Результат:" << s <<"\n\n";
				The_Main_Choice2();
				cin.clear();
				cin.ignore(256, '\n');
				cin >> x; "1 || 2";
				break;

			  case 3:                                                              // Конкантенация введенных строк
				cout << "Введите первую строку\n";
				cin >> s1; cout << "\n";
				cout << "Введите вторую строку\n";
				cin >> s2; cout << "\n";
				s3 = s1 + s2;
				cout << "Результат: " << s3 << "\n\n";
				The_Main_Choice2();
				cin.clear();
				cin.ignore(256, '\n');
				cin >> x; "1 || 2";
				break;

			  case 5:                                                             // Возвращение к основному выбору
				  The_Main_Choice2();
				  cin.clear();
				  cin.ignore(256, '\n');
				  cin >> x; "1 || 2";
				break;

			  case 4:                                                            // Вывод строк в файл
				cout << "Введите первую строку\n";
				cin >> s1; cout << "\n";
				cout << "Введите вторую строку\n";
				cin >> s2; cout << "\n";
				ofstream outf("Файл с введенными строками.txt");

				if (!outf)
				{
					cerr << "Ошибка! Невозможно открыть файл!\n\a";
					Functional_String();
					break;
				}
				outf << s1 << endl;
				outf << s2 << endl;
				cout << "Файл создан!" << "\n\n";
				The_Main_Choice2();
				cin.clear();
				cin.ignore(256, '\n');
				cin >> x; "1 || 2";
				break;
			}
		}
	}
	
	if (x == 2)
	{                                                                             // Чтение из файла (Файл с введенными строками.txt)

		cout << "Чтение из файла (Файл с введенными строками.txt)\n";
		cout << "По умолчанию читается файл, созданный ранее в 4м пункте действий с введенными строками.\n";
		string path = "Файл с введенными строками.txt";
		ifstream fin;
		fin.open(path);

		if (!fin.is_open())
		{
			cout << "Ошибка открытия файла!\n\a";
		}

		else
		{
			cout << "Файл успешно открыт!\n\n";
			string str;

			while (!fin.eof())
			{
				str = "";
				getline(fin, str);
				cout << str << "\n";
			}
		}
		fin.close();
		The_Main_Choice2();
		cin.clear();
		cin.ignore(256, '\n');
		cin >> x; "1 || 2";
	}
	
	system("pause");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

unordered_map < string, int > word_separation()                                    // Задание 3
{
	unordered_map < string, int > Set_of_words;
	char* wor;
	string str;

	getline(cin, str); cout << "\n";
	char* cstr = &str[0];
	char* sep = strtok(cstr, " ");
	while (sep != NULL)
	{
		Set_of_words[string(sep)]++;
		sep = strtok(NULL, " ");
	}
	return Set_of_words;
}
void Search_for_the_most_common_word_or_char()
{
	cout << "Введите текст на английском языке:\n";

	unordered_map < string, int > Set_of_words = word_separation();
	int limit_frequency = -1;
	string the_most_common_word = "";
	for (const auto& wo : Set_of_words)
	{
		if (wo.second > limit_frequency)
		{
			limit_frequency = wo.second;
			the_most_common_word = wo.first;
		}
	}
	cout << "Наиболее встречаемое слово: " << the_most_common_word << "\n";
	system("pause");
}


/////////////////////////////////////////////////////////////////////////////////////////////////////

void Choice()
{
	cout << "Выберите задание: \n";
	cout << "1. Калькулятор на switch\n";
	cout << "2. Обработка строк\n";
	cout << "3. Поиск наиболее встречаемого слова\n";
	int сhoice = 0;
	cin >> сhoice; "1 || 2 || 3";
	if (сhoice != 1 && сhoice != 2 && сhoice != 3)
	{
		cout << "Ошибка выбора!\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> сhoice; "1 || 2 || 3";
	}
	if (сhoice == 1)
	{
		Calculator();
	}
	if (сhoice == 2)
	{
		String_Processing();
	}
	if (сhoice == 3)
	{
		word_separation();
		Search_for_the_most_common_word_or_char();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	setlocale(LC_ALL, "ru");
	Choice();
	system("pause");
	return 0;
}
