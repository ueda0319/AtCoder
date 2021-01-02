#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n,0);
    int w[m];
    int i, j;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    cout <<"a" << endl;
    vector<int> c(n+1,0);
    int b;
    long long l_min=-1, l;
    for(j=0;j<m;j++){
    cout <<"b" << endl;
        cin >> b;
        copy(a.begin(), a.end(), c.begin());
        c[n] = b;
        std::sort(c.begin(), c.end() );
        l=0;
        for(i=0;i<n+1;i+=2){
            l+=abs(c[i]-c[i+1]);
        }
        if(l_min==-1 || l_min > l){
            l_min=l;
        }

    }
    cout << l_min << endl;
    return 0;
}