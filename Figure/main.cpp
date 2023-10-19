#include <iostream>
#include <time.h>
#include <Windows.h>//	Sleep;
#include <string>
#include <vector>
#include <algorithm>
#include<conio.h>
using namespace std;
enum Color
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown,
	LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получаем дискриптор активного окна
void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27 };
void setCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}
//Описать абстрактный класс ФИГУРА.
//Поля:
//цвет
//координаты левой верхней точки
//высота
//ширина
//методы :
//показать фигуру - чисто виртуальный метод
//вернуть площадь - чисто виртальный метод
//вернуть периметр - чисто виртуальный метод
//set - методы для всех полей
//get - методы для всех полей
//перемещение фигуры

//Описать набор классов наследников :
//Прямоугольник
//Равнобедренный треугольник
//Прямоугольный треугольник
class Figure
{
protected:
	Color color = Red;
	int height = 4;
	int width = 4;
	int X = 1, Y = 1;
public:
	Figure()
	{
		color = Red;
		height = 4;
		width = 4;
		X = 1;
		Y = 1;
	}
	Figure(Color color, int height, int width, int X, int Y)
	{
		this->setColorFigure(color);
		this->setHeight(height);
		this->setWight(width);
		this->setX(X);
		this->setY(Y);
	}
	/*~Figure()
	{
		clearFigure();
	}*/
	Figure(const Figure& right)
	{
		this->setColorFigure(right.color);
		this->setHeight(right.height);
		this->setWight(right.width);
		this->setX(right.X);
		this->setY(right.Y);
	}
	void setAll(Color color, int height, int width, int X, int Y)
	{
		this->setColorFigure(color);
		this->setHeight(height);
		this->setWight(width);
		this->setX(X);
		this->setY(Y);
	}
	virtual void showFigure() = 0;
	virtual int getArea() = 0;
	virtual int getPerimeter() = 0;
	void setColorFigure(Color color)
	{
		if (color != Black)
		{
			this->color = color;
		}
	}
	void setX(const size_t X)
	{
		if (X > 0 && X < 100)
		{
			this->X = X;
		}
	}
	void setY(const size_t Y)
	{
		if (Y > 0 && Y < 100)
		{
			this->Y = Y;
		}
	}
	void setHeight(const size_t height)
	{
		if (height >= 4 && height <= 20)
		{
			this->height = height;
		}
	}
	void setWight(const size_t width)
	{
		if (width >= 4 && width <= 20)
		{
			this->width = width;
		}
	}
	Color getColorFigure()
	{
		return color;
	}
	size_t getX()
	{
		return X;
	}
	size_t getY()
	{
		return Y;
	}
	size_t getHeight()
	{
		return height;
	}
	size_t getWight()
	{
		return width;
	}
	void clearFigure()//???
	{
		setColor(Black, Black);
		for (size_t i = 0; i < height; i++)
		{
			setCursor(X, Y + i);
			for (size_t j = 0; j < width; j++)
			{
				cout << "+";
			}
		}
		setColor(White, Black);
	}
	void move()
	{
		int key;
		do {
			showFigure();
			key = _getch();
			clearFigure();
			switch (key)
			{
			case Up:
				if (Y > 1)
				{
					Y--;
				}
				break;
			case Left:
				if (X > 1)
				{
					X--;
				}
				break;
			case Right:
				if (X < 50)
				{
					X++;
				}
				break;
			case Down:
				if (Y < 50)
				{
					Y++;
				}
				break;
			case Enter:
				break;
			}
		} while (key != esc);
	}
};
class myRectangle : public Figure
{
public:
	myRectangle() : Figure(Blue, 8, 6, 2, 2)
	{

	}
	myRectangle(Color color, int height, int width, int X, int Y) : Figure(color, height, width, X, Y)
	{

	}
	void showFigure() override
	{
		setColor(color, color);
		for (size_t i = 0; i < height; i++)
		{
			setCursor(X, Y + i);
			for (size_t j = 0; j < width; j++)
			{
				cout << "+";
			}
		}
		setColor(White, Black);
	}
	int getArea() override
	{
		return height * width;
	}
	int getPerimeter() override
	{
		return 2 * height + 2 * width;
	}
};
class TriangleRavn : public Figure
{
public:
	TriangleRavn() :Figure(Green, 4, 4, 2, 2)
	{

	}
	TriangleRavn(Color color, int height, int width, int X, int Y) : Figure(color, height, width, X, Y)
	{

	}
	void showFigure() override
	{
		setColor(color, color);
		for (size_t i = 0; i < height; i++)
		{
			setCursor(X, Y + i);
			for (size_t j = 0; j < width; j++)
			{
				if (j < width / 2 - i || j >= width / 2 + i)
				{
					setColor(Black, Black);
				}
				else
				{
					setColor(color, color);
				}
				cout << "+";
			}
		}
		setColor(White, Black);
	}
	int getArea() override
	{
		return height * width / 2;
	}
	int getPerimeter() override
	{
		return width + 2 * (sqrt((width / 2) * (width / 2) + height * height));
	}
};
class TrianglePryam : public Figure
{
public:
	TrianglePryam() :Figure(Green, 8, 6, 2, 2)
	{

	}
	TrianglePryam(Color color, int height, int width, int X, int Y) : Figure(color, height, width, X, Y)
	{

	}
	void showFigure() override
	{
		setColor(color, color);
		for (size_t i = 0; i < height; i++)
		{
			setCursor(X, Y + i);
			for (size_t j = 0; j < width; j++)
			{
				if (j <= i)
				{
					setColor(color, color);
				}
				else
				{
					setColor(Black, Black);
				}
				cout << "+";
			}
		}
		setColor(White, Black);
	}
	int getArea() override
	{
		return height * width / 2;
	}
	int getPerimeter() override
	{
		return width + height + sqrt(width * width + height * height);
	}
};
void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	vector <Figure*> myFigure;
	myFigure.push_back(new myRectangle(Red, 8, 6, 1, 1));
	myFigure.push_back(new TriangleRavn(Blue, 4, 8, 10, 1));
	myFigure.push_back(new TrianglePryam(Green, 9, 9, 20, 1));
	myFigure.push_back(new myRectangle(Yellow, 5, 6, 1, 15));
	myFigure.push_back(new TriangleRavn(LightCyan, 8, 8, 10, 15));
	myFigure.push_back(new TrianglePryam(White, 5, 9, 20, 15));
	vector<Figure*>temp;
	temp.push_back(new myRectangle(Red, 8, 6, 30, 1));
	int num = 1;
	for (auto var : myFigure)
	{
		var->showFigure();
		setCursor(var->getX(), var->getY() - 1);
		cout << num++;
	}
	int indexF;
	char ansver;
	do
	{
		do
		{
			setCursor(1, 25);
			cout << "Введите номер фигуры для работы: " << endl;
			cin >> indexF;
		} while (indexF < 1 || indexF > myFigure.size());
		cout << "Area: " << myFigure[indexF - 1]->getArea() << endl;
		cout << "Perimeter: " << myFigure[indexF - 1]->getPerimeter() << endl;
		cout << "Двигайте фигуру при помощи стрелок, для перехода к следующему действию Esc" << endl;
		myFigure[indexF - 1]->showFigure();
		myFigure[indexF - 1]->move();
		setCursor(50, 25);
		cout << "Вы хотите продолжить работу? Y/N" << endl;
		setCursor(50, 26);
		cin >> ansver;
	} while (ansver != 'N' && ansver != 'n');
	system("cls");
	do
	{
		do
		{
			setCursor(1, 25);
			cout << "Для добавления фигуры введите 1 /Для удаления 2" << endl;
			cin >> ansver;
		} while (ansver != '1' && ansver != '2');
		do
		{
			setCursor(1, 27);
			cout << "Введите позицию:" << endl;
			cin >> indexF;
		} while (indexF < 1 && indexF>6);
		if (ansver == '1')
		{
			myRectangle obj(LightCyan, 4, 4, 30, 1);
			myFigure.emplace(myFigure.begin() + indexF - 1, &obj);
		}
		if (ansver == '2')
		{
			myFigure.erase(myFigure.begin() + indexF - 1);
		}
		num = 1;
		for (auto var : myFigure)
		{
			var->showFigure();
			setCursor(var->getX(), var->getY() - 1);
			cout << num++;
		}
		setCursor(1, 28);
		cout << "Вы хотите продолжить работу? Y/N" << endl;
		cin >> ansver;
	} while (ansver != 'N' && ansver != 'n');
	setCursor(0, 50);
}