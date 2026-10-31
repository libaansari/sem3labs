//classes and object
#include <iostream>
using namespace std;

class Student
{
    int rollNo;
    string name;
    float marks;

public:
    void read()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << "\n   Student Details    " << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    Student s;  

    s.read();    
    s.display(); 

    return 0;
}