#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,t;
    cin >> n >> x >> t;
    int p=0;
    int i;
    for(i=0;i<n;i+=x){
        p+=t;
    }
    cout << p << endl;
    return 0;
}