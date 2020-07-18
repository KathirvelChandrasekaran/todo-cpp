#include <iostream>
#include <iterator>
#include <fstream>
#include <list>
using namespace std;
list<string> todo;
list<list<string> > nestTodo;
class Todo
{
private:
    int n;
    string s;
    static int count;
    int counter;

public:
    Todo()
    {
        n = 0;
        counter = 0;
    }
    void addtodo();
    int resultCount();
    int intemCount();
    void viewTodo();
    ~Todo() {}
};

void Todo::addtodo()
{
    ofstream out;
    out.open("todo.dat");
    cout << "Enter the number of items\n";
    cin >> n;
    cout << "Enter the todo items\n";
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        todo.push_back(s);
        out << s << endl;
        intemCount();
    }
    nestTodo.push_back(todo);
    int ch, con;
    do
    {
        cout << "Do you want to add prior item to List\n1 -> Yes\n2 -> No\n";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter the Todo Item\n";
            cin >> s;
            todo.push_front(s);
            out << s << endl;
        }
        cout << "Non Zero value to add another prior value\n";
        cin >> con;
    } while (con != 0);
    cout << "Items in the Todo list\n----------------------------\n";
    list<string>::iterator i;
    int j = 0;
    for (i = todo.begin(); i != todo.end(); ++i)
    {
        cout << ++j << ")"
             << "\t" << *i << "\n";
        count++;
    }
    cout << "\n";
}

void Todo::viewTodo()
{
    list<list<string> >::iterator nestItr;
    for (nestItr = nestTodo.begin(); nestItr != nestTodo.end(); ++nestItr)
    {
        cout << "[\n\n";
        list<string>::iterator singleItr;
        list<string> &single_list_pointer = *nestItr;
        int j = 0;

        for (singleItr = single_list_pointer.begin();
             singleItr != single_list_pointer.end();
             singleItr++)
        {
            cout << "\t\t" << ++j << ")\t" << *singleItr << "\n";
        }
        cout << "\n\n]\n\n";
    }
}

int Todo::intemCount()
{
    return counter++;
}

int Todo::resultCount()
{
    return count;
}

int Todo::count = 0;