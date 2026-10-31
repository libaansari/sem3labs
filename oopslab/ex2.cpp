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

    friend void display(Number);
};

void display(Number obj)
{
    cout << "Number = " << obj.n << endl;
}

int main()
{
    Number obj;

    obj.getData();
    display(obj);

    return 0;
}