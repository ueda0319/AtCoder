#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int p[n]={0};
    int count = n;
    int i,j, d, a;
    for(i=0;i<k;i++){
        cin >> d;
        for(j=0;j<d;j++){
            cin >> a;
            if(p[a-1]==0){
                p[a-1]=1;
                count--;
            }
        }
    }cout << count << endl;
    return 0;
}