#pragma once
namespace Big_cars {


// значения ключей для каждой из фигур

enum key { TRUCK, BUS };
struct transport {

	key k; // ключ
	transport *next;//указатель на следующий узел
	int power;//мощность двигателя
	short int fuel_consumption;//расход топлива на 100 км
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
	short int fuel_consumption;//расход топлива на 100 км
	short int passengercapacity;
};

struct truck:transport 
{
	key k; // ключ
	transport *next;//указатель на следующий узел
	int power;
	short int fuel_consumption;//расход топлива на 100 км
	int  tonnage;
};

} // end Big_cars namespace