#include<queue>
#include<iostream>
using namespace std;

int main(){

queue<int> myQ;

for(int i = 1; i <=10; i++){

myQ.push(i);
cout << i << " ";



}
cout << endl;

while(!myQ.empty()){

    cout << myQ.front() << endl;
}



}