#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int n;
    cin >> n >> s;
    int i,j,k;
    long sum=0;
    int r_n[n], g_n[n], b_n[n];
    r_n[n-1] = 0;
    g_n[n-1] = 0;
    b_n[n-1] = 0;
    if(s[n-1]=='R')r_n[n-1]++;
    if(s[n-1]=='G')g_n[n-1]++;
    if(s[n-1]=='B')b_n[n-1]++; 
    for(i=1;i<n;i++){
        r_n[n-1-i] = r_n[n-i];
        g_n[n-1-i] = g_n[n-i];
        b_n[n-1-i] = b_n[n-i];
        if(s[n-1-i]=='R')r_n[n-1-i]++;
        if(s[n-1-i]=='G')g_n[n-1-i]++;
        if(s[n-1-i]=='B')b_n[n-1-i]++; 
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            if(s[j]!=s[i]){
                if(abs(s[i]-s[j])==11){
                    //RG
                    sum+=b_n[j+1];
                    if(j+(j-i) < n){
                        if(s[j+j-i]=='B')sum--;
                    }
                }
                if(abs(s[i]-s[j])==5){
                    //GB
                    sum+=r_n[j+1];
                    if(j+(j-i) < n){
                        if(s[j+j-i]=='R')sum--;
                    }
                }
                if(abs(s[i]-s[j])==16){
                    //RG
                    sum+=g_n[j+1];
                    if(j+(j-i) < n){
                        if(s[j+j-i]=='G')sum--;
                    }
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}