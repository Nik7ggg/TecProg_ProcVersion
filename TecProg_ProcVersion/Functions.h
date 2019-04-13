#pragma once
namespace Big_cars {


// значения ключей для каждой из фигур

enum key { TRUCK, BUS, PASSENGER_CAR };
struct transport {

	key k; // ключ
	transport *next;//указатель на следующий узел
	int power;//мощность двигателя
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
	short int passengercapacity;
};

struct truck:transport 
{
	key k; // ключ
	transport *next;//указатель на следующий узел
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