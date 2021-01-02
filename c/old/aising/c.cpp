#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x,y,z;
    int f[n+1]={0};
    int k;
    for(x=1;x<100;x++){
        for(y=1;y<100;y++){
            for(z=1;z<100;z++){
                k=x*x+y*y+z*z+x*y+y*z+z*x;
                if(k<=n)f[k]++;
            }
        }
    }
    for(k=1;k<=n;k++){
        cout << f[k] << endl;
    }
    return 0;
}