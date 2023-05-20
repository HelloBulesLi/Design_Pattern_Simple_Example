#include <iostream>
#include <string>

using namespace std;

class Bulb {
public:
    void turn_on()
    {
        cout << "bulb has been lit" << endl;
    }
    void turn_off()
    {
        cout << "darkness" << endl;
    }
};

class Command {
public:
    virtual void execute()=0;
    virtual void undo()=0;
    virtual void redo()=0;
    virtual ~Command()=default;
};

class TurnOn: public Command {
public:
    TurnOn(Bulb *bulb)
    {
        this->bulb = bulb;
    }
    virtual void execute() override {
        this->bulb->turn_on();
    }
    virtual void undo() override {
        this->bulb->turn_off();
    }
    virtual void redo() override {
        this->execute();
    }
private:
    Bulb* bulb;
};

class TurnOff: public Command {
public:
    TurnOff(Bulb *bulb)
    {
        this->bulb = bulb;
    }
    virtual void execute() override {
        this->bulb->turn_off();
    }
    virtual void undo() override {
        this->bulb->turn_on();
    }
    virtual void redo() override {
        this->execute();
    }
private:
    Bulb* bulb;
};

class RemoteControl {
public:
    void submit(Command *command)
    {
        command->execute();
    }
};

int main(int argc, char** argv)
{
    Bulb* bulb = new Bulb();
    TurnOn* turn_on = new TurnOn(bulb);
    TurnOff* turn_off = new TurnOff(bulb);

    RemoteControl* remote_control = new RemoteControl();

    remote_control->submit(dynamic_cast<Command*>(turn_on));
    remote_control->submit(dynamic_cast<Command*>(turn_off));

    delete bulb;
    delete turn_on;
    delete turn_off;
    delete remote_control;
    return 0;
}
