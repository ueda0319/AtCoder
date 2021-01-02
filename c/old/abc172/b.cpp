#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    int l = s.length();
    int i, count=0;
    for(i=0;i<l;i++){
        if(s[i]!=t[i])count++;
    }
    cout << count << endl;
    return 0;
}