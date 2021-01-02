#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int l = s.length();
    int i, p=0;
    for(i=0;i<l;i++){
        p=(p+(s[i]-'0'))%9;
    }
    if(p==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}