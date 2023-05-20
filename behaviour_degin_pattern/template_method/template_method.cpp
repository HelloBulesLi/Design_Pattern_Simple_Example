#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Builder {
public:
    void build()
    {
        test();
        lint();
        assemble();
        deploy();
    }
    virtual void test()=0;
    virtual void lint()=0;
    virtual void assemble()=0;
    virtual void deploy()=0;
    virtual ~Builder()=default;
};

class AndroidBuilder: public Builder {
public:
    virtual void test() override
    {
        cout << "running android test" << endl;
    }
    virtual void lint() override
    {
        cout << "linting the android code" << endl;
    }
    virtual void assemble() override
    {
        cout << "assembling the android build" << endl;
    }
    virtual void deploy() override
    {
        cout << "Deploying android build to server" << endl;
    }
    ~AndroidBuilder(){
        cout << "release android resource" << endl;
    }
};

class IosBuilder: public Builder {
public:
    virtual void test()
    {
        cout << "running ios tests" << endl;
    }
    virtual void lint()
    {
        cout << "linting the ios code" << endl;
    }
    virtual void assemble()
    {
        cout << "assembling the ios build" << endl;
    }
    virtual void deploy()
    {
        cout << "Deploy ios build to server" << endl;
    }
    ~IosBuilder(){
        cout << "release IOS resource" << endl;
    }
};


int main(int argc, char** argv)
{
    std::shared_ptr<Builder> builder1(dynamic_cast<Builder*>(new AndroidBuilder));
    std::shared_ptr<Builder> builder2(dynamic_cast<Builder*>(new IosBuilder));

    builder1->build();

    builder2->build();

    return 0;
}