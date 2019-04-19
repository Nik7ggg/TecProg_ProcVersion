#pragma once
namespace Big_cars {

	const int weight_man = 75;
// �������� ������ ��� ������ �� �����

enum key { TRUCK, BUS, PASSENGER_CAR };
struct transport {

	key k; // ����
	transport *next;//��������� �� ��������� ����
	int power;//�������� ���������
	float fuel_consumption;//������ ������� �� 100 ��
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
	float fuel_consumption;//������ ������� �� 100 ��
	short int passengercapacity;
};

struct truck:transport 
{
	key k; // ����
	transport *next;//��������� �� ��������� ����
	int power;
	float fuel_consumption;//������ ������� �� 100 ��
	int  tonnage;
};

struct passenger_car :transport
{
	key k;
	transport *next;
	int power;
	float fuel_consumption;
	short int full_speed;
};

} // end Big_cars namespace