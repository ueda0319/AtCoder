#include <iostream>
#include <string>
#include <math.h>

int main(){
    unsigned long n, l=0;
    std::cin >> n;
    while(n>0){
        int a = n % 10;
        n=(n-a)/10;

        if(a>5){
            l+=10-a;
            n++;
        }else{
            l+=a;
        }
    }
    std::cout << l;
    return 0;
}