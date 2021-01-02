#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    long bitw[33] = {0};
    int n;
    cin >> n;
    long a[n];
    long i,j;
    for(i=0;i<n;i++){
        cin >> a[i];
        for(j=0;j<33;j++){
            if (a[i] & (1ull <<j))bitw[j]++;
        }
    }
    long bi = 0;
    for(i=0;i<33;i++){
        if(bitw[i]%2==1) bi += (1ull <<i);
    }
    for(i=0;i<n;i++){
        j = a[i] ^ bi;
        cout << j << " ";
    }
    cout << endl;
    return 0;
}