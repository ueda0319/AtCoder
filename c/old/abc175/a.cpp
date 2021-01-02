#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int i, j=0;
    if(s=="RRR"){
        cout << 3 << endl;
    }else if((s=="RRS")||(s=="SRR")){
        cout << 2 << endl;
    }else if((s=="RSR")||(s=="RSS")||(s=="SRS")||(s=="SSR")){
        cout << 1 << endl;
    }else if(s=="SSS"){
        cout << 0 << endl;
    }
    return 0;
}