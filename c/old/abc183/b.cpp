#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    double sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    double p = (sy*gx+sx*gy)/(gy+sy);
    cout<<fixed << setprecision(15) << p << endl;
    return 0;
}