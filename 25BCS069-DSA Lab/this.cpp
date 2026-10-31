#include<iostream>
using namespace std;
class Cricketer{
    public:
    string name;
    int runs;

    Cricketer(string name, int runs){
        this->name= name;
        this->runs= runs;
    }
};

int main(){
    Cricketer c1("xyz" , 2);

    cout<<c1.name<<endl;
}