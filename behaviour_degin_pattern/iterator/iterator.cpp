#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class RadioStation
{
public:
    RadioStation(float freq)
    {
        frequency=freq;
    }
    float get_frequency()
    {
        return frequency;
    }
private:
    float frequency;
};

class StationList{
public:
    void add_station(RadioStation* station)
    {
        stations.push_back(station);
    }
    void remove_station(RadioStation* station)
    {
        for(auto it = stations.begin(); it != stations.end(); ++it)
        {
            if((*it)->get_frequency() == station->get_frequency())
            {
                stations.erase(it);
            }
        }
    }
    int count()
    {
        return stations.size();
    }
    int key()
    {
        return counter;
    }
    RadioStation* current()
    {
        return stations[counter];
    }
    void next()
    {
        counter++;
    }
    void rewind()
    {
        counter = 0;
    }
    bool valid()
    {
        return counter < stations.size();
    }
private:
    vector<RadioStation*> stations;
    int counter=0;
};


int main(int argc, char** argv)
{
    StationList* stations = new StationList();

    stations->add_station(new RadioStation(89));
    stations->add_station(new RadioStation(100));
    stations->add_station(new RadioStation(101.5));
    stations->add_station(new RadioStation(107));

    stations->remove_station(new RadioStation(89));

    cout << "radio channel: " << endl;
    for(int i = 0; ; i++)
    {
        if(stations->valid())
        {
            cout << stations->current()->get_frequency() << ' ' << endl;
        }
        else
        {
            break;
        }
        stations->next();
    }


    return 0;
}
