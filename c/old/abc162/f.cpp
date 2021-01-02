#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    long a[n];
    int i;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    int n2 = n/2;
    long long left[n2], right[n2];
    left[0]=0;
    right[0]=0;
    for(i=0;i<n2-1;i++){
        left[i+1]=left[i] + a[i*2];
        right[i+1] = right[i]*a[n-1 - i*2];
    }
    long long m = 0;
    for(i=0;i<n2;i++){
        long long p = left[i]+right[n2-1-i];
        if(m<p) m=p;
    }
    cout << m << endl;
    return 0;
}