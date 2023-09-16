#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task
{
    string description;
    bool completed;
};

void printTasks(const vector<Task>& tasks)
{
    cout << "Task List:\n";
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". ";
        if (tasks[i].completed)
        {
            cout << "[X] ";
        }
        else
        {
            cout << "[ ] ";
        }
        cout << tasks[i].description << "\n";
    }
}

int main()
{
    vector<Task> tasks;

    while (true)
    {
        cout << "To-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            Task newTask;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, newTask.description);
            newTask.completed = false;
            tasks.push_back(newTask);
            cout << "Task added successfully!\n";

        }
        else if (choice == 2)
        {
            if (tasks.empty())
            {
                cout << "No tasks available.\n";
            }
            else
            {
                printTasks(tasks);
            }

        }
        else if (choice == 3)
        {
            cout << "Enter task number to mark as completed: ";
            int taskNumber;
            cin >> taskNumber;

            if (taskNumber <= 0 || taskNumber > static_cast<int>(tasks.size()))
            {
                cout << "Invalid task number.\n";
            }
            else
            {
                tasks[taskNumber - 1].completed = true;
                cout << "Task marked as completed.\n";
            }

        }
        else if (choice == 4)
        {
            if (tasks.empty())
            {
                cout << "No tasks available.\n";
            }
            else
            {
                cout << "Enter task number to remove: ";
                int taskNumber;
                cin >> taskNumber;

                if (taskNumber <= 0 || taskNumber > static_cast<int>(tasks.size()))
                {
                    cout << "Invalid task number.\n";
                }
                else
                {
                    tasks.erase(tasks.begin() + taskNumber - 1);
                    cout << "Task removed successfully.\n";
                }
            }

        }
        else if (choice == 5)
        {
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
