#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int ck(unsigned long long p){
    int k=0;
    while(p>=10){
        k++;
        p/=10;
    }
    return k;
}
int tk(unsigned long long p){
    int k=0;
    while(p>=10){
        k++;
        p/=10;
    }
    return p;
}
int main(){
    int n;
    cin >> n;
    unsigned long long m=1,a;
    int i;
    bool flg=false;
    bool zeroflg=false;
    for(i=0;i<n;i++){
        cin >> a;
        if((ck(m)+ck(a)>18)){
            flg=true;
        }else{
            m*=a;
        }
        if(m>1000000000000000000){
            flg=true;
        }
        if(a==0){
            zeroflg=true;
        }
    }
    if(zeroflg){
    cout << 0 << endl;
    }else if(flg){
    cout << -1 << endl;
    }else{
    cout << m << endl;
    }
    return 0;
}