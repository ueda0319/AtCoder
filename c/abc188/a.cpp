#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b;
    if(a>b){
        c=a;
        a=b;
        b=c;
    }
    if(a+3>b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}