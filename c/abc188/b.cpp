#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int *as;
    as=(int*)malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++){
        cin >> as[i];
    }
    int b;
    long long dot=0;
    for(i=0;i<n;i++){
        cin >> b;
        dot += as[i]*b;
    }
    if(dot==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}