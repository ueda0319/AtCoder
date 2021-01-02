#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int n,x;
    string s;
    cin >> n >> x;
    cin >> s;
    int i;
    for(i=0;i<n;i++){
        if(s[i]=='o'){
            x++;
        }else if(x>0){
            x--;
        }
    }
    cout << x << endl;
    return 0;
}