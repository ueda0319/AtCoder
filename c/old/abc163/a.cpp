#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long a[n];
    int i;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    int le = (n%2==0) ? n/2 : (n+1)/2;
    long hmax_left=0, hmax_right=0, lh, rh;
    long long happy = 0;
    int hmaxp_left=0, hmaxp_right=0, lp = 0; rp = n-1;
    for(i=0;i<le;i++){
        for(j=0;j<n;j++){
            lh = a[j] * abs(j-lp);
            rh = a[j] * abs(j - rp);
            if(lh > hmax_left){
                hmax_left = lh;
                hmaxp_left = j;
            }
            if(rh > hmax_right){
                hmax_right = rh;
                hmaxp_right = j;
            }
        }
        if(hmaxp_left == hmaxp_right){
            if(hmax_left < hmax_right){
                happy += hmax_right;
                rp--;
                a[hmaxp_right] = 0;
            }else{
                happy += hmax_left;
                lp++;
                a[hmaxp_left] = 0;
            }
        }else{
            happy += hmax_left + hmax_right;
            rp--;
            a[hmaxp_right] = 0;
            lp++;
            a[hmaxp_left] = 0;

        }
    }

    cout << happy << endl;
    return 0;
}