#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int x,n;
    cin >> x >> n;
    int p[102] = {0};
    int i,j;
    for(i=0;i<n;i++){
        cin >> j;
        p[j]=1;
    }
    if(p[x]==0){
        cout << x << endl;
        return 0;
    }
    for(i=1;i<100;i++){
        if(p[x-i]==0){
            cout << x-i << endl;
            return 0;
        }
        if(p[x+i]==0){
            cout << x+i << endl;
            return 0;
        }
    }
    return 0;
}