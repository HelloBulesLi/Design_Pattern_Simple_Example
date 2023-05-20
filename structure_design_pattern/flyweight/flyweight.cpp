#include <iostream>
#include <string>
#include <map>

using namespace std;

class KarakTea {

};

class TeaMaker {
public:
    virtual KarakTea* make(string preference)
    {
        if(!available_tea.count(preference))
        {
            available_tea[preference] = new KarakTea();
        }
        return available_tea[preference];
    }
private:
    map<string, KarakTea*> available_tea;
};

class TeaShop {
public:
    TeaShop(TeaMaker* tea_maker)
    {
        this->tea_maker = tea_maker;
    }
    void take_order(string &tea_type, int table)
    {
        this->orders[table] = this->tea_maker->make(tea_type);
    }
    void take_order(string &&tea_type, int table)
    {
        this->orders[table] = this->tea_maker->make(tea_type);
    }
    void serve()
    {
        for(auto order:orders)
        {
            cout << "serve tea to table" << ' ' << order.first << ' ';
        }
        cout << endl;
    }
private:
    map<int, KarakTea*> orders;
    TeaMaker* tea_maker;
};


int main(int argc, char** argv)
{
    TeaMaker *teamaker = new TeaMaker();
    TeaShop * teashop = new TeaShop(teamaker);

    teashop->take_order("add sugar",1 );
    teashop->take_order("add milk", 2);
    teashop->take_order("add coffee", 3);

    teashop->serve();
    return 0;
}
