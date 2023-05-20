#include <iostream>
#include <string>

using namespace std;
class Sheep {
public:
    Sheep(string &name, string category = "Mountain Sheep")
    {
        this->name = name;
        this->category = category;
    }
    Sheep(string &&name, string category = "Mountain Sheep")
    {
        this->name = name;
        this->category = category;
    }
    void set_name(string &name)
    {
        this->name = name;
    }
    string get_name()
    {
        return name;
    }
    void set_category(string category)
    {
        this->category = category;
    }
    string get_category()
    {
        return this->category;
    }
    Sheep* Clone()
    {
        Sheep* sheep_clone = new Sheep(this->name, this->category);
        return sheep_clone;
    }
private:
    string name;
    string category;
};

int main(int argc, char** argv)
{
    // string sheep_name = "hali";
    Sheep sheep1("hali");

    Sheep* sheep1_clone = sheep1.Clone();

    cout << sheep1_clone->get_category() << ' ' << sheep1_clone->get_name() << endl;

    return 0;
}
