#include <iostream>
#include <time.h>
#include<Windows.h>
#include<conio.h>
#include <string>
#include<io.h>
#include<vector>
#include<algorithm>
#include <exception>
#include<fstream>
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
void setCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}
/*
Описать класс студент с полями:
имя
пол
средний балл

опистаь набор методв:
заполнить поля случайными значениями
вывести объект
вернуть значение каждого поля

создать вектор студентов.
Описать функцию, принимающую указатель на предикат, для поиска студента соответствующего условиям запроса:
1) самого умного студента
2)самого отстающего студента
3)всех девочек
4)всех мальчиков
5)самого умного/отстающего мальчика/девочку

проверки организовать лямбдами
*/
class Student
{
	char gender;
	string surname;
	string name;
	class Subject
	{
		enum { kol_marks = 5 };
		string subject_name;
		double marks[kol_marks];
	public:
		Subject()//конструктор по умолчанию
		{
			setSubject_name("nomane");
			setMarks();
		}
		void setSubject_name(string subject_name)
		{
			this->subject_name = subject_name;
		}
		void setMarks()
		{
			for (size_t i = 0; i < kol_marks; i++)
			{
				marks[i] = 2 + rand() % 4;
			}
		}
		string getSubject_name()
		{
			return subject_name;
		}
		void ShowMarks()
		{
			for (size_t i = 0; i < kol_marks; i++)
			{
				cout << marks[i] << " ";
			}
		}
		double getMarks()
		{
			double sum = 0;
			for (size_t i = 0; i < kol_marks; i++)
			{
				sum += marks[i];
			}
			return sum / kol_marks;
		}
		void showSubject()
		{
			cout << getSubject_name() << ": " << getMarks() << "  ";
		}
	};
	enum { kol_subject = 3 };
	Subject subject[kol_subject];
public:
	Student()//конструктор по умолчанию
	{
		surname = "noname";
		name = "noname";
		gender = 'n';
	}
	void setSurname(string surname)
	{
		this->surname = surname;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setGender(char gender)
	{
		if (gender == 'm' || gender == 'M' || gender == 'w' || gender == 'W')
			this->gender = gender;
		else
		{
			this->gender = 'n';
		}
	}
	void setMarks()
	{
		for (size_t i = 0; i < kol_subject; i++)
		{
			subject[i].setMarks();
		}
	}
	void setSubject(const string* var_subj)
	{
		for (size_t i = 0; i < kol_subject; i++)
		{
			subject[i].setSubject_name(var_subj[i]);
		}
	}
	void setAll(char gender, string surname, string name)
	{
		if (gender == 'm' || gender == 'M' || gender == 'w' || gender == 'W')
			this->gender = gender;
		else
		{
			this->gender = 'n';
		}
		this->surname = surname;
		this->name = name;
	}
	char getGender()
	{
		return gender;
	}
	string getSurname()
	{
		return surname;
	}
	string getName()
	{
		return name;
	}
	Student getStudent(Student obj)
	{
		return obj;
	}
	double getAverage()
	{
		double sum = 0;
		for (size_t i = 0; i < kol_subject; i++)
		{
			sum += subject[i].getMarks();
		}
		return round((sum / kol_subject) * 10) / 10;
	}
	void showStudent()
	{
		cout << "name: " << getName() << " " << getSurname() << "\tgender: " << getGender() << endl;
		/*for (size_t i = 0; i < kol_subject; i++)//вся успеваемость по всем предметам
		{
			cout<<subject[i].getSubject_name()<<": ";
			subject[i].ShowMarks();
			cout << endl;
		}*/
		for (size_t i = 0; i < kol_subject; i++)
		{
			subject[i].showSubject();
		}
		cout << "\tAverage mark: " << getAverage();
		cout << endl << endl;
	}
};
Student getAll(vector <Student> group, bool(*ptr)(Student, Student))//передаем предикат и сортируем. Выводим самого верхнего в списке
{
	sort(group.begin(), group.end(), ptr);
	return group[0];
}
Student getGirlBoy(vector <Student> group, bool (*ptr)(Student), bool(*ptr1)(Student, Student))
{
	vector <Student> temp;
	for (size_t i = 0; i < group.size(); i++)
	{
		if (ptr(group[i]))
		{
			temp.push_back(group[i]);
		}
	}
	sort(temp.begin(), temp.end(), ptr1);
	return temp[0];
}
int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	string sabj[3] = { "Maht", "Eng", "Art" };
	int lenght_grupp = 8;
	string ar_name[8] = { "Mark","Jessi","Nill","Kate","Emma","Vlad","Tany","Rick" };
	string ar_surname[8] = { "Markin","Jessin","Nillon","Katerin","Emmanov","Vladov","Tanin","Rickov" };
	char ar_gender[2] = { 'm','w' };
	vector <Student> group321;//вектор студентов
	for (size_t i = 0; i < lenght_grupp; i++)//заполнение вектора студентов
	{
		Student obj;
		obj.setAll(ar_gender[rand() % 2], ar_surname[rand() % lenght_grupp], ar_name[rand() % lenght_grupp]);
		obj.setMarks();
		obj.setSubject(sabj);
		group321.push_back(obj);
	}
	Student res;
	auto Hight = [](Student a, Student b)->bool {return a.getAverage() > b.getAverage(); };//самый умный
	auto myLyambdaGirl = [=](Student a, Student b)->bool {return a.getGender() == 'w' && b.getGender() != 'w'; };//выведуться первые девочки
	auto myLyambdaBoy = [=](Student a, Student b)->bool {return a.getGender() == 'm' && b.getGender() != 'm'; };//выведуться первые мальчики
	auto isGirl = [](Student a)->bool {return a.getGender() == 'w'; };//дамы
	auto isBoy = [](Student a)->bool {return a.getGender() == 'm'; };//ребятки
	cout << "Девочки потом мальчики" << endl;
	sort(group321.begin(), group321.end(), myLyambdaGirl);//сортировка по полу (девочки первые)
	for (auto var : group321)//вывод вектора студентов
	{
		var.showStudent();
		cout << endl;
	}
	cout << "Студент глупыш" << endl;
	res = getAll(group321, [](Student a, Student b)->bool {return a.getAverage() < b.getAverage(); });
	res.showStudent();
	cout << "Студент умник" << endl;
	res = getAll(group321, [](Student a, Student b)->bool {return a.getAverage() > b.getAverage(); });
	res.showStudent();
	cout << "Самая умная девочка" << endl;
	res = getGirlBoy(group321, isGirl, Hight);
	res.showStudent();
	cout << "Самая умный мальчик" << endl;
	res = getGirlBoy(group321, isBoy, Hight);
	res.showStudent();
}