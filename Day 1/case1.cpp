#include <iostream>
using namespace std;
int main(){
    int array [10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i=0 ; i<10 ; i++){
        if (array[i]%2==0){
            cout<<" boom ";
        }else cout<< array[i];
    }
}
