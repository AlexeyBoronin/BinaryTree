//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stdio.h>
//using namespace std;
//struct Elem
//{
//	int OwnerPoints; //Очки хозяина
//	int OppPoints; //Очки соперника
//	char Match[10]; //Счет
//	char Name[20]; //Команда
//	char Opponent[20]; //Соперник
//	Elem* left, * right, * parent;
//};
//class Tree
//{
//	//корень
//	Elem* root;
//public:
//	Tree();
//	~Tree();
//	//печать от указанного узла
//	void Print(Elem* Node);
//	//поиск от указанного узла
//	Elem* Search(Elem* Node, char* key);
//	//min от указанного узла
//	Elem* Min(Elem* Node);
//	//max от указанного узла
//	Elem* Max(Elem* Node);
//	//следующий для указанного узла
//	Elem* Next(Elem* Node);
//	//предыдущий для указанного узла
//	Elem* Previous(Elem* Node);
//	//вставка узла
//	void Insert(Elem* z);
//	//удаление ветки для указанного узла,
//	//0 - удаление всего дерева
//	void Del(Elem* z = 0);
//	//получить корень
//	Elem* GetRoot();
//};
//Tree::Tree()
//{
//	root = NULL;
//}
//Tree::~Tree()
//{
//	Del();
//}
////Рекурсивный обход дерева
//void Tree::Print(Elem* Node)
//{
//	if (Node != 0)
//	{
//		Print(Node->left);
//		cout << Node->Name
//			<< Node->Match
//			<< Node->Opponent
//			<< endl;
//		Print(Node->right);
//	}
//}
//Elem* Tree::Search(Elem* Node, char* k)
//{
//	//Пока есть узлы и ключи не совпадают
//	while (Node != 0 && strcmp(k, Node->Name) != 0)
//	{
//		if (strcmp(k, Node->Name) < 0)
//			Node = Node->left;
//		else
//			Node = Node->right;
//	}
//	return Node;
//}
//Elem* Tree::Min(Elem* Node)
//{
//	//Поиск самого "левого" узла
//	if (Node != 0)
//		while (Node->left != 0)
//			Node = Node->left;
//	return Node;
//}
//Elem* Tree::Max(Elem* Node)
//{
//	//Поиск самого "правого" узла
//	if (Node != 0)
//		while (Node->right != 0)
//			Node = Node->right;
//	return Node;
//}
//Elem* Tree::Next(Elem* Node)
//{
//	Elem* y = 0;
//	if (Node != 0)
//	{
//		//если есть правый потомок
//		if (Node->right != 0)
//			return Min(Node->right);
//		//родитель узла
//		y = Node->parent;
//		//если Node не корень и Node справа
//		while (y != 0 && Node == y->right)
//		{
//			//Движемся вверх
//			Node = y;
//			y = y->parent;
//		}
//	}
//	return y;
//}
//Elem* Tree::Previous(Elem* Node)
//{
//	Elem* y = 0;
//	if (Node != 0)
//	{
//		//если есть левый потомок
//		if (Node->left != 0)
//			return Max(Node->left);
//		//родитель узла
//		y = Node->parent;
//		//если Node не корень и Node слева
//		while (y != 0 && Node == y->left)
//		{
//			//Движемся вверх
//			Node = y;
//			y = y->parent;
//		}
//	}
//	return y;
//}
//Elem* Tree::GetRoot()
//{
//	return root;
//}
//void Tree::Insert(Elem* z)
//{
//	//потомков нет
//	z->left = NULL;
//	z->right = NULL;
//	Elem* y = NULL;
//	Elem* Node = root;
//	//поиск места
//	while (Node != 0)
//	{
//		//будущий родитель
//		y = Node;
//		if (strcmp(z->Name, Node->Name) < 0)
//			Node = Node->left;
//		else
//			Node = Node->right;
//	}
//	//заполняем родителя
//	z->parent = y;
//	if (y == 0) //элемент первый (единственный)
//		root = z;
//	//чей ключ больше?
//	else if (strcmp(z->Name, y->Name) < 0)
//		y->left = z;
//	else
//		y->right = z;
//}
//void Tree::Del(Elem* z)
//{
//	//удаление куста
//	if (z != 0)
//	{
//		Elem* Node, * y;
//		//не 2 ребенка
//		if (z->left == 0 || z->right == 0)
//			y = z;
//		else
//			y = Next(z);
//		if (y->left != 0)
//			Node = y->left;
//		else
//			Node = y->right;
//		if (Node != 0)
//			Node->parent = y->parent;
//		//Удаляется корневой узел?
//		if (y->parent == 0)
//			root = Node;
//		else if (y == y->parent->left)
//			//слева от родителя?
//			y->parent->left = Node;
//		else
//			//справа от родителя?
//			y->parent->right = Node;
//		if (y != z)
//		{
//			//Копирование данных узла
//			strcpy(z->Name, y->Name);
//			strcpy(z->Opponent, y->Opponent);
//			strcpy(z->Match, y->Match);
//			z->OppPoints = y->OppPoints;
//			z->OwnerPoints = y->OwnerPoints;
//		}
//		delete y;
//	}
//	else //удаление всего дерева
//		while (root != 0)
//			Del(root);
//}
////Турнирная таблица
//Tree tournament;
//void Game(char Commands[][20], int N)
//{
//	int i, j;
//	int p1, p2; //Счет
//	//Каждая команда играет с каждой по 2 раза -
//	//дома и в гостях
//	int k;
//	Elem* temp;
//	for (k = 0; k < 2; k++)
//		for (i = 0; i < N - 1; i++)
//		{
//			for (j = i + 1; j < N; j++)
//			{
//				temp = new Elem;
//				if (k == 0)
//				{
//					//1 игра
//					strcpy(temp->Name, Commands[i]);
//					strcpy(temp->Opponent, Commands[j]);
//				}
//				else
//				{
//					//2 игра
//					strcpy(temp->Name, Commands[j]);
//					strcpy(temp->Opponent, Commands[i]);
//				}
//				p1 = rand() % 6;
//				p2 = rand() % 6;
//				if (p1 > p2)
//				{
//					temp->OwnerPoints = 3;
//					temp->OppPoints = 0;
//				}
//				else if (p1 == p2)
//				{
//					temp->OwnerPoints = 1;
//					temp->OppPoints = 1;
//				}
//				else
//				{
//					temp->OwnerPoints = 0;
//					temp->OppPoints = 3;
//				}
//				//Запись счета
//				sprintf(temp->Match, " %d : %d ", p1, p2);
//				//Добавление записи
//				tournament.Insert(temp);
//			}
//		}
//}
//void main()
//{
//	srand(time(0));
//	const int N = 4;
//	char Commands[4][20] =
//	{
//	"Arsenal",
//	"Liverpool",
//	"Lids United",
//	"Manchester United"
//	};
//	//Игра
//	Game(Commands, N);
//	//Вывод результатов
//	tournament.Print(tournament.GetRoot());
//}
//#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
//#include <stdio.h>
//#include <stdlib.h> // для перехода на русский язык
//int main()
//{
//	float y;
//	system("chcp 1251"); // переходим в консоли на русский язык
//	system("cls");       // очищаем окно консоли
//	printf("Введите y: "); // выводим сообщение
//	scanf("%f", &y);     // вводим значения переменной y
//	printf("Значение переменной y=%f", y); // выводим значение переменной y
//	getchar(); getchar();
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <windows.h>
//#include <io.h>
//#include <stdio.h>
//#include<winuser.h>
//using namespace std;
////Функция, выводящая на экран строку
//void RussianMessage(const char* str) {
//	char message[100];
//	//перевод строки из кодировки Windows
//	//в кодировку MS DOS
//	CharToOem(str, message);
//	cout << message;
//}
////Функция копирования файла
//bool CopyFile(char* source, char* destination) {
//	const int size = 65536;
//	FILE* src, * dest;
//	//Открытие Файла
//	if (!(src = fopen(source, "rb"))) {
//		return false;
//	}
//	//Получение дескриптора файла
//	int handle = _fileno(src);
//	//выделение памяти под буффер
//	char* data = new char[size];
//	if (!data) {
//		return false;
//	}
//	//Открытие файла, куда будет производиться копирование
//	if (!(dest = fopen(destination, "wb"))) {
//		delete[]data;
//		return false;
//	}
//	int realsize;
//	while (!feof(src)) {
//		//Чтение данных из файла
//		realsize = fread(data, sizeof(char), size, src);
//		//Запись данных в файл
//		fwrite(data, sizeof(char), realsize, dest);
//	}
//	//Закрытие файлов
//	fclose(src);
//	fclose(dest);
//	return true;
//}
//void main() {
//	//MAX_PATH - Константа, определяющая
//	//максимальный размер пути.
//	//Даная константа содержится в stdlib.h
//	char source[_MAX_PATH];
//	char destination[_MAX_PATH];
//	char answer[20];
//	RussianMessage("\nВведите путь и название копируемого файлу : \n");
//		//Получение пути к первому файлу
//		cin.getline(source, _MAX_PATH);
//	//Проверка Существует ли файл
//	if (_access(source, 00) == -1) {
//		RussianMessage("\nУказан неверный путьили название файла\n");
//			return;
//	}
//	RussianMessage("\nВведите путь и название нового файла:\n");
//		//Получение пути к второму файлу
//		cin.getline(destination, _MAX_PATH);
//	//Проверка на существование файла
//	if (_access(destination, 00) == 0) {
//		RussianMessage("\nТакой Файл уже существует перезаписать его(1 - Да / 2 - Нет) ? \n");
//		cin.getline(answer, 20);
//		if (!strcmp(answer, "2")) {
//			RussianMessage("\nОперация отменена\n");
//			return;
//		}
//		else if (strcmp(answer, "1")) {
//			RussianMessage("\nНеправильный ввод\n");
//			return;
//		}
//		if (_access(destination, 02) == -1) {
//			RussianMessage("\nНет доступа к записи.\n");
//			return;
//		}
//	}
//	//Копирование файла
//	if (!CopyFile(source, destination)) {
//		RussianMessage("\nОшибка при работе с файлом\n");
//	}
//}
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <time.h>
#include <sys\locking.h>
#include <string.h>
#include <ctype.h>
using namespace std;
//Максимальная длина слова
#define MAX_WORD_LENGTH 21
//Кол-во попыток
int Tries = 10;
//Кол-во угаданных слов
int CountWords = 0;
//Загрузка слова
bool LoadWord(FILE* file, char* word)
{
	int i = 0;
	char s[MAX_WORD_LENGTH] = { 0 };
	//Кол-во слов в файле
	static int count = -1;
	if (count == -1)
	{
		//Подсчет количества слов
		while (!feof(file))
		{
			fgets(s, MAX_WORD_LENGTH, file);
			count++;
		}
		//Слов нет?
		if (count == 0)
			return false;
		//Возврат файлового указателя в начало файла
		fseek(file, 0, 0);
	}
	//Случайное слово
	int n = rand() % count;
	//Поиск слова
	while (i <= n)
	{
		fgets(s, MAX_WORD_LENGTH, file);
		i++;
	}
	//Определяем длину слова
	int wordlen = strlen(s);
	//Минимальная длина слова 2 буквы
	if (wordlen <= 1)
		return false;
	//Убираем Enter (в DOS'е 2 байта 13 10)
	if (s[wordlen - 1] == 10)
		s[wordlen - 2] = 0;
	else if (s[wordlen - 1] == 13)
		s[wordlen - 1] = 0;
	//Копируем слово
	strcpy(word, s);
	//Получаем дескриптор файла
	int hFile = _fileno(file);
	//Вычисляем размер файла
	int size = _filelength(hFile);
	//Блокировка файла
	fseek(file, 0, 0);
	_locking(hFile, _LK_NBLCK, size);
	return true;
}
//Игра
void Game(char* word)
{
	//Перевод в большие буквы
	strupr(word);
	int len = strlen(word);
	//Строка-копия
	char* copy = new char[len + 1];
	memset(copy, '*', len);
	copy[len] = 0;
	//Алфавит + пробелы
	char letters[52];
	int i, j = 0;
	for (i = 0; i < 26; i++)
	{
		letters[j++] = i + 'A';
		letters[j++] = ' ';
	}
	//Замыкающий ноль
	letters[51] = 0;
	//Буква
	char letter;
	char* pos;
	bool replace = false;
	do {
		//Очистка экрана
		system("cls");
		cout << copy << endl << endl;
		cout << letters << endl << endl;
		cout << "Count of tries: " << Tries << endl
			<< endl;
		cout << "Input any letter:\t";
		cin >> letter;
		//Звуковой сигнал
		Beep(500, 200);
		//if(letter >= 'A' && letter <= 'Z'
		//|| letter >= 'a' && letter <= 'z')
		//Буква?
		if (!isalpha(letter))
		{
			cout << "It's not a letter" << endl;
			//Задержка на 1 секунду
			Sleep(1000);
			continue;
		}
		//Перевод буквы в большую
		letter = toupper(letter);
		//Поиск буквы в алфавите
		pos = strchr(letters, letter);
		//Такая буква уже была
		if (pos == 0)
		{
			cout << "This letter have been already pressed" << endl;
				Sleep(1000);
			continue;
		}
		else
		{
			//Убираем букву из алфавита
			pos[0] = ' ';
		}
		//Поиск буквы в слове
		for (i = 0; i < len; i++)
		{
			if (word[i] == letter)
			{
				copy[i] = letter;
				replace = true;
			}
		}
		if (replace == false)
			Tries--;
		else
			replace = false;
		//Условие победы
		if (strcmp(word, copy) == 0)
		{
			system("cls");
			cout << copy << endl << endl;
			cout << letters << endl << endl;
			cout << "Count of tries: " << Tries <<
				endl << endl;
			cout << "Congratulation !!!" << endl;
			CountWords++;
			break;
		}
	} while (Tries != 0);
	delete[] copy;
}
void main()
{
	//Открываем файл на чтение в двоичном режиме
	FILE* f = fopen("words.txt", "rb");
	//Если файл не открылся
	if (f == 0)
	{
		//Ошибка
		perror("Open");
		return;
	}
	srand(time(0));
	char Word[20];
	//Пытаемся загрузить слово
	if (!LoadWord(f, Word))
	{
		//Если неудачно
		cout << "Error !!!" << endl;
		fclose(f);
		return;
	}
	char answer;
	//Играем, пока не надоест
	do
	{
		Game(Word);
		//Если попыток не осталось, то выход
		if (Tries == 0)
		{
			cout << "Count of words: " << CountWords << endl;
			cout << "Bye-bye" << endl;
			break;
		}
		//Если остались
		cout << "Continue ??? (Y/N)\t";
		cin >> answer;
		//Еще играем?
		if (answer == 'Y' || answer == 'y')
			if (!LoadWord(f, Word))
			{
				cout << "Error !!!" << endl;
				fclose(f);
				return;
			}
	} while (answer == 'Y' || answer == 'y');
	//получаем дескриптор
	int hFile = _fileno(f);
	//Разблокировка файла
	int size = _filelength(hFile);
	fseek(f, 0, 0);
	_locking(hFile, _LK_UNLCK, size);
	fclose(f);
}