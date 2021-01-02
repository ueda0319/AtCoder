#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    if(a==b || a==b+1){
        cout << x << endl;
    }else if(a<b){
        int fl = b-a;
        int ct =min(y, 2*x);
        int t = x+fl*ct;
        cout << t << endl;
    }else{
        int fl = a-b-1;
        int ct =min(y, 2*x);
        int t = x+fl*ct;
        cout << t << endl;
    }
    return 0;
}