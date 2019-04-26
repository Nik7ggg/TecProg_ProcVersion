#pragma once

namespace Big_cars {
const int weight_man = 75; //вес одного человека
enum key { TRUCK, BUS, PASSENGER_CAR };

struct Transport {

	key k; // ключ
	Transport *next;//указатель на следующий узел
	int power;//мощность двигателя
	float fuel_consumption;//расход топлива на 100 км
};


struct Container
{
	int size_of_list; // текущая длина
	Transport *head, *tail;
};


struct Bus:Transport
{
	key k; // ключ
	Transport *next;//указатель на следующий узел
	int power;
	float fuel_consumption;//расход топлива на 100 км
	short int passengercapacity;
};


struct Truck:Transport 
{
	key k; // ключ
	Transport *next;//указатель на следующий узел
	int power;
	float fuel_consumption;//расход топлива на 100 км
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