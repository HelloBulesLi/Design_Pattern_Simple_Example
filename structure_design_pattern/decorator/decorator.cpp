#include <iostream>
#include <string>

using namespace std;

class Coffee {
public:
    virtual float get_cost() = 0;
    virtual string get_description() = 0;
};

class SimpleCoffee: public Coffee {
public:
    virtual float get_cost() override
    {
        return 10;   
    }
    virtual string get_description() override
    {
        return "Simple coffee";
    }
};

class MilkCoffe: public Coffee{
public:
    MilkCoffe(Coffee* coffee)
    {
        this->coffee = coffee;
    }
    virtual float get_cost() override
    {
        return coffee->get_cost() + 2;
    }
    virtual string get_description() override
    {
        return coffee->get_description() + " add milk";
    }
private:
    Coffee* coffee;
};

class WhipCoffe: public Coffee{
public:
    WhipCoffe(Coffee* coffee)
    {
        this->coffee = coffee;
    }
    virtual float get_cost() override
    {
        return coffee->get_cost() + 3;
    }
    virtual string get_description() override
    {
        return coffee->get_description() + " add whip";
    }
private:
    Coffee* coffee;
};

class VanillaCoffe: public Coffee{
public:
    VanillaCoffe(Coffee* coffee)
    {
        this->coffee = coffee;
    }
    virtual float get_cost() override
    {
        return coffee->get_cost() + 4;
    }
    virtual string get_description() override
    {
        return coffee->get_description() + " add vanilla";
    }
private:
    Coffee* coffee;
};


int main(int argc, char** argv)
{
    Coffee* coffee = new SimpleCoffee();
    
    Coffee* add_milk_coffee = new MilkCoffe(coffee);

    Coffee* add_whip_coffee = new WhipCoffe(add_milk_coffee);

    Coffee* add_vanilla_coffee = new VanillaCoffe(add_whip_coffee);

    cout << add_vanilla_coffee->get_description() << endl;
    cout << add_vanilla_coffee->get_cost() << endl;
    return 0;
}
