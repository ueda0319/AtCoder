#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
char rsp(char a, char b){
    if(a==b)return a;
    if(a=='R'){
        return (b=='P')? b : a;
    }else if(a=='P'){
        return (b=='S')? b : a;
    }else{
        return (b=='R')? b : a;
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    string so, s;
    cin >> so;
    s = so + so;
    string s2;
    int i,j;
    for(i=0;i<k;i++){
        s2=s;
        for(j=0;j<2*n;j++){
            int id = (j*2)%(2*n);
            s[j] = rsp(s2[(j*2)%(2*n)], s2[(j*2+1)%(2*n)]);
        }
    }
    cout << s[0] << endl;
    return 0;
}