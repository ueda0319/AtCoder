#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int l, r, d;
    cin >> l >> r >> d;
    int lc = (l-1)/d;
    int rc = r/d;
    cout << rc-lc << endl;
    return 0;
}