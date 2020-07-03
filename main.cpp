#include <iostream>
#include "user.h"
using namespace std;

namespace check
{
    void checkVal(int a, int b, int c = 0)
    {
        if (a <= b)
        {
            User *u;
            u = new User();
            if (c == 1)
                u[a - 1].viewUser(a);
            else if (c == 2)
                u[a - 1].deleteUser(a);
        }
        else
        {
            throw "Exception Raised!!! Selected user is incorrect!!!";
        }
    }
} // namespace check

namespace package
{
    void todo()
    {
        int ch, con, count;
        User *u;
        u = new User();
        count = 0;
        do
        {
            cout << "1 -> Add User\n2 -> View User\n3 -> View Total Items\n4 -> Delete User\n5 -> View All List Items\n";
            cin >> ch;
            if (ch == 1)
            {
                u[count].addUser();
                count++;
            }
            if (ch == 2)
            {
                if (count == 0)
                    cout << "No user available!!!Add user\n";
                else
                {
                    int chuser;
                    cout << "Choose the user\n";
                    for (int i = 0; i < count; i++)
                        cout << i + 1 << "\t";
                    cout << "\n";
                    cin >> chuser;
                    try
                    {
                        check::checkVal(chuser, count, 1);
                    }
                    catch (const char *msg)
                    {
                        cout << msg << endl;
                    }
                }
            }
            if (ch == 3)
            {
                User u;
                u.counter();
            }
            if (ch == 4)
            {
                if (count == 0)
                    cout << "No user available!!!Add user\n";
                else
                {
                    int chuser;
                    cout << "Choose the user\n";
                    for (int i = 0; i < count; i++)
                        cout << i + 1 << "\t";
                    cout << "\n";
                    cin >> chuser;
                    try
                    {
                        check::checkVal(chuser, count, 2);
                        count--;
                    }
                    catch (const char *msg)
                    {
                        cout << msg << endl;
                    }
                }
            }
            if (ch == 5)
            {
                cout<< "View All List\n";
                User t;
                t.viewTodo();
            }
            cout << "Non zero value to continue\n";
            cin >> con;
        } while (con != 0);
    }
} // namespace package

int main()
{
    package::todo();
    return 0;
}