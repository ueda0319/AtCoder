#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int sa1=a/100;
    int sa2=(a%100)/10;
    int sa3=a%10;
    int sb1=b/100;
    int sb2=(b%100)/10;
    int sb3=b%10;
    int sa=sa1+sa2+sa3;
    int sb=sb1+sb2+sb3;
    if(sa>=sb){
        cout << sa << endl;
    }else{
        cout << sb << endl;
    }
    return 0;
}