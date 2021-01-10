#include <bits/stdc++.h>
using namespace std;
long long act(long long dif, long long dim){
    long long a=0;
    for(long long i=0;i<dim;i++){
        a+=(dif>>i)&1;
    }
    a+= (dif>>dim);
    return a;
}
int main(){
    long long x,y;
    cin >> x >> y;
    if(x>=y){
        cout << x-y << endl;
        return 0;
    }
    long long xd=x;
    long long dim;
    for(dim=0;dim<100;dim++){
        if(xd*2>=y)break;
        xd*=2;
    }
    long long a = act(y-xd, dim)+dim;
    long long b = act(xd*2-y, dim+1)+dim+1;

    cout << min(a,b) << endl;
    return 0;
}