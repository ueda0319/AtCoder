#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int bef[n],aft[n];
    int i,j;
    for(i=0;i<n;i++){
        cin >> a[i];
        if(i>0)bef[i]=i-1;
        aft[i]=i+1;
    }
    std::sort(a, a + SIZE_OF_ARRAY(a));
    int count=0;
    bool flg=false;
    for(i=0;i<n;i=aft[i]){
        flg=false;
        for(j=i+1;j<n;j=aft[j]){
            if(a[i]%a[j]==0){
                flg=true;
            }
            if(a[j]%a[i]==0){
                aft[bef[j]]=aft[j];
                bef[aft[j]]=bef[j];
            }
        }
        if(!flg)count++;
    }
    cout << count << endl;
    return 0;
}