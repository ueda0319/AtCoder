#include <iostream>
#include <string>
#include <math.h>
using namespace std;
bool is_prime(const unsigned long long n,unsigned long long nmin){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された

    if(n % 2 == 0 || n % 3 == 0) return false;
    // n は 2 と 3 のいずれの倍数でもないことが保証された
    // これより n は (6の倍数)-1 か (6の倍数)+1 である
    int start=(nmin-5)/6;
    start=5+start*6;
    // 6の倍数前後の数を使って試し割りをする
    for(unsigned long long  i = start; i * i <= n; i += 6) {
        if(n % i     == 0) return false; // (6の倍数)-1
        if(n % (i+2) == 0) return false; // (6の倍数)+1
    }

    return true;
}
int main(){
    long long n;
    cin >> n;
    long long  i,j, k;
    long long  count=0;
    int step=1;
    if(is_prime(n,5)&&n>1){
        count++;
    }else{
    for(i=2;i<=n;i+=step){
        j=0;
        k=0;
        while(n%i==0){
            n/=i;
            j++;
            if(j>k){
                j=0;
                k++;
                count++;
            }
        }
        if(j>0){
            
        if(is_prime(n,i-1)&&n>1){
            count++;
            break;
        }
        }
        if(i==5)step=2;
        if(i>5){
            if(step==2){
                step=4;
            }else{
                step=2;
            }
        }
    }
    }
    cout << count << endl;
    return 0;
}