#pragma once
namespace Big_cars {


// �������� ������ ��� ������ �� �����

enum key { TRUCK, BUS };
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

} // end Big_cars namespace