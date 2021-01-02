#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int i,j;
    int c = 0;
    for(i=0;i<n;i++){
        cin >> j;
        if(i%2== 0 && j%2==1)c++;
    }
    cout << c << endl;
    return 0;
}