#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    double s,p;
    cin >> s >> p;
    double n1=(s+sqrt(s*s-4*p))/2;
    double n2=(s-sqrt(s*s-4*p))/2;
    long long n1l = (long long)floor(n1);
    long long n2l = (long long)floor(n2);
    if((n1==n1l)&&(n1l>0)&&(s-n1l>0)){
        cout << "Yes" << endl;
    }else if((n2==n2l)&&(n2l>0)&&(s-n2l>0)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}