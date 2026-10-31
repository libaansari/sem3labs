#include <iostream>
using namespace std;
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
    double x[n];
    cout<<"Enter "<<n<<" elements of array ";
    for(int i =0;i<n;i++){
        cin>>x[i];
    }
    double A[n];
    average_n(x,A,n);
        cout<<"Average array by meathod 1[o(n2)] is ";
    for(int i =0;i<n;i++){
        cout<<A[i]<<" " ;
    }

    average_n2(x,A,n);
        cout<<endl<<"Average array by meathod 1[o(n2)] is ";
    for(int i =0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;

}