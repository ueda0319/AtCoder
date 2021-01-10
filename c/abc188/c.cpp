#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long ai, am1=0,am2=0;
    int nm1,nm2;
    int i;
    long n2 = 1;
    for(i=1;i<n;i++)n2*=2;
    for(i=0;i<n2;i++){
        cin >> ai;
        if(ai>am1){
            am1=ai;
            nm1=i;
        }
    }
    for(i=0;i<n2;i++){
        cin >> ai;
        if(ai>am2){
            am2=ai;
            nm2=i+n2;
        }
    }
    if(am1>am2){
        cout << nm2+1 << endl;
    }else{
        cout << nm1+1 << endl;
    }
    return 0;
}