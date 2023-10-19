#include<iostream>
#include<thread>
#include<chrono>
#include<Windows.h>
#include<conio.h>
#include<mutex>
using namespace std;
using namespace std::literals::chrono_literals;
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
#define MIN_TANK_VOLUME 35//����� ����
#define MAX_TANK_VOLUME 160
#define MIN_TANK_LEVEL 5//����� ������� �������
#define MIN_ENGINE_CONSUMPTION 15//����������� �� 100��
#define MAX_ENGINE_CONSUMPTION 30
#define MAX_SPEED_MAX 320//��������
#define MAX_SPEED_MIN 140
#define MAX_ACCELERATION 40//���������
#define MIN_ACCELERATION 15
#define MIN_CONSUMPTION 0,003
class Tank
{
	const int VOLUME;//��������������
	double fuel_level;//���������
public:
	int get_VOLUME()const
	{
		return VOLUME;
	}
	double get_fuel_level()const//������� ������� �������
	{
		return fuel_level;
	}
	void fill(double fuel)//���������� ���/��� �������� ������� � ���������� ��� � ������ ������/���� ���� ��� �� ���� ������� ����� ������ 
	{
		if (fuel < 0)return;
		if (fuel + this->fuel_level > VOLUME)this->fuel_level = VOLUME;
		else this->fuel_level += fuel;//���� ����� � ���� ���� �� ���������� ����������
	}
	double give_fuel(double amount)//��������� ������� ������� �������� ����/���������� ������� ������� ������� � ����
	{
		fuel_level -= amount;
		if (fuel_level < 0)fuel_level = 0;
		return fuel_level;
	}
	Tank(int volume) :VOLUME(
		volume< MIN_TANK_VOLUME ? MIN_TANK_VOLUME :
		volume>MAX_TANK_VOLUME ? MAX_TANK_VOLUME :
		volume), fuel_level(0)//������������� � ��������� � �������� ��� ������ �����������
	{
		/*	cout << "TConstructor\t" << this << endl;*/
			//if(volume<35)volume=35;
			//if(volume>160)volume=160;
			//this->VOLUME=volume;
	}
	~Tank()
	{
		/*cout << "TDestructor\t" << this << endl;*/
	}
	void Info()const
	{
		cout << "Volume:\t" << get_VOLUME() << " liters.\n";
		cout << "Fuel:\t" << get_fuel_level() << " liters.\n";
	}
	bool is_fill()//��������� �� ���
	{
		if (get_fuel_level() > MIN_TANK_LEVEL && get_fuel_level() < VOLUME) return true;
		else return false;
	}
};
class Engine
{
	const double CONSUMPTION;
	double consumption_per_second;
	bool is_started;
public:
	Engine(double consumption) :CONSUMPTION(
		consumption<MIN_ENGINE_CONSUMPTION ? MIN_ENGINE_CONSUMPTION :
		consumption>MAX_ENGINE_CONSUMPTION ? MAX_ENGINE_CONSUMPTION :
		consumption)
	{
		set_consuption_per_second();
		is_started = false;
		/*cout << "EConstructor\t" << this << endl;*/
	}
	~Engine()
	{
		/*cout << "EDestructor\t" << this << endl;*/
	}
	void set_consuption_per_second()
	{
		consumption_per_second = CONSUMPTION * 3e-5;
	}
	double get_consuption_per_second()const
	{
		return consumption_per_second;
	}
	double get_consuption()const
	{
		return CONSUMPTION;
	}
	void start()//���� �������� ��� ��������� �� ���//�� ������� ������ �� �� �������� ���� �� ���������
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	bool started()
	{
		return is_started;
	}
	void Info()const
	{
		cout << "������ �� 100 ��.:  " << CONSUMPTION << " �." << endl;
		cout << "������ �� 1 �������: " << consumption_per_second << " �." << endl;
		cout << "��������� " << (is_started ? "ON" : "OFF") << endl;//���������
	}
};
class Car
{
	Tank tank;
	Engine engine;
	int speed;
	const int MAX_SPEED;
	const int ACCELERATION;
	bool driver_inside;
	struct
	{
		std::thread panel_thread;
		std::thread idle_thread;
		std::thread friction_force;
	}threads;
public:
	Car(Tank tank, Engine engine, int max_speed = 250, int accelleration = 10) :
		tank(tank),
		engine(engine),
		speed(0),
		MAX_SPEED
		(
			max_speed< MAX_SPEED_MIN ? MAX_SPEED_MIN :
			max_speed>MAX_SPEED_MAX ? MAX_SPEED_MAX :
			max_speed),
		ACCELERATION
		(
			accelleration > MAX_ACCELERATION ? MAX_ACCELERATION :
			accelleration < MIN_ACCELERATION ? MIN_ACCELERATION :
			accelleration)
	{
		driver_inside = false;
		cout << "Your car is ready, press Enter to get in" << endl;
	}
	~Car()
	{
		cout << "Car :-(" << endl;
	}
	int get_speed()
	{
		return speed;
	}
	void driver_in()//��������� �����, ����� �������� � ������ ��� ������ ������
	{
		driver_inside = true;
		threads.panel_thread = std::thread(&Car::panel, this);
	}
	void driver_out()
	{
		system("cls");
		driver_inside = false;
		if (threads.panel_thread.joinable())threads.panel_thread.join();
		cout << "�� �����! ����� ���������� ������� F" << endl;
		std::this_thread::sleep_for(1s);
	}
	void panel()
	{
		while (driver_inside)
		{
			system("cls");
			cout << "�� � ������! ����� ������� I/������� Up/��������� Down/����� Enter" << endl;
			cout << "������� �������: " << tank.get_fuel_level() << " ������" << endl;
			cout << "���������: " << (engine.started() ? "�������" : "��������") << endl;
			cout << "��������: " << speed << " ��/�" << endl;
			alarm();
			std::this_thread::sleep_for(1s);
		}
	}
	mutex mtx;
	void friction()
	{
		mtx.lock();
		while (speed > 0)
		{
			speed -= 1;
			if (speed < 1)speed = 0;
			std::this_thread::sleep_for(1s);
			cout << "Friction" << endl;
		}
		mtx.unlock();
	}
	//������� ������
	void idle_car()//��� ������� ����������� ������ ����������� ����������
	{
		while (engine.started() && tank.give_fuel(engine.get_consuption_per_second()))
		{
			if (tank.get_fuel_level() == 0) engine.stop();
			std::this_thread::sleep_for(1s);
		}
	}
	double consuption_per_second(int speed)//������ �� ��������
	{
		if (speed >= 1 && speed <= 60) return 0.0020;
		if (speed >= 61 && speed <= 100) return 0.0014;
		if (speed >= 101 && speed <= 140) return 0.0020;
		if (speed >= 141 && speed <= 200) return 0.0025;
		if (speed >= 201 && speed <= 250) return 0.0030;

	}
	void move_car()
	{
		speed += ACCELERATION;
		if (speed > MAX_SPEED)speed = MAX_SPEED;
		tank.give_fuel(consuption_per_second(speed));
		cout << "Consuption: " << consuption_per_second(speed) << endl;
		std::this_thread::sleep_for(1s);
		threads.friction_force = std::thread(&Car::friction, this);
		if (threads.friction_force.joinable())threads.friction_force.detach();
	}
	void brake_car()
	{
		speed -= ACCELERATION;
		if (speed < 1)speed = 0;
		tank.give_fuel(consuption_per_second(speed));//�������� ����������� ��������
		std::this_thread::sleep_for(1s);
		threads.friction_force = std::thread(&Car::friction, this);
		if (threads.friction_force.joinable())threads.friction_force.detach();
	}
	void stop_car()
	{
		engine.stop();
		if (threads.idle_thread.joinable())threads.idle_thread.join();
	}
	void start_car()//��������� ����� ��� ������ ������, ����� ����������� �������, ���� ��������
	{
		engine.start();
		threads.idle_thread = std::thread(&Car::idle_car, this);
	}
	void alarm()//���������
	{
		if (!tank.is_fill()) cout << "������ ������� �������!!!!!!!" << endl;
	}
	void car_brain()//���������� �������
	{
		char key = 0;
		bool Stop = false;
		do
		{
			if (_kbhit)//���������� ��������� ��������, ���� �� ������ ������
			key = _getch();//�������� ���������� ��� �������
			switch (key)
			{
			case Enter:if (!engine.started()) driver_inside ? driver_out() : driver_in();//����������� �� ���� �� �����)) �� ���� ����������!
				break;
			case 'F'://����������
			case 'f':
				if (driver_inside)//���� ������ �� �������� � �������� �����, ����������
				{
					cout << "����� ����� �� ������!" << endl;
					break;
				}
				double kol_fuel;
				cout << "���������: "; cin >> kol_fuel;
				tank.fill(kol_fuel);
				break;
			case 'I'://���������
			case 'i':
				if (driver_inside && speed == 0)
				{
					engine.started() ? stop_car() : start_car();
				}
				break;
			case esc://��������� � �������
				if (speed == 0 && !engine.started())
				{
					driver_out();
					cout << "Bye!" << endl;
					Stop = true;
				}
				else cout << "�� ������ ������������ � ��������� ���������!" << endl;
				std::this_thread::sleep_for(1s);
				break;
				}
				if (tank.get_fuel_level() == 0) stop_car();
				if (GetAsyncKeyState(VK_DOWN))
				{
					if (driver_inside && engine.started())
					{
						brake_car();
					}
				}
				if (GetAsyncKeyState(VK_UP))
				{
					if (driver_inside && engine.started())
					{
						move_car();
					}
				}
			} while (!Stop);
		}
		void Info()const
		{
			engine.Info();
			tank.Info();
			cout << "Max speed:    \t" << MAX_SPEED << " km/h\n";
			cout << "Acceleration:\t" << ACCELERATION << " km/h\n";
			cout << "Speed:\t\t\t" << speed << " km/h\n";
		}
	};

#define TANK_CHECK
#define ENGINE_CHECK
	void main()
	{
		setlocale(LC_ALL, "");
#ifdef TANK_CHECK
		Tank tank(20);//����������� ���
#endif // TANK_CHECK
#ifdef ENGINE_CHECK
		Engine engine(15);//����������� ������
#endif // ENGINE_CHECK
		Car car(tank, engine);
		car.car_brain();
	}