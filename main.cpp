#include <iostream>
#include <cassert>

class TrainCar
{

    int passengersMax = 0;
    int passengers = 0;
public:

    TrainCar(int inPassengersMax): passengersMax(inPassengersMax)
    {
        assert(inPassengersMax >= 0);
    }

    void load(int value)
    {
        passengers += value;
        if(passengers > passengersMax)
        {
            passengersMax = passengers;
        }
    }

    int getPassengers()
    {
        return passengers;
    }

};

class Train
{
    int count = 0;
    TrainCar** cars = nullptr;
public:

    Train(int inCount, int inPassengersMax):count(inCount)
    {
        assert(inCount >= 0);
        cars = new TrainCar*[inCount];
        for(int i = 0; i < count; i++)
        {
            cars[i] = new TrainCar(inPassengersMax);
        }
    }

    TrainCar* getCarAt(int index)
    {
        if(index < 0) return nullptr;
        if(index >= count) return nullptr;
        else return cars[index];
    }

    int getCount()
    {
        return count;
    }
};

int main()
{
    Train* train = new Train{10, 30};

    for(int i = 0; i < train->getCount(); i++)
    {
        int passengers = 0;
        std::cin >> passengers;
        train->getCarAt(i)->load(passengers);
    }

    return 0;
}
