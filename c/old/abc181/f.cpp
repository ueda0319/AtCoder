#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int root(int *uf, int k){
    if(uf[k]==k){
        return k;
    }else{
        uf[k]=root(uf, uf[k]);
        return uf[k];
    }
}
int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    long long t1 = ((a+1)*a/2)%998244353;
    long long t2 = ((b+1)*b/2)%998244353;
    long long t3 = ((c+1)*c/2)%998244353;
    long long t = (((t1*t2)%998244353)*t3)%998244353;
    cout << t << endl;
    return 0;
}