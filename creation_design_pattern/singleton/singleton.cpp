#include <iostream>
#include <string>

using namespace std;

class President {
public:
    static President* get_instance()
    {
        cout << "get current instance" << endl;
        return &instance;
    }
private:
    static President instance;
    President()
    {
        cout << "creat instance" << endl;
    }
};

int main(int argc, char** argv)
{
    President* present1 = President::get_instance();
    President* present2 = President::get_instance();
    return 0;
}
