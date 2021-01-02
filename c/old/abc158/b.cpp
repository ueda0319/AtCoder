#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    unsigned long long n, a, b;
    cin >> n >> a >> b;
    unsigned long long x = n / (a+b);
    unsigned long long o = x * a + std::min(n%(a+b), a);
    cout << o << endl;
    return 0;
}