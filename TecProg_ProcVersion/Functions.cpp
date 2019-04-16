#include <fstream>
#include "Functions.h"
#include "iostream"
using namespace std;
namespace Big_cars {
	int ProcessRatationPower(transport *obj);
	int GetPassengerCapasity(bus *m);
	int GetTonnage(truck *m);
	// c�������� ��������� ������� �������
	truck* InDataForTruck(ifstream &ifst);
	bus* InDataForBus(ifstream &ifst);
	void OutBus(bus *m, ofstream &ofst);
	void ChooseForOut(transport *s, ofstream &ofst);
	transport *In(ifstream &ifdt);
	void OutTruck(truck *r, ofstream &ofst);
	void Out(container &c, ofstream &ofst);
	void SortList(container&obj);
	bool compare(transport*first);
	bool compare(transport* first)
	{
		int arg1 = ProcessRatationPower(first);
		int arg2 = ProcessRatationPower(first->next);
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
	// ���� ���������� ���������� ������ �� �����
	transport* In(ifstream &ifst)
	{
		transport *sp;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new transport;
			// � ����� �������
			sp = (transport*)InDataForTruck(ifst);
			ifst >> sp->power;
			//cout << sp->power;
			sp->k = TRUCK;
			return sp;
		case 2:
			sp = new transport;
			// � ����� �������
			sp = (transport*)InDataForBus(ifst);
			ifst >> sp->power;
			//cout << sp->power;
			sp->k = BUS;
			return sp;
		default:
			return 0;
		}
	}
	void OutTruck(truck *r, ofstream &ofst) {
		ofst<<", tonnage = " << r->tonnage<<", ";
	}
	int ProcessRatationPower(transport * obj)
	{
		int temp;
		switch (obj->k) {
		case TRUCK:
			temp = GetTonnage((truck*)obj)/ obj->power;
			return temp;
			break;
		case BUS:
			temp = (GetPassengerCapasity((bus*)obj)*weight_man) / obj->power;
			return temp;
			break;
		//case PASSENGERCAR
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
	truck* InDataForTruck(ifstream &ifst)// ���� ��� ����������
	{
		truck *m;
		m = new truck;
		//ifst >> m->power;
		ifst >> m->tonnage;
		return(m);
	}
	
	// ����� ����������� ���������� � ��������� �����
	void Out(container &c, ofstream &ofst) {
		ofst << "Container contains " << c.len
			<< " elements." << endl;
		int i = 1;
		for (transport *temp = c.Head; i!= c.len + 1;temp = temp->next) 
		{
			
			ofst << i << ": ";
			ChooseForOut(temp, ofst);
			i++;
		} 
	}


	// ���� ����������� ���������� �� ���������� ������
	void In(container &c, ifstream &ifst) {
		transport *temp=NULL;
		while (!ifst.eof()) {
			if ((temp = In(ifst)) != 0) 
			{ 
				
				temp->next = c.Head;
				if (c.Head != NULL)                       //� ��� ������ ���� ������ �� ������
				{
					c.Tail->next = temp;                    //������ ������ � ��������� �� ��������� ��������� ����
					c.Tail = temp;                          //��������� �������� �������=������ ��� ���������.
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
	// ������� ���������� �� ���������
	// (������������ ������)
	void Clear(container &c) {
		while (c.len != 0)                        //���� ����������� ������ �� ������ �������
		{
			transport *temp = c.Head->next;
			delete c.Head;                           //����������� ������ �� ��������� ��������
			c.Head = temp;                           //����� ������ ������ �� ����� ���������� ��������
			c.len--;                                //���� ������� ����������. ������������ ����� ���������
		}
		c.Head = NULL;
		c.Tail = NULL;

	}
	void OutBus(bus *m, ofstream &ofst)
	{
		ofst <<", pass. capacity = " << m->passengercapacity << ", ";
	}
	bus* InDataForBus(ifstream &ifst)// ���� ��� ���������
	{
		bus *m;
		m = new bus;
		//ifst >> m->power;// � ����� �������
		ifst >> m->passengercapacity;
		return(m);
	}

	// ����� ���������� ������� ������ � �����
	void ChooseForOut(transport *s, ofstream &ofst) 
	{
		switch (s->k) {
		case TRUCK:
			ofst << "It is truck: power = " << s->power;
			OutTruck((truck*)s, ofst);
			ofst << "Ratation of power= " << ProcessRatationPower(s) << endl;
			break;
		case BUS:
			ofst << "It is bus: power = " << s->power;
			OutBus((bus*)s, ofst);
			ofst << "Ratation of power= " << ProcessRatationPower(s) << endl;
			break;
		default:
			ofst << "Incorrect figure!" << endl;
		}
	}
} // end simple_shapes namespace