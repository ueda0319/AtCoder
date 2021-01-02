#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    int i, j, k;
    for(i=1;i<=1100;i++){
        j = std::floor(i * 0.08);
        k = std::floor(i * 0.1);
        if((a==j)&&(b==k)){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}