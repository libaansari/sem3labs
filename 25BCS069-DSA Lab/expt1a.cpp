#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void average_n2(double x [] , double A[] , int n){
    for(int i =0 ; i<n;i++){
       double  sum =0;
       for(int j =0 ; j<=i ; j++){
           sum += x[j];
        }
       A[i] = (double)sum/(i+1);
     }
}
void average_n(double x [] , double A[] , int n){
    double  sum =0;
    for(int i =0 ; i<n;i++){
        sum += x[i]; 
       A[i] = (double)sum/(i+1);
     }
}

int main(){
    int n ;
    cout<<"Enter size of an array : ";
    cin>>n;
    double* x = new double[n];
    for(int i =0;i<n;i++){
         x[i]=i+1;
    }

    double* A = new double[n];

    
    
    auto start2 = high_resolution_clock::now();
        average_n(x,A,n);
    auto end2 = high_resolution_clock::now();
    auto t2 = duration_cast<nanoseconds>(end2-start2);
    cout<<"time taken by meathod 1 O(n) is "<<t2.count()<<" ns"<<endl;
    
    auto start1 = high_resolution_clock::now();
    average_n2(x,A,n);
    auto end1 = high_resolution_clock::now();
    auto t1 = duration_cast<nanoseconds>(end1-start1);
    cout<<"time taken by meathod 2 O(n2) is "<<t1.count()<< " ns"<<endl;

    delete [] A;
    delete [] x;




    return 0;

}