#include <bits/stdc++.h>
using namespace std;
int getDigit(int k){
    int i;
    int t=1;
    for(i=0;i<8;i++){
        if(t>k)return i;
        t*=10;
    }
    return -1;
}
int main(){
    int k;
    cin >> k;
    if((k%2==0)||(k%5==0)){
        cout << -1 << endl;
        return 0;
    }
    if(k==3){
        cout << 3 << endl;
        return 0;
    }
    int digit = getDigit(k);
    int i,j;
    int p=k-1;
    for(i=digit;i*i<=p;i++){
        if(p%i==0){
            cout << i << endl;
            return 0;
        }
    }
    cout << p << endl;
    return 0;
}