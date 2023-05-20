#include <iostream>
#include <string>

using namespace std;
class Theme {
public:
   virtual string get_color()=0;
   virtual ~Theme(){}
};

class DarkTheme: public Theme {
public:
    virtual string get_color() override
    {
        return "dark theme";
    }
};

class WhiteTheme: public Theme {
public:
    virtual string get_color() override
    {
        return "white theme";
    }
};

class BlueTheme: public Theme {
public:
    virtual string get_color() override
    {
        return "blue theme";
    }
};

class Webpage {
public:
    Webpage(Theme *theme) {};
    virtual string get_content()=0;
    virtual ~Webpage() {};
};

class About: public Webpage {
public:
    About(Theme *theme): Webpage(theme) {
        this->theme = theme;
    }
    virtual string get_content()
    {
        return "About page is "+ theme->get_color();
    }
private:
    Theme* theme;
};

class Career: public Webpage {
public:
    Career(Theme *theme): Webpage(theme) {
        this->theme = theme;
    }
    virtual string get_content()
    {
        return "Career page is "+ theme->get_color();
    }
private:
    Theme* theme;
};

int main(int argc, char** argv)
{
    DarkTheme dark_theme;
    WhiteTheme white_theme;
    Webpage* webpage = new Career(&dark_theme);
    Webpage* webpage1 = new About(&white_theme);

    cout << webpage->get_content() << endl;
    cout << webpage1->get_content() << endl;

    delete webpage;
    delete webpage1;
    return 0;
}
