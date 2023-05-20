#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Account {
public:
    void set_next(Account *account)
    {
        this->successor = account;
    }
    bool can_pay(int need_pay)
    {
        return this->balance >= need_pay;
    }
    void pay(int need_pay)
    {
        if(can_pay(need_pay))
        {
            cout << "using " << typeid(*this).name() << " finish payment" << endl;
        }
        else if(this->successor)
        {
            this->successor->pay(need_pay);
        }
        else
        {
            cout << typeid(*this).name() << \
            " can't finish pay and no next processor" << endl;
        }
    }
    virtual ~Account()=default;
protected:
    int balance;
    Account* successor = nullptr;
};

class Bank: public Account {
public:
    Bank(int balance)
    {
        this->balance = balance;
    }
};

class Paypal: public Account {
public:
    Paypal(int balance)
    {
        this->balance = balance;
    }
};

class Bitcoin: public Account {
public:
    Bitcoin(int balance)
    {
        this->balance = balance;
    }
};

int main(int argc, char** argv)
{
    Bank* bank = new Bank(100);
    Paypal* paypal = new Paypal(200);
    Bitcoin* bitcoin = new Bitcoin(400);

    bank->set_next(dynamic_cast<Account*>(paypal));
    paypal->set_next(dynamic_cast<Account*>(bitcoin));

    bank->pay(350);

    bank->pay(180);

    delete bank;
    delete paypal;
    delete bitcoin;

    return 0;
}
