#include"dataF.h"
#include"headlines.h"
#include"departureBoard.h"


int mainMenu—hoice;


void MainMenu()
{
	std::cout << "Select an action: " << std::endl;
	std::cout << "(1) Create a new database: " << std::endl;
	std::cout << "(2) Load a database from the file: " << std::endl;
	std::cout << "(3) Print the database: " << std::endl;
	std::cout << "(4) Edit the data: " << std::endl;
	std::cout << "(5) Add a flight: " << std::endl;
	std::cout << "(6) Delete a flight: " << std::endl;
	std::cout << "(7) Search a flight: " << std::endl;
	std::cout << "(8) Save the data in the file: " << std::endl;
	std::cout << "(9) Clear database: " << std::endl;
	std::cout << "(0) Exit the program: " << std::endl;
	std::cout << "Your choice: ";
	std::cin >> mainMenu—hoice;
}




int main()
{
	MainMenu();
	int actions;
	int index;
	int size = 0;
	std::string fileName;
	std::string departureTime;
	std::string gate;
	std::string placeOfDeparture;
	std::string placeOfArrival;
	std::string status;
	std::string delayTime;
	std::string search;
	DataFlight flight;
	DepartureBoard<DataFlight> board;

	while (mainMenu—hoice != 0)
	{
		switch (mainMenu—hoice)
		{
		case 1:
			system("cls");
			std::cout << "How many flights do you want to add to the database? " << std::endl;
			std::cout << "Enter the number of flights: ";
			std::cin >> size;

			for (int i = 0; i < size; i++)
			{
				DataFlight flight;
				std::cout << "Fill flight details. " << std::endl;
				flight.FillFlightDetails();
				board.AddFlight(flight);
				std::cout << "___________________________________________" << std::endl;
			}


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
				board.DataFromFile(fileName);
				break;
			case 2:
				std::cin >> fileName;
				board.DataFromFile(fileName);
				break;
			default:
				std::cout << "Incorrect data entered" << std::endl;
			}
			system("pause");
			system("cls");
			MainMenu();
			break;
		case 3:
			system("cls");
			if (board.GetSizeArrFlight() != 0)
			{
				board.PrintDepartureBoard();
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
			std::cout << "Enter the flight index whose data you want to change. Starting with 0, max index - " << board.GetSizeArrFlight() - 1 << std::endl;
			std::cin >> index;
			if (index > board.GetSizeArrFlight() - 1)
			{
				std::cout << "Invalid index!" << std::endl;
				break;
			}
			std::cout << "(1) Change all data" << std::endl;
			std::cout << "(2) Change departure time" << std::endl;
			std::cout << "(3) Change gate" << std::endl;
			std::cout << "(4) Change place of departure" << std::endl;
			std::cout << "(5) Change place of arrival" << std::endl;
			std::cout << "(6) Change place of status" << std::endl;
			std::cout << "(7) Change place of delay time" << std::endl;
			std::cin >> actions;

			switch (actions)
			{
			case 1:
				std::cout << "Enter new data" << std::endl;
				board.ChangeCompletelyDataFlight(index);
				break;
			case 2:
				std::cout << "Enter the new departure time" << std::endl;
				std::cin >> departureTime;
				board.ChangeDepartureTime(index, departureTime);
				break;
			case 3:
				std::cout << "Enter the new gate" << std::endl;
				std::cin >> gate;
				board.ChangeGate(index, gate);
				break;
			case 4:
				std::cout << "Enter the place of departure;" << std::endl;
				std::cin >> placeOfDeparture;
				board.ChangePlaceOfArrival(index, placeOfDeparture);
				break;
			case 5:
				std::cout << "Enter the place of arrival;" << std::endl;
				std::cin >> placeOfArrival;
				board.ChangePlaceOfArrival(index, placeOfArrival);
				break;
			case 6:
				std::cout << "Enter the status;" << std::endl;
				std::cin >> status;
				board.ChangeStatus(index, status);
				break;
			case 7:
				std::cout << "Enter the delay time;" << std::endl;
				std::cin >> delayTime;
				board.ChangeDelayTime(index, delayTime);
				break;
			default:
				std::cout << "Incorrect data entered" << std::endl;
				break;
			}

			system("pause");
			system("cls");
			MainMenu();
			break;
		case 5:
			system("cls");
			for (int i = 0; i < 1; i++)
			{
				DataFlight flight;
				std::cout << "Fill flight details: " << std::endl;
				flight.FillFlightDetails();
				board.AddFlight(flight);
			}

			system("pause");
			system("cls");
			MainMenu();
			break;
		case 6:
			system("cls");
			std::cout << "Specify the flight index you want to delete:" << std::endl;
			std::cin >> index;
			board.DeleteFlight(index);
			system("pause");
			system("cls");
			MainMenu();
			break;
		case 7:
			system("cls");
			std::cout << "Specify what you are looking for" << std::endl;
			std::cin >> search;
			std::cout << "(1) Search departure time" << std::endl;
			std::cout << "(2) Search gate" << std::endl;
			std::cout << "(3) Search place of departure" << std::endl;
			std::cout << "(4) Search place of arrival" << std::endl;
			std::cout << "(5) Search place of status" << std::endl;
			std::cout << "(6) Search place of delay time" << std::endl;
			std::cin >> actions;
			board.SearchData(search, actions);
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
				board.DataSaveFile(fileName);
				break;
			case 2:
				std::cin >> fileName;
				board.DataSaveFile(fileName);
				break;
			default:
				std::cout << "Incorrect data entered" << std::endl;
				break;
			}

			system("pause");
			system("cls");
			MainMenu();
			break;
		case 9:
			system("cls");
			board.ClearDepartureBoard();
			system("pause");
			system("cls");
			MainMenu();
		default:
			std::cout << "You have entered an item that is not in the menu!" << std::endl;
			system("pause");
			system("cls");
			MainMenu();
			break;
		}
	}


}