#include <iostream>
#include <string>
#include <mutex>

using namespace std;

class President {
public:
    static President* get_instance()
    {
        if(instance == nullptr)
        {
            std::lock_guard<std::mutex> lock(mutex);
            if(instance == nullptr) {
                instance = new President();
            }
        }
        cout << "get current instance" << endl;
        return instance;
    }
private:
    static President* instance;
    static std::mutex mutex;
    President()
    {
        cout << "creat instance" << endl;
    }
};

President* President::instance = nullptr;
std::mutex President::mutex;

int main(int argc, char** argv)
{
    President* present1 = President::get_instance();
    President* present2 = President::get_instance();
    return 0;
}
