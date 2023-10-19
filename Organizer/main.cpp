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
	COORD myCoords = { x,y };//�������������� ������������� ���������� ������ ���������
	SetConsoleCursorPosition(hStdOut, myCoords);
}
struct User
{
	string login;
	string pass;
};
struct myTime
{
	int hour;
	int minute;
	void setTime(int hour, int minute)
	{
		this->hour = hour;
		this->minute = minute;
	}
};
class Event
{
	myTime begin_event;
	myTime end_event;
	string name_event;
	int priority;//-1 ��������� 1-������� 2-������� 3- ���������� ���������
public:
	Event()
	{
		name_event = "noname";
		begin_event.hour = 0;
		begin_event.minute = 0;
		end_event.hour = 0;
		end_event.minute = 0;
		priority = 0;
	}
	Event(string name, int begin_hour, int begin_minute, int end_hour, int end_minute, int prior)
	{
		name_event = name;
		begin_event.hour = begin_hour;
		begin_event.minute = begin_minute;
		end_event.hour = end_hour;
		end_event.minute = end_minute;
		priority = prior;
	}
	Event(const Event& right)//�����������
	{
		name_event = right.name_event;
		begin_event.hour = right.begin_event.hour;
		begin_event.minute = right.begin_event.minute;
		end_event.hour = right.end_event.hour;
		end_event.minute = right.end_event.minute;
		priority = right.priority;
	}
	~Event()
	{
		//cout << "������� �������!" << endl;
	}
	void setName(string name)
	{
		name_event = name;
	}
	void setBegin(int begin_hour, int begin_minute)
	{
		if (begin_hour >= 0 && begin_hour <= 23)
		{
			begin_event.hour = begin_hour;
		}
		if (begin_minute <= 59 && begin_minute >= 0)
		{
			begin_event.minute = begin_minute;
		}
	}
	void setEnd(int end_hour, int end_minute)
	{
		if (end_hour >= 0 && end_hour <= 23)
		{
			end_event.hour = end_hour;
		}
		if (end_minute <= 59 && end_minute >= 0)
		{
			end_event.minute = end_minute;
		}
	}
	void setPriority(int prior)
	{
		if (prior >= 0 && prior <= 3)
		{
			priority = prior;
		}
	}
	void setAllEvent(string name, int begin_hour, int begin_minute, int end_hour, int end_minute, int prior)
	{
		setName(name);
		setBegin(begin_hour, begin_minute);
		setEnd(end_hour, end_minute);
		setPriority(prior);
	}
	string getName() const
	{
		return name_event;
	}
	int getBeginHour() const
	{
		return begin_event.hour;
	}
	int getBeginMinute() const
	{
		return begin_event.minute;
	}
	int getEndHour() const
	{
		return end_event.hour;
	}
	int getEndMinute() const
	{
		return end_event.minute;
	}
	int getPriority() const
	{
		return priority;
	}
	void showEvent()
	{
		if (getPriority() != 3)
		{
			cout << begin_event.hour / 10 << begin_event.hour % 10 << ":" << begin_event.minute / 10 << begin_event.minute % 10 << " - " << end_event.hour / 10 << end_event.hour % 10 << ":" << end_event.minute / 10 << end_event.minute % 10 << "\t" << name_event << endl;
		}
		else
		{
			cout << name_event << endl;
		}
	}
};
class myDay
{
	int day;
	int month;
	int year;
	vector <Event> day_events;//� ������ ���� ����� ����������� ������� ����� ���
public:
	myDay()//
	{
		day = 1;
		month = 0;
		year = 2023;
	}
	myDay(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	~myDay()
	{
		if (day_events.size() > 0)
		{
			day_events.clear();
		}
	}
	void setDay(int day)
	{
		this->day = day;
	}
	void setMonth(int month)
	{
		this->month = month;
	}
	void setYear(int year)
	{
		this->year = year;
	}
	void setAllDay(int day, int month, int year)
	{
		setDay(day);
		setMonth(month);
		setYear(year);
	}
	int getDay() const
	{
		return day;
	}
	int getMonth() const
	{
		return month;
	}
	int getYear() const
	{
		return year;
	}
	int getPriorityD(int index) const//��������� �� �������
	{
		if (day_events.size() > 0)
		{
			return day_events[index].getPriority();
		}
	}
	int getPriority(myDay obj)//���������� ���� � ���� ��� ������� ���� myDay
	{
		time_t current_time;//�����������
		time(&current_time);
		tm mytime_proverka;//��������� ��� �������� ������� ����
		localtime_s(&mytime_proverka, &current_time);//���������� �� ����
		mytime_proverka.tm_mday = obj.getDay();
		mytime_proverka.tm_mon = obj.getMonth();
		mytime_proverka.tm_year = obj.getYear() - 1900;
		mktime(&mytime_proverka);
		return mytime_proverka.tm_yday;
	}
	int getKolEvents() const
	{
		return day_events.size();
	}
	string getName(int index) const
	{
		return day_events[index].getName();
	}
	int getBeginHour(int index) const
	{
		return day_events[index].getBeginHour();
	}
	int getBeginMinute(int index) const
	{
		return day_events[index].getBeginMinute();
	}
	int getEndHour(int index) const
	{
		return day_events[index].getEndHour();
	}
	int getEndMinute(int index) const
	{
		return day_events[index].getEndMinute();
	}
	bool isEmptyEvents()
	{
		return day_events.size() == 0;
	}
	myDay getThisDay(myDay obj) const
	{
		return *this;
	}
	void pushEvent(string name, int begin_hour, int begin_minute, int end_hour, int end_minute, int prior)//�������� ������� � ������ ��� ������
	{
		Event obj(name, begin_hour, begin_minute, end_hour, end_minute, prior);
		day_events.push_back(obj);
	}
	void pushEvent(Event obj)//�������� ������� ��� ���������
	{
		day_events.push_back(obj);
	}
	//����� �������� �������
	void dellEvent(int index)//�� ������� ������� ��� ������
	{
		if (day_events.size() > 0)
		{
			day_events.erase(day_events.begin() + index);
		}
	}
	//����� ���������� �� ������� � ������� ������� ������ ���
	static bool IsTime(Event a, Event b)
	{
		return a.getBeginHour() * 60 + a.getBeginMinute() < b.getBeginHour() * 60 + b.getBeginMinute();
	}
	void sortEvents()
	{
		sort(day_events.begin(), day_events.end(), IsTime);
	}
	void showDay(int X, int Y)//����� ���� ��������������� ������� ���
	{
		sortEvents();
		setCursor(X, Y);
		setColor(Black, White);
		cout << day << "." << month << "." << year << endl;
		setColor(Black, Yellow);
		if (day_events.size() > 0)
		{
			for (size_t i = 0; i < day_events.size(); i++)
			{
				setCursor(X, Y + 1 + i);
				day_events[i].showEvent();
			}
		}
	}
	void showEvent(int index, int X, int Y)//�������� ������� �� ������� ������� �� �������
	{
		setCursor(X, Y);
		setColor(Black, White);
		if (day_events.size() > 0)
		{
			day_events[index].showEvent();
		}
	}
};
int kol_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string week[7] = { "��", "��", "��", "��", "��", "��", "��" };//0,1,2,3,4,5,6
string month_ar[12] = { "������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������" };
class Calendar
{
	vector <myDay> month_days;
public:
	~Calendar()
	{
		if (month_days.size() > 0)
		{
			month_days.clear();
		}
	}
	void clearMonth()
	{
		if (month_days.size() > 0)//������� ���������� �����
		{
			month_days.clear();
		}
	}
	bool isLeapYear(int year)//�������� �� ����������
	{
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;//����������
	}
	void setMonth(int month, int year)//��������� ������� ���� �� ���� (���� ��� �������)
	{
		int kol;
		if (month == 2 && isLeapYear(year))//�������� �������
		{
			kol = 29;
		}
		else {
			kol = kol_days[month - 1];
		}
		for (size_t i = 1; i <= kol; i++)
		{
			month_days.push_back(myDay(i, month, year));
		}
	}
	int getPriorityD(myDay hand_off, myDay obj)//������������� � ���������� ���������� ��������� �� ������ ��� � ����
	{
		int prior = 0;
		if (obj.getPriority(obj) < hand_off.getPriority(hand_off))
		{
			prior = -1;
		}
		if (obj.getPriority(obj) == hand_off.getPriority(hand_off))
		{
			prior = 1;
		}
		if (obj.getPriority(obj) > hand_off.getPriority(hand_off))
		{
			prior = 2;
		}
		if (obj.getPriorityD(0) == 3)
		{
			prior = 3;
		}
		return prior;
	}
	void setEvents(myDay hand_off, vector<myDay>& obj)//�������� ������ ������� �������� �� ����� � ��������������� ��� ������� �� ������� �����
	{
		int prior;
		for (size_t i = 0; i < month_days.size(); i++)//������� � ������� ������������ �� ���������
		{
			for (size_t j = 0; j < obj.size(); j++)
			{
				if (month_days[i].getDay() == obj[j].getDay() && month_days[i].getMonth() == obj[j].getMonth() && month_days[i].getYear() == obj[j].getYear())
				{
					prior = getPriorityD(hand_off, obj[j]);
					month_days[i].pushEvent(obj[j].getName(0), obj[j].getBeginHour(0), obj[j].getBeginMinute(0), obj[j].getEndHour(0), obj[j].getEndMinute(0), prior);
					obj.erase(obj.begin() + j);//��� ���������� ������� ��������� �� ������ �������
					j--;
				}
			}
		}
	}
	void showMonth(int X, int Y)
	{
		for (auto var : month_days)
		{
			var.showDay(X, Y);
		}
	}
	void pushEvent(myDay hand_off, int index, string name, int begin_hour, int begin_minute, int end_hour, int end_minute)//��������� ������� � ��� ��������������� ������ ���� ������
	{
		int prior = 0;
		if (month_days[index].getPriority(month_days[index]) < hand_off.getPriority(hand_off))//���������� �� ��� � ����
		{
			prior = -1;
		}
		if (month_days[index].getPriority(month_days[index]) == hand_off.getPriority(hand_off))
		{
			prior = 1;
		}
		if (month_days[index].getPriority(month_days[index]) > hand_off.getPriority(hand_off))
		{
			prior = 2;
		}
		myDay obj(month_days[index]);
		obj.pushEvent(name, begin_hour, begin_minute, end_hour, end_minute, prior);
		month_days.erase(month_days.begin() + index);
		month_days.insert(month_days.begin() + index, obj);
	}
	void pushEvent(vector<myDay>& obj)//����������� ��� ������� �� ������� ������ � ����� ������ ��� �������� ���������
	{
		int kol = 0;
		for (size_t i = 0; i < month_days.size(); i++)
		{
			if (month_days[i].getKolEvents() > 0)
			{
				kol = month_days[i].getKolEvents();
				while (kol != 0)
				{
					myDay temp(month_days[i].getDay(), month_days[i].getMonth(), month_days[i].getYear());
					temp.pushEvent(month_days[i].getName(0), month_days[i].getBeginHour(0), month_days[i].getBeginMinute(0), month_days[i].getEndHour(0), month_days[i].getEndMinute(0), month_days[i].getPriorityD(0));
					month_days[i].dellEvent(0);
					obj.push_back(temp);
					kol--;
				}
			}
		}
	}
	//�������� ������� � ������� ����
	void dellEvent(int index_day, int index_event)//�������� ������ ��� � ������ ������� ������� �� ������� ������� ���
	{
		myDay obj(month_days[index_day]);//���� �� ������� ������
		obj.dellEvent(index_event);//������� �� ���� ������� �� ������� ������� ���
		month_days.erase(month_days.begin() + index_day);//������� ���� ���� �� ������� ������
		month_days.insert(month_days.begin() + index_day, obj);//��������� ���������� ����
	}
	void showEvent(int index, int X, int Y)//������� �� ���������� ��� �� ������� ���� ������
	{
		month_days[index].showDay(X, Y);
	}
	void showEvent(int X, int Y)//������� ��� ���, ��� ���� ����� �� ������� �� ���� �����
	{
		int kol;
		setCursor(X, Y);
		setColor(Black, Yellow);
		for (auto var : month_days)
		{
			if (var.getKolEvents() > 0)
			{
				kol = var.getKolEvents();
				var.showDay(X, Y);
				Y += kol + 1;
			}
		}
	}
	bool isEmptyEvents(int index)//�������� ���� �� � ���� ��� ��������� ������ �������
	{
		return month_days[index].isEmptyEvents();
	}
	myDay operator [](int index)
	{
		return month_days[index];
	}
	void showMonth(int weekday, myDay hand_off)//����� ������+������������� ���� � ������� ���� �������
	{
		int X = 19, Y = 3;
		setCursor(X, Y);
		cout << month_ar[month_days[0].getMonth() - 1] << endl << endl;//�������� ������
		if (weekday == 0)//������� �� 0!
		{
			weekday = 6;
		}
		else
		{
			weekday--;
		}
		X = 10;
		Y += 2;
		setCursor(X, Y);
		for (size_t i = 0; i < 7; i++)
		{
			cout << week[i] << "  ";//����� ���� ������
		}
		setCursor(X - 1, Y + 1);
		for (size_t i = 0; i < 7; i++)
		{
			cout << "____";
		}
		X = 10 + (weekday * 4);
		Y += 3;
		for (size_t i = 0; i < month_days.size(); i++)
		{
			setCursor(X, Y);
			if (month_days[i].getPriorityD(0) == 1)//�������
			{
				setColor(White, LightGreen);
			}
			else if (month_days[i].getPriorityD(0) == 2)//�������
			{
				setColor(White, Blue);
			}
			else if (month_days[i].getPriorityD(0) == 3)//���������� ���������
			{
				setColor(White, Red);
			}
			else if (month_days[i].getPriorityD(0) == -1)//�������
			{
				setColor(White, DarkGray);
			}
			else if (month_days[i].getPriority(month_days[i]) == hand_off.getPriority(hand_off))//����������� ���� ������������
			{
				setColor(Red, LightGray);
			}
			else
			{
				setColor(Black, White);
			}
			cout << month_days[i].getDay() << " ";
			X += 4;
			if (X > 34)
			{
				X = 10;
				Y += 3;
			}
		}
		setColor(Black, Yellow);
	}
	//����� ������� � ������������ �� ������� �������
	int MoveCursor(int weekday, int weekend, int month, myDay hand_off)
	{
		if (weekday == 0)//������� �� 0!
		{
			weekday = 7;
		}
		if (weekend == 0)
		{
			weekend = 7;
		}
		int X = 6 + (weekday * 4), Y = 8, key, pos_i = 0, Y1, Y2;
		if ((kol_days[month] == 31 && weekday == 6 || weekday == 7) || (kol_days[month] == 30 && weekday == 7))//����� ������ �����/��� �� Y
		{
			Y1 = 20;
			Y2 = 23;
		}
		else
		{
			Y1 = 17;
			Y2 = 20;
		}
		do {
			setCursor(X, Y);
			setColor(Blue, Blue);
			cout << "  ";
			setColor(Black, White);
			key = _getch();
			setCursor(X, Y);
			showMonth(weekday, hand_off);
			switch (key)
			{
			case Up:
				if (Y > 8 && X >= 6 + (weekday * 4) || Y > 13)
				{
					Y -= 3;
					pos_i -= 7;
				}
				break;
			case Left:
				if (X > 10 && Y > 10 || X > 6 + (weekday * 4))
				{
					X -= 4;
					pos_i--;
				}
				break;
			case Right:
				if (Y <= Y2 && X < 6 + (weekend * 4) || Y <= Y1 && X < 34)
				{
					X += 4;
					pos_i++;
				}
				break;
			case Down:
				if (Y < Y1 && X <= 34 || Y < Y2 && X <= 6 + (weekend * 4))
				{
					Y += 3;
					pos_i += 7;
				}
				break;
			case Enter:
				return pos_i;
				break;
			}
		} while (key != Enter);
		return -1;
	}
};
//���� 
	//������� ��� ������ ���� �� ����� �� �����������, �������� ����� ���� ������� ������ ������
void printMenu(vector<string>masMenu, int punct, int X, int Y)
{
	for (size_t i = 0; i < masMenu.size(); i++)
	{
		if (i == punct)
		{
			setColor(LightGreen, White);
		}
		else
		{
			setColor(White, LightGreen);
		}
		setCursor(X, Y + i);
		cout << masMenu[i];
	}
	setColor(White, Black);
}
void printStrelka(vector<string>masMenu, int punct, int X, int Y, int var_strelka)//���� ����� ������� ��������� ��� ������� � ������ �����/�����
{
	for (size_t i = 0; i < masMenu.size(); i++)
	{
		if (i == punct)
		{
			setColor(LightGreen, White);
		}
		else
		{
			setColor(White, LightGreen);
		}
		setCursor(X + i * var_strelka, Y);
		cout << masMenu[i];
	}
	setColor(White, Black);
}
int choiseDellEvents(myDay obj, int(*ptr)(vector<string>, int, int))//��� ������ ������� ��� �������� �� ������� ������� ����� � ���
{
	vector<string>num;
	int k = 0, index = 0;
	string str;
	for (size_t i = 0; i < obj.getKolEvents(); i++)
	{
		str = " > ";
		num.push_back(str);
	}
	index = ptr(num, 40, 11);
	return index;//���������� ������ �������
}
int choiseMenu(vector<string>masMenu, int X, int Y)//����� ������� ���� ���
{
	int key;
	int punctNumber = 0;
	do
	{
		printMenu(masMenu, punctNumber, X, Y);
		key = _getch();//���������� ��� ������� �������
		switch (key)
		{
		case Up:
			if (punctNumber > 0)
			{
				punctNumber--;
			}
			break;

		case Down:
			if (punctNumber < masMenu.size() - 1)
			{
				punctNumber++;
			}
			break;
		case Enter:
			if (punctNumber == masMenu.size()/* - 1*/)
			{
				return -1;
			}
			return punctNumber;
			break;
		}
	} while (key != esc);
	return -1;
}
//�������� ������� ����������, ������� �� ������������ � ����
bool isUser(ifstream& FILE, User user, User& temp)
{
	if (FILE.is_open())
	{
		while (!FILE.eof())
		{
			FILE >> temp.login >> temp.pass;
			/*cout << temp.login << "\t" << temp.pass << "\n";*/
			if (temp.login.compare(user.login) == 0)
			{
				return true;
				break;
			}
		}
		return false;
	}
}
bool isEmpty(ifstream& FILE)//�������� ���� �� ����
{
	int size;
	FILE.seekg(0, ios::end);//��������� �� ������ ����� �� �����
	size = FILE.tellg();//����� �� ����� ���������� ���� ��������� ��������
	return size == 0;
}
void Painting(Color color, int h, int w, int X, int Y)//����������� � ��������� ����� ���������������
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
	setColor(White, Yellow);
}
//���� ����� ��� ������ ����� � �����
int getVar(int size_var, vector <string> menu_strelka, int X, int Y, int var_strelka)//��������� ������ ������� � ���������� ��� ������(� ���� ������� ��������� � ���������)
{
	int key, index = 0, i_vector = 5;
	do
	{
		printStrelka(menu_strelka, index, X, Y, var_strelka);
		setCursor(X + 4, Y);
		setColor(Black, White);
		cout << " " << i_vector << " ";
		key = _getch();
		switch (key)
		{
		case Left:
			index = 1;
			if (i_vector > 0)
			{
				i_vector--;
			}
			break;
		case Right:
			index = 0;
			if (i_vector < size_var - 1)
			{
				i_vector++;
			}
			break;
		case Enter:
			return i_vector;
			break;
		}
	} while (key != esc);
	return -1;
}
//������� ��������� ��������, ������� ������ ������������ �� ����������� �������
bool isNameEvent(string name)
{
	int poz;
	poz = name.find_first_of("/*+-&?.,_!#$%^()=<>");
	if (poz != name.npos)
	{
		return false;
	}
}
void setNameEvent(string& name)//���� ������������ ������ ������, ������ ����� ��� ���������� � ����
{
	int poz;
	do
	{
		poz = name.find_first_of(' ');
		if (poz != name.npos)
		{
			name.erase(name.begin() + poz);
			name.insert(name.begin() + poz, '_');
		}
	} while (poz != name.npos);
}
template<typename myType>
void copyVector(vector<myType>obj, vector<myType>& temp)//����������� ������ ��������
{
	temp.clear();
	for (size_t i = 0; i < obj.size(); i++)
	{
		temp.push_back(obj[i]);
	}
}
//��������� ������� ����������� 2 ����
void setTimeEvent(vector<int>myHour, vector<int>myMinute, vector<string>menu_strelka, int& beg_h, int& beg_m, int& end_h, int& end_m, int (*ptr2)(int, vector<string>, int, int, int))
{
	bool endTime = false;
	do
	{
		setCursor(42, 15);
		setColor(Black, Yellow);
		cout << "������ (����):";
		beg_h = getVar(myHour.size(), menu_strelka, 42, 17, 9);
		setCursor(58, 15);
		setColor(Black, Yellow);
		cout << "������ (������):";
		beg_m = getVar(myMinute.size(), menu_strelka, 58, 17, 9);
		Painting(Color(Yellow), 5, 40, 42, 15);
		setCursor(42, 15);
		setColor(Black, Yellow);
		cout << "��������� (����):";//�������� ���� ����� ��������� ������ ������� ������ �� ���� ����������
		end_h = getVar(myHour.size(), menu_strelka, 42, 17, 9);
		setCursor(62, 15);
		setColor(Black, Yellow);
		cout << "��������� (������):";
		end_m = getVar(myMinute.size(), menu_strelka, 62, 17, 9);
		if (beg_h * 60 + beg_m < end_h * 60 + end_m)
		{
			endTime = true;
		}
		else
		{
			Painting(Color(Yellow), 5, 40, 42, 15);
			setCursor(42, 15);
			setColor(Black, Yellow);
			cout << "����� ��������� ������� ";
			setCursor(42, 16);
			cout << "�� ����� ���� ������ ������� ������!";
			Sleep(1500);
			Painting(Color(Yellow), 5, 40, 42, 15);
			endTime = false;
		}
	} while (endTime == false);
}
static bool IsData(myDay a, myDay b)//���������� ������ �� �������� ��� ��� ���������� � ����� ������� �������
{
	int secA, secB;
	tm setA, setB;
	setA.tm_mday = a.getDay();
	setA.tm_mon = a.getMonth();
	setA.tm_year = a.getYear() - 1900;
	setA.tm_hour = a.getBeginHour(0);
	setA.tm_min = a.getBeginMinute(0);
	setB.tm_mday = b.getDay();
	setB.tm_mon = b.getMonth();
	setB.tm_year = b.getYear() - 1900;
	setB.tm_hour = b.getBeginHour(0);
	setB.tm_min = b.getBeginMinute(0);
	return mktime(&setA) < mktime(&setB);
}
//���������� �� ���� � ������� ������� ���� � ���������
void sortEvents(vector<myDay>& events)
{
	sort(events.begin(), events.end(), IsData);
}
//���������� 2 �������� ������� � ����������� ������� �� ��������� ���� ��� ������� � �������� ��� ������������ �������� ���������
void sortVectorData(vector<myDay>& all_holidays, myDay hand_off, myTime hand_off_time, int& var, vector<string>yes_no, int size_holidays)
{
	vector<myDay>past, future;
	int index;
	if (all_holidays.size() > size_holidays)
	{
		for (size_t i = 0; i < all_holidays.size(); i++)
		{
			if (all_holidays[i].getPriorityD(0) != 3)
			{
				if (all_holidays[i].getPriority(all_holidays[i]) - hand_off.getPriority(hand_off) == 1 || all_holidays[i].getPriority(all_holidays[i]) == hand_off.getPriority(hand_off) && all_holidays[i].getBeginHour(0) - hand_off_time.hour > 1)
				{
					future.push_back(all_holidays[i]);
				}
				if (hand_off.getPriority(hand_off) - all_holidays[i].getPriority(all_holidays[i]) == 1 || all_holidays[i].getPriority(all_holidays[i]) == hand_off.getPriority(hand_off) && hand_off_time.hour - all_holidays[i].getBeginHour(0) > 1)
				{
					past.push_back(all_holidays[i]);
				}
			}
		}
		if (var == 0)
		{
			if (future.size() > 0 || past.size() > 0)
			{
				setCursor(45, 3);
				setColor(Red, Yellow);
				cout << "������������� �������:";
				sortEvents(future);
				int i = 0;
				for (auto var : future)
				{
					i += 2;
					var.showDay(45, 3 + i);
				}
				setCursor(45, 10);
				setColor(Red, Yellow);
				cout << "��������� �������:";
				sortEvents(past);
				i = 0;
				for (auto var : past)
				{
					i += 2;
					var.showDay(45, 10 + i);
				}
				past.clear();
				future.clear();
				setCursor(45, 21);
				setColor(Red, White);
				cout << " ��������� ����������? ";
				index = choiseMenu(yes_no, 70, 21);
				if (index == 0)
				{
					var = 1;
				}
				Painting(Yellow, 40, 50, 40, 3);
			}
		}
	}
}
void changeTime(tm& mytime, myDay& hand_off, myTime& hand_off_time, vector<myDay>& all_holidays, int& var, vector<string>yes_no, int size_holidays)//����� ������������ ����� ����������������� ���������� ��� ��������� ������� ���� � ������� �� ����� � �������� �������
{
	time_t current_time;//�����������
	time(&current_time);
	tm mytime_proverka;//��������� ��� �������� ������� ����
	localtime_s(&mytime_proverka, &current_time);//���������� �� ����
	/*cout << "hand off hour:" << hand_off_time.hour << "\thand off minute:" << hand_off_time.minute << endl;*/
	/*cout << "mytime2.hour:" << mytime_proverka.tm_hour << "\tmytime2.minute:" << mytime_proverka.tm_min << endl;*/
	if ((mytime_proverka.tm_hour * 60 + mytime_proverka.tm_min) - (mytime.tm_hour * 60 + mytime.tm_min) > 0)
	{
		hand_off.setAllDay(mytime_proverka.tm_mday, mytime_proverka.tm_mon + 1, mytime_proverka.tm_year + 1900);
		hand_off_time.setTime(mytime_proverka.tm_hour, mytime_proverka.tm_min);//��������� ������� ����
		setCursor(44, 13);
		/*cout << "hand_of hour:" << hand_off_time.hour << "\thand_of minute: " << hand_off_time.minute << endl;*/
		mytime.tm_hour = mytime_proverka.tm_hour;
		mytime.tm_min = mytime_proverka.tm_min;
		if ((mytime_proverka.tm_hour * 60 + mytime_proverka.tm_min) == 0)//���� ���������� ��������� ����� ���������������� ��������� 
		{
			localtime_s(&mytime, &current_time);
			mktime(&mytime);
			myDay obj(mytime.tm_mday, mytime.tm_mon + 1, mytime.tm_year + 1900);
			cout << "�������:  ";
			obj.showDay(24, 1);
		}
		sortVectorData(all_holidays, hand_off, hand_off_time, var, yes_no, size_holidays);
	}
}
int main() {
	SetConsoleCP(1251);//���� ���������
	SetConsoleOutputCP(1251);//����� ���������
	srand(time(NULL));
	system("Color E3");
	system("mode con cols=100 lines=50");
	//����������� � �����������
	User account;
	User temp;
	myDay temp_day;
	Event temp_event;
	myDay holiday1, holiday2, holiday3, holiday4;
	string fileName;
	vector<myDay>all_holidays, temp_vector;//���� ����������� � ������������ ��� ���������
	holiday1.setAllDay(8, 3, 2023);
	holiday1.pushEvent("8_�����", 0, 0, 23, 59, 3);
	all_holidays.push_back(holiday1);
	holiday2.setAllDay(5, 10, 2023);
	holiday2.pushEvent("����_�������", 0, 0, 23, 59, 3);
	all_holidays.push_back(holiday2);
	holiday3.setAllDay(9, 5, 2023);
	holiday3.pushEvent("9_���", 0, 0, 23, 59, 3);
	all_holidays.push_back(holiday3);
	holiday4.setAllDay(31, 12, 2023);
	holiday4.pushEvent("�����_���", 0, 0, 23, 59, 3);
	all_holidays.push_back(holiday4);
	int index, index_yes_no;
	vector<string>menu{ "   �����������   ", "   �����������   ", "      �����      " };
	vector<string>menu_strelka{ " < ", " > " };
	vector<string> yes_no{ " ��  ", " ��� " };
	vector<string>add_dell{ " �������� �������      ", " ������� �������       ", " ������������� ������� " };
	vector<string>redaktor{ " ����� �������     ", " �������� �������  " };
	vector<string>choiceEvents{ "  �����������  ", "  �������      ", "  �������      ", "  ���� ������� " };//���� ������� ������� �������
	vector<int>myHour{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	vector<int>myMinute{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 };
	bool isCorrect = true;
	int count_autoriz = 0;
	int poz;
	//����������� � �����������
	do
	{
		isCorrect = true;
		index = choiseMenu(menu, 35, 15);
		if (index == 0)//����������� ������ ������� ������� /*-+_?& � �������
		{
			poz = -1;
			Painting(Color(Yellow), 10, 60, 20, 15);
			setCursor(30, 15);
			setColor(White, Green);
			cout << " ������� �����: ";
			Painting(Color(White), 1, 25, 46, 15);
			setCursor(47, 15);
			setColor(Green, White);
			getline(cin, account.login);
			poz = account.login.find_first_of("/*+-&?., _!#$%^()=<>�������������������������������");
			if (poz != account.login.npos)
			{
				setCursor(10, 18);
				cout << "����������� ������! ����� ������ �������� �� ��������� ���� � ���� ��� ��������!" << endl;
				Sleep(2000);
				Painting(Color(Yellow), 20, 80, 10, 15);
				isCorrect = false;
			}
			if (poz == -1)
			{
				ifstream readF("superuser.txt");
				if (readF.is_open())
				{
					if (isUser(readF, account, temp))
					{
						Painting(Color(Yellow), 10, 60, 20, 15);
						setCursor(28, 18);
						setColor(White, Green);
						cout << "����� �����!" << endl;
						Sleep(2000);
						Painting(Color(Yellow), 10, 60, 20, 15);
						isCorrect = false;
					}
					readF.close();
				}
				if (isCorrect)
				{
					poz = -1;
					ofstream writeF("superuser.txt", ios::app);
					setCursor(30, 17);
					setColor(White, Green);
					cout << " ������� ������: ";
					Painting(Color(White), 1, 25, 46, 17);
					setCursor(47, 17);
					setColor(Green, White);
					getline(cin, account.pass);
					poz = account.pass.find_first_of("/*+-&?., _!#$%^()=<>�������������������������������");
					if (poz != account.pass.npos)
					{
						setCursor(10, 18);
						cout << "����������� ������! ������ ������ �������� �� ��������� ���� � ���� ��� ��������!" << endl;
						Sleep(2000);
						Painting(Color(Yellow), 20, 80, 10, 15);
						isCorrect = false;
					}
					//���� ���� �� ���� - ���������� ����� ����� ������ \n
					else
					{
						if (!isEmpty(readF))
						{
							writeF << "\n" << account.login << " " << account.pass;
						}
						else
						{
							writeF << account.login << " " << account.pass;
						}
						writeF.close();
						Painting(Color(Yellow), 10, 60, 20, 15);
						setCursor(30, 15);
						setColor(White, Green);
						cout << "����������� �������!" << endl;
						Sleep(1000);
						Painting(Color(Yellow), 10, 60, 20, 15);
						fileName = account.login;//������ 8 �����
						fileName += ".txt";
						ofstream writeEvents(fileName);//������ ���������� ���������� ������ ����� �������� �����������
						for (size_t i = 0; i < all_holidays.size(); i++)
						{
							writeEvents << all_holidays[i].getDay() << " " << all_holidays[i].getMonth() << " " << all_holidays[i].getYear() << " " << all_holidays[i].getBeginHour(0) << " " << all_holidays[i].getBeginMinute(0) << " " << all_holidays[i].getEndHour(0) << " " << all_holidays[i].getEndMinute(0) << " " << all_holidays[i].getName(0) << " " << all_holidays[i].getPriorityD(0);
							if (i < all_holidays.size() - 1)//����������� ������� �� ����� ������ ����� ����� ����������
							{
								writeEvents << "\n";
							}
						}
						writeEvents.close();
						isCorrect = true;
					}
				}
			}
		}
		if (index == 1)//�����������
		{
			isCorrect = false;
			Painting(Color(Yellow), 10, 60, 20, 15);
			setCursor(30, 15);
			setColor(White, Green);
			cout << " ������� �����: ";
			Painting(Color(White), 1, 25, 46, 15);
			setCursor(47, 15);
			setColor(Green, White);
			getline(cin, account.login);
			ifstream readF("superuser.txt");
			if (readF.is_open())
			{
				if (isUser(readF, account, temp))
				{
					setCursor(70, 15);
					setColor(Green, Yellow);
					cout << "����� ������!" << endl;
					isCorrect = true;
				}
				else
				{
					setCursor(70, 15);
					setColor(Green, Yellow);
					cout << "����� �� ������!" << endl;
					Sleep(1000);
					Painting(Color(Yellow), 10, 80, 20, 15);
					isCorrect = false;
				}
				readF.close();
				if (isCorrect)
				{
					do
					{
						setCursor(30, 17);
						setColor(White, Green);
						cout << " ������� ������: ";
						Painting(Color(White), 1, 25, 46, 17);
						setCursor(47, 17);
						setColor(Green, White);
						getline(cin, account.pass);
						if (temp.pass.compare(account.pass) == 0)
						{
							setCursor(72, 17);
							setColor(Green, Yellow);
							cout << "������ ������" << endl;
							Sleep(1000);
							count_autoriz = 3;
							isCorrect = true;
						}
						else
						{
							setCursor(72, 17);
							setColor(Green, Yellow);
							cout << "������ ������" << endl;
							Sleep(1000);
							Painting(Color(Yellow), 10, 80, 20, 15);
							count_autoriz++;
							isCorrect = false;
						}
					} while (count_autoriz != 3);
				}
			}
			else
			{
				setCursor(70, 15);
				setColor(Green, Yellow);
				cout << "����� �� ������!" << endl;
				Sleep(1000);
				Painting(Color(Yellow), 10, 80, 20, 15);
				isCorrect = false;
			}
		}
	} while (!isCorrect);
	system("cls");
	time_t current_time;//�����������
	time(&current_time);
	tm mytime;//��������� ��� �������� ������� ����
	localtime_s(&mytime, &current_time);//���������� �� ����
	myDay obj(mytime.tm_mday, mytime.tm_mon + 1, mytime.tm_year + 1900);
	myDay hand_off(obj);//���� ���� ��� ���� ������������ ��� ��� ��������� ������
	myTime hand_off_time;//������� �����
	hand_off_time.setTime(mytime.tm_hour, mytime.tm_min);//��������� ������� �����
	setCursor(14, 1);
	setColor(Black, White);
	cout << "�������:  ";
	obj.showDay(24, 1);
	Calendar cal;
	index = 0;
	int pos_vector, index_choice = 0, index_event = 0;
	int day_t, month_t, year_t, beg_h, beg_m, end_h, end_m, prior_t;
	string name_t;
	all_holidays.clear();
	//��������� � ������ ���� ��� �� ����� �����
	fileName = account.login;
	fileName += ".txt";
	ifstream readEvents(fileName);
	if (readEvents.is_open())
	{
		while (!readEvents.eof())
		{
			readEvents >> day_t >> month_t >> year_t >> beg_h >> beg_m >> end_h >> end_m >> name_t >> prior_t;
			setColor(Black, Yellow);
			Event myEvent(name_t, beg_h, beg_m, end_h, end_m, prior_t);
			myDay mydayEvent(day_t, month_t, year_t);
			mydayEvent.pushEvent(myEvent);
			all_holidays.push_back(mydayEvent);
		}
	}
	readEvents.close();
	int weekend, index_strelka = 0, key, var = 0;
	bool endTime = false;
	int (*ptr)(vector<string>, int, int);//�������� ������� � �������� ���������
	int (*ptr2)(int, vector<string>, int, int, int);
	ptr2 = getVar;
	ptr = choiseMenu;
	int key_first = 0, size_holidays = 4;
	do
	{
		copyVector(all_holidays, temp_vector);
		cal.setMonth(mytime.tm_mon + 1, mytime.tm_year + 1900);//���������� ������ ���� ������� ����
		cal.setEvents(hand_off, all_holidays);//����������� ������� ������ �� ��������� ����� � ��������� �� ������ �������
		mytime.tm_mday = kol_days[mytime.tm_mon];//������ ���� ������ ���������� ���
		if (mytime.tm_mon == 1 && cal.isLeapYear(mytime.tm_year))//�������� ��� �������
		{
			mytime.tm_mday = 29;
		}
		mktime(&mytime);
		weekend = mytime.tm_wday;
		mytime.tm_mday = 1;//������ �� ������ ����� ������ ����� ������ ���� ������ 1 ���
		mktime(&mytime);
		Painting(White, 22, 30, 8, 3);//�������� �����������
		setColor(Black, White);
		cal.showMonth(mytime.tm_wday, hand_off);
		cal.showEvent(8, 26);//����� ������� ������
		if (key_first == 0)//����� ������� ������ ��� ������ ����������� ������� ���� ��� ���� ����� �� ��������������� ��� ����������� �������
		{
			sortVectorData(temp_vector, hand_off, hand_off_time, var, yes_no, size_holidays);
			key_first = 1;
		}
		printStrelka(menu_strelka, index_strelka, 12, 3, 18);
		key = _getch();
		switch (key)//������� ������
		{
		case Left:
			index_strelka = 1;
			mytime.tm_mon--;
			break;
		case Right:
			index_strelka = 0;
			mytime.tm_mon++;
			break;
		case Enter:
			pos_vector = cal.MoveCursor(mytime.tm_wday, weekend, mytime.tm_mon, hand_off);//����� �������
			index = choiseMenu(add_dell, 42, 5);
			if (index == 1)//�������� �������
			{
				if (!cal.isEmptyEvents(pos_vector))
				{
					cal[pos_vector].showDay(44, 10);
					index_event = choiseDellEvents(cal[pos_vector], ptr);
					if (cal[pos_vector].getPriorityD(index_event) == 3)//������ ������� ���������� ���������
					{
						setCursor(44, 15);
						setColor(Black, Yellow);
						cout << "������ �������/�������������!";
						Sleep(1000);
						Painting(Yellow, 10, 40, 38, 10);
					}
					else
					{
						cal.dellEvent(pos_vector, index_event);//�������� ������� � �������
						Painting(Yellow, 10, 40, 38, 10);
						cal[pos_vector].showDay(44, 10);
					}
				}
			}
			if (index == 0)//���������� �������
			{
				Painting(Yellow, 10, 40, 38, 10);
				index_choice = choiseMenu(choiceEvents, 42, 10);
				if (index_choice == 0)//����� ����������� �������� ��� ���� � ����������
				{
					name_t = "�����������";
				}
				if (index_choice == 1)
				{
					name_t = "�������";
				}
				if (index_choice == 2)
				{
					name_t = "�������";
				}
				if (index_choice == 3)
				{
					do
					{
						setCursor(58, 13);
						setColor(Black, Yellow);
						getline(cin, name_t);
						if (!isNameEvent(name_t))
						{
							setCursor(58, 13);
							setColor(Black, Yellow);
							cout << "����������� �������!";
							setCursor(58, 14);
							cout << "��������� ������ �����";
							Sleep(1000);
							Painting(Color(Yellow), 10, 40, 58, 13);
						}
					} while (!isNameEvent(name_t));//�� �������� ������� ����������� �������
					setNameEvent(name_t);//��������� �������� �������
				}
				setTimeEvent(myHour, myMinute, menu_strelka, beg_h, beg_m, end_h, end_m, ptr2);
				cal.pushEvent(hand_off, pos_vector, name_t, beg_h, beg_m, end_h, end_m);//��������� ������� �� ����
			}
			if (index == 2)//�������������� �������, ������� ��� �������
			{
				index_choice = 0;
				Painting(Color(Yellow), 40, 50, 38, 2);
				if (cal[pos_vector].getKolEvents() > 0)//������� ���� ���� �������
				{
					cal[pos_vector].showDay(44, 10);
					index_event = choiseDellEvents(cal[pos_vector], ptr);//�������� �� �������
					if (cal[pos_vector].getPriorityD(index_event) == 3)
					{
						setCursor(44, 15);
						setColor(Black, Yellow);
						cout << "������ �������/�������������!";
						Sleep(1000);
						Painting(Yellow, 10, 40, 38, 10);
					}
					else
					{
						Painting(Yellow, 30, 50, 40, 10);
						cal[pos_vector].showEvent(index_event, 42, 10);
						index_choice = choiseMenu(redaktor, 42, 12);//����� ��� �� ����������� ���� ���� ���� ��������
						if (index_choice == 0)//�������������� �� �������
						{
							setTimeEvent(myHour, myMinute, menu_strelka, beg_h, beg_m, end_h, end_m, ptr2);
							name_t = cal[pos_vector].getName(index_event);
							cal.dellEvent(pos_vector, index_event);
							cal.pushEvent(hand_off, pos_vector, name_t, beg_h, beg_m, end_h, end_m);
							Painting(Yellow, 10, 50, 38, 10);
							cal[pos_vector].showDay(44, 10);
						}
						if (index_choice == 1)//�������������� ��������
						{
							do
							{
								setCursor(62, 13);
								setColor(Black, Yellow);
								getline(cin, name_t);
								if (!isNameEvent(name_t))
								{
									setCursor(62, 13);
									setColor(Black, Yellow);
									cout << "����������� �������!";
									setCursor(62, 14);
									cout << "��������� ������ �����";
									Sleep(1000);
									Painting(Color(Yellow), 10, 40, 58, 13);
								}
							} while (!isNameEvent(name_t));
							setNameEvent(name_t);
							beg_h = cal[pos_vector].getBeginHour(index_event);
							beg_m = cal[pos_vector].getBeginMinute(index_event);
							end_h = cal[pos_vector].getEndHour(index_event);
							end_m = cal[pos_vector].getEndMinute(index_event);
							cal.dellEvent(pos_vector, index_event);
							cal.pushEvent(hand_off, pos_vector, name_t, beg_h, beg_m, end_h, end_m);
							Painting(Yellow, 10, 50, 38, 10);
							cal[pos_vector].showDay(44, 10);
						}
					}
				}
			}
			setColor(Black, White);
			break;
		}
		Painting(Color(Yellow), 40, 50, 38, 2);
		cal.pushEvent(all_holidays);//��� ������� ����������������� ��������� ������� � ����� ������
		mktime(&mytime);
		cal.clearMonth();
		Painting(Yellow, 15, 50, 0, 26);
		cal.showEvent(8, 26);//����� ������� ��� ���������� ������ ����� ���������� � ��������
		ofstream writeEvents(fileName);
		if (writeEvents.is_open())//�������������� ��� ������� � ����
		{
			for (size_t i = 0; i < all_holidays.size(); i++)
			{
				writeEvents << all_holidays[i].getDay() << " " << all_holidays[i].getMonth() << " " << all_holidays[i].getYear() << " " << all_holidays[i].getBeginHour(0) << " " << all_holidays[i].getBeginMinute(0) << " " << all_holidays[i].getEndHour(0) << " " << all_holidays[i].getEndMinute(0) << " " << all_holidays[i].getName(0) << " " << all_holidays[i].getPriorityD(0);
				if (i < all_holidays.size() - 1)
				{
					writeEvents << "\n";
				}
			}
		}
		writeEvents.close();
		changeTime(mytime, hand_off, hand_off_time, all_holidays, var, yes_no, size_holidays);//����� ���������� ���� � ������� ��� ���������
	} while (key != esc);
	setCursor(40, 40);
}