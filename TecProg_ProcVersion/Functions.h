#pragma once
namespace Big_cars {

	const int weight_man = 75;
// значения ключей для каждой из фигур

enum key { TRUCK, BUS, PASSENGER_CAR };
struct transport {

	key k; // ключ
	transport *next;//указатель на следующий узел
	int power;//мощность двигателя
	float fuel_consumption;//расход топлива на 100 км
};
 // end simple_shapes namespace
//struct transport;
// Простейший контейнер на основе одномерного массива
struct container
{
	int len; // текущая длина
	transport *Head, *Tail;
};


struct bus:transport
{
	key k; // ключ
	transport *next;//указатель на следующий узел
	int power;
	float fuel_consumption;//расход топлива на 100 км
	short int passengercapacity;
};

struct truck:transport 
{
	key k; // ключ
	transport *next;//указатель на следующий узел
	int power;
	float fuel_consumption;//расход топлива на 100 км
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