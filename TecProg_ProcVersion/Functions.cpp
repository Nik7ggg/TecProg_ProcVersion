#include <fstream>
#include "Functions.h"
#include "iostream"
#include <string>
using namespace std;
namespace Big_cars {
	float ProcessRatationPower(transport *obj);
	int GetPassengerCapasity(bus *m);
	int GetTonnage(truck *m);
	// cигнатуры требуемых внешних функций
	truck* InDataForTruck(ifstream &ifst);
	bus* InDataForBus(ifstream &ifst);
	passenger_car* InDataForPassengerCar(ifstream &ifst);
	void OutBus(bus *m, ofstream &ofst);
	void ChooseForOut(transport *s, ofstream &ofst);
	transport *In(ifstream &ifdt);
	void OutTruck(truck *r, ofstream &ofst);
	void OutPassengerCar(passenger_car *r, ofstream &ofst);
	void Out(container &c, ofstream &ofst);
	void SortList(container&obj);
	bool compare(transport*first);

	bool compare(transport* first)
	{
		float arg1 = ProcessRatationPower(first);
		float arg2 = ProcessRatationPower(first->next);
		return (arg1 > arg2);
	}
	
	void SortList(container& obj)
	{
		if (obj.len < 2)
			return;
		for (int i = 0; i < obj.len - 1; i++)
		{
			for (int k = 0; k < obj.len - 1; k++)
			{
				if (compare(obj.Head))
				{
					transport* previosly=obj.Head;

					while (previosly->next != obj.Head)
						previosly = previosly->next;

					transport *next1 = obj.Head->next;
					transport *next2 = obj.Head->next->next;

					obj.Head->next->next = obj.Head;
					obj.Head->next = next2;
					previosly->next = next1;
					obj.Head = next1;
				}

				obj.Head = obj.Head->next;
			}
			obj.Head = obj.Head->next;
		}
	}
	void OutOnlyTruck(container &c,ofstream &ofst);
	
	// ввод параметров обобщенной фигуры из файла
	transport* In(ifstream &ifst)
	{
		transport *sp;
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
			//sp = new transport;
			// в общую вынести
			sp = (transport*)InDataForTruck(ifst);
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
			
			sp = (transport*)InDataForBus(ifst);
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

			sp = (transport*)InDataForPassengerCar(ifst);
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
	void OutTruck(truck *r, ofstream &ofst) {
		ofst<<", tonnage = " << r->tonnage<<", ";
	}
	float ProcessRatationPower(transport * obj)
	{
		float temp;
		switch (obj->k) {
		case TRUCK:
			if (obj->power != 0)
			{
				temp = (float)GetTonnage((truck*)obj) / (float)obj->power;
				return temp;
			}
			else
				return -1;
			break;
		case BUS:
			if (obj->power != 0)
			{
			temp = (float)(GetPassengerCapasity((bus*)obj)*weight_man) / (float)obj->power;
			return temp;
			}
			else
				return -1;
			break;
		case PASSENGER_CAR:
			if (obj->power != 0)
			{
				temp = (float)(5 * weight_man) / (float)obj->power;
				return temp;
			}
			else
				return -1;
			break;
		default:
			return 0;
		}
		
	}
	int GetPassengerCapasity(bus * m)
	{
		return m->passengercapacity;
	}
	int GetTonnage(truck * m)
	{
		return m->tonnage;
	}
	void OutPassengerCar(passenger_car * r, ofstream & ofst)
	{
		ofst << ", full speed = " << r->full_speed<<", ";
	}
	truck* InDataForTruck(ifstream &ifst)// ввод для Грузовиков
	{
		truck *m;
		m = new truck;
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
	void Out(container &c, ofstream &ofst) {
		ofst << "Container contains " << c.len
			<< " elements." << endl;
		int i = 1;
		for (transport *temp = c.Head; i!= c.len + 1;temp = temp->next) 
		{
			
			ofst << i << ": ";
			if (temp != NULL)
			{
				ChooseForOut(temp, ofst);
			}
			else
				ofst << "Error reading data! Expected other values in the string." << endl;
			ofst << endl;
			i++;
		} 
	}

	void OutOnlyTruck(container & c, ofstream & ofst)
	{
		ofst << "Container contains " << c.len
			<< " elements." << endl;
		ofst << "Only Buses." << endl;
		int i = 1;
		for (transport *temp = c.Head; i != c.len + 1; temp = temp->next)
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
			ofst << "Error reading data! Expected other values in the string." << endl;
			ofst << endl;
			i++;
		}
	}


	// ввод содержимого контейнера из указанного потока
	void In(container &c, ifstream &ifst) {
		transport *temp=NULL;
		while (!ifst.eof()) {
			if ((temp = In(ifst)) != 0) 
			{ 
				
				temp->next = c.Head;
				if (c.Head != NULL)                       //В том случае если список не пустой
				{
					c.Tail->next = temp;                    //Запись данных в следующее за последним элементом поле
					c.Tail = temp;                          //Последний активный элемент=только что созданный.
				}
				else
				{
					c.Head = temp;
					c.Tail = temp;
				}
				c.len++; 
			}
		}
	}
	void Init(container &c) 
	{ 
		c.Head=c.Tail=NULL;
		c.len = 0; 
	}
	// Очистка контейнера от элементов
	// (освобождение памяти)
	void Clear(container &c) {
		while (c.len != 0)                        //Пока размерность списка не станет нулевой
		{
			transport *temp = c.Head->next;
			delete c.Head;                           //Освобождаем память от активного элемента
			c.Head = temp;                           //Смена адреса начала на адрес следующего элемента
			c.len--;                                //Один элемент освобожден. корректируем число элементов
		}
		c.Head = NULL;
		c.Tail = NULL;

	}
	void OutBus(bus *m, ofstream &ofst)
	{
		ofst <<", pass. capacity = " << m->passengercapacity << ", ";
	}
	bus* InDataForBus(ifstream &ifst)// ввод для автобусов
	{
		bus *m;
		m = new bus;
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

	passenger_car * InDataForPassengerCar(ifstream & ifst)
	{
		passenger_car *m;
		m = new passenger_car;
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
	void ChooseForOut(transport *s, ofstream &ofst) 
	{
		switch (s->k) {
		case TRUCK:
			ofst << "It is truck: power = " << s->power;
			ofst << ", Fuel_consumption=" << s->fuel_consumption;
			OutTruck((truck*)s, ofst);
			ofst << "Ratation of power= " << ProcessRatationPower(s);
			break;
		case BUS:
			ofst << "It is bus: power = " << s->power;
			ofst << ", Fuel_consumption=" << s->fuel_consumption;
			OutBus((bus*)s, ofst);
			ofst << "Ratation of power= " << ProcessRatationPower(s);
			break;
		case PASSENGER_CAR:
			ofst << "It is passenger car: power = " << s->power;
			ofst << ", Fuel_consumption=" << s->fuel_consumption;
			OutPassengerCar((passenger_car*)s, ofst);
			ofst << "Ratation of power= " << ProcessRatationPower(s);
			break;
		default:
			ofst << "Incorrect object!" << endl;
		}
	}
} // end simple_shapes namespace