#include<iostream>
#include<string>
#include<fstream>

class DataFlight
{
public:
	void FillFlightDetails()
	{
		std::cout << "Enter the flight departure time: " << std::endl;
		std::string departureTime;
		std::cin >> departureTime;
		SetDepartureTime(departureTime);
		std::cout << "Enter the gate: " << std::endl;
		std::string gate;
		std::cin >> gate;
		SetGate(gate);
		std::cout << "Enter the place of arrival: " << std::endl;
		std::string placeOfArrival;
		std::cin >> placeOfArrival;
		SetPlaceOfArrival(placeOfArrival);
		std::cout << "Enter the place of arrival: \n 1 - if the flight arrived \n 2 - if arrival is expected \n 3 - if the flight lands \n 4 - if the flight is delayed \n 5 - if the flight is cancelled" << std::endl;
		std::string status;
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
		SetStatus(status);
		std::string delayTime;
		if (a == 4)
		{
			std::cout << "please indicate the flight delay time: " << std::endl;
			std::cin >> delayTime;
		}
		else
		{
			delayTime = "-";
		}
		SetDelayTime(delayTime);

	}

	void PrintFlightDetails()
	{
		std::cout << "Departure time: " << departureTime << std::endl;
		std::cout << "Gate: " << gate << std::endl;
		std::cout << "Place of arrival: " << placeOfArrival << std::endl;
		std::cout << "Status flight: " << status << std::endl;
		std::cout << "delay time: " << delayTime << std::endl;
	}

	void SetDepartureTime(std::string departureTime)
	{
		this->departureTime = departureTime;
	}
	void SetGate(std::string gate)
	{
		this->gate = gate;
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
	std::string GetDepartureTime(){ return departureTime; }
	std::string GetGate(){ return gate; }
	std::string GetPlaceOfArrival(){ return placeOfArrival; }
	std::string GetStatus(){ return status; }
	std::string GetDelayTime(){ return delayTime; }
private:
	std::string departureTime;
	std::string gate;
	std::string placeOfArrival;
	std::string status;
	std::string delayTime;
};


int main()
{
	std::string path = "data_flight.txt";
	DataFlight a;
	a.FillFlightDetails();
	a.PrintFlightDetails();
	std::ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		std::cout << "Erorr" << std::endl;
	}
	else
	{
		fout.write((char*)&a,sizeof(DataFlight));
	}
}