#include <iostream>
#include <string>

using namespace std;

class Door {
public:
    // virtual void open()=0;
    virtual void open(){};
    virtual void close() = 0;
};

class LabDoor: public Door {
public:
    virtual void open() override
    {
        cout << "opening lab door" << endl;
    }
    virtual void close() override
    {
        cout << "closing lab door" << endl;
    }
};

class SecuredDoor: public Door {
public:
    SecuredDoor(Door *door)
    {
        real_door = door;
    }
    void open(string &password)
    {
        if(password == "123456")
        {
            real_door->open();
        }
        else
        {
            cout << "wrong password, enter again" << endl;
        }
    }
    
    void open(string &&password)
    {
        if(password == "123456")
        {
            real_door->open();
        }
        else
        {
            cout << "wrong password, enter again" << endl;
        }
    }
    // virtual void open() override
    // {

    // }
    virtual void close() override
    {
        real_door->close();
    }
private:
    Door* real_door;
};

int main()
{
    Door* real_door = new LabDoor();
    SecuredDoor* user_door = new SecuredDoor(real_door);

    user_door->open("123456");
    user_door->close();

    user_door->open("3435");

    delete real_door;
    delete user_door;

    return 0;
}
