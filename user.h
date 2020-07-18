#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <fstream>
#include "todo.h"
using namespace std;
list<string> user;

class User : public Todo
{
private:
    string u;
    static int userCount;
    int n;

public:
    User()
    {
        n = userCount;
    }
    void addUser();
    void viewUser(int);
    void deleteUser(int);
    void counter();
    ~User()
    {
    }
};

void User::addUser()
{
    ofstream out;
    out.open("todo.dat");
    out << "kathir" << endl;
    userCount++;
    User us;
    Todo t;
    cout << "Enter the user name\n";
    cin >> us.u;
    us.n = userCount;
    cout << "Added user is " << us.u << endl;
    for (int i = 0; i < us.n; i++)
    {
        user.push_back(us.u);
        cout << "Create Todo List\n";
        cout << "\n\n";
        cout << us.u << endl;
        cout << "--------------------\n";
        t.addtodo();
        cout << endl;
    }
}

void User::viewUser(int ch)
{
    User r;
    // cout << "User ID\t\t\t" << r.n << endl;
    list<string>::iterator it = user.begin();
    advance(it, ch - 1);
    cout << "User Name\t\t" << *it << "\n";
}

void User::deleteUser(int ch)
{
    User r;
    if (r.n == 0)
        cout << "No Users available\n";
    else
    {
        // cout << "User ID\t\t\t" << r.n << endl;
        list<string>::iterator it = user.begin();
        advance(it, ch - 1);
        cout << "User Name\t\t" << *it << "\n";
        it = user.erase(it);
        r.n--;
        cout << "User Deleted\n";
    }
}

void User::counter()
{
    Todo t;
    cout << "Total User Count " << userCount << endl;
    cout << "Total List item count in the Todo-List " << t.resultCount() << endl;
}

int User::userCount = 0;