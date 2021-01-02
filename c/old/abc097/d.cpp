#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int root(int *uf, int k){
    if(uf[k]==k){
        return k;
    }else{
        uf[k]=root(uf, uf[k]);
        return uf[k];
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    int p[n];
    int uf[n];
    int i;
    for(i=0; i<n;i++){
        cin >> p[i];
        uf[i]=i;
    }
    for(i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        int rx=root(uf,x-1);
        int ry=root(uf,y-1);
        if(rx!=ry){
            uf[rx]=ry;
        }
    }
    int count=0;
    for(i=0;i<n;i++){
        if(root(uf, i) == root(uf, p[i]-1))count++;
    }
    cout << count << endl;
    return 0;
}