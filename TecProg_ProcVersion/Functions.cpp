#include <fstream>
#include "Functions.h"
#include "iostream"
using namespace std;
namespace Big_cars {
	// c�������� ��������� ������� �������
	truck* InDataForTruck(ifstream &ifst);
	bus* InDataForBus(ifstream &ifst);
	void OutBus(bus *m, ofstream &ofst);
	void ChooseForOut(transport *s, ofstream &ofst);
	transport *In(ifstream &ifdt);
	void OutTruck(truck *r, ofstream &ofst);
	void Out(container &c, ofstream &ofst);
	// ���� ���������� ���������� ������ �� �����
	transport* In(ifstream &ifst)
	{
		transport *sp;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			//sp = new transport;
			// � ����� �������
			sp = (transport*)InDataForTruck(ifst);
			ifst >> sp->power;
			ifst >> sp->fuel_consumption;
			//cout << sp->power;
			sp->k = TRUCK;
			return sp;
		case 2:
			//sp = new transport;
			// � ����� �������
			sp = (transport*)InDataForBus(ifst);
			ifst >> sp->power;
			ifst >> sp->fuel_consumption;
			//cout << sp->power;
			sp->k = BUS;
			return sp;
		default:
			return 0;
		}
	}
	void OutTruck(truck *r, ofstream &ofst) {
		ofst<<", tonnage = " << r->tonnage << endl;
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
		ofst <<", pass. capacity = " << m->passengercapacity<< endl;
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
			ofst << ", Fuel_consumption=" << s->fuel_consumption;
			OutTruck((truck*)s, ofst);
			break;
		case BUS:
			ofst << "It is bus: power = " << s->power;
			ofst << ", Fuel_consumption=" << s->fuel_consumption;
			OutBus((bus*)s, ofst);
			break;
		default:
			ofst << "Incorrect object!" << endl;
		}
	}
} // end simple_shapes namespace