#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <Windows.h>

using namespace std;

int counter = 0;

struct Date {
	int day,
		month,
		year;
	bool operator==(const Date& ptr);
	bool operator<(const Date& ptr);
	bool operator>(const Date& ptr);
	int total_day() const;
	int dayOfMonth(int month, int year) const;
	bool leapYear() const;
};

 

struct Initial
{
	string name,
		surname;
};

struct Data
{
	Initial initial;
	Date birthday;
	string gender ;
	int tabularNumber;
	Date recruitment;
private:

};

void DataEntry(Data* (&workers), int& n);
void ReadingData(Data* (&workers), int& n, string fileName);
void Print(Data* workers, int n);
void DataChange(Data* (&d), int n);
void DeleteData(Data* (&d), int& n);
void Copy(Data* (&d_n), Data* (&d_o), int n);
void Copy(Data& d_n, Data& d_o);
void AddData(Data* (&d), int& n);
void DataSorting(Data* d, int n);
void SavingData(Data* d, int n, string fileName);