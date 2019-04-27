#include "stdafx.h"
#include "CppUnitTest.h"
#include "Functions.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Functions.cpp"
#include "main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Big_cars;

namespace TestProc
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(RatationPowerTrack)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InTruck.txt");
			float expected = 50;
			transport *actual;
			actual = (transport*)InDataForTruck(fin);
			actual->k = TRUCK;
			actual->power = 200;
			actual->fuel_consumption = 15;
			float actualResult = ProcessRatationPower(actual);
			Assert::AreEqual(expected,actualResult);
		}
		TEST_METHOD(RatationPowerBus)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InBus.txt");
			float expected = 75;
			transport *actual;
			actual = (transport*)InDataForBus(fin);
			actual->k = BUS;
			actual->power = 200;
			actual->fuel_consumption = 15;
			float actualResult = ProcessRatationPower(actual);
			Assert::AreEqual(expected, actualResult);
		}
		TEST_METHOD(RatationPowerCar)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InCar.txt");
			float expected = 1.875;
			transport *actual;
			actual = (transport*)InDataForPassengerCar(fin);
			actual->k = PASSENGER_CAR;
			actual->power = 200;
			actual->fuel_consumption = 15;
			float actualResult = ProcessRatationPower(actual);
			Assert::AreEqual(expected, actualResult);
		}
		TEST_METHOD(GetPass)
		{
			//ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InBus.txt");
			int expected = 200;
			bus *actual=new bus;
			//actual = (transport*)InDataForBus(fin);
			actual->k = BUS;
			actual->power = 0;
			actual->fuel_consumption = 0;
			actual->passengercapacity = 200;
			int actualResult =GetPassengerCapasity((bus*)actual);
			Assert::AreEqual(expected, actualResult);
		}
		TEST_METHOD(GetTon)
		{
			//ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InTruck.txt");
			int expected = 10000;
			truck *actual=new truck;
			//actual = (transport*)InDataForTruck(fin);
			actual->k = TRUCK;
			actual->power = 0;
			actual->fuel_consumption = 0;
			actual->tonnage = 10000;
			int actualResult = GetTonnage((truck*)actual);
			Assert::AreEqual(expected, actualResult);
		}
		TEST_METHOD(InTruck)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InTruck.txt");
			truck expected;
			expected.tonnage = 10000;
			transport *actual;
			truck *temp;
			actual = (transport*)InDataForTruck(fin);
			actual->k = TRUCK;
			actual->power = 0;
			actual->fuel_consumption = 0;
			temp = (truck*)actual;
			Assert::AreEqual(int(expected.tonnage),int(temp->tonnage));
		}
		TEST_METHOD(InBus)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InBus.txt");
			bus expected;
			expected.passengercapacity = 200;
			transport *actual;
			bus *temp;
			actual = (transport*)InDataForBus(fin);
			actual->k = BUS;
			actual->power = 0;
			actual->fuel_consumption = 0;
			temp = (bus*)actual;
			Assert::AreEqual(expected.passengercapacity, temp->passengercapacity);
		}
		TEST_METHOD(InCar)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InCar.txt");
			passenger_car expected;
			expected.full_speed = 140;
			transport *actual;
			passenger_car *temp;
			actual = (transport*)InDataForPassengerCar(fin);
			actual->k = PASSENGER_CAR;
			actual->power = 0;
			actual->fuel_consumption = 0;
			temp = (passenger_car*)actual;
			Assert::AreEqual(expected.full_speed, temp->full_speed);
		}
		TEST_METHOD(OutB)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outBus.txt");
			bus bus;
			bus.passengercapacity = 200;
			OutBus(&bus, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corB.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outBus.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TransportOut)
		{
			ofstream fout("outTransp.txt");
			transport transp;
			transp.k = BUS;
			transp.fuel_consumption = 10;
			transp.power = 200;
			ChooseForOut(&transp, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corTransport.txt");
			ifstream fin2("outTransp.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TransportInput)
		{
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\InTransport.txt");
			transport* actual = NULL;
			actual = In(fin);
			transport expected;
			expected.k = TRUCK;
			expected.power = 200;
			expected.fuel_consumption = 15;
			Assert::AreEqual(int(expected.k), int(actual->k));
			Assert::AreEqual(int(expected.power), int(actual->power));
			Assert::AreEqual(int(expected.fuel_consumption), int(actual->fuel_consumption));
		}
		TEST_METHOD(OutTr)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outTruck.txt");
			truck truck1;
			truck1.tonnage = 10000;
			OutTruck(&truck1, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corT.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outTruck.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(OutCar)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outCar.txt");
			passenger_car car;
			car.full_speed = 140;
			OutPassengerCar(&car, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corC.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outCar.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(OutList)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outList.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\input.txt");
			container c;
			Init(c);
			In(c,fin);
			Out(c, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corL.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outList.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestSort)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outSort.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\inputSort.txt");
			container c;
			Init(c);
			In(c, fin);
			SortList(c);
			Out(c, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corS.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outSort.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestCompare)
		{
			transport *car2=new transport;
			transport car1;
			car1.k = PASSENGER_CAR;
			car1.power = 20;
			car1.next = car2;
			
			car2->k = PASSENGER_CAR;
			car2->power = 5;
			bool actual = compare(&car1);
			bool expected = false;
			Assert::AreEqual(expected, actual);
		}
		/*TEST_METHOD(TestInit)
		{
			container actual;
			Init(actual);
			container expected;
			expected.Head = NULL;
			expected.Tail = NULL;
			expected.len = 0;
			//Assert::AreEqual(int(expected.Head), int(actual.Head));
			//Assert::AreEqual(int(expected.len), int(actual.len));
			Assert::AreEqual(expected.Tail, actual.Tail);
		}*/
		TEST_METHOD(OutOTruck)
		{
			ofstream fout("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outOnlyTruck.txt");
			ifstream fin("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\input.txt");
			container c;
			Init(c);
			In(c, fin);
			OutOnlyTruck(c, fout);
			fout.close();
			ifstream fin1("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\corOT.txt");
			ifstream fin2("E:\\Installed\\TexProg\\TecProg_ProcVersion\\UnitTest1\\outOnlyTruck.txt");
			string expected;
			getline(fin1, expected, '\0');
			string actual;
			getline(fin2, actual, '\0');
			Assert::AreEqual(expected, actual);
		}
	};
}