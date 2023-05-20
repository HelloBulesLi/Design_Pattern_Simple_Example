#include <iostream>
#include <string>

using namespace std;

class BurgerBuilder {
public:
    BurgerBuilder(int &size)
    {
        this->size = size;
    }
    void add_pepper()
    {
        pepperoni = true;
    }
    void add_lettuce()
    {
        lettuce = true;
    }
    void add_cheese()
    {
        cheese = true;
    }
    void add_tomato()
    {
        tomato = true;
    }

    int size;
    int cheese = false;
    int pepperoni = false;
    int lettuce = false;
    int tomato = false;
};

class Burger {
public:
    Burger(BurgerBuilder* builder)
    {
        size = builder->size;
        cheese = builder->cheese;
        pepperoni = builder->pepperoni;
        lettuce = builder->lettuce;
        tomato = builder->tomato;
    }
private:
    int size;
    int cheese = false;
    int pepperoni = false;
    int lettuce = false;
    int tomato = false;
};

int main(int argc, char** argv)
{
    int size = 100;
    BurgerBuilder* builder = new BurgerBuilder(size);
    builder->add_cheese();
    builder->add_lettuce();

    Burger* burg = new Burger(builder);

    delete builder;
    delete burg;
    return 0;
}
