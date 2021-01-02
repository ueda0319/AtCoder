#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int checkfox(string &s, int &i, int &n){
    int step=0;
    for(step=0;step<3;step++){
        if(step==0){
            if(s[i]!='f'){
                return -1;
            }
        }else if(step==1){
            if(s[i]=='f'){
                int k = checkfox(s,i, n);
                if(k==-1)return -1;
                step--;
            }else if(s[i]!='o') return -1;
        }else if(step==2){
            if(s[i]=='f'){
                int k = checkfox(s,i, n);
                if(k==-1)return -1;
                step--;
            }else if(s[i]!='x'){
                return -1;
            }else{
                n++;
                return i+3;
            }
        }
        i++;
    }
    return -1;
}
int main(){
    int n, i, j;
    string s;
    cin >> n;
    cin >> s;
    int count=0;
    for(i=0;i<n;){
        j=checkfox(s, i, count);
        if(j==-1)i++;
    }
    cout << n-count*3 << endl;
    return 0;
}