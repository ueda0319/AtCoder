#include <bits/stdc++.h>
using namespace std;
std::map<long long,long long> s;
long long solve(long long x, long long y){
    if(s[y]>0) return s[y];
    if(y==1){
        s[y]=abs(x-y);
    }else if(y%2==1){
        s[y]=min(abs(x-y), min(solve(x,(y+1)/2)+2, solve(x, (y-1)/2)+2));
    }else{
        s[y]=min(abs(x-y), solve(x,y/2)+1);
    }
    return s[y];
}
long long act(long long dif, long long dim){
    long long a=0;
    for(long long i=0;i<dim;i++){
        a+=(dif>>i)&1;
    }
    a+= (dif>>dim);
    return a;
}
int solve_bin(long long x, long long y){
    if(x>=y){
        return x-y;
    }
    long long xd=x;
    long long dim;
    for(dim=0;dim<100;dim++){
        if(xd*2>=y)break;
        xd*=2;
    }
    long long a = act(y-xd, dim)+dim;
    long long b = act(xd*2-y, dim+1)+dim+1;
    return min(a,b);
}

int main(){
    long long x,y;
    cin >> x >> y;
    cout << solve(x,y) << endl;
    return 0;
}