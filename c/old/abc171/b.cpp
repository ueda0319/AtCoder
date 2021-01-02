#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int p[n];
    int i;
    for(i=0;i<n;i++){
        cin >> p[i];
    }
    sort(p,p+n);
    int c=0;
    for(i=0;i<k;i++){
        c+=p[i];
    }
    cout << c << endl;
    return 0;
}