#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n,0);
    int w[m];
    int i, j;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    std::sort(a.begin(), a.end() );
    int b;
    int bplace=0;
    long long l_min=-1, l;
    for(j=0;j<m;j++){
        cin >> b;
        if(b>a[n-1]){
            bplace=n;
        }else{
            for(bplace=0;bplace<n;bplace++){
                if(b<a[bplace]) break;
            }
        }
        if(bplace%2==0){
            for(i=0;i<bplace;i+=2){
                l+=abs(a[i]-a[i+1]);
            }
            l+=abs(a[bplace]-b);
            for(i=bplace+1;i<n-1;i+=2){
                l+=abs(a[i]-a[i-1]);
            }
        }else{
            for(i=0;i<bplace;i+=2){
                l+=abs(a[i]-a[i+1]);
            }
            l+=abs(a[bplace-1]-b);
            for(i=bplace+1;i<n-1;i+=2){
                l+=abs(a[i]-a[i+1]);
            }
        }
        if(l_min==-1 || l_min > l){
            l_min=l;
        }

    }
    cout << l_min << endl;
    return 0;
}