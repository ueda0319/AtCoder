#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    unsigned long long x, a;
    cin >> x;
    int i;
    a = 100;
    for(i=1;i<4000;i++){
        a += a / 100;
        if(a>=x){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}