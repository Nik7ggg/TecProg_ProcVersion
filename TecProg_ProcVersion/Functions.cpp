#include <fstream>
#include "Functions.h"
#include "iostream"
#include <string>

using namespace std;

namespace Big_cars {
	float ProcessRatationPower(Transport *obj);
	int GetPassengerCapasity(Bus *m);
	int GetTonnage(Truck *m);
	Truck* InDataForTruck(ifstream &ifst);
	Bus* InDataForBus(ifstream &ifst);
	PassengerCar* InDataForPassengerCar(ifstream &ifst);
	void OutBus(Bus *m, ofstream &ofst);
	void ChooseForOut(Transport *s, ofstream &ofst);
	Transport *In(ifstream &ifdt);
	void OutTruck(Truck *r, ofstream &ofst);
	void OutPassengerCar(PassengerCar *r, ofstream &ofst);
	void Out(Container &c, ofstream &ofst);
	void SortList(Container&obj);
	bool Сompare(Transport*first);
	void OutOnlyTruck(Container &c, ofstream &ofst);

	bool Сompare(Transport* first)
	{
		float arg1 = ProcessRatationPower(first);
		float arg2 = ProcessRatationPower(first->next);

		if (arg1 == -1 && arg2 != -1)
		{
			return true;
		}
		if (arg1 != -1 && arg2 == -1)
		{
			return false;
		}
		if (arg1 == -1 && arg2 == -1)
		{
			return false;
		}
		if (arg1 != -1 && arg2 != -1)
		{
			return (arg1 > arg2);
		}
	}
	
	void SortList(Container& obj)
	{
		if (obj.size_of_list < 2)
			return;

		for (int i = 0; i < obj.size_of_list - 1; i++)
		{
			for (int k = 0; k < obj.size_of_list - 1; k++)
			{
				if (Сompare(obj.head))
				{
					if (obj.size_of_list == 2)
					{
						obj.head = obj.head->next;
						return;
					}

					Transport* previosly=obj.head;

					while (previosly->next != obj.head)
						previosly = previosly->next;

					Transport *next1 = obj.head->next;
					Transport *next2 = obj.head->next->next;

					obj.head->next->next = obj.head;
					obj.head->next = next2;
					previosly->next = next1;
					obj.head = next1;
				}

				obj.head = obj.head->next;
			}
			obj.head = obj.head->next;
		}
	}

	// ввод параметров обобщенной фигуры из файла
	Transport* In(ifstream &ifst)
	{
		Transport *sp;
		string temp;
		int fuel_consumption;
		int power;
		ifst >> temp;
		if (temp == "\0")
		{
			return false;
		}
		if (temp.length()  > 1)
		{
			ifst.get();
			getline(ifst, temp, '\n');
			return NULL;
		}
		if (!isdigit(int(unsigned char(temp.front()))))
		{
			ifst.get();
			getline(ifst, temp, '\n');
			return NULL;
		}
		int k = stoull(temp);
		ifst >> temp;
		if (temp == "\0")
		{
			return false;
		}
		if (temp.length() > 4)
		{
			getline(ifst, temp, '\n');
			return NULL;
		}
		for (auto iter = temp.begin(); iter != temp.end(); ++iter)
		{
			if (!isdigit(int(unsigned char(*iter))))
			{
				getline(ifst, temp, '\n');
				return NULL;
			}
		}
		power = stoul(temp);

		ifst >> temp;
		if (temp == "\0")
		{
			return false;
		}
		for (auto iter = temp.begin(); iter != temp.end(); ++iter)
		{
			if (!isdigit(int(unsigned char(*iter))))
			{
				getline(ifst, temp, '\n');
				return NULL;
			}
		}
		if (temp.length() > 3)
		{
			getline(ifst, temp, '\n');
			return NULL;
		}
		fuel_consumption = stoull(temp);
		switch (k) {
		case 1:
			sp = (Transport*)InDataForTruck(ifst);
			if (!sp)
			{
				return NULL;
			}
			else
			{
				sp->k = TRUCK;
				sp->power = power;
				sp->fuel_consumption = fuel_consumption;
				return sp;
			}
		case 2:
			
			sp = (Transport*)InDataForBus(ifst);
			if (!sp)
			{
				return NULL;
			}
			else
			{
				sp->k = BUS;
				sp->power = power;
				sp->fuel_consumption = fuel_consumption;
				return sp;
			}

		case 3:

			sp = (Transport*)InDataForPassengerCar(ifst);
			if (!sp)
			{
				return NULL;
			}
			else
			{
				sp->k = PASSENGER_CAR;
				sp->power = power;
				sp->fuel_consumption = fuel_consumption;
				return sp;
			}
		default:
			getline(ifst, temp, '\n');
			return NULL;
		}
	}

	void OutTruck(Truck *r, ofstream &ofst) {
		ofst<<", tonnage = " << r->tonnage<<", ";
	}

	float ProcessRatationPower(Transport * obj)
	{
		float temp;
		switch (obj->k) {
		case TRUCK:
			if (obj->power != 0)
			{
				temp = (float)GetTonnage((Truck*)obj) / (float)obj->power;
				return temp;
			}
			else
			{
				return -1;
			}
			break;
		case BUS:
			if (obj->power != 0)
			{
			temp = (float)(GetPassengerCapasity((Bus*)obj)*weight_man) / (float)obj->power;
			return temp;
			}
			else
			{
				return -1;
			}
			break;
		case PASSENGER_CAR:
			if (obj->power != 0)
			{
				temp = (float)(5 * weight_man) / (float)obj->power;
				return temp;
			}
			else
			{
				return -1;
			}
			break;
		default:
			return 0;
		}
		
	}

	int GetPassengerCapasity(Bus * m)
	{
		return m->passengercapacity;
	}

	int GetTonnage(Truck * m)
	{
		return m->tonnage;
	}

	void OutPassengerCar(PassengerCar * r, ofstream & ofst)
	{
		ofst << ", full speed = " << r->full_speed<<", ";
	}

	Truck* InDataForTruck(ifstream &ifst)// ввод для Грузовиков
	{
		Truck *m;
		m = new Truck;
		string temp;
		ifst >> temp;
		if (temp == "\0")
		{
			return false;
		}
		if (!isdigit(int(unsigned char(temp.front()))))
		{
			getline(ifst, temp, '\n');
			return false;
		}

		m->tonnage = stoull(temp);
		return(m);
	}

	// Вывод содержимого контейнера в указанный поток
	void Out(Container &c, ofstream &ofst) {
		ofst << "Container contains " << c.size_of_list
			<< " elements." << endl;
		int i = 1;
		for (Transport *temp = c.head; i!= c.size_of_list + 1;temp = temp->next)
		{
			
			ofst << i << ": ";
			if (temp != NULL)
			{
				ChooseForOut(temp, ofst);
				ofst << endl;
			}
			else
			{
				ofst << "Error reading data! Expected other values in the string.";
			}
			i++;
		} 
	}

	void OutOnlyTruck(Container & c, ofstream & ofst)
	{
		ofst << "Container contains " << c.size_of_list
			<< " elements." << endl;
		ofst << "Only Buses." << endl;
		int i = 1;
		for (Transport *temp = c.head; i != c.size_of_list + 1; temp = temp->next)
		{

			ofst << i << ": ";
			if (temp != NULL)
			{
				if (temp->k == TRUCK)
				{
					ChooseForOut(temp, ofst);
				}
			}
			else
			{
				ofst << "Error reading data! Expected other values in the string." << endl;
			}
			ofst << endl;
			i++;
		}
	}


	// ввод содержимого контейнера из указанного потока
	void In(Container &c, ifstream &ifst) {
		Transport *temp=NULL;
		while (!ifst.eof()) {
				
				temp = In(ifst);
				if (temp == NULL)
				{
					temp = new Transport;
				}
				temp->next = c.head;
				if (c.head != NULL)                       //В том случае если список не пустой
				{
					c.tail->next = temp;                    //Запись данных в следующее за последним элементом поле
					c.tail = temp;                          //Последний активный элемент=только что созданный.
				}
				else
				{
					c.head = temp;
					c.tail = temp;
				}
				c.size_of_list++;
		}
	}

	void Init(Container &c) 
	{ 
		c.head = c.tail=NULL;
		c.size_of_list = 0;
	}

	// Очистка контейнера от элементов
	// (освобождение памяти)
	void Clear(Container &c) {
		while (c.size_of_list != 0)                        //Пока размерность списка не станет нулевой
		{
			Transport *temp = c.head->next;
			delete c.head;                           //Освобождаем память от активного элемента
			c.head = temp;                           //Смена адреса начала на адрес следующего элемента
			c.size_of_list--;                                //Один элемент освобожден. корректируем число элементов
		}

		c.head = NULL;
		c.tail = NULL;

	}

	void OutBus(Bus *m, ofstream &ofst)
	{
		ofst <<", pass. capacity = " << m->passengercapacity << ", ";
	}

	Bus* InDataForBus(ifstream &ifst)// ввод для автобусов
	{
		Bus *m;
		m = new Bus;
		string temp;
		ifst >> temp;
		if (temp == "\0")
		{
			return false;
		}
		if (temp.length() > 4)
		{
			getline(ifst, temp, '\n');
			return false;
		}
		if (!isdigit(int(unsigned char(temp.front()))))
		{
			getline(ifst, temp, '\n');
			return false;
		}

		m->passengercapacity = stoull(temp);
		return(m);
	}

	PassengerCar * InDataForPassengerCar(ifstream & ifst)
	{
		PassengerCar *m;
		m = new PassengerCar;
		string temp;
		ifst >> temp;
		if (temp == "\0")
		{
			return false;
		}
		if (temp.length() >= 4)
		{
			getline(ifst, temp, '\n');
			return false;
		}
		if (!isdigit(int(unsigned char(temp.front()))))
		{
			getline(ifst, temp, '\n');
			return false;
		}

		m->full_speed = stoull(temp);
		return(m);
	}

	// Вывод параметров текущей фигуры в поток
	void ChooseForOut(Transport *s, ofstream &ofst) 
	{
		switch (s->k) {
		case TRUCK:
			ofst << "It is truck: power = " << s->power;
			ofst << ", Fuel_consumption=" << s->fuel_consumption;
			OutTruck((Truck*)s, ofst);
			ofst << "Ratation of power= " << ProcessRatationPower(s);
			break;
		case BUS:
			ofst << "It is bus: power = " << s->power;
			ofst << ", Fuel_consumption=" << s->fuel_consumption;
			OutBus((Bus*)s, ofst);
			ofst << "Ratation of power= " << ProcessRatationPower(s);
			break;
		case PASSENGER_CAR:
			ofst << "It is passenger car: power = " << s->power;
			ofst << ", Fuel_consumption=" << s->fuel_consumption;
			OutPassengerCar((PassengerCar*)s, ofst);
			ofst << "Ratation of power= " << ProcessRatationPower(s);
			break;
		default:
			ofst << "Incorrect object!";
		}
	}
}