#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    n = n % 10;
    switch(n){
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
            cout << "hon" << endl;
            break;
        case 0:
        case 1:
        case 6:
        case 8:
            cout << "pon" << endl;
            break;
        case 3:
            cout << "bon" << endl;
            break;
    }
    return 0;
}