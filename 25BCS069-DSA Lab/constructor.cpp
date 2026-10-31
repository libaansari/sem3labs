#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int rollno;
    float gpa;

    Student(string s, int r, float g){
        name = s;
        rollno= r;
        gpa=g;
    }
};

int main(){
    Student ss("xyz" , 55,5);

    cout<<ss.name<<" "<<ss.rollno<<" "<<ss.gpa<<" "<<endl;
}