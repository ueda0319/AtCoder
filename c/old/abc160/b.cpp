#include <iostream>
#include <string>
using namespace std;
int main(){
    long x;
    long src = 0;
    cin >> x;
    src += (int)(x / 500) * 1000;
    x = x % 500;
    src += (int)(x / 5) * 5;
    cout << src << endl;
    return 0;
}