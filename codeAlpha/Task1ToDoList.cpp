#include <iostream>
#include <string>
using namespace std;

class todo
{
private:
    string *starray;
    int size;
    int top;

public:
    string addtask(string);
    string markcompleted();
    void viewcur_task();
    todo(int);
    todo();
    ~todo();  // Destructor to free memory
};

todo::todo()
{
    starray = new string[5];
    top = -1;
    size = 5;
}

todo::todo(int s)
{
    starray = new string[s];
    top = -1;
    size = s;
}

todo::~todo()
{
    delete[] starray;
}

string todo::addtask(string data)
{
    if (top == size - 1)
    {
        return "Cannot add task: array is full";
    }
    else
    {
        top++;
        starray[top] = data;
        return "Task added successfully";
    }
}

string todo::markcompleted()
{
    if (top == -1)
    {
        return "No task to mark as completed";
    }
    else
    {
        top--;
        return "Task marked as completed";
    }
}

void todo::viewcur_task()
{
    if (top == -1)
    {
        cout << "No current task to view" << endl;
    }
    else
    {
        cout << "Current task: " << starray[top] << endl;
    }
}

int main()
{
    todo t1;
    int choice = 0;

    cout << "Enter your choice" << endl;
    cout << "\n1. Add task \n2. Mark as completed \n3. View current task \n4. Exit" << endl;

    while (choice != 4)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string data;
            cout << "Enter the task to add: ";
            cin >> data;
            cout << t1.addtask(data) << endl;
            break;
        }
        case 2:
        {
            cout << t1.markcompleted() << endl;
            break;
        }
        case 3:
        {
            t1.viewcur_task();
            break;
        }
        case 4:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
            cout << "Wrong choice" << endl;
        }
    }

    return 0;
}

