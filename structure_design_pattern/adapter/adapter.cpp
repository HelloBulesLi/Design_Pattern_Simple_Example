#include <iostream>
#include <string>

using namespace std;

class Lion {
public:
    virtual void roar() = 0;
    virtual ~Lion() {};
};

class AfricanLion:public Lion {
public:
    virtual void roar() override
    {
        cout << "it's a african lion" << endl;
    }
};

class AsiaLion:public Lion {
public:
    virtual void roar() override
    {
        cout << "it's a asia lion" << endl;
    }
};

class Hunter {
public:
    void hunt_lion(Lion& lion)
    {
        lion.roar();
    }
};

class WildDog
{
public:
    void dog_bark()
    {
        cout << "it's wild dog" << endl;
    }
};

class WildDogAdapter: public Lion {
public:
    WildDogAdapter(WildDog* dog)
    {
        this->dog = dog;
    }
    virtual void roar() override
    {
        this->dog->dog_bark();
    }
private:
    WildDog* dog;
};




int main(int argc, char** argv)
{
    WildDog dog;
    WildDogAdapter dog_adapter(&dog);
    
    Hunter hunter;
    hunter.hunt_lion(dog_adapter);
    return 0;
}
