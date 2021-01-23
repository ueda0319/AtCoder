#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;

    long long l2 = 1;
    long long val = 1;
    int l;
    for(l=0;l<n;l++){
        l2*=2;
        cin >> s;
        if(s[0]=='A'){
            // And
            
        }else{
            // Or
            val=val+l2;
        }
    }
    cout << val << endl;
    return 0;
}