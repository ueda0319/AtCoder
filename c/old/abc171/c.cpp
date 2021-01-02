#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    string s = "";
    n--;
    while(1){
        long long p = n%26;
        char c = 'a' + p;
        s=c+s;
        if(n>=26){
            n=(n-p)/26-1;
        }else{
            break;
        }
    }
    cout << s << endl;
    return 0;
}