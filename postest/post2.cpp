#include <iostream>
using namespace std;

int main(){
    int berat;
    int bagi;

    for (berat=1; berat<=10 ; berat++){
        cout << berat ;
        bagi = berat /2;
        if (bagi%2==0){
            cout<< " YA "<<endl;
        }else cout<< " TIDAK "<<endl;
    }

}
/* ada kesalahan dalam program yaitu saat membagi beberapa angka dan hasilnya ganjil namun pecahan,
program hanya akan membaca angka depannya yang genap karena tipe datanya integer*/
