#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    int i, sum;
    sum = 0;
    for(i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    int p=0;
    int th = sum/4/m;
    if(th*4*m>=sum)th--;
    //float th=sum/4.0/m;
    for(i=0;i<n;i++){
        if(th < a[i]) p++;
    }
    if(p>=m){
        cout << "Yes" <<endl;
    }else{
        cout << "No" <<endl;
    }
    return 0;
}