#include <iostream>
using namespace std;

int main(){
    for (int i=0 ; i<=30 ; i++){
        if (i%10==0){
            continue;
        }else if (i%2==0){
            cout<< " mewing ";
        }else if(i%5==0){
            cout<< " skibidi ";
        } else cout<< i << " ";

    }
    return 0;
}
