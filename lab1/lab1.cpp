#include "Functions.h"

int stateMenu;
void Menu()
{
	cout << "(0) Exit" << endl
		<< "(1) Date input" << endl
		<< "(2) Date output" << endl
		<< "(3) Change element" << endl
		<< "(4) Delete element" << endl
		<< "(5) Add element" << endl
		<< "(6) Sort" << endl
		<< "(7) Saving" << endl
		<< "Make your choice:";
	cin >> stateMenu;
}

int main()
{
	Menu();

	int actions,
		amountOfDate = 0;

	Data* workers = new Data[amountOfDate];

	while (stateMenu !=0)
	{
		switch (stateMenu)
		{
		case 1:
			system("cls");

			cout << "Manual or file input?: ";
			cin >> actions;
			if (actions == 1)
				DataEntry(workers, amountOfDate);
			else
				ReadingData(workers, amountOfDate, "Date.txt");

			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			if (amountOfDate != 0) 
				Print(workers, amountOfDate);
			else
				cout << "No date" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		case 3: 
			system("cls");
			if (amountOfDate != 0)
				DataChange(workers, amountOfDate);
			else
				cout << "No date" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			if (amountOfDate != 0)
				DeleteData(workers, amountOfDate);
			else
				cout << "No data" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			if (amountOfDate != 0)
				AddData(workers, amountOfDate);
			else
				cout << "No data" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
				if (amountOfDate != 0)
					DataSorting(workers, amountOfDate);
				else
					cout << "No data" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 7:
			system("cls");
			if (amountOfDate != 0)
				SavingData(workers, amountOfDate, "Output.txt");
			else
				cout << "No data" << endl;
			system("pause");
			system("cls");
			Menu();
			break;

		}
	}
} 