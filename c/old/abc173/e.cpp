#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    long long a[n], b[n], c[n];
    int al=0, bl=0;
    int i,j;
    for(i=0;i<n;i++){
        cin >> j;
        if(j<0){
            b[bl]=-j;
            c[i]=-j;
            bl++;
        }else{
            a[al]=j;
            c[i]=j;
            al++;
        }
    }
    std::sort(a, a + al);
    std::sort(b, b + bl);
    long long sum=1;
    if((k==n)&&(bl%2==1)){
        for(i=0;i<al;i++){
            sum = (sum*a[i])%1000000007;
        }
        for(i=0;i<bl;i++){
            sum = (sum*b[i])%1000000007;
        }
        sum = (1000000007-sum)%1000000007;
    }else if((al==0)&&(k%2==1)){
        for(i=0;i<k;i++){
            sum = (sum*b[i])%1000000007;
        }
        sum = (1000000007-sum)%1000000007;
    }else{
        int pc = 0;
        if(k>bl){
            while(k>bl){
                sum = (sum*a[al-1])%1000000007;
                al--;
                k--;
            }
        }
        if(k%2==1){
            sum = (sum*a[al-1])%1000000007;
            al--;
            k--;
        }
        for(i=0;i<k;i++){
            if(al-pc*2-2<0)break;
            if(bl-k+pc*2+1>=bl)break;
            if(a[al-pc*2-1]*a[al-pc*2-2] < b[bl-k+pc*2]*b[bl-k+pc*2+1]){
                break;
            }
            pc++;
        }
        for(i=al-pc*2;i<al;i++){
            sum = (sum*a[i])%1000000007;
        }
        for(i=bl-k+pc*2;i<bl;i++){
            sum = (sum*b[i])%1000000007;
        }

    }
    cout << sum << endl;
    return 0;
}