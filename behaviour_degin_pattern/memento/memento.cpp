#include <iostream>
#include <string>

using namespace std;

class EiditorMemento {
public:
    EiditorMemento(string &content)
    {
        this->content = content;
    }
    EiditorMemento(string &&content)
    {
        this->content = content;
    }
    string get_content()
    {
        return content;
    }
private:
    string content;
};

class Editor {
public:
    // void type(string &words)
    // {
    //     content = content +' '+ words;
    // }
    // void type(string &&words)
    // {
    //     content = content +' '+ words;
    // }
    template <typename T>
    void type(T &&words)
    {
        content = content +' '+ words;
    }

    string get_content()
    {
        return content;
    }

    EiditorMemento* save()
    {
        return new EiditorMemento(this->content);
    }

    void restore(EiditorMemento* &memento)
    {
        content = memento->get_content();
    }
private:
    string content;
};

int main(int argc, char** argv)
{
    EiditorMemento* saved;
    Editor *edit = new Editor();

    string third = "kiit";
    edit->type("hello world.");
    edit->type("hello everyone.");

    saved = edit->save();

    edit->type(third);

    cout << edit->get_content() << endl;

    edit->restore(saved);

    cout << edit->get_content() << endl;

    return 0;
}
