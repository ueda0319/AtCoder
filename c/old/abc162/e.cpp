#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int n;
    cin >> n >> s;
    int i,j,k;
    long sum=0;
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            if(s[j]!=s[i]){
                for(k=j+1;k<n;k++){
                    if((k-j != j-i)&&(s[k]!=s[j])&&(s[k]!=s[i])){
                        sum++;
                    }
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}