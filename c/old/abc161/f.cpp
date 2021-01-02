#include <iostream>
#include <string>
using namespace std;
int main(){
    long n;
    cin >> n;
    long i;
    int t=0;
    cout << t << endl;
    for(i=2;i<n;i++){
        long x=n;
        while(true){
            if(x%i==0){
                x=x/i;
            }else{
                x=x-i;
            }
            if(x==1){
                cout << i << endl;
                t++;
                break;
            }
            if(x<i)break;
        }
    }
    cout << t << endl;
    return 0;
}