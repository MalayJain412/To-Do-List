#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task
{
    string Description;
    bool Done;
};

class To_do_list
{
private:
    vector<Task> tasks;
    int operation;

public:
    To_do_list();
    void new_task();
    void add_task(const string &Description);
    void view_task();
    void task_comp(size_t index);
    void remove_task(size_t index);
    void perform();
    // ~To_do_list();
};

void To_do_list::new_task()
{
    string taskDescription;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, taskDescription);
    add_task(taskDescription);
}

void To_do_list::add_task(const string &Description)
{
    Task tsk;
    tsk.Description = Description;
    tsk.Done = false;
    tasks.push_back(tsk);
    cout << "Task added successfully!" << endl;
}

void To_do_list::view_task()
{
    if (tasks.empty())
    {
        cout << "No tasks to be done!!!";
    }
    else
    {
        cout << "----------Tasks----------"<<endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << ". ";
            cout << (tasks[i].Done ? "[Completed] " : "[Pending] ");
            cout << tasks[i].Description << endl;
        }
    }
}

void To_do_list::task_comp(size_t index)
{
    if (index > 0 && index <= tasks.size())
    {
        tasks[index - 1].Done = true;
        cout << "Task marked as completed!!!" << endl;
    }
    else
        cout << "Invalid index no." << endl;
}

void To_do_list::remove_task(size_t index)
{
    if (index > 0 && index <= tasks.size())
    {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!\n";
    }
    else
        cout << "Invalid task index.\n";
}

To_do_list::To_do_list()
{
    cout << "Operations are:-" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark the Task as completed" << endl;
    cout << "4. Delete the task" << endl;
}

void To_do_list::perform()
{
    size_t task_Index;
    do
    {
        cout << "Enter the operation you want to perform:-";
        cin >> operation;
        switch (operation)
        {
        case 1:
            new_task();
            break;
        case 2:
            view_task();
            break;
        case 3:
            cout << "Enter the task index to mark as completed: ";
            cin >> task_Index;
            task_comp(task_Index);
            break;
        case 4:
            cout << "Enter the task index to remove: "; 
            cin >> task_Index;
            remove_task(task_Index);
            break;
        default:
            break;
        }
    } while (operation != 5);
}

// To_do_list::~To_do_list()
// {
// }

int main()
{

    cout << "===========Your To-Do List===========";

    To_do_list day1;
    day1.perform();
    return 0;
}
