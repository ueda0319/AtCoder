#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int e = min(min(a,b), min(c,d));
    cout << e << endl;
    return 0;
}