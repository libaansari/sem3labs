//increement and decreement
#include <iostream>
using namespace std;

class Number
{
    int n;

public:
    void getData()
    {
        cout << "Enter a number: ";
        cin >> n;
    }

    void operator++()
    {
        ++n;
    }

    void operator--()
    {
        --n;
    }

    void display()
    {
        cout << "Value = " << n << endl;
    }
};

int main()
{
    Number obj;

    obj.getData();

    ++obj;
    cout << "After increment: ";
    obj.display();

    --obj;
    cout << "After decrement: ";
    obj.display();

    return 0;
}