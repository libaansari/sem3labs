//concat
#include <iostream>
#include <string>
using namespace std;

class String
{
    string str;

public:
    void getData()
    {
        cout << "Enter string: ";
        cin >> str;
    }

    String operator+(String s)
    {
        String temp;
        temp.str = str + s.str;
        return temp;
    }

    void display()
    {
        cout << "Concatenated String = " << str << endl;
    }
};

int main()
{
    String s1, s2, s3;

    s1.getData();
    s2.getData();

    s3 = s1 + s2;

    s3.display();

    return 0;
}