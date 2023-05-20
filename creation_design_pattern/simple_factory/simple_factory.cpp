#include <iostream>
#include <string>


using namespace std;

class Door {
public:
    virtual int get_width()= 0;
    virtual int get_height()= 0;
};

class WoodDoor:public Door{
public:
    WoodDoor(int w, int h):width(w),height(h){}
    virtual int get_width() override {
        return width;
    }
    virtual int get_height() override {
        return height;
    }
private:
    int width,height;
};

class DoorFactory {
public:
    static WoodDoor* makeDoor(int width, int height)
    {
        WoodDoor* newdoor = new WoodDoor(width, height);
        return newdoor;
    }
};

int main(int argc, char** argv)
{
    WoodDoor* door = DoorFactory::makeDoor(10,5);

    cout << door->get_height() << ' ' << door->get_width() << endl;
    return 0;
}