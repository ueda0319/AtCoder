#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
using namespace std;
int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    int p[a], q[b], r[c];
    int i;
    for(i=0; i<a; i++){
        cout >> p[i];
    }
    for(i=0; i<b; i++){
        cout >> q[i];
    }
    for(i=0; i<c; i++){
        cout >> r[i];
    }
    std::sort(p, p + SIZE_OF_ARRAY(p));
    std::sort(q, q + SIZE_OF_ARRAY(q));
    std::sort(r, r + SIZE_OF_ARRAY(r));
    int z[x+y];
    memcpy(&z, &p[a-x-1],sizeof(int)*x);
    memcpy(&z[x], &q[b-y-1],sizeof(int)*y);
    std::sort(z, z + SIZE_OF_ARRAY(z));
    int r_max = r[c-1];
    int j=0;
    for(i=0; i<x+y; i++){
        if(i>=c-1) break;
        if(z[i] > r_max)break;
        for(; j<c; j++){
            if(z[i] < r[j]){
                z[i] = r[j];
                j++;
                break;
            }
        }
    }
    long sum = 0;
    for(i=0;i<x+y;i++){
        sum += z[i];
    }
    cout << sum << endl;
    return 0;
}