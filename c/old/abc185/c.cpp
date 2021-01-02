#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
long long bikkus[201];
long long bikku(int a){
    int i;
    int out=1;
    for(i=1;i<=a;i++)out*=i;
    bikkus[a]=(long long)out;
    return out;
}
bool check(int a[12], int p, int l, long long &count){
    int i;
    int a_l = (p>0) ? a[p]-a[p-1] : a[p];
    if(p==10){
        if(l-a[p]>=a_l){
            a[11]=l;
            int t=1, c=bikku(12);
            for(i=1;i<12;i++){
                if(i==1&&a[1]-a[0]==a[0]){
                    t++;
                }else if(a[i]-a[i-1]==a[i-1]-a[i-2]){
                    t++;
                }else{
                    c/=bikku(t);
                    t=1;
                }
            }
            c/=bikku(t);
            count+=c;
            return true;
        }
    }
    if(l-a[p]<a_l) return false;
    for(i=a_l;i<l;i++){
        a[p+1]=a[p]+i;
        if(a[p]+a_l*(12-p-1)>l) break;
        if(!check(a, p+1, l, count))break;
    }
    return true;
}
int main(){
    int l;
    cin >> l;
    long long count=0;
    int a[12];
    int i;
    bikkus[0]=1;
    bikkus[1]=1;
    for(i=2;i<=200;i++){
        bikkus[i]=i*bikkus[i-1];
    }
    count = bikkus[l] / bikkus[l-12]/bikkus[12];
    cout << count << endl;
    return 0;
}