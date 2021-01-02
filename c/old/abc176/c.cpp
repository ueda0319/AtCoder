#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long i, a, b, sum=0;
    cin >> a;
    b=a;
    for(i=1;i<n;i++){
        cin >> a;
        if(a < b){
            sum += b-a;
        }else{
            b=a;
        }
    }
    cout << sum << endl;
    return 0;
}