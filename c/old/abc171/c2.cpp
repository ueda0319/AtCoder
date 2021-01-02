#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    long long n;
    long long i;
    string last="";
    for(i=1000;i<1000000000000001;i++){
        n=i;
        string s = "";
        n--;
        while(1){
            int p = n%26;
            char c = 'a' + p;
            s=c+s;
            if(n>=26){
                n=(n-p)/26-1;
            }else{
                break;
            }
        }
        if(s<=last){
            cout << i << "," << s << endl;
        }
        last=s;
    }
    return 0;
}