#include <iostream>
#include <string>

using namespace std;
// Vistor
class AnimalOperation;

// Visitee
class Animal {
public:
    virtual void accept(AnimalOperation *operation) = 0;
    virtual ~Animal() = default;
};

class Monkey;
class Lion;
class Dolphin;
// Visitor
class AnimalOperation {
public:
    virtual void visitMonkey(Monkey *monkey)=0;
    virtual void visitLion(Lion *lion)=0;
    virtual void visitDolphin(Dolphin *dolphin)=0;
    // virtual void visitMonkey(Monkey *monkey){};
    // virtual void visitLion(Lion *lion){};
    // virtual void visitDolphin(Dolphin *dolphin){};
    virtual ~AnimalOperation() = default;
};

class Monkey: public Animal {
public:
    void shout()
    {
        cout << "ooh oo aa aa" << endl;
    }
    void accept(AnimalOperation *operation)
    {
        operation->visitMonkey(this);
    }
};

class Lion: public Animal {
public:
    void roar()
    {
        cout << "ooh ou ou ou" << endl;
    }
    void accept(AnimalOperation *operation)
    {
        operation->visitLion(this);
    }
};

class Dolphin: public Animal {
public:
    void speak()
    {
        cout << "ooh haha haha" << endl;
    }
    void accept(AnimalOperation *operation)
    {
        operation->visitDolphin(this);
    }
};

// Visitor inherit
class Speak: public AnimalOperation {
public:
    virtual void visitMonkey(Monkey *monkey) override
    {
        monkey->shout();
    }
    virtual void visitLion(Lion *lion) override
    {
        lion->roar();
    }
    virtual void visitDolphin(Dolphin *dolphin) override
    {
        dolphin->speak();
    }
};

class Jump: public AnimalOperation {
public:
    virtual void visitMonkey(Monkey *monkey) override
    {
        cout << "monkey jump" << endl;
    }
    virtual void visitLion(Lion *lion) override
    {
        cout << "lion jump" << endl;
    }
    virtual void visitDolphin(Dolphin *dolphin) override
    {
        cout << "dolphin jump" << endl;
    }
};


int main(int argc, char** argv)
{
    Monkey vistee1;
    Lion vistee2;
    Dolphin vistee3;
    Speak* visitor1 = new Speak();
    Jump* visitor2 = new Jump();

    vistee1.accept(dynamic_cast<AnimalOperation*>(visitor1));
    vistee2.accept(dynamic_cast<AnimalOperation*>(visitor1));
    vistee3.accept(dynamic_cast<AnimalOperation*>(visitor1));

    vistee1.accept(dynamic_cast<AnimalOperation*>(visitor2));
    vistee2.accept(dynamic_cast<AnimalOperation*>(visitor2));
    vistee3.accept(dynamic_cast<AnimalOperation*>(visitor2));

    delete visitor1;
    delete visitor2;

    return 0;
    
}
