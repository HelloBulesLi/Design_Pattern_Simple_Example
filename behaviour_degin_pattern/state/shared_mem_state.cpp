#include <iostream>
#include <string>
#include <memory>

using namespace std;

class PhoneState {
public:
    virtual std::shared_ptr<PhoneState> pick_up()=0;
    virtual std::shared_ptr<PhoneState> hang_up()=0;
    virtual std::shared_ptr<PhoneState> dial()=0;
    virtual ~PhoneState() = default;
};

class PhoneStateIdle: public PhoneState {
public:
    virtual std::shared_ptr<PhoneState> pick_up() override;
    virtual std::shared_ptr<PhoneState> hang_up() override;
    virtual std::shared_ptr<PhoneState> dial() override;
    ~PhoneStateIdle(){
        cout << "relase idle state" << endl;
    }
};

class PhoneStatePickUp: public PhoneState {
public:
    virtual std::shared_ptr<PhoneState> pick_up() override;
    virtual std::shared_ptr<PhoneState> hang_up() override;
    virtual std::shared_ptr<PhoneState> dial() override;
    ~PhoneStatePickUp() {
        cout << "release pick up state" << endl;
    }
};

class PhoneStateCalling: public PhoneState {
public:
    virtual std::shared_ptr<PhoneState> pick_up() override;
    virtual std::shared_ptr<PhoneState> hang_up() override;
    virtual std::shared_ptr<PhoneState> dial() override;
    ~PhoneStateCalling() {
        cout << "relase calling state" << endl;
    }
};


std::shared_ptr<PhoneState> PhoneStateIdle::pick_up()
{
    cout << "from idle to pick up state" << endl;
    // PhoneState* ptr = dynamic_cast<PhoneState*>(new PhoneStatePickUp);
    // std::shared_ptr<PhoneState> shared_p(ptr);
    std::shared_ptr<PhoneState> shared_p(dynamic_cast<PhoneState*>(new PhoneStatePickUp));
    return shared_p;
}
std::shared_ptr<PhoneState> PhoneStateIdle::hang_up()
{
    throw "already in idle state";
}
std::shared_ptr<PhoneState> PhoneStateIdle::dial()
{
    throw "phone is in idle, please pick up first";
}


std::shared_ptr<PhoneState> PhoneStatePickUp::pick_up()
{
    throw "already in pick up state";
}
std::shared_ptr<PhoneState> PhoneStatePickUp::hang_up()
{
    cout << "from pick up to idle state" << endl;
    // PhoneState* ptr = dynamic_cast<PhoneState*>(new PhoneStateIdle);
    std::shared_ptr<PhoneState> shared_p(dynamic_cast<PhoneState*>(new PhoneStateIdle));
    return shared_p;
}
std::shared_ptr<PhoneState>PhoneStatePickUp::dial()
{
    cout << "from pick up to dial state" << endl;
    // PhoneState* ptr = dynamic_cast<PhoneState*>(new PhoneStateCalling);
    std::shared_ptr<PhoneState> shared_p( dynamic_cast<PhoneState*>(new PhoneStateCalling));
    return shared_p;
}

std::shared_ptr<PhoneState> PhoneStateCalling::pick_up()
{
    throw "already picked up";
}
std::shared_ptr<PhoneState> PhoneStateCalling::hang_up()
{
    cout << "from dial to idle state" << endl;
    // PhoneState* ptr = dynamic_cast<PhoneState*>(new PhoneStateIdle);
    std::shared_ptr<PhoneState> shared_p(dynamic_cast<PhoneState*>(new PhoneStateIdle));

    return shared_p;
}
std::shared_ptr<PhoneState> PhoneStateCalling::dial()
{
    throw "aldreay in dial state";
}

class Phone {
public:
    Phone(std::shared_ptr<PhoneState> init_state)
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
    std::shared_ptr<PhoneState> cur_state;
};

int main(int argc, char** argv)
{
    std::shared_ptr<PhoneState> init_state(dynamic_cast<PhoneState*>(new PhoneStateIdle));
    std::shared_ptr<Phone> phone(new Phone(init_state));
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
