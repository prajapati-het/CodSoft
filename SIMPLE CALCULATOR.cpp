#include <iostream>
#include <exception>

using namespace std;

int main()
{
    char continueChoice;

    do
    {
        double num1, num2;
        char operation;

        cout << "Enter the first number: ";
        cin >> num1;

        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Choose an operation:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "Enter the number corresponding to the operation: ";
        cin >> operation;

        double result;

        try
        {
            switch (operation)
            {
                case '1':
                    result = num1 + num2;
                    break;
                case '2':
                    result = num1 - num2;
                    break;
                case '3':
                    result = num1 * num2;
                    break;
                case '4':
                    if (num2 != 0)
                    {
                        result = num1 / num2;
                    }
                    else
                    {
                        throw runtime_error("Error: Division by zero is not allowed.");
                    }
                    break;
                default:
                    throw invalid_argument("Invalid operation selected.");
            }

            cout << "Result: " << result << endl;

            cout << "Do you want to continue? (y/n): ";
            cin >> continueChoice;
        }
        catch (const exception &e)
        {
            cout << "An error occurred: " << e.what() << endl;
            cout << "Do you want to continue? (y/n): ";
            cin >> continueChoice;
        }

    } while (continueChoice == 'y' || continueChoice == 'Y');

    cout << "Calculator program ended. Goodbye!" << endl;

    return 0;
}
