#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int x[5];
    int i,j=0;
    for(i=0;i<5;i++){
        cin >> x[i];
        if(x[i]==0)j=i+1;
    }
    
    cout << j << endl;
    return 0;
}