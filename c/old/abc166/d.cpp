#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    long long x;
    cin >> x;
    long long a, b=-100;
    for(a=1;;a++){
        if(a*a*a*a*a*2<x)continue;
        for(;b<a;b++){
            long long ab = a*a*a*a*a-b*b*b*b*b;
            if(ab==x){
                cout << a << " " << b << endl;
                return 0;
            }else if(ab < x){
                b--;
                break;
            }
        }
    }
    return 0;
}