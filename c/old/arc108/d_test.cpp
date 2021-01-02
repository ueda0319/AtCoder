#include <iostream>
#include <string>
#include <math.h>
#include <unordered_map>
#define NMAX 11
using namespace std;
unordered_map<string, int> mp;
void stt(string s, int n, string &aa,string &ab,string &ba, string &bb){
    int i;
    for(i=0;i<n-1;i++){
        string ins = "A";
        if(s[i]=='A'&&s[i+1]=='A') ins = aa;
        if(s[i]=='A'&&s[i+1]=='B') ins = ab;
        if(s[i]=='B'&&s[i+1]=='A') ins = ba;
        if(s[i]=='B'&&s[i+1]=='B') ins = bb;
        string sd = s.insert(i, ins);
        if(n+1==NMAX){
            mp[sd] =mp[sd]+1;
        }else{
            stt(sd,n+1,aa,ab,ba,bb);
        }
    }
}
int main(){
    string aa="A", ab="B", ba="B", bb="A";
    for(int iaa=0;iaa<2;iaa++){
        aa=(iaa==0) ? "A" : "B";
        for(int iab=0;iab<2;iab++){
            ab=(iab==0) ? "A" : "B";
            for(int iba=0;iba<2;iba++){
                ba=(iba==0) ? "A" : "B";
                for(int ibb=0;ibb<2;ibb++){
                    bb=(ibb==0) ? "A" : "B";
                    stt("AB", 2, aa,ab,ba,bb);
                    cout << mp.size() << endl;
                    mp.clear();
                }
            }
        }
    }
    return 0;
}