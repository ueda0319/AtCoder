#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x[n], y[n];
    int i,j;
    int dx,dy;
    for(i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    int count=0;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            dx=abs(x[i]-x[j]);
            dy=abs(y[i]-y[j]);
            if(dy<=dx)count++;
        }
    }
    cout << count << endl;
    return 0;
}