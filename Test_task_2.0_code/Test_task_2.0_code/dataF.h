#pragma once
#include"headlines.h"
#include"departureBoard.h"


enum class statusFlight
{
	arrived,
	expected,
	landing,
	delayed,
	cancelled
};

class DataFlight
{
public:
	DataFlight()
	{
		departureTime = "";
		gate = "";
		placeOfDeparture = "";
		placeOfArrival = "";
		status = "";
		delayTime = "";
	}
	DataFlight(std::string departureTime, std::string gate, std::string placeOfDeparture, std::string placeOfArrival, std::string status, std::string delayTime)
	{
		this->departureTime = departureTime;
		this->gate = gate;
		this->placeOfDeparture = placeOfDeparture;
		this->placeOfArrival = placeOfArrival;
		this->status = status;
		this->delayTime = delayTime;
	}
	void FillFlightDetails()
	{
		std::string departureTime;
		std::string gate;
		std::string placeOfDeparture;
		std::string placeOfArrival;
		std::string status;
		std::string delayTime;
		std::cout << "Enter the flight departure time: " << std::endl;
		std::cin >> departureTime;
		std::cout << "Enter the gate: " << std::endl;
		std::cin >> gate;
		std::cout << "Enter the place of departure: " << std::endl;
		std::cin >> placeOfDeparture;
		std::cout << "Enter the place of arrival: " << std::endl;
		std::cin >> placeOfArrival;
		//
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

		this->departureTime = departureTime;
		this->gate = gate;
		this->placeOfDeparture = placeOfDeparture;
		this->placeOfArrival = placeOfArrival;
		this->status = status;
		this->delayTime = delayTime;
	}

	void PrintFlightDetails()
	{
		std::cout << "Departure time: " << departureTime << std::endl;
		std::cout << "Gate: " << gate << std::endl;
		std::cout << "Place of departure: " << placeOfDeparture << std::endl;
		std::cout << "Place of arrival: " << placeOfArrival << std::endl;
		std::cout << "Status flight: " << status << std::endl;
		std::cout << "Delay time: " << delayTime << std::endl;
	}

	void SetDepartureTime(std::string departureTime)
	{
		this->departureTime = departureTime;
	}
	void SetGate(std::string gate)
	{
		this->gate = gate;
	}
	void SetPlaceOfDeparture(std::string placeOfDeparture)
	{
		this->placeOfDeparture = placeOfDeparture;
	}
	void SetPlaceOfArrival(std::string placeOfArrival)
	{
		this->placeOfArrival = placeOfArrival;
	}
	void SetStatus(std::string status)
	{
		this->status = status;
	}
	void SetDelayTime(std::string delayTime)
	{
		this->delayTime = delayTime;
	}
	DataFlight& operator = (DataFlight other)
	{
		this->departureTime = other.departureTime;
		this->gate = other.gate;
		this->placeOfDeparture = other.placeOfDeparture;
		this->placeOfArrival = other.placeOfArrival;
		this->status = other.status;
		this->delayTime = other.delayTime;

		return *this;
	}
	std::string GetDepartureTime() { return departureTime; }
	std::string GetGate() { return gate; }
	std::string GetPlaceOfArrival() { return placeOfArrival; }
	std::string GetPlaceOfDeparture() { return placeOfDeparture; }
	std::string GetStatus() { return status; }
	std::string GetDelayTime() { return delayTime; }
private:
	std::string departureTime;
	std::string gate;
	std::string placeOfDeparture;
	std::string placeOfArrival;
	std::string status;
	std::string delayTime;
};