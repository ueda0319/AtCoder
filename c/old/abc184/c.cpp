#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    long long r1,c1,r2,c2;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    if(r1==r2 && c1==c2){
        cout << 0 << endl;
        return 0;
    }
    if((r1+c1==r2+c2)||(r1-c1==r2-c2)||(abs(r1-r2)+abs(c1-c2)<=3)){
        cout << 1 << endl;
        return 0;
    }
    if(((abs(r1-r2)+abs(c1-c2))%2==0)||(abs(r1-r2)+abs(c1-c2)<=6)||(abs(abs(r1-r2)-abs(c1-c2))<=3)){
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
    return 0;
}