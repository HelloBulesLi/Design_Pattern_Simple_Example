#include <iostream>
#include <string>


using namespace std;

class Interviewer {
public:
    virtual void ask_questions()=0;
    virtual ~Interviewer() {};
};

class Developer: public Interviewer {
public:
    virtual void ask_questions() override {
        cout << "ask about develop question" << endl;
    }
};

class CommunityExecutive: public Interviewer {
public:
    virtual void ask_questions() override {
        cout << "ask about community question" << endl;
    }
};

class HireManager {
public:
    virtual Interviewer* make_interview() = 0;
    void takeInterview()
    {
        Interviewer* cur_interviewer = make_interview();
        cur_interviewer->ask_questions();
    }
    virtual ~HireManager() {}
    // ~HireManager(){ cout << "only base class release" << endl;}
};

class DevelopmentManager: public HireManager {
public:
    virtual Interviewer* make_interview() override
    {
        viewer = new Developer();
        return viewer;   
    }
    ~DevelopmentManager()
    {
        delete viewer;
        cout << "relese developinterviewer" << endl;
    }
private:
    Interviewer* viewer;
};

class MarketingManage: public HireManager {
public:
    virtual Interviewer* make_interview() override
    {
        Interviewer* viewer = new CommunityExecutive();
        return viewer;
    }
    ~MarketingManage()
    {
        delete viewer;
        cout << "relase marketmanager" << endl;
    }
private:
    Interviewer* viewer;
}; 



int main(int argc, char** argv)
{
    HireManager* manager1 = new DevelopmentManager();
    manager1->takeInterview();

    HireManager* manager2 = new MarketingManage();
    manager2->takeInterview();

    delete manager1;
    delete manager2;
    return 0;
}