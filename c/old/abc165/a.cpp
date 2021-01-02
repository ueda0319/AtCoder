#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int k, a, b;
    cin >> k >> a >> b;
    int i = a/k;
    int j=b/k;
    if((a%k==0)||(b%k==0)||(j-i>0)){
        cout << "OK" << endl;

    }else{
        cout << "NG" << endl;
    }
    return 0;
}