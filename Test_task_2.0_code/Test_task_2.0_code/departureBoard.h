#pragma once
#include"headlines.h"
#include"dataF.h"

template <typename T>
class DepartureBoard
{
public:

public:
	void ClearDepartureBoard()
	{
		arrFlight.clear();
		std::cout << "All flights have been removed" << std::endl;
	}
	void DataSaveFile(std::string fileName)
	{
		std::ofstream fout(fileName);
		if (fout)
		{
			fout << arrFlight.size() << std::endl;

			for (int i = 0; i < arrFlight.size(); i++)
			{
				fout << arrFlight[i].GetDepartureTime() << std::endl;
				fout << arrFlight[i].GetGate() << std::endl;
				fout << arrFlight[i].GetPlaceOfDeparture() << std::endl;
				fout << arrFlight[i].GetPlaceOfArrival() << std::endl;
				fout << arrFlight[i].GetStatus() << std::endl;
				fout << arrFlight[i].GetDelayTime() << std::endl;
				if (i < arrFlight.size() - 1)
					fout << std::endl;
			}
		}
		else {
			std::cout << "Error opening file" << std::endl;
		}

		std::cout << "Data saved in " << fileName << std::endl;

	}
	void DataFromFile(std::string fileName)
	{
		std::ifstream fin(fileName);

		int size = 0;
		if (fin)
		{
			std::string departureTime;
			std::string gate;
			std::string placeOfDeparture;
			std::string placeOfArrival;
			std::string status;
			std::string delayTime;

			fin >> size;
			arrFlight.resize(size);
			for (int i = 0; i < size; i++)
			{
				fin >> departureTime;
				fin >> gate;
				fin >> placeOfDeparture;
				fin >> placeOfArrival;
				fin >> status;
				fin >> delayTime;

				arrFlight[i].SetDepartureTime(departureTime);
				arrFlight[i].SetGate(gate);
				arrFlight[i].SetPlaceOfDeparture(placeOfDeparture);
				arrFlight[i].SetPlaceOfArrival(placeOfArrival);
				arrFlight[i].SetStatus(status);
				arrFlight[i].SetDelayTime(delayTime);
			}
			std::cout << "Data loaded" << std::endl;
		}
		else
		{
			std::cout << "Error opening file" << std::endl;
		}
	}
	void SearchData(std::string search, int actions)
	{
		int counter = 0;
		switch (actions)
		{
		case 1:
			for (int i = 0; i < arrFlight.size(); i++)
			{
				if (arrFlight[i].GetDepartureTime() == search)
				{
					counter++;
					std::cout << "The required departure time was found in flight index " << i << std::endl;
				}
			}
			if (counter == 0)
				std::cout << "No matches found" << std::endl;
			break;
		case 2:
			for (int i = 0; i < arrFlight.size(); i++)
			{
				if (arrFlight[i].GetGate() == search)
				{
					counter++;
					std::cout << "The required gate was found in flight index " << i << std::endl;
				}
			}
			if (counter == 0)
				std::cout << "No matches found" << std::endl;
			break;
		case 3:
			for (int i = 0; i < arrFlight.size(); i++)
			{
				if (arrFlight[i].GetPlaceOfDeparture() == search)
				{
					counter++;
					std::cout << "The required place of departure was found in flight index " << i << std::endl;
				}

			}
			if (counter == 0)
				std::cout << "No matches found" << std::endl;
			break;
		case 4:
			for (int i = 0; i < arrFlight.size(); i++)
			{
				if (arrFlight[i].GetPlaceOfArrival() == search)
				{
					counter++;
					std::cout << "The required place of arrival was found in flight index " << i << std::endl;
				}

			}
			if (counter == 0)
				std::cout << "No matches found" << std::endl;
			break;
		case 5:
			for (int i = 0; i < arrFlight.size(); i++)
			{
				if (arrFlight[i].GetStatus() == search)
				{
					counter++;
					std::cout << "The required status was found in flight index " << i << std::endl;
				}
			}
			if (counter == 0)
				std::cout << "No matches found" << std::endl;
			break;
		case 6:
			for (int i = 0; i < arrFlight.size(); i++)
			{
				if (arrFlight[i].GetDelayTime() == search)
				{
					counter++;
					std::cout << "The required delay time was found in flight index " << i << std::endl;
				}
			}
			if (counter == 0)
				std::cout << "No matches found" << std::endl;
			break;
		default:
			std::cout << "Invalid search criteria!" << std::endl;
			break;
		}
	}
	void ChangeDelayTime(int index, std::string delayTime)
	{
		if (index > arrFlight.size() - 1)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}
		arrFlight[index].SetDelayTime(delayTime);
		std::cout << "Data has been changed" << std::endl;
	}
	void ChangeStatus(int index, std::string status)
	{
		if (index > arrFlight.size() - 1)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}
		arrFlight[index].SetStatus(status);
		std::cout << "Data has been changed" << std::endl;
	}
	void ChangePlaceOfArrival(int index, std::string placeOfArrival)
	{
		if (index > arrFlight.size() - 1)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}
		arrFlight[index].SetPlaceOfArrival(placeOfArrival);
		std::cout << "Data has been changed" << std::endl;
	}
	void ChangePlaceOfDeparture(int index, std::string placeOfDeparture)
	{
		if (index > arrFlight.size() - 1)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}
		arrFlight[index].SetPlaceOfDeparture(placeOfDeparture);
		std::cout << "Data has been changed" << std::endl;
	}
	void ChangeGate(int index, std::string gate)
	{
		if (index > arrFlight.size() - 1)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}
		arrFlight[index].SetGate(gate);
		std::cout << "Data has been changed" << std::endl;
	}
	void ChangeDepartureTime(int index, std::string departureTime)
	{
		if (index > arrFlight.size() - 1)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}
		arrFlight[index].SetDepartureTime(departureTime);
		std::cout << "Data has been changed" << std::endl;
	}
	void ChangeCompletelyDataFlight(int index)
	{
		if (index > arrFlight.size() - 1)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}
		arrFlight[index].FillFlightDetails();
		std::cout << "Data has been changed" << std::endl;
	}
	void DeleteFlight(int index)
	{
		if (index > arrFlight.size() - 1)
		{
			std::cout << "Invalid index!" << std::endl;
			return;
		}
		arrFlight.erase(arrFlight.begin() + index);
		std::cout << "Data delete" << std::endl;
	}
	void AddFlight(T flight)
	{
		arrFlight.push_back(flight);
		std::cout << "New flight added" << std::endl;
	}
	void PrintDepartureBoard()
	{
		for (int i = 0; i < arrFlight.size(); i++)
		{
			std::cout << "Flight index " << i << ": " << std::endl;
			arrFlight[i].PrintFlightDetails();
			std::cout << "_________________________________________" << std::endl;
		}
	}
	int GetSizeArrFlight()
	{
		return arrFlight.size();
	}
private:
	std::vector <T> arrFlight;
};
