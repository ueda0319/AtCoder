#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    int a[n];
    int i;
    int z[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            z[i]=a[i];
        }else{
            z[i]
        }
        z=z^a[i];
    }
    int t,x,y;
    for(i=0;i<q;i++){
        cin >> t >> x >> y;
        if()
    }
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