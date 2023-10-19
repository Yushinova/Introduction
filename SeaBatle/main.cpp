#include <iostream>
#include <time.h>
#include<Windows.h>
#include<conio.h>
#include <string>
#include<io.h>
using namespace std;
enum Color
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown,
	LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Spase = 32, Enter = 13, esc = 27 };
enum DirKill { KillUp = 1, KillDown = 2, KillLeft = 3, KillRight = 4 };
enum DirShip { DrowDown = 1, DrowRight = 2 };
enum Registration { Registr = 0, Avtoriz = 1 };
enum Condition { Pusto = 0, Ranil = 5, Ubil = 6, Mimo = 7 };
enum ProverkaShot { ShotMimo = 0, ShotRanil = 1, ShotUbil = 2 };
void setCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}
void letterM(Color color, int X, int Y)
{
	int h = 10, w = 10;
	setColor(color, color);
	for (size_t i = 0; i < h; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < w; j++)
		{
			if ((i == 0 || i == 1) && (j >= 2 && j <= 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 2 || i == 3) && (j == 4 || j == 5))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 4 || i == 5) && (j == 2 || j == 3 || j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i >= 6 && i <= 9) && (j >= 2 && j <= 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else
			{
				setColor(Red, Red);
			}
			cout << "* ";
		}
		Sleep(1);
	}
	setColor(LightBlue, Black);
}
void letterO(Color color, int X, int Y)
{
	int h = 10, w = 8;
	setColor(color, color);
	for (size_t i = 0; i < h; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < w; j++)
		{
			if ((i == 0 || i == 1) && (j == 0 || j == 1 || j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i >= 2 && i <= 7) && (j >= 2 && j <= 5))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 8 || i == 9) && (j == 0 || j == 1 || j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else
			{
				setColor(Red, Red);
			}
			cout << "* ";
		}
		Sleep(1);
	}
	setColor(LightBlue, Black);
}
void letterR(Color color, int X, int Y)
{
	int h = 10, w = 8;
	setColor(color, color);
	for (size_t i = 0; i < h; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < w; j++)
		{
			if ((i == 0 || i == 1) && (j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i >= 2 && i <= 5) && (j >= 2 && j <= 5))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 6 || i == 7) && (j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 8 || i == 9) && (j >= 2 && j <= 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else
			{
				setColor(Red, Red);
			}
			cout << "* ";
		}
		Sleep(1);
	}
	setColor(LightBlue, Black);
}
void letterS(Color color, int X, int Y)
{
	int h = 10, w = 8;
	setColor(color, color);
	for (size_t i = 0; i < h; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < w; j++)
		{
			if ((i == 0 || i == 1) && (j == 0 || j == 1 || j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if (((i >= 2 && i <= 7) && (j >= 2 && j <= 5)) || ((i == 4 || i == 5) && (j == 6 || j == 7)))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 8 || i == 9) && (j == 0 || j == 1 || j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else
			{
				setColor(Red, Red);
			}
			cout << "* ";
		}
		Sleep(1);
	}
	setColor(LightBlue, Black);
}
void letterK(Color color, int X, int Y)
{
	int h = 10, w = 8;
	setColor(color, color);
	for (size_t i = 0; i < h; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < w; j++)
		{
			if ((i == 0 || i == 1) && (j >= 2 && j <= 5))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 2 || i == 3) && (j == 2 || j == 3 || j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 4 || i == 5) && (j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i >= 6 && i <= 9) && (j >= 2 && j <= 5))
			{
				setColor(LightBlue, LightBlue);
			}
			else
			{
				setColor(Red, Red);
			}
			cout << "* ";
		}
		Sleep(1);
	}
	setColor(LightBlue, Black);
}
void letterIi(Color color, int X, int Y)
{
	int h = 12, w = 10;
	setColor(color, color);
	for (size_t i = 0; i < h; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < w; j++)
		{
			if ((i == 0 || i == 1) && ((j >= 0 && j <= 3) || (j >= 6 && j <= 9)))
			{
				setColor(LightBlue, LightBlue);
			}
			else if (((i == 2 || i == 3) && (j >= 2 && j <= 7)) || ((i == 4 || i == 5) && (j >= 2 && j <= 5)) || ((i == 6 || i == 7) && (j == 2 || j == 3)))
			{
				setColor(LightBlue, LightBlue);
			}
			else if (((i == 6 || i == 7) && (j == 6 || j == 7)) || ((i == 8 || i == 9) && (j >= 4 && j <= 7)) || ((i == 10 || i == 11) && (j >= 2 && j <= 7)))
			{
				setColor(LightBlue, LightBlue);
			}
			else
			{
				setColor(Red, Red);
			}
			cout << "* ";
		}
		Sleep(1);
	}
	setColor(LightBlue, Black);
}
void letterB(Color color, int X, int Y)
{
	int h = 10, w = 8;
	setColor(color, color);
	for (size_t i = 0; i < h; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < w; j++)
		{
			if ((i == 0 || i == 1) && (j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 2 || i == 3) && (j >= 2 && j <= 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if ((i == 4 || i == 5) && (j == 6 || j == 7))
			{
				setColor(LightBlue, LightBlue);
			}
			else if (((i == 6 || i == 7) && (j >= 2 && j <= 5)) || ((i == 8 || i == 9) && (j == 6 || j == 7)))
			{
				setColor(LightBlue, LightBlue);
			}
			else
			{
				setColor(Red, Red);
			}
			cout << "* ";
		}
		Sleep(1);
	}
	setColor(LightBlue, Black);
}
void Water(int length, Color color, int X, int Y)
{
	setColor(color, color);
	setCursor(X, Y);
	for (size_t i = 0; i < length; i++)
	{

		cout << "* ";
	}

}
void Painting(Color color, int h, int w, int X, int Y)//затиралочка и отрисовка любых прямоугольников
{
	setColor(Color(color), Color(color));
	for (size_t i = 0; i < h; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < w; j++)
		{
			cout << "+";
		}
	}
	setColor(White, LightBlue);
}
struct User
{
	char login[20];
	char password[20];
	int viktory = 0;
	int loss = 0;
};
//предикат, который определяет записан ли пользователь в файл
bool isUser(FILE* file, User user, User& temp)
{
	int size, count;
	if (file != nullptr)
	{
		size = _filelength(_fileno(file));	//узнём размер файла
		if (size > 0)
		{
			count = size / sizeof(User);
			for (size_t i = 0; i < count; i++)
			{
				fread(&temp, sizeof(User), 1, file);
				if (_stricmp(temp.login, user.login) == 0)//проверяем - есть ли в файле такой логин
				{
					return true;
				}
			}
			return false;
		}
	}
}
void MenuFunc(string* arr, int size, int menu_item, int X, int Y)//вывод пунктов меню
{
	for (size_t i = 0; i < size; i++)
	{
		setCursor(X, Y + i);
		if (i == menu_item)
		{
			setColor(Red, White);
		}
		else
		{
			setColor(White, Blue);
		}

		cout << arr[i];
	}
	setColor(White, LightBlue);
}
int selectingItem(string* arr, int size, int X, int Y)//переключение пунктов меню (бывший клац клац)
{
	int menu_item = 0;
	int key;
	do
	{
		MenuFunc(arr, size, menu_item, X, Y);
		key = _getch();
		if (key == Down)
		{
			if (menu_item < size)
			{
				menu_item++;
			}
			if (menu_item == size)
			{
				menu_item = 0;
			}
		}
		if (key == Up)
		{
			if (menu_item >= 0)
			{
				menu_item--;
			}
			if (menu_item == -1)
			{
				menu_item = size - 1;
			}
		}
		if (key == Enter)
		{
			return menu_item;
		}
	} while (key != esc);
}
const int h = 22;
const int w = 42;
void SetVisualField(char visualField[h][w])// заполнение визуального поля
{
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			if (i == h - 1 || j == 0 || i == 0 || j == w - 1)
			{
				visualField[i][j] = '*';
			}
			else if (j % 4 == 0 && i % 2 != 0)
			{
				visualField[i][j] = '|';
			}
			else if (i % 2 == 0)
			{
				visualField[i][j] = '_';
			}
			else
			{
				visualField[i][j] = ' ';
			}
		}
	}
}
int size_one = 1, size_two = 2, size_three = 3, size_four = 4;//количество палуб
const int n = 12;
void SetField(int field[n][n])//заполнение скрытого поля
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i == n - 1 || j == 0 || i == 0 || j == n - 1)
			{
				field[i][j] = 9;
			}
			else
			{
				field[i][j] = 0;
			}
		}
	}
}
void PrintVisualField(char visualField[h][w], int X, int Y)//печать визуального поля
{
	for (size_t i = 0; i < h; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < w; j++)
		{
			if (visualField[i][j] == '*')
			{
				setColor(DarkGray, DarkGray);
			}
			else if (visualField[i][j] == '+')
			{
				setColor(Green, Green);
			}
			else if (visualField[i][j] == '.')
			{
				setColor(Red, Red);
			}
			else if (visualField[i][j] == '-')
			{
				setColor(LightGray, LightGray);
			}
			else if (visualField[i][j] == '1')
			{
				setColor(Black, Black);
			}
			else
			{
				setColor(Black, White);
			}
			cout << visualField[i][j];
		}
		cout << endl;
	}
	setColor(White, LightBlue);
}
void PrintField(int field[n][n], int X, int Y)//печать поля (потом скрыть)
{
	for (size_t i = 0; i < n; i++)
	{
		setCursor(X, Y + i);
		for (size_t j = 0; j < n; j++)
		{
			if (field[i][j] == 9)
			{
				setColor(White, LightGray);
			}
			else
			{
				setColor(Black, White);
			}
			cout << field[i][j];
		}
		cout << endl;
	}
	setColor(White, LightBlue);
}
bool Proverka(int field[n][n], int pos_i, int pos_j, int DirShip, int ship_size)//проверка возможности установки корабля
{
	bool key;
	for (int i = 0; i < ship_size; i++)
	{
		if (pos_i<1 || pos_j<1 || pos_i>n - 2 || pos_j>n - 2)//проверяем границы
		{
			key = false;
			break;
		}
		if ((field[pos_i - 1][pos_j - 1] >= size_one && field[pos_i - 1][pos_j - 1] <= size_four)//проверяем нет ли вокруг корабля
			|| (field[pos_i - 1][pos_j] >= size_one && field[pos_i - 1][pos_j] <= size_four)
			|| (field[pos_i - 1][pos_j + 1] >= size_one && field[pos_i - 1][pos_j + 1] <= size_four)
			|| (field[pos_i][pos_j - 1] >= size_one && field[pos_i][pos_j - 1] <= size_four)
			|| (field[pos_i][pos_j + 1] >= size_one && field[pos_i][pos_j + 1] <= size_four)
			|| (field[pos_i + 1][pos_j - 1] >= size_one && field[pos_i + 1][pos_j - 1] <= size_four)
			|| (field[pos_i + 1][pos_j] >= size_one && field[pos_i + 1][pos_j] <= size_four)
			|| (field[pos_i + 1][pos_j + 1] >= size_one && field[pos_i + 1][pos_j + 1] <= size_four))
		{
			key = false;
			break;
		}
		switch (DirShip)
		{
		case DrowDown:
			pos_i++;
			break;
		case DrowRight:
			pos_j++;
			break;
		}
		key = true;
	}
	return key;//если выходит из цикла true все проверки прошли и корабль установить возможно
}
void AutoShip(int field[n][n], int ship_size, int kol)//автоматическая расстановка кораблей
{
	int pos_i, pos_j, DirShip;
	bool key;
	do {
		do {
			key = false;
			do {
				pos_i = 1 + rand() % 10;
				pos_j = 1 + rand() % 10;
			} while (field[pos_i][pos_j] != 0);
			DirShip = 1 + rand() % 2;
			if (Proverka(field, pos_i, pos_j, DirShip, ship_size))//проверка установки корабля
			{
				key = true;
				for (int i = 0; i < ship_size; i++)
				{
					field[pos_i][pos_j] = ship_size;//установка корабля
					switch (DirShip)
					{
					case DrowDown:
						pos_i++;
						break;
					case DrowRight:
						pos_j++;
						break;
					}
				}
			}
		} while (!key);//если корабль установить возможно выходит из цикла и отнимает количество
		kol--;
	} while (kol != 0);
}
int h_cell = 2, w_cell = 4;//высота и ширина одной большой ячейки
void SetCell(char visualField[h][w], int pos_i, int pos_j, char symbol)//заполнение 1 ячейки чарового массива
{
	for (size_t i = 0; i < h_cell; i++)
	{
		for (size_t j = 0; j < w_cell; j++)
		{
			visualField[pos_i + i][pos_j + j] = symbol;
		}
	}
}
void DrowShip(int ship_size, int DirShip, int X = 56, int Y = 6)//вывод корабля для ручной установки ячейка 4х2
{
	switch (DirShip)
	{
	case DrowDown:
		for (size_t i = 0; i < ship_size * h_cell; i++)//вертикально
		{
			setCursor(X, Y + i);
			for (size_t j = 0; j < w_cell; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		break;
	case DrowRight:
		for (size_t i = 0; i < h_cell; i++)//горизонтально
		{
			setCursor(X, Y + i);
			for (size_t j = 0; j < ship_size * w_cell; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		break;
	}
}
void HandShip(char visualField[h][w], int field[n][n], int ship_size, int kol)//ручная установка кораблей
{
	int DirShip = 1, key, pos_i = 1, pos_j = 1, i_big = 1, j_big = 1, X = 56, Y = 6;
	while (kol != 0) {
		PrintVisualField(visualField, 55, 5);
		DirShip = 1 + rand() % 2;
		pos_i = 1, pos_j = 1, i_big = 1, j_big = 1, X = 56, Y = 6;
		do {
			setCursor(X, Y);
			setColor(Blue, Blue);
			DrowShip(ship_size, DirShip, X, Y);
			key = _getch();
			setCursor(X, Y);
			PrintVisualField(visualField, 55, 5);
			switch (key)
			{
			case Up:
				if (Y > 6)
				{
					Y -= 2;
					pos_i--;
					i_big -= 2;
				}
				break;
			case Left:
				if (X > 56)
				{
					X -= 4;
					pos_j--;
					j_big -= 4;
				}
				break;
			case Right:
				if (DirShip == DrowRight)
				{
					if (X < 94 - ship_size * w_cell)
					{
						X += 4;
						pos_j++;
						j_big += 4;
					}
				}
				else
				{
					if (X < 90)
					{
						X += 4;
						pos_j++;
						j_big += 4;
					}
				}
				break;
			case Down:
				if (DirShip == DrowDown)
				{
					if (Y < 26 - ship_size * h_cell)
					{
						Y += 2;
						pos_i++;
						i_big += 2;
					}
				}
				else
				{
					if (Y < 24)
					{
						Y += 2;
						pos_i++;
						i_big += 2;
					}
				}
				break;
			case Spase:
				//как сделать чтобы перключал вправо и вниз поочереди?
				if ((DirShip == DrowDown && X < 98 - ship_size * w_cell) || (DirShip == DrowRight && Y < 28 - ship_size * h_cell))//проверка от застревания в текстурах
				{
					DirShip = 1 + rand() % 2;
					DrowShip(ship_size, DirShip, X, Y);
				}
				break;
			case Enter:
				if (Proverka(field, pos_i, pos_j, DirShip, ship_size))//проверка и установка корабля
				{
					for (int i = 0; i < ship_size; i++)
					{
						field[pos_i][pos_j] = ship_size;//происходит запись в маленький массив
						SetCell(visualField, i_big, j_big, '+');//происходит запись в чаровый массив
						switch (DirShip)
						{
						case DrowDown:
							pos_i++;
							i_big += 2;
							break;
						case DrowRight:
							pos_j++;
							j_big += 4;
							break;
						}
					}
					kol--;
				}
				break;
			}
		} while (key != Enter);
	}
}
//int Shot(int field[n][n], int pos_i, int pos_j, int ship_size)
//{
//	int shot = 0, tempUp_i = pos_i, tempDown_i = pos_i, tempLeft_j = pos_j, tempRight_j = pos_j;
//	if (field[pos_i][pos_j] >= 1 && field[pos_i][pos_j] <= 4)
//	{
//		for (size_t i = 0; i < ship_size; i++)
//		{
//			if (tempUp_i < 1 || tempDown_i > n - 2 || tempLeft_j < 1 || tempRight_j > n - 2
//				|| field[tempUp_i][pos_j] == 0 || field[tempDown_i][pos_j] == 0
//				|| field[pos_i][tempLeft_j] == 0 || field[pos_i][tempRight_j] == 0
//				|| field[tempUp_i][pos_j] == 7 || field[tempDown_i][pos_j] == 7
//				|| field[pos_i][tempLeft_j] == 7 || field[pos_i][tempRight_j] == 7)
//			{
//				break;
//			}
//			tempUp_i--;
//			tempDown_i++;
//			tempLeft_j--;
//			tempRight_j++;
//			if (field[tempUp_i][pos_j] == ship_size || field[tempDown_i][pos_j] == ship_size
//				|| field[pos_i][tempLeft_j] == ship_size || field[pos_i][tempRight_j] == ship_size)
//			{
//				shot = 1;
//				break;
//			}
//			else
//			{
//				shot = 2;
//			}
//		}
//	}
//	return shot;
//}
bool ShotUp(int field[n][n], int pos_i, int pos_j, int ship_size)
{
	bool shot = false;
	do
	{
		if (pos_i < 1 || field[pos_i][pos_j] == Pusto || field[pos_i][pos_j] == Mimo)
		{
			break;
		}
		pos_i--;
		if (field[pos_i][pos_j] >= size_one && field[pos_i][pos_j] <= size_four)
		{
			shot = true;
		}

	} while (ship_size != 0);
	return shot;
}
bool ShotDown(int field[n][n], int pos_i, int pos_j, int ship_size)
{
	bool shot = false;
	do
	{
		if (pos_i > n - 2 || field[pos_i][pos_j] == Pusto || field[pos_i][pos_j] == Mimo)
		{
			break;
		}
		pos_i++;
		if (field[pos_i][pos_j] >= size_one && field[pos_i][pos_j] <= size_four)
		{
			shot = true;
		}

	} while (ship_size != 0);
	return shot;
}
bool ShotLeft(int field[n][n], int pos_i, int pos_j, int ship_size)
{
	bool shot = false;
	do
	{
		if (pos_j < 1 || field[pos_i][pos_j] == Pusto || field[pos_i][pos_j] == Mimo)
		{
			break;
		}
		pos_j--;
		if (field[pos_i][pos_j] >= size_one && field[pos_i][pos_j] <= size_four)
		{
			shot = true;
		}

	} while (ship_size != 0);
	return shot;
}
bool ShotRight(int field[n][n], int pos_i, int pos_j, int ship_size)
{
	bool shot = false;
	do
	{
		if (pos_j > n - 2 || field[pos_i][pos_j] == Pusto || field[pos_i][pos_j] == Mimo)
		{
			break;
		}
		pos_j++;
		if (field[pos_i][pos_j] >= size_one && field[pos_i][pos_j] <= size_four)
		{
			shot = true;
		}

	} while (ship_size != 0);
	return shot;
}
int Shot(int field[n][n], int pos_i, int pos_j, int ship_size)
{
	int shot = ShotMimo;
	if (field[pos_i][pos_j] >= size_one && field[pos_i][pos_j] <= size_four)
	{
		if (ShotUp(field, pos_i, pos_j, ship_size) == true || ShotDown(field, pos_i, pos_j, ship_size) == true
			|| ShotLeft(field, pos_i, pos_j, ship_size) == true || ShotRight(field, pos_i, pos_j, ship_size) == true)
		{
			shot = ShotRanil;
		}
		else
		{
			shot = ShotUbil;
		}
	}
	return shot;
}
void SetKill(int field[n][n], int ship_size)//заполнение маленького массива в случае убийства корабля
{
	int size_poisk = 3;
	do {
		for (size_t i = 1; i < n - 1; i++)
		{
			for (size_t j = 1; j < n - 1; j++)
			{
				if (field[i][j] == Ranil && (field[i - 1][j - 1] == Ubil || field[i - 1][j] == Ubil || field[i - 1][j + 1] == Ubil
					|| field[i][j - 1] == Ubil || field[i][j + 1] == Ubil || field[i + 1][j - 1] || field[i + 1][j] == Ubil || field[i + 1][j + 1] == Ubil))
				{
					field[i][j] = Ubil;
					ship_size--;
				}
			}
		}
	} while (ship_size != 0);
	for (size_t i = 1; i < n - 1; i++)
	{
		for (size_t j = 1; j < n - 1; j++)
		{
			if (field[i][j] == Ubil)
			{
				for (size_t n = 0; n < size_poisk; n++)
				{
					for (size_t k = 0; k < size_poisk; k++)
					{
						if (field[i - 1 + n][j - 1 + k] == Pusto)
						{
							field[i - 1 + n][j - 1 + k] = Mimo;//вокруг ячейки записываем 7-промах
						}
					}
				}
			}
		}
	}
}
void SetKill(char visualField[h][w], int field[n][n])//заполнение чарового массива
{
	for (size_t i = 1, i_big = 1; i < n - 1; i++, i_big += 2)
	{
		for (size_t j = 1, j_big = 1; j < n - 1; j++, j_big += 4)
		{
			if (field[i][j] == Ranil)
			{
				SetCell(visualField, i_big, j_big, '.');
			}
			if (field[i][j] == Ubil)
			{
				SetCell(visualField, i_big, j_big, '1');
			}
			if (field[i][j] == Mimo)
			{
				SetCell(visualField, i_big, j_big, '-');
			}
		}
	}
}
int main() {
	SetConsoleCP(1251);//ввод кириллицы
	SetConsoleOutputCP(1251);//вывод кириллицы
	srand(time(NULL));
	system("Color 90");
	system("mode con cols=143 lines=60");
	Water(20, Color(Blue), 1, 18);
	Water(18, Color(Blue), 105, 18);
	Water(15, Color(Blue), 3, 23);
	Water(15, Color(Blue), 110, 23);
	Water(7, Color(Blue), 10, 28);
	Water(7, Color(Blue), 115, 28);
	letterM(Color(Red), 2, 3);
	letterO(Color(Red), 25, 3);
	letterR(Color(Red), 44, 3);
	letterS(Color(Red), 63, 3);
	letterK(Color(Red), 82, 3);
	letterO(Color(Red), 101, 3);
	letterIi(Color(Red), 120, 1);
	letterB(Color(Red), 44, 17);
	letterO(Color(Red), 63, 17);
	letterIi(Color(Red), 82, 15);
	FILE* file;
	bool isCorrect = true;
	User user, temp;
	int size_item = 3, X = 20, Y = 30, menu_item_reg, size, string_size = 20, count = 0, painting_h = 10, painting_w = 100;
	string* menu_reg = new string[size_item]{ "   Регистрация   ", "   Авторизация   ", "      Выход      " };
	do {
		Painting(Color(LightBlue), painting_h, painting_w, X, Y);
		menu_item_reg = selectingItem(menu_reg, size_item, 63, 30);
		if (menu_item_reg == Registr)//регистрация
		{
			errno_t err = fopen_s(&file, "users.txt", "r");//если список существует - открываем
			Painting(Color(LightBlue), painting_h, painting_w, X, Y);
			setCursor(51, 30);
			setColor(White, Red);
			cout << " Введите логин: ";
			Painting(Color(White), 1, 25, 67, 30);
			setCursor(68, 30);
			setColor(Red, White);
			cin.getline(user.login, string_size);
			setColor(LightBlue, Red);
			setCursor(51, 32);
			setColor(White, Red);
			cout << " Введите пароль: ";
			Painting(Color(White), 1, 25, 67, 32);
			setCursor(68, 32);
			setColor(Red, White);
			cin.getline(user.password, string_size);
			setColor(White, Red);
			if (err == 0)//если список существует проверяем есть ли в нем пользователь
			{
				if (isUser(file, user, temp))//если логин совпадает с чужим
				{
					Painting(Color(LightBlue), painting_h, painting_w, X, Y);
					setCursor(65, 30);
					setColor(Red, White);
					cout << " Логин занят! \n";
					Sleep(1000);
					isCorrect = false; //перебрасываем пользователя снова в меню
				}
				else
				{
					fclose(file);
					fopen_s(&file, "users.txt", "a");
					fwrite(&user, sizeof(User), 1, file);//записали нового пользователя, если логин не совпадает
					Painting(Color(LightBlue), painting_h, painting_w, X, Y);
					setCursor(58, 30);
					setColor(Red, White);
					cout << " Регистрация прошла успешно \n";
					isCorrect = true;//выходим из меню
					Sleep(1000);
				}
				fclose(file);
			}
			if (err != 0)//список не существует, создаем пользователя сразу без проверок
			{
				Painting(Color(LightBlue), painting_h, painting_w, X, Y);
				setCursor(58, 30);
				setColor(Red, White);
				cout << " Регистрация прошла успешно \n";
				Sleep(1000);
				fopen_s(&file, "users.txt", "a");
				if (file != nullptr)
				{
					fwrite(&user, sizeof(User), 1, file);
					fclose(file);
				}
			}
		}
		else if (menu_item_reg == Avtoriz)//авторизация
		{
			Painting(Color(LightBlue), painting_h, painting_w, X, Y);
			setCursor(51, 30);
			setColor(White, Red);
			cout << " Введите логин: ";
			Painting(Color(White), 1, 25, 67, 30);
			setCursor(68, 30);
			setColor(Red, White);
			cin.getline(user.login, string_size);
			setColor(LightBlue, Red);
			setCursor(51, 32);
			setColor(White, Red);
			cout << " Введите пароль: ";
			Painting(Color(White), 1, 25, 67, 32);
			setCursor(68, 32);
			setColor(Red, White);
			cin.getline(user.password, string_size);
			setColor(White, Red);
			fopen_s(&file, "users.txt", "r");
			if (isUser(file, user, temp))//проверяем есть ли такой пользователь
			{
				Painting(Color(LightBlue), painting_h, painting_w, X, Y);
				setCursor(60, 30);
				setColor(Red, White);
				cout << " Пользователь найден! \n";
				Sleep(1000);

				if (strcmp(temp.password, user.password) == 0)//проверяем совпадает ли пароль
				{
					Painting(Color(LightBlue), painting_h, painting_w, X, Y);
					setCursor(63, 30);
					setColor(Red, White);
					cout << "Пароль верный!";
					Sleep(1000);
					isCorrect = true;
				}
				else
				{
					Painting(Color(LightBlue), painting_h, painting_w, X, Y);//перебрасываем в начало если пароль не верный
					setCursor(63, 30);
					setColor(Red, White);
					cout << "Пароль неверный!";
					Sleep(1000);
					isCorrect = false;
				}
			}
			else
			{
				Painting(Color(LightBlue), painting_h, painting_w, X, Y);//в начало, пользователь не найден
				setCursor(60, 30);
				setColor(Red, White);
				cout << " Пользователь не найден! \n";
				Sleep(1000);
				isCorrect = false;
			}
		}
		else
		{
			system("cls");
			exit(0);
		}
	} while (!isCorrect || !exit);
	Painting(Color(LightBlue), painting_h, painting_w, X, Y);
	int menu_item_game, menu_item_choice, size_item2 = 2;
	string* menu_game = new string[size_item]{ "   Играть   ", "  Правила   ", "   Выход    " };
	string* menu_choice = new string[size_item2]{ "     Ручная установка     ", " Автоматическая установка " };
	int kol_one = 4, kol_two = 3, kol_three = 2, kol_four = 1, ships_user = 10, ships_komp = 10;
	char user_visualField[h][w], komp_visualField[h][w];//визуальные игровые поля
	int user_field[n][n], komp_field[n][n];// скрытые поля
	do {
		Painting(Color(LightBlue), painting_h + 3, painting_w, 22, 30);
		menu_item_game = selectingItem(menu_game, size_item, 63, 30);
		cout << endl;
		if (menu_item_game == 0)
		{
			system("cls");
			setCursor(5, 3);
			setColor(White, Red);
			cout << "  Корабли противника  ";
			setColor(White, LightBlue);
			setCursor(55, 3);
			setColor(White, Red);
			cout << "  Мои корабли  ";
			setColor(White, LightBlue);
			SetVisualField(komp_visualField);//заполнение визуального поля противника
			PrintVisualField(komp_visualField, 5, 5);//печать визуального поля комп. 
			Painting(Color(DarkGray), 2, 8, 5, 27);
			SetVisualField(user_visualField);//заполнение визуального поля юзера
			PrintVisualField(user_visualField, 55, 5);//печать визуального поля юзера
			Painting(Color(DarkGray), 2, 8, 55, 27);
			SetField(komp_field);//заполнение массива противника
			SetField(user_field);//заполнение массива юзера
			AutoShip(komp_field, size_four, kol_four);//установка 4х палубника ДЛЯ КОМПА
			AutoShip(komp_field, size_three, kol_three);//3х
			AutoShip(komp_field, size_two, kol_two);//2х
			AutoShip(komp_field, size_one, kol_one);//1но палубника
			//PrintField(komp_field, 5, 30);//вывод поля противника УБРАТЬ
			setCursor(7, 27);
			setColor(Red, White);
			cout << " " << ships_komp << " ";
			menu_item_choice = selectingItem(menu_choice, size_item2, 102, 14);//выбор заполнения поля кораблями
			if (menu_item_choice == 0) {
				HandShip(user_visualField, user_field, size_four, kol_four);//ручная установка кораблей ЮЗЕРА
				HandShip(user_visualField, user_field, size_three, kol_three);
				HandShip(user_visualField, user_field, size_two, kol_two);
				HandShip(user_visualField, user_field, size_one, kol_one);
				setCursor(57, 27);
				setColor(Red, White);
				cout << " " << ships_user << " ";
			}
			if (menu_item_choice == 1) {
				AutoShip(user_field, size_four, kol_four);// автоматическая установка ДЛЯ ЮЗЕРА
				AutoShip(user_field, size_three, kol_three);//3х
				AutoShip(user_field, size_two, kol_two);//2х
				AutoShip(user_field, size_one, kol_one);//1но палубника
				for (size_t i = 1, i_big = 1; i < n - 1; i++, i_big += 2)//раскрашивание всех кораблей юзера
				{
					for (size_t j = 1, j_big = 1; j < n - 1; j++, j_big += 4)
					{
						if (user_field[i][j] >= 1 && user_field[i][j] <= 4)
						{
							SetCell(user_visualField, i_big, j_big, '+');//заполнение ячейки чарового массива
						}
					}
				}
				setCursor(57, 27);
				setColor(Red, White);
				cout << " " << ships_user << " ";
			}
			//PrintField(user_field, 20, 30);//вывод поля юзера УБРАТЬ
			PrintVisualField(user_visualField, 55, 5);
			char komp_ansver[] = { " ХОД ПРОТИВНИКА! " }, user_ansver[] = { " ТВОЙ ХОД! " }, mimo[] = { " МИМО! " }, ranil[] = { " РАНИЛ! " }, ubil[] = { " УБИЛ! " };
			Painting(Color(LightBlue), painting_h, 40, 100, 10);
			setCursor(99, 14);
			setColor(White, Red);
			cout << " Нажмите Enter, чтобы подбросить монетку " << endl;
			bool isShot;//переключатель и проверка для выхода из цикла комп/юзер
			bool isKill = true; //для бота переключатель добивания корабля
			int key, ship_size = 1, DirShip = 1, X = 6, Y = 6, proverkaShot = 0, size_komp = 0;
			int komp_i = 1, komp_j = 1, user_i = 1, user_j = 1, temp_i = 0, temp_j = 0, size_user = 0;
			int coin = _getch(), brosok=0, DirKill;
			if (coin == Enter)
			{
				brosok = rand() % 2;
			}
			if (brosok == 0)
			{
				isShot = true;//ходит первый комп
			}
			else
			{
				isShot = false;//ходит первый юзер
			}
			Painting(Color(LightBlue), painting_h, 50, 98, 10);
			while (ships_user != 0 && ships_komp != 0) {
				//логика КОМПА
				Sleep(800);
				if (isShot == true) {
					setCursor(102, 14);
					setColor(White, Red);
					cout << komp_ansver << endl;
					Sleep(800);
					while (isShot == true && ships_user > 0) {
						Sleep(800);
						Painting(Color(LightBlue), painting_h, 40, 100, 10);
						isShot = false;//меняем
						if (isKill == true)
						{
							do //рандом выстрела
							{
								user_i = 1 + rand() % 10;
								user_j = 1 + rand() % 10;
							} while (user_field[user_i][user_j] > size_four);
							size_user = user_field[user_i][user_j];//размер корабля или его жизни
							proverkaShot = Shot(user_field, user_i, user_j, size_user);//возвращает 1-ранил, 2-убил, 0-мимо
							if (proverkaShot == ShotRanil)//ранил в первый раз
							{
								isKill = false;//чтобы в следующий раз сюда не заходил
								isShot = true;//если ранил, ходит еще раз
								user_field[user_i][user_j] = Ranil;//происходит запись в маленький массив ранил=5
								SetKill(user_visualField, user_field);//происходит запись в чаровый массив
								PrintVisualField(user_visualField, 55, 5);
								setCursor(102, 14);
								setColor(White, Red);
								cout << ranil << endl;
								Sleep(800);
								temp_i = user_i;// запоминаем начальные позиции куда попал
								temp_j = user_j;
								DirKill = 1;//в первый раз всегда проверяет вверх
							}
							else if (proverkaShot == ShotUbil)
							{
								isShot = true;//ходит еще раз
								user_field[user_i][user_j] = Ubil;//убил=6
								SetKill(user_field, size_user - 1);
								SetKill(user_visualField, user_field);
								PrintVisualField(user_visualField, 55, 5);
								setCursor(102, 14);
								setColor(White, Red);
								cout << ubil << endl;
								isKill = true;//заходит опять на рандом выстрела
								Sleep(800);
								ships_user--;//отнимаем количество кораблей
							}
							else
							{
								isShot = false;//выходит из цикла и ходит теперь юзер
								user_field[user_i][user_j] = Mimo;//происходит запись в маленький массив промах=7
								SetKill(user_visualField, user_field);
								PrintVisualField(user_visualField, 55, 5);
								setCursor(102, 14);
								setColor(White, Red);
								cout << mimo << endl;
								isKill = true;//в следующий раз заходит на рандом выстрела
								Sleep(800);
							}
						}
						if (isKill == false)//добивание корабля
						{
							if (DirKill == KillUp)//проверка вверх
							{
								if (temp_i > 1 && user_field[temp_i - 1][temp_j] < Mimo)//если есть смысл вверх, отнимает i
								{
									temp_i--;
								}
								else
								{
									temp_i = user_i;//возвращаем последнюю удачную позицию
									DirKill = KillDown;// если нет смысла проверять вверх, переходит вниз
								}
							}
							if (DirKill == KillDown)//проверка вниз
							{
								if (temp_i < n - 2 && user_field[temp_i + 1][temp_j] < Mimo)
								{
									temp_i++;
								}
								else
								{
									temp_i = user_i;//возвращаем последнюю удачную позицию
									DirKill = KillLeft;//если нет смысла вниз, переключаем влево
								}
							}
							if (DirKill == KillLeft)//проверка лево
							{
								if (temp_j > 1 && user_field[temp_i][temp_j - 1] < Mimo)
								{
									temp_j--;
								}
								else
								{
									temp_j = user_j;//возвращаем последнюю удачную позицию
									DirKill = KillRight;//если нет смысла влево, переключаем вправо
								}
							}
							if (DirKill == KillRight)//проверка вправо
							{
								if (temp_j < n - 2 && user_field[temp_i][temp_j + 1] < Mimo)
								{
									temp_j++;
								}
							}
							proverkaShot = Shot(user_field, temp_i, temp_j, size_user);//после изменения проверяем состояние корабля и этой ячейки
							if (proverkaShot == ShotRanil)//ранил 2ой раз
							{
								isKill = false;//опять заходит на добивание
								isShot = true;//комп повторно стреляет
								user_field[temp_i][temp_j] = Ranil;//происходит запись в маленький массив ранил=5
								SetKill(user_visualField, user_field);//происходит запись в чаровый массив
								PrintVisualField(user_visualField, 55, 5);
								setCursor(102, 14);
								setColor(White, Red);
								cout << ranil << endl;
								Sleep(800);
							}
							else if (proverkaShot == ShotUbil)
							{
								isShot = true;//комп повторно стреляет
								isKill = true;//заходит на рандом выстрела
								user_field[temp_i][temp_j] = Ubil;//убил=6
								SetKill(user_field, size_user - 1);
								SetKill(user_visualField, user_field);
								PrintVisualField(user_visualField, 55, 5);
								setCursor(102, 14);
								setColor(White, Red);
								cout << ubil << endl;
								Sleep(800);
								ships_user--;
							}
							else
							{
								isShot = false;//ход юзера
								isKill = false;//в следующий раз заходим на добивание
								user_field[temp_i][temp_j] = Mimo;//происходит запись в маленький массив промах=7
								SetKill(user_visualField, user_field);
								PrintVisualField(user_visualField, 55, 5);
								setCursor(102, 14);
								setColor(White, Red);
								cout << mimo << endl;
								temp_i = user_i;//возвращаемся к последним удачным позиям
								temp_j = user_j;
								DirKill++;//переключаем направление
								Sleep(800);
							}
						}
						setCursor(57, 27);
						setColor(Red, White);
						cout << " " << ships_user << " ";//вывод кораблей внизу поля
					}
				}
				//логика юзера БОЙ
				if (isShot == false) {
					setCursor(102, 14);
					setColor(White, Red);
					cout << user_ansver << endl;
					while (!isShot && ships_komp > 0) {//пока попадает(ранил/убил) цикл продолжается
						PrintVisualField(komp_visualField, 5, 5);
						Sleep(800);
						Painting(Color(LightBlue), painting_h, 40, 100, 10);
						X = 6, Y = 6;
						komp_i = 1, komp_j = 1, proverkaShot = 0;//каждый проход переменные возврщаются к исходным
						isShot = true;//меняем 
						do {
							setCursor(X, Y);
							setColor(Blue, Blue);
							DrowShip(ship_size, DirShip, X, Y);//отрисовка курсора
							key = _getch();
							setCursor(X, Y);
							PrintVisualField(komp_visualField, 5, 5);//каждый раз отрисовывается поле
							switch (key)//ползание по полю противника
							{
							case Up:
								if (Y > 6)
								{
									Y -= 2;
									komp_i--;
								}
								break;
							case Left:
								if (X > 6)
								{
									X -= 4;
									komp_j--;
								}
								break;
							case Right:
								if (X < 42)
								{
									X += 4;
									komp_j++;
								}
								break;
							case Down:
								if (Y < 24)
								{
									Y += 2;
									komp_i++;
								}
								break;
							case Enter:
								size_komp = komp_field[komp_i][komp_j];//размер корабля или его жизни
								proverkaShot = Shot(komp_field, komp_i, komp_j, size_komp);//возвращает 1-ранил, 2-убил, 0-мимо
								if (proverkaShot == ShotRanil)
								{
									isShot = false;
									komp_field[komp_i][komp_j] = Ranil;//происходит запись в маленький массив ранил=5
									SetKill(komp_visualField, komp_field);//происходит запись в чаровый массив
									PrintVisualField(komp_visualField, 5, 5);
									setCursor(102, 14);
									setColor(White, Red);
									cout << ranil << endl;
								}
								else if (proverkaShot == ShotUbil)
								{
									isShot = false;
									komp_field[komp_i][komp_j] = Ubil;//убил=6
									SetKill(komp_field, size_komp - 1);
									SetKill(komp_visualField, komp_field);
									PrintVisualField(komp_visualField, 5, 5);
									setCursor(102, 14);
									setColor(White, Red);
									cout << ubil << endl;
									ships_komp--;
								}
								else
								{
									isShot = true;
									if (komp_field[komp_i][komp_j] == 0) {
										komp_field[komp_i][komp_j] = Mimo;//мимо=7
									}
									SetKill(komp_visualField, komp_field);
									PrintVisualField(komp_visualField, 5, 5);
									setCursor(102, 14);
									setColor(White, Red);
									cout << mimo << endl;
									Sleep(800);
								}
								break;
							}
						} while (key != Enter);
						setCursor(7, 27);
						setColor(Red, White);
						cout << " " << ships_komp << " ";
					}
				}
				//PrintVisualField(komp_visualField, 5, 5);
				//PrintField(komp_field, 5, 30);//УБРАТЬ
				//PrintField(user_field, 20, 30);
				//PrintVisualField(user_visualField, 55, 5);
			}
			painting_h = 7, painting_w = 62;
			if (ships_komp == 0)
			{
				Painting(Color(Red), painting_h, painting_w, 20, 12);
				setCursor(41, 14);
				setColor(Red, White);
				cout << "  ИГРА ОКОНЧЕНА  ";
				setCursor(41, 16);
				setColor(Red, White);
				cout << "  ТЫ ПОБЕДИЛ!!!  ";
				isCorrect = true;
			}
			else
			{
				Painting(Color(Red), painting_h, painting_w, 20, 12);
				setCursor(41, 14);
				setColor(Red, White);
				cout << "  ИГРА ОКОНЧЕНА  ";
				setCursor(38, 16);
				setColor(Red, White);
				cout << "  ПРОТИВНИК ПОБЕДИЛ!!!  ";
				isCorrect = true;
			}
		}
		if (menu_item_game == 1)
		{
			Painting(Color(Red), painting_h + 3, painting_w, 22, 30);
			setCursor(30, 31);
			setColor(White, Red);
			cout << "  Для движения вверх, используйте клавишу " << endl;
			system("chcp 866>>NULL");
			setCursor(76, 31);
			setColor(White, Black);
			cout << " " << (char)30 << " " << endl;
			system("chcp 1251>>NULL");
			setCursor(30, 33);
			setColor(White, Red);
			cout << "  Для движения вниз, используйте клавишу  " << endl;
			system("chcp 866>>NULL");
			setCursor(76, 33);
			setColor(White, Black);
			cout << " " << (char)31 << " " << endl;
			system("chcp 1251>>NULL");
			setCursor(30, 35);
			setColor(White, Red);
			cout << "  Для движения влево, используйте клавишу  " << endl;
			system("chcp 866>>NULL");
			setCursor(76, 35);
			setColor(White, Black);
			cout << " " << (char)17 << " " << endl;
			system("chcp 1251>>NULL");
			setCursor(30, 37);
			setColor(White, Red);
			cout << "  Для движения вправо, используйте клавишу  " << endl;
			system("chcp 866>>NULL");
			setCursor(76, 37);
			setColor(White, Black);
			cout << " " << (char)16 << " " << endl;
			system("chcp 1251>>NULL");
			setCursor(30, 39);
			setColor(White, Red);
			cout << "  Для поворота корабля, используйте клавишу  " << endl;
			setCursor(76, 39);
			setColor(White, Black);
			cout << " Space " << endl;
			setCursor(30, 41);
			setColor(White, Red);
			cout << "  Установить корабль или произвести выстрел  " << endl;
			setCursor(76, 41);
			setColor(White, Black);
			cout << " Enter " << endl;
			setCursor(92, 34);
			setColor(Red, White);
			cout << "  Для перехода  " << endl;
			setCursor(92, 35);
			setColor(Red, White);
			cout << " в главное меню " << endl;
			setCursor(92, 36);
			setColor(Red, White);
			cout << "    нажмите     " << endl;
			setCursor(96, 38);
			setColor(White, Black);
			cout << " Enter " << endl;
			int exit = _getch();
			if (exit == Enter)
			{
				isCorrect = false;
			}
		}
		if (menu_item_game == 2)
		{
			isCorrect = false;
			exit(0);
		}
	} while (!isCorrect);
	setCursor(34, 30);
	setColor(LightBlue, LightBlue);
	setCursor(40, 40);
}