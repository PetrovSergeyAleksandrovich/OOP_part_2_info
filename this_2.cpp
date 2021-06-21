#include <iostream>
#include <cassert>

class TrainCar
{

    int passengersMax = 0;
    int passengers = 0;

    class Train* train = nullptr;

public:

    TrainCar(class Train* inTrain, int PassengersMax)
    {
        assert(inTrain != nullptr);
        assert(PassengersMax >= 0);
        this->passengersMax = PassengersMax;
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

    int getNumber();

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
            cars[i] = new TrainCar(this, inPassengersMax);
        }
    }

    TrainCar* getCarAt(int index)
    {
        if(this == nullptr) return nullptr;
        if(index < 0) return nullptr;
        if(index >= this->count) return nullptr;
        else return this->cars[index];
    }

    int getCount()
    {
        return count;
    }
};

int TrainCar::getNumber()
{
    for(int i = 0; i < train->getCount(); i++)
    {
        TrainCar* car = train->getCarAt(i);
        if(car == this) return  i;
    }
    assert(false);
}

int main()
{
    Train* train = nullptr;
    train->getCarAt(2);
    train = new Train{10, 30};

    for(int i = 0; i < train->getCount(); i++)
    {
        int passengers = 0;
        std::cin >> passengers;
        train->getCarAt(i)->load(passengers);
    }

    TrainCar* car3 = train->getCarAt(2);
    std::cout << car3->getNumber() << ": " << car3->getPassengers() << std::endl;

    return 0;
}
