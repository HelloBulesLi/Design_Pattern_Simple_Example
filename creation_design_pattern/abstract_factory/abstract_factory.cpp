#include <iostream>
#include <string>

using namespace std;

class Door {
public:
    virtual void get_description() = 0;
    virtual ~Door() {}
};

class WoodDoor: public Door {
public:
    virtual void get_description() override
    {
        cout << "it's a wooden door" << endl;
    }
};

class IronDoor: public Door {
public:
    virtual void get_description() override
    {
        cout << "it's a iron door" << endl;
    }
};

class Expert {
public:
    virtual void get_description() = 0;
    virtual ~Expert() {}
};

class WoodExpert: public Expert {
public:
    virtual void get_description() override
    {
        cout << "it's a wooden expert" << endl;
    }
};

class IronExpert: public Expert {
public:
    virtual void get_description() override
    {
        cout << "it's a iron expert" << endl;
    }
};

class DoorFactory {
public:
    virtual Door* makeDoor() = 0;
    virtual Expert* makeFittingExpert() = 0;
    virtual ~DoorFactory() {}
};

class WoodDoorFactory: public DoorFactory {
public:
    virtual Door* makeDoor() override
    {
        return new WoodDoor();
    }

    virtual Expert* makeFittingExpert() override
    {
        return new WoodExpert();
    }
};

class IronDoorFactory: public DoorFactory {
public:
    virtual Door* makeDoor() override
    {
        return new IronDoor();
    }

    virtual Expert* makeFittingExpert() override
    {
        return new IronExpert();
    }
};

int main(int argc, char** argv)
{
    DoorFactory* factory1 = new WoodDoorFactory();
    DoorFactory* factory2 = new IronDoorFactory();

    Door* door1 = factory1->makeDoor();
    Expert* expert1 = factory1->makeFittingExpert();

    Door* door2 = factory2->makeDoor();
    Expert* expert2 = factory2->makeFittingExpert();

    door1->get_description();
    expert1->get_description();

    door2->get_description();
    expert2->get_description();

    delete factory1;
    delete factory2;

    delete door1,door2;
    delete expert1,expert2;

    return 0;
}