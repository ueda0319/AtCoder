#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int *c = (int *)malloc(sizeof(int)*(n+1));
    c[1]=1;
    long long i, j;
    long long sum=1;
    for(i=2;i<=n;i++){
        j=i;
        while(j<=n){
            c[j]++;
            j+=i;
        }
        sum+=i*(c[i]+1);
    }
    cout << sum << endl;
    return 0;
}