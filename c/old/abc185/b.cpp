#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    long n, t;
    int m;
    cin >> n >> m >> t;
    long n_max = n;
    int a,b;
    long t_last = 0;
    int i;
    for(i=0;i<m;i++){
        cin >> a >> b;
        if(n-(a-t_last) <= 0){
            cout << "No" << endl;
            return 0;
        }
        n-=a-t_last;
        n+=b-a;
        n=min(n,n_max);
        t_last=b;
    }
    n-=t-t_last;
    if(n<=0){
        cout << "No" << endl;

    }else{
        cout << "Yes" << endl;
    }
    return 0;
}