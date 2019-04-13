#pragma once
namespace Big_cars {

	const int weight_man = 75;
// �������� ������ ��� ������ �� �����

enum key { TRUCK, BUS };
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

} // end Big_cars namespace