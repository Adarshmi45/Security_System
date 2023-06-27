#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "-----------Security System--------------" << endl;
    cout << "________________________________________" << endl;
    cout << "              1.Register                " << endl;
    cout << "              2.Login                   " << endl;
    cout << "              3.Change Password         " << endl;
    cout << "              4.End Program             " << endl;
    cout << "________________________________________" << endl
         << endl;

    do
    {
        cout << endl;
        cout << "Enter your choice: ";
        cin >> a;

        switch (a)
        {
        case 1:
        {
            cout << "------------------------------------" << endl;
            cout << "|            Register              |" << endl;
            cout << "------------------------------------" << endl
                 << endl;
            cout << "Please enter your name: ";
            cin >> name;
            cout << "Please enter your password: ";
            cin >> password0;
            cout << "Please enter your age: ";
            cin >> age;

            ofstream of1;
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0 << "\n";
                cout << "Registration Successful" << endl;
            }
            else
            {
                cout << "Error: Unable to open file." << endl;
            }

            break;
        }
        case 2:
        {
            i = 0;
            cout << "------------------------------------" << endl;
            cout << "|             Login                |" << endl;
            cout << "------------------------------------" << endl
                 << endl;
            ifstream of2;
            of2.open("file.txt");
            cout << "Please enter the username: ";
            cin >> user;
            cout << "Please enter the password: ";
            cin >> pass;

            if (of2.is_open())
            {
                while (getline(of2, text))
                {
                    istringstream iss(text);
                    iss >> word;
                    creds[i] = word;
                    i++;
                }

                if (user == creds[0] && pass == creds[1])
                {
                    cout << "--------Log in Successful--------" << endl << endl;
                    cout << "Details" << endl;
                    cout << "Username: " + user << endl;
                    cout << "Password: " + pass << endl;
                    cout << "Age: " + age << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Incorrect Password: " << endl;
                    cout << "Press 2 to log in again " << endl;
                    cout << "Press 3 to change password" << endl;
                }
            }
            else
            {
                cout << "Error: Unable to open file." << endl;
            }

            break;
        }
        case 3:
        {
            i = 0;
            cout << "---------------------Change Password-------------" << endl;

            ifstream of0;
            of0.open("file.txt");
            cout << "Enter the old password: " << endl;
            cin >> old;
            if (of0.is_open())
            {
                while (getline(of0, text))
                {
                    istringstream iss(text);
                    iss >> word1;
                    cp[i] = word1;
                    i++;
                }

                if (old == cp[1])
                {
                    of0.close();
                    ofstream of1;
                    of1.open("file.txt");
                    if (of1.is_open())
                    {
                        cout << "Enter your new password: " << endl;
                        cin >> password1;
                        cout << "Enter your password again: " << endl;
                        cin >> password2;

                        if (password1 == password2)
                        {
                            of1 << cp[0] << "\n";
                            of1 << password1;
                            cout << "Password Changed successfully!" << endl;
                        }
                        else
                        {
                            of1 << cp[0] << "\n";
                            of1 << old;
                            cout << "Password does not match" << endl;
                        }
                    }
                    else
                    {
                        cout << "Error: Unable to open file." << endl;
                    }
                }
                else
                {
                    cout << "Please enter a valid password!" << endl;
                }
            }
            else
            {
                cout << "Error: Unable to open file." << endl;
            }

            break;
        }
        case 4:
        {
            cout << "_____________Thank You_________________" << endl;
            break;
        }
        default:
        {
            cout << "Enter a valid choice" << endl;
            break;
        }
        }
    } while (a != 4);

    return 0;
}
