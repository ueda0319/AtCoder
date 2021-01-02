#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    long a = 0;
    for(int i = 0; i < m; i++){
        long ai;
        cin >> ai;
        a += ai;
    }
    if(n<a){
        cout << -1 << endl;
    }else{
        cout << n-a << endl;
    }
    return 0;
}