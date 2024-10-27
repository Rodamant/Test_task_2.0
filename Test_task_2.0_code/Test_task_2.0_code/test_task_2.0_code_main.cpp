#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include"DataFlight.h"

int mainMenu—hoice;
void DataCopy(DataFlight* newFlightArr, DataFlight* flightArr, int n)
{
	for (int i = 0; i < n; i++)
	{
		newFlightArr[i] = flightArr[i];
	}

}

void DataSaveFile(DataFlight* (&flightArr), int& n, std::string fileName)
{
	std::ofstream fout(fileName);
	if (fout)
	{
		fout << n << std::endl;

		for (int i = 0; i < n; i++)
		{
			fout << flightArr[i].GetDepartureTime() << std::endl;
			fout << flightArr[i].GetGate() << std::endl;
			fout << flightArr[i].GetPlaceOfDeparture() << std::endl;
			fout << flightArr[i].GetPlaceOfArrival() << std::endl;
			fout << flightArr[i].GetStatus() << std::endl;
			fout << flightArr[i].GetDelayTime() << std::endl;
			if (i < n - 1)
				fout << std::endl;
		}
	}
	else {
		std::cout << "Error opening file" << std::endl;
	}

	std::cout << "Data saved in " << fileName << std::endl;
	fout.close();

}

void DataSearch(DataFlight* (&flightArr), int& n)
{
	std::string departureTime;
	std::string gate;
	std::string placeOfDeparture;
	std::string placeOfArrival;
	std::string status;
	std::string delayTime;

	int actions;
	int counter = 0;

	std::cout << "Select search criteria: " << std::endl;
	std::cout << "(1) Departure time" << std::endl;
	std::cout << "(2) Gate" << std::endl;
	std::cout << "(3) Place of departure" << std::endl;
	std::cout << "(4) Place of arrival" << std::endl;
	std::cout << "(5) Status(arrived,expected,lands,delayed,cancelled)" << std::endl;
	std::cout << "(6) Delay time" << std::endl;
	std::cin >> actions;
	switch (actions)
	{
	case 1:
		std::cout << "Enter the departure time you are looking for:" << std::endl;
		std::cin >> departureTime;
		for (int i = 0; i < n; i++)
		{
			if (flightArr[i].GetDepartureTime() == departureTime)
			{
				counter++;
				std::cout << "The required departure time was found in flight number " << i + 1 << std::endl;
			}
		}
		if (counter == 0)
		{
			std::cout << "No matches found" << std::endl;
		}
		break;
	case 2:
		std::cout << "Enter the gate you are looking for:" << std::endl;
		std::cin >> gate;
		for (int i = 0; i < n; i++)
		{
			if (flightArr[i].GetGate() == gate)
			{
				counter++;
				std::cout << "The required gate was found in flight number " << i + 1 << std::endl;
			}
		}
		if (counter == 0)
		{
			std::cout << "No matches found" << std::endl;
		}
		break;
	case 3:
		std::cout << "Enter the place of departure you are looking for:" << std::endl;
		std::cin >> placeOfDeparture;
		for (int i = 0; i < n; i++)
		{
			if (flightArr[i].GetPlaceOfDeparture() == placeOfDeparture)
			{
				counter++;
				std::cout << "The required place of departure was found in flight number " << i + 1 << std::endl;
			}
		}
		if (counter == 0)
		{
			std::cout << "No matches found" << std::endl;
		}
		break;
	case 4:
		std::cout << "Enter the place of arrival you are looking for:" << std::endl;
		std::cin >> placeOfArrival;
		for (int i = 0; i < n; i++)
		{
			if (flightArr[i].GetPlaceOfArrival() == placeOfArrival)
			{
				counter++;
				std::cout << "The required place of arrival was found in flight number " << i + 1 << std::endl;
			}
		}
		if (counter == 0)
		{
			std::cout << "No matches found" << std::endl;
		}
		break;
	case 5:
		std::cout << "Enter the status you are looking for:" << std::endl;
		std::cin >> status;
		for (int i = 0; i < n; i++)
		{
			if (flightArr[i].GetStatus() == status)
			{
				counter++;
				std::cout << "The required status was found in flight number " << i + 1 << std::endl;
			}
		}
		if (counter == 0)
		{
			std::cout << "No matches found" << std::endl;
		}
		break;
	case 6:
		std::cout << "Enter the delay time you are looking for:" << std::endl;
		std::cin >> delayTime;
		for (int i = 0; i < n; i++)
		{
			if (flightArr[i].GetDelayTime() == delayTime)
			{
				counter++;
				std::cout << "The required delay time was found in flight number " << i + 1 << std::endl;
			}
		}
		if (counter == 0)
		{
			std::cout << "No matches found" << std::endl;
		}
		break;
	}

}

void DataDelete(DataFlight* (&flightArr), int& n) 
{
	int elementDel;
	DataFlight* buf = new DataFlight[n];
	std::cout << "Enter number deleteble flight(from 1 to " << n << "): ";
	std::cin >> elementDel;
	elementDel--;
	if (elementDel >= 0 && elementDel < n) {
		DataCopy(buf, flightArr, n);
		int q = 0;
		n--;

		flightArr = new DataFlight[n];
		for (int i = 0; i <= n; i++) {
			if (i != elementDel){
				flightArr[q] = buf[i];
				q++;
			}
		}
		std::cout << "Data delete" << std::endl;
	}
	else
	{
		std::cout << "The number is not correct!" << std::endl;
	}

	delete[] buf;

}

void DataAdd(DataFlight* (&flightArr), int& n)
{
	std::string departureTime;
	std::string gate;
	std::string placeOfDeparture;
	std::string placeOfArrival;
	std::string status;
	std::string delayTime;
	DataFlight* buf = new DataFlight[n];
	int size = n, newSize = ++n;

	DataCopy(buf, flightArr, size);

	flightArr = new DataFlight[newSize];

	DataCopy(flightArr, buf, size);

		std::cout << "Enter the flight departure time: " << std::endl;
		std::cin >> departureTime;
		std::cout << "Enter the gate: " << std::endl;
		std::cin >> gate;
		std::cout << "Enter the place of departure: " << std::endl;
		std::cin >> placeOfDeparture;
		std::cout << "Enter the place of arrival: " << std::endl;
		std::cin >> placeOfArrival;
		std::cout << "Please indicate the flight status: \n 1 - if the flight arrived \n 2 - if arrival is expected \n 3 - if the flight lands \n 4 - if the flight is delayed \n 5 - if the flight is cancelled" << std::endl;
		int a;
		std::cin >> a;
		switch (a)
		{
		case 1:
			status = "arrived";
			break;
		case 2:
			status = "expected";
			break;
		case 3:
			status = "lands";
			break;
		case 4:
			status = "delayed";
			break;
		case 5:
			status = "cancelled";
			break;
		}
		if (a == 4)
		{
			std::cout << "please indicate the flight delay time: " << std::endl;
			std::cin >> delayTime;
		}
		else
		{
			delayTime = "-";
		}
		flightArr[size].FillFlightDetails(departureTime, gate, placeOfDeparture, placeOfArrival, status, delayTime);

		std::cout << "New flight added" << std::endl;
		delete[] buf;
}

void DataChange(DataFlight* flightArr, int n)
{
	std::string departureTime;
	std::string gate;
	std::string placeOfDeparture;
	std::string placeOfArrival;
	std::string status;
	std::string delayTime;
	int elementVariable;

	std::cout << "Enter number variable flight(from 1 to " << n <<"): ";
	std::cin >> elementVariable;
	elementVariable--;

	if(elementVariable >=0 && elementVariable < n){
	
		std::cout << "Enter the new flight departure time: " << std::endl;
		std::cin >> departureTime;
		std::cout << "Enter the new gate: " << std::endl;
		std::cin >> gate;
		std::cout << "Enter the new place of departure: " << std::endl;
		std::cin >> placeOfDeparture;
		std::cout << "Enter the new place of arrival: " << std::endl;
		std::cin >> placeOfArrival;
		std::cout << "Please indicate the new flight status: \n 1 - if the flight arrived \n 2 - if arrival is expected \n 3 - if the flight lands \n 4 - if the flight is delayed \n 5 - if the flight is cancelled" << std::endl;
		int a;
		std::cin >> a;
		switch (a)
		{
		case 1:
			status = "arrived";
			break;
		case 2:
			status = "expected";
			break;
		case 3:
			status = "lands";
			break;
		case 4:
			status = "delayed";
			break;
		case 5:
			status = "cancelled";
			break;
		}
		if (a == 4)
		{
			std::cout << "please indicate the flight delay time: " << std::endl;
			std::cin >> delayTime;
		}
		else
		{
			delayTime = "-";
		}
		flightArr[elementVariable].FillFlightDetails(departureTime, gate, placeOfDeparture, placeOfArrival, status, delayTime);
	}
	else {
		std::cout << "The number is not correct!" << std::endl;
	}

}
void DataPrint(DataFlight* (&flightArr), int& n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "Data # " << i + 1 << std::endl;
		flightArr[i].PrintFlightDetails();
		std::cout << "____________________________________________________________________" << std::endl;
	}

}

void DataFromFile(DataFlight* (&flightArr), int& n, std::string fileName)
{
	std::ifstream fin(fileName);

	if (fin) {

		std::string departureTime;
		std::string gate;
		std::string placeOfDeparture;
		std::string placeOfArrival;
		std::string status;
		std::string delayTime;

		fin >> n;

		flightArr = new DataFlight[n];

		for (int i = 0; i < n; i++) {
			fin >> departureTime;
			fin >> gate;
			fin >> placeOfDeparture;
			fin >> placeOfArrival;
			fin >> status;
			fin >> delayTime;

			flightArr[i].FillFlightDetails(departureTime, gate, placeOfDeparture, placeOfArrival, status, delayTime);
		}

		std::cout << "Data loaded" << std::endl;
	}
	else {
		std::cout << "Error opening file" << std::endl;
	}
	fin.close();
}
void FillDataFlight(DataFlight*(&flightArr), int & n)
{
	std::cout << "Enter the number of flights you want to record (array size): " << std::endl;
	std::cin >> n;
	std::string departureTime;
	std::string gate;
	std::string placeOfDeparture;
	std::string placeOfArrival;
	std::string status;
	std::string delayTime;

	flightArr = new DataFlight[n];

	for (int i = 0; i < n; i++) {
		std::cout << "Enter the flight departure time: " << std::endl;
		std::cin >> departureTime;
		std::cout << "Enter the gate: " << std::endl;
		std::cin >> gate;
		std::cout << "Enter the place of departure: " << std::endl;
		std::cin >> placeOfDeparture;
		std::cout << "Enter the place of arrival: " << std::endl;
		std::cin >> placeOfArrival;
		std::cout << "Please indicate the flight status: \n 1 - if the flight arrived \n 2 - if arrival is expected \n 3 - if the flight lands \n 4 - if the flight is delayed \n 5 - if the flight is cancelled" << std::endl;
		int a;
		std::cin >> a;
		switch (a)
		{
		case 1:
			status = "arrived";
			break;
		case 2:
			status = "expected";
			break;
		case 3:
			status = "lands";
			break;
		case 4:
			status = "delayed";
			break;
		case 5:
			status = "cancelled";
			break;
		}
		if (a == 4)
		{
			std::cout << "please indicate the flight delay time: " << std::endl;
			std::cin >> delayTime;
		}
		else
		{
			delayTime = "-";
		}

		flightArr[i].FillFlightDetails(departureTime, gate, placeOfDeparture, placeOfArrival, status, delayTime);
		std::cout << "__________________________________________________________________\n";
	}
}

void MainMenu()
{
	std::cout << "Select an action: " << std::endl;
	std::cout << "(1) Create a new database: " << std::endl;
	std::cout << "(2) Load database from disk: " << std::endl;
	std::cout << "(3) Print database: " << std::endl;
	std::cout << "(4) Edit data: " << std::endl;
	std::cout << "(5) Add flight: " << std::endl;
	std::cout << "(6) Delete flight: " << std::endl;
	std::cout << "(7) Search flight: " << std::endl;
	std::cout << "(8) Save data in file: " << std::endl;
	std::cout << "(0) Exit the program: " << std::endl;
	std::cout << "Your choice: ";
	std::cin >> mainMenu—hoice;
}




int main()
{
	MainMenu();
	int actions;
	int sizeArr = 0;
	std::string fileName;
	DataFlight* flightArr = new DataFlight[sizeArr];

	while (mainMenu—hoice != 0)
	{
		switch (mainMenu—hoice)
		{
		case 1:
			system("cls");
			std::cout << "Fill flight details: " << std::endl;

			FillDataFlight(flightArr, sizeArr);
		
			system("pause");
			system("cls");
			MainMenu();
			break;
		case 2:
			system("cls");
			std::cout << "Do you want to specify a file? Or use the default file?\n(1) - default file\n(2) - specify file" << std::endl;

			std::cin >> actions;

			switch (actions)
			{
			case 1:
				fileName = "data_flight.txt";
				DataFromFile(flightArr, sizeArr, fileName);
				break;
			case 2:
				std::cin >> fileName;
				DataFromFile(flightArr, sizeArr, fileName);
				break;
			}
			system("pause");
			system("cls");
			MainMenu();
			break;
		case 3:
			system("cls");
			if (sizeArr != 0)
			{
				DataPrint(flightArr, sizeArr);
			}
			else {
				std::cout << "Data empty " << std::endl;
			}
			system("pause");
			system("cls");
			MainMenu();
			break;
		case 4:
			system("cls");
			DataChange(flightArr, sizeArr);
			system("pause");
			system("cls");
			MainMenu();
			break;
		case 5:
			system("cls");
			DataAdd(flightArr, sizeArr);
			system("pause");
			system("cls");
			MainMenu();
			break;
		case 6:
			system("cls");
			DataDelete(flightArr, sizeArr);
			system("pause");
			system("cls");
			MainMenu();
			break;
		case 7:
			system("cls");
			DataSearch(flightArr, sizeArr);
			system("pause");
			system("cls");
			MainMenu();
			break;
		case 8:
			system("cls");
			std::cout << "Do you want to specify a file? Or use the default file?\n(1) - default file\n(2) - specify file" << std::endl;

			std::cin >> actions;

			switch (actions)
			{
			case 1:
				fileName = "data_flight.txt";
				DataSaveFile(flightArr, sizeArr, fileName);
				break;
			case 2:
				std::cin >> fileName;
				DataSaveFile(flightArr, sizeArr, fileName);
				break;
			}
			system("pause");
			system("cls");
			MainMenu();
			break;
		default:
			std::cout << "You have entered an item that is not in the menu!" << std::endl;
			system("pause");
			system("cls");
			MainMenu();
			break;
		}
	}

}