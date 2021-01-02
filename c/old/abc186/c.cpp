#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int i,j,p=0;
    bool flg;
    for(i=1;i<=n;i++){
        flg=false;
        int q=i;
        
        for(j=0;j<20;j++){
            if(q==0)break;
            if(q%8==7){
                flg=true;
                break;
            }
            q=q/8;
        }
        if(!flg){
            q=i;
        
            for(j=0;j<10;j++){
                if(q==0)break;
                if(q%10==7){
                    flg=true;
                    break;
                }
                q=q/10;
            }
        }
        if(!flg) p++;
    }
    cout << p << endl;
    return 0;
}