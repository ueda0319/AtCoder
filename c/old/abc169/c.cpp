#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    unsigned long long a;
    //double b;
    string b;
    cin >> a >> b;
    char b1=b[0]-'0';
    char b2=b[2]-'0';
    char b3=b[3]-'0';
    //int b2=(int)round(b*10)%10;
    //int b3=(int)round(b*100)%10;
    unsigned long long a2 = a/10;
    unsigned long long a3 = a/100;
    unsigned long long c=a*b1 +a2*b2 + a3*b3;
    cout << c << endl;
    return 0;
}