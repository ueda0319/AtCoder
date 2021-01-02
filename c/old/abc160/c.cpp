#include <iostream>
#include <string>
using namespace std;
int main(){
    int k, n;
    cin >> k >> n;
    int a[n];
    int i;
    int dst_max = 0;
    for(i=0;i<n;i++){
        cin >> a[i];
        if(i>=1){
            if(a[i]-a[i-1] > dst_max) dst_max = a[i]-a[i-1];
        }
    }
    if(a[0] + k - a[n-1] > dst_max) dst_max = a[0] + k - a[n-1];
    int res = k - dst_max;
    cout << res << endl;
    return 0;
}