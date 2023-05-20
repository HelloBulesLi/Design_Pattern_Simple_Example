#include <iostream>
#include <string>

using namespace std;

class User;

class ChatRoomMediator {
public:
    virtual void show_message(User *user, string &message)=0;
    virtual ~ChatRoomMediator()=default;
};

class User {
public:
    User(string &name, ChatRoomMediator* chat_mediator)
    {
        this->name = name;
        mediator = chat_mediator;
    }
    User(string &&name, ChatRoomMediator* chat_mediator)
    {
        this->name = name;
        mediator = chat_mediator;
    }
    void send(string message)
    {
        this->mediator->show_message(this, message);
    }
    string get_name()
    {
        return name;
    }
private:
    string name;
    ChatRoomMediator* mediator;
};

class ChatRoom: public ChatRoomMediator {
public:
    virtual void show_message(User *user, string &message) override
    {
        cout << user->get_name() << "[send]: " << message << endl;        
    }
};

int main(int argc, char** argv)
{
    ChatRoom *chatroom = new ChatRoom();

    User user1("blues", dynamic_cast<ChatRoomMediator*>(chatroom));
    User user2("john", dynamic_cast<ChatRoomMediator*>(chatroom));

    user1.send("hello kitty");
    user2.send("hello mose");

}
