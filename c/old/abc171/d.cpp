#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int table[100001];
    int i;
    for(i=0;i<100001;i++){
        table[i]=0;
    }
    int n, q;
    cin >> n;
    int a[n];
    long long sum=0;
    for(i=0;i<n;i++){
        cin >> a[i];
        table[a[i]] ++;
        sum+=a[i];
    }
    cin >> q;
    int b,c;
    for(i=0;i<q;i++){
        cin >> b >> c;
        sum += (c-b)*table[b];
        table[c]+=table[b];
        table[b]=0;
        cout << sum << endl;
    }
    return 0;
}