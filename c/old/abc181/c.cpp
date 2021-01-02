#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x[n], y[n];
    int i, j, k;
    int t1,t2;
    for(i=0;i<n;i++){
        cin >> x[i] >> y[i];
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            for(k=j+1;k<n;k++){
                t1 = (x[j]-x[i])*(y[k]-y[i]);
                t2 = (x[k]-x[i])*(y[j]-y[i]);
                if(t1==t2){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}