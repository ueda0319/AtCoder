#include <iostream>
#include <string>
using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    int n;
    cin >> n;
    long long sum=0;
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            for(k=1;k<=j;k++){
                int gcd1 = gcd(i,j);
                int gcd2 = gcd(gcd1,k);
                int mt = 1;
                if((j==i)&&(k==j)){
                    mt=1;
                }else if((j==i)||(k==j)){
                    mt=3;
                }else{
                    mt=6;
                }
                sum += mt * gcd2;
            }
        }
    }
    cout << sum << endl;
    return 0;
}