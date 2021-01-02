#include <iostream>
#include <string>
#include <math.h>
#include <vector>
typedef long long ll;
using namespace std;
const ll M = 1000000007;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}
int root(int *uf, int k){
    if(uf[k]==k){
        return k;
    }else{
        uf[k]=root(uf, uf[k]);
        return uf[k];
    }
}
int main(){
    int n;
    cin >> n;
    long long uf[n];
    int ufc[n]={0};
    long a,b;
    long long nab;
    int i,j;
    int ufi=0;
    int ar,br;
    bool flg;
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    for(i=0;i<n;i++)uf[i]=i;
    for(i=0;i<n;i++){
        cin >> a >> b;
        nab=a*b;
        flg=true;
        for(j=0;j<ufi;j++){
            if(uf[j]==nab){
                ufc[j]++;
                flg=false;
                break;
            }
        }
        if(flg){
            uf[ufi]=nab;
            ufc[ufi]=1;
            ufi++;
        }
    }
    int nc = 0;
    long long sum=0;
    for(i=0;i<ufi;i++){
        int nn = nc;
        flg=true;
        for(j=0;j<i;j++){
            if(uf[i]==-uf[j]){
                cout << "a" << endl;
                flg=false;
                nn-=ufc[j];
                break;
            }
        }
        long long na = ufc[i], nb=nn;
        long long sa=0,sb=0;
        for(j=1;j<=na;j++){
            sa = (sa + comb(na,j))%M;
        }
        for(j=0;j<=nb;j++){
            sb = (sb+comb(nb,j))%M;
        }
        cout << i << "," << nn << ","<< na << "," << nb << "," << sa << "," << sb << endl;
        sum = (sum + sa * sb)%M;
        if(flg)nc+=ufc[i];
    }
    cout << sum << endl;
    return 0;
}