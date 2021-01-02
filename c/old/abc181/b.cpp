#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n;
    long long s=0;
    cin >> n;
    long long a,b;
    int i;
    for(i=0;i<n;i++){
        cin >> a >> b;
        s += (a+b)*(b-a+1)/2;
    }
    cout << s << endl;
    return 0;
}