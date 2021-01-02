#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    string s, t;
    cin >> s >> t;
    int ls = s.length();
    int lt = t.length();
    int i;
    bool flg=true;
    for(i=0;i<ls;i++){
        if(s[i]!=t[i]){
            flg=false;
            break;
        }
    }
    if(flg){
        cout << "Yes" << endl;

    }else{
        
        cout << "No" << endl;
    }
    return 0;
}