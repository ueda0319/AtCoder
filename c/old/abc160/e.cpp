#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
using namespace std;
int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    int p[a], q[b], r[c];
    int i;
    for(i=0; i<a; i++){
        cin >> p[i];
    }
    for(i=0; i<b; i++){
        cin >> q[i];
    }
    for(i=0; i<c; i++){
        cin >> r[i];
    }
    std::sort(p, p + SIZE_OF_ARRAY(p));
    std::sort(q, q + SIZE_OF_ARRAY(q));
    std::sort(r, r + SIZE_OF_ARRAY(r));
    int z[x+y];
    memcpy(&z, &p[a-x],sizeof(int)*x);
    memcpy(&z[x], &q[b-y],sizeof(int)*y);
    std::sort(z, z + SIZE_OF_ARRAY(z));
    int r_max = r[c-1];
    int j=c-1;
    for(i=0; i<x+y; i++){
        if(z[i] < r[j]){
            z[i] = r[j];
            j--;
            if(j<0) break;
        }else{
            break;
        }
    }
    long sum = 0;
    for(i=0;i<x+y;i++){
        sum += z[i];
    }
    cout << sum << endl;
    return 0;
}