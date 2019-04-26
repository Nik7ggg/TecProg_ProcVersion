#pragma once

namespace Big_cars {
const int weight_man = 75; //��� ������ ��������
enum key { TRUCK, BUS, PASSENGER_CAR };

struct Transport {

	key k; // ����
	Transport *next;//��������� �� ��������� ����
	int power;//�������� ���������
	float fuel_consumption;//������ ������� �� 100 ��
};


struct Container
{
	int size_of_list; // ������� �����
	Transport *head, *tail;
};


struct Bus:Transport
{
	key k; // ����
	Transport *next;//��������� �� ��������� ����
	int power;
	float fuel_consumption;//������ ������� �� 100 ��
	short int passengercapacity;
};


struct Truck:Transport 
{
	key k; // ����
	Transport *next;//��������� �� ��������� ����
	int power;
	float fuel_consumption;//������ ������� �� 100 ��
	int  tonnage;
};


struct PassengerCar :Transport
{
	key k;
	Transport *next;
	int power;
	float fuel_consumption;
	short int full_speed;
};

}