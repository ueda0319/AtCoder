#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long i, sum=0;
    for(i=1; i<=n;i++){
        if((i%3!=0)&&(i%5!=0)) sum += i;
    }
    cout << sum << endl;
    return 0;
}