#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long l[n];
    int i, j, k;
    int count=0;
    for(i=0;i<n;i++){
        cin >> l[i];
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            for(k=j+1;k<n;k++){
                if((l[i]!=l[j])&&(l[i]!=l[k])&&(l[k]!=l[j])&&(l[i]+l[j]>l[k])&&(l[i]+l[k]>l[j])&&(l[k]+l[j]>l[i])){
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}