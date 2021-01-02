#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int k;
    string s;
    cin >> k >> s;
    if(s.length()<= k){
        cout << s << endl;
    }else{
        int i;
        for(i=0;i<k;i++) cout << s[i];
        cout << "..." << endl;
    }
    return 0;
}