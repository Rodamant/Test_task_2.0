#pragma once

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
	void FillFlightDetails(std::string departureTime, std::string gate, std::string placeOfDeparture, std::string placeOfArrival, std::string status, std::string delayTime)
	{
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