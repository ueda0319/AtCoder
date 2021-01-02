#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    long a, b, n;
    cin >> a >> b >> n;
    /*
    long x=1;
    long score_max=0;
    while(1){
        long score = (long)(a*x/b)-a*(long)(x/b);
        cout << score << endl;
        if(score_max < score) score_max=score;
        x++;
        if(x>b)break;
    }*/
    long x = min(n, b-1);
    long score = (long)(a*x/b);
    cout << score << endl;
    return 0;
}