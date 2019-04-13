#pragma once
namespace Big_cars {


// �������� ������ ��� ������ �� �����

enum key { TRUCK, BUS, PASSENGER_CAR };
struct transport {

	key k; // ����
	transport *next;//��������� �� ��������� ����
	int power;//�������� ���������
};
 // end simple_shapes namespace
//struct transport;
// ���������� ��������� �� ������ ����������� �������
struct container
{
	int len; // ������� �����
	transport *Head, *Tail;
};


struct bus:transport
{
	key k; // ����
	transport *next;//��������� �� ��������� ����
	int power;
	short int passengercapacity;
};

struct truck:transport 
{
	key k; // ����
	transport *next;//��������� �� ��������� ����
	int power;
	int  tonnage;
};

struct passenger_car :transport
{
	key k;
	transport *next;
	int power;
	short int full_speed;
};

} // end Big_cars namespace