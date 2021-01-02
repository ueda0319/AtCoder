#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    int sl = s.length();
    int tl = t.length();
    int i,j;
    int count=0, countMax=1001;
    for(i=0;i<=sl-tl;i++){
        count=0;
        for(j=0;j<tl;j++){
            if(s[i+j]!=t[j])count++;
        }
        if(count<countMax)countMax=count;
    }
    cout << countMax << endl;
    return 0;
}