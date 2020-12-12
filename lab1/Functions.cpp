#include "Functions.h"

void DataEntry(Data* (&workers), int& n)
{
	cout << "Enter number of workers: ";
	cin >> n;

	workers = new Data[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter name and surname: ";
		cin >> workers[i].initial.name;
		cin >> workers[i].initial.surname;

		cout << "Enter Birthday: ";
		cin >> workers[i].birthday.day;
		cin >> workers[i].birthday.month;
		cin >> workers[i].birthday.year;

		cout << "Enter gender: ";
		cin >> workers[i].gender;
		
		cout << "Enter recruitment time: ";
		cin >> workers[i].recruitment.day;
		cin >> workers[i].recruitment.month;
		cin >> workers[i].recruitment.year;

		workers[i].tabularNumber = ++counter;

		cout << "________________________________________" << endl;
	}

}

void ReadingData(Data* (&workers), int& n, string fileName)
{
	ifstream reading(fileName);

	if (reading) {

		reading >> n;

		workers = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> workers[i].initial.name;
			reading >> workers[i].initial.surname;

			reading >> workers[i].birthday.day;
			reading >> workers[i].birthday.month;
			reading >> workers[i].birthday.year;

			reading >> workers[i].gender;

			reading >> workers[i].recruitment.day;
			reading >> workers[i].recruitment.month;
			reading >> workers[i].recruitment.year;

			workers[i].tabularNumber = ++counter;
		}
		cout << "Data read" << endl;
	}
	else
		cout << "File open ERROR" << endl; 
}

void Print(Data* workers, int n)
{
	try
	{
		if (n > counter)
			throw exception("The number of items requested for output exceeds the number of items in the data base");
		for (int i = 0; i < n; i++)
		{
			cout << "№ " << workers[i].tabularNumber << "\t";
			cout << "Name: " << workers[i].initial.name << "\t"
				<< "Surname: " << workers[i].initial.surname << endl;
			cout << "Birthday: " << workers[i].birthday.day << ":"
				<< workers[i].birthday.month << ":" << workers[i].birthday.year << endl;
			cout << "Gender: " << workers[i].gender << endl;
			cout << "____________________________" << "\n\n";
		}

	}
	catch (const exception& ex) { cout << ex.what(); }
	

}

void DataChange(Data* (&workers), int n)
{
	int _n;
	cout << "Input the tabular number of worker [1;" << n << "]: ";
	cin >> _n; _n--;
	

	if (_n >= 0 && _n <= n)
	{
		cout << "Enter name and surname: ";
		cin >> workers[_n].initial.name;
		cin >> workers[_n].initial.surname;

		cout << "Enter Birthday: ";
		cin >> workers[_n].birthday.day;
		cin >> workers[_n].birthday.month;
		cin >> workers[_n].birthday.year;

		cout << "Enter gender: ";
		cin >> workers[_n].gender;

		cout << "Enter recruitment time: ";
		cin >> workers[_n].recruitment.day;
		cin >> workers[_n].recruitment.month;
		cin >> workers[_n].recruitment.year;

		system("cls");

		cout << "Data successfully changed" << endl;
	}
	else
		cout << "Invalid number" << endl;
}

void DeleteData(Data* (&workers), int& n)
{
	int _n;
	cout << "Input the tabular number of worker [1;" << n << "]: ";
	cin >> _n; _n--;

	if (_n >= 0 && _n <= n)
	{
		Data* buf = new Data[n];

		Copy(buf, workers, n);
		--n;
		int q = 0;

		for (int i = 0; i < n; i++){
			if (i != _n)
				workers[q] = buf[i];
				++q;
		}
		system("cls");
		delete[_n] buf;
		delete[] buf;

		cout << "Data successfully deleated" << endl;
	}
	else
		cout << "Invalid number" << endl;
}

void Copy(Data* (&workers_n), Data* (&workers_o), int n)
{
	for (int i = 0; i < n; i++)
		workers_n[i] = workers_o[i];
} 

void Copy(Data& workers_n, Data& workers_o)
{ 
	workers_n.initial.name = workers_o.initial.name;
	workers_n.initial.surname = workers_o.initial.surname;

	workers_n.birthday.day = workers_o.birthday.day;
	workers_n.birthday.month = workers_o.birthday.month;
	workers_n.birthday.year = workers_o.birthday.month;

	workers_n.gender = workers_o.birthday.month;

	workers_n.recruitment.day = workers_o.recruitment.day;
	workers_n.recruitment.month = workers_o.recruitment.month;

	workers_n.recruitment.year = workers_o.recruitment.year;


}

void AddData(Data* (&workers), int& n)
{
	Data* buf = new Data[n];

	Copy(buf, workers, n);
	n++;
	workers = new Data[n];
	Copy(workers, buf, --n);

	cout << "Enter name and surname: ";
	cin >> workers[n].initial.name;
	cin >> workers[n].initial.surname;

	cout << "Enter Birthday: ";
	cin >> workers[n].birthday.day;
	cin >> workers[n].birthday.month;
	cin >> workers[n].birthday.year;

	cout << "Enter gender: ";
	cin >> workers[n].gender;
	workers[n].tabularNumber = ++counter;

	cout << "Enter recruitment time: ";
	cin >> workers[n].recruitment.day;
	cin >> workers[n].recruitment.month;
	cin >> workers[n].recruitment.year;
	system("cls");

	cout << "Element added." << endl;
	
	delete[] buf;
}

void DataSorting(Data* workers, int n)
{
	Data buf;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (workers[i].recruitment> workers[j].recruitment)
			{
				Copy(buf, workers[j]);
				Copy(workers[j], workers[i]);
				Copy(workers[i], buf);
			}
		}
	}
}

void SavingData(Data* workers, int n, string fileName)
{
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;
		for (int  i = 0; i < n; i++)
		{
			record << workers[i].initial.name;
			record << workers[i].initial.surname;

			record << workers[i].birthday.day;
			record << workers[i].birthday.month;
			record << workers[i].birthday.year;

			record << workers[i].gender;

			record << workers[i].recruitment.day;
			record << workers[i].recruitment.month;
			record << workers[i].recruitment.year;
		}
	}
}

bool Date::operator==(const Date& ptr)
{
	return (this->year == ptr.year&& this->month == ptr.month && this->day == ptr.day);
}

bool Date::operator<(const Date& ptr)
{
	return total_day() < ptr.total_day();
}

bool Date::operator>(const Date& ptr)
{
	return total_day() > ptr.total_day();
}

int Date::total_day() const
{
	int summ = 0;

	for (int i = 0; i < this->month; i++)
	{
		summ += dayOfMonth(i, this->year);
	}

	summ += this->day;

	return summ;
}

int Date::dayOfMonth(int month, int year) const
{
	int d = 29;
	static int dom[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 1)
	{
		if (this->leapYear() == true)
		{
			return d;
		}
		else
		{
			return dom[month];
		}
	}
	else
	{
		return dom[month];
	}
}

bool Date::leapYear() const
{
	if ((this->year % 4 == 0) && ((this->year % 100 != 0) || (this->year % 400 == 0)))  // условие високосности года
	{
		return true;
	}
	else
	{
		return false;
	}
}