#include<iostream>


using namespace std;

void prefixAverage1(int X[], int A[], int n){

int counter = 0;

int s = X[0];
A[0] = s;

    for(int i = 1; i < n; i++){

        s+=X[i];
        A[i] = s/i;
    }


  for(int i = 0; i < n; i++){

        cout << A[i] << endl;
    }
counter++;
   





}

void prefixAverage2(int X[], int A[], int n){

int counter = 0;
int s = X[0];
A[0] = s;

for(int i =1; i < n; i++){
    s = s+X[i];
    
    A[i] = s /(i+1);
}

//cout << counter << endl;


}

int main(){

    int x[] = {1,2,3,4,6,7,9,23,50};
    int y[] = {0};
    int z = 10;

for(int i =0; i < z; i++){
    x[i] = i;
}

prefixAverage1(x,y,z);
prefixAverage2(x,y,z);

for(int i =0; i < z; i++){
    cout << y[i] << endl;
}

    return 0;

}

