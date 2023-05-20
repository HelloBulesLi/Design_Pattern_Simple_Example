#include <iostream>
#include <string>
#include <memory>

using namespace std;

class PhoneState {
public:
    virtual PhoneState* pick_up()=0;
    virtual PhoneState* hang_up()=0;
    virtual PhoneState* dial()=0;
};

class PhoneStateIdle: public PhoneState {
public:
    virtual PhoneState* pick_up() override;
    virtual PhoneState* hang_up() override;
    virtual PhoneState* dial() override;
};

class PhoneStatePickUp: public PhoneState {
public:
    virtual PhoneState* pick_up() override;
    virtual PhoneState* hang_up() override;
    virtual PhoneState* dial() override;
};

class PhoneStateCalling: public PhoneState {
public:
    virtual PhoneState* pick_up() override;
    virtual PhoneState* hang_up() override;
    virtual PhoneState* dial() override;
};


PhoneState* PhoneStateIdle::pick_up()
{
    cout << "from idle to pick up state" << endl;
    return dynamic_cast<PhoneState*>(new PhoneStatePickUp);
}
PhoneState* PhoneStateIdle::hang_up()
{
    throw "already in idle state";
}
PhoneState* PhoneStateIdle::dial()
{
    throw "phone is in idle, please pick up first";
}


PhoneState* PhoneStatePickUp::pick_up()
{
    throw "already in pick up state";
}
PhoneState* PhoneStatePickUp::hang_up()
{
    cout << "from pick up to idle state" << endl;
    return new PhoneStateIdle();
}
PhoneState* PhoneStatePickUp::dial()
{
    cout << "from pick up to dial state" << endl;
    return new PhoneStateCalling();
}

PhoneState* PhoneStateCalling::pick_up()
{
    throw "already picked up";
}
PhoneState* PhoneStateCalling::hang_up()
{
    cout << "from dial to idle state" << endl;
    return new PhoneStateIdle();
}
PhoneState* PhoneStateCalling::dial()
{
    throw "aldreay in dial state";
}

class Phone {
public:
    Phone(PhoneState* init_state)
    {
        cur_state = init_state;
    }
    void pick_up()
    {
        cur_state = cur_state->pick_up();
    }
    void hang_up()
    {
        cur_state = cur_state->hang_up();
    }
    void dial()
    {
        cur_state = cur_state->dial();
    }
private:
    PhoneState* cur_state;
};

int main(int argc, char** argv)
{
    PhoneStateIdle init_state;
    Phone *phone = new Phone(dynamic_cast<PhoneState*>(&init_state));
    try
    {
        phone->dial();
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
    try
    {
        phone->pick_up();
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }

    try
    {
        phone->dial();
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
    
    return 0;
}
