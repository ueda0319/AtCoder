#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r=0, l=n-1;
    int cost=0;
    for(;r<l;r++){
        if(s[r]=='W'){
            cost++;
            for(;l>r;l--){
                if(s[l]=='R'){
                    l--;
                    break;
                }
            }
            if((r==l)&&(s[l+1]!='R'))cost--;
        }
    }
    cout << cost << endl;
    return 0;
}