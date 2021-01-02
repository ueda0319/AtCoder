#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int bk[n];
    int i;
    for(i=0;i<n;i++)bk[i]=0;
    for(i=1;i<n;i++){
        int a;
        cin >> a;
        bk[a-1]++;
    }
    for(i=0;i<n;i++){
        cout << bk[i] << endl;
    }
    return 0;
}