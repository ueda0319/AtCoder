#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,p;
    string s;
    cin >> n >> p >> s;
    //int si[n];
    int i, j, ss, c=0;
    bool issub = false, issub_last = false;
    //const char *sc = s.c_str();
    s[0] -= '0';
    //si[0] = s[0] - '0';
    for(i=0; i<n-1; i++){
        j=i;
        ss = s[i];
        if(ss >= p) ss = ss % p;
        if(ss==0){
            c++;
            issub = true;
            //cout << i << "," << j << endl;
        }
        for(j=i+1; j<n; j++){
            if(i==0)s[j] -= '0';//si[j] = s[j] - '0';
            ss = ss * 10 + s[j];
            if(ss >= p) ss = ss % p;
            if(ss==0){
                c++;
                //cout << i << "," << j << endl;
            }
        }
    }
    ss = s[n-1];
    if(ss >= p) ss = ss % p;
    if(ss==0){
        c++;
        //cout << n-1 << "," << n-1 << endl;
    }
    cout << c << endl;
    return 0;
}