#include <iostream>
#include <string>
using namespace std;
int main(){
    long long k;
    cin >> k;
    long long i=1;
    long long x, t=0;
    long long f;
    bool flg=true;
    bool runrun;
    while(flg){
        //cout << i << endl;
        x=i;
        runrun=true;
        f=1;
        while(x>10){
            long long p=x%10;
            x/=10;
            long long q=x%10;
            if((p-q<=1)&&(q-p<=1)){

            }else{
                runrun=false;
                if(p<q){
                    i=x*f*10 + (q-1)*f - 1;
                    //i+=(q-p-1)*f-1;
                }else{
                    i=(x+1)*f*10 - 1;
                    //i+=(10-p)*f-1;
                }
                break;
            }
            f*=10;
        }
        if(runrun)t++;
        if(t==k){
            cout << i << endl;
            return 0;
        }
        i++;
    }
    return 0;
}