#include <iostream>
#include <string>

using namespace std;

class Computer {
public:
    void get_electricshock()
    {
        cout << "Ouch" << endl;
    }
    void make_sound()
    {
        cout << "Beep" << endl;
    }
    void show_loading_screen()
    {
        cout << "loading..." << endl;
    }
    void bam()
    {
        cout << "ready to be used" << endl;
    }
    void close_everything()
    {
        cout << "Bup bup bup buzzz" << endl;
    }
    void sooth()
    {
        cout << "Zzzzz" << endl;
    }
    void pull_current()
    {
        cout << "pull current" << endl;
    }
};

class CompterFacade {
public:
    CompterFacade(Computer* computer)
    {
        this->computer = computer;
    }
    void turn_on()
    {
        computer->get_electricshock();
        computer->make_sound();
        computer->show_loading_screen();
        computer->bam();
    }
    void turn_off()
    {
        computer->close_everything();
        computer->pull_current();
        computer->sooth();
    }
private:
    Computer* computer;
};

int main(int argc, char** argv)
{
    Computer computer;
    CompterFacade user_interface(&computer);
    cout << "turn on computer" << endl;
    user_interface.turn_on();
    cout << "turn off computer" << endl;
    user_interface.turn_off();
    return 0;
}
