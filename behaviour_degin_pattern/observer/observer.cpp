#include <iostream>
#include <string>
#include <vector>

using namespace std;

class JobPost {
public: 
    template<typename T>
    JobPost(T&& title)
    {
        this->title = title;
    }
    string get_title()
    {
        return title;
    }
private:
    string title;
};

class JobSeeker{
public:
    template<typename T>
    JobSeeker(T&& name)
    {
        this->name = name;
    }
    void on_job_posted(JobPost* job)
    {
        cout << "Hi " << name << " there is a job: " << job->get_title() << endl;
    }
private:
    string name;
};

class EmploymentAgency {
public:
    void notify(JobPost* job_post)
    {
        for(auto job_seeker:observers)
        {
            job_seeker->on_job_posted(job_post);
        }
    }
    void attach(JobSeeker* job_seeker)
    {
        observers.push_back(job_seeker);
    }
    void add_job(JobPost* job_post)
    {
        notify(job_post);
    }
private:
    vector<JobSeeker*> observers;
};

int main(int argc, char** argv)
{
    JobSeeker* bob = new JobSeeker("bob");
    JobSeeker* blues = new JobSeeker("blues");

    EmploymentAgency* boss = new EmploymentAgency();
    boss->attach(bob);
    boss->attach(blues);

    JobPost* new_job = new JobPost("engineer");

    boss->add_job(new_job);

    delete bob;
    delete blues;
    delete boss;
    delete new_job;

    return 0;
}
