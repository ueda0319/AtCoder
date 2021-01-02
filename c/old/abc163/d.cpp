#include <iostream>
#include <string>
using namespace std;
long long sumbet(long long a, long long b){
    long long c = b-a+1;
    if(c%2==0){
        return (b+a)*c/2;
    }else{
        return (b+a)*(c-1)/2 + (a+(c-1)/2);
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    long long count=0;
    long long a, b;
    for(a=k;a<=n+1;a++){
        count += sumbet(n-a+1, n) - sumbet(0, a-1)+1;
        if(count > 1000000007) count = count %1000000007;
    }
    cout << count << endl;
    return 0;
}