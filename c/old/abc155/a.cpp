#include <iostream>
#include <string>
#include <math.h>

int main(){
    int l, n, m;
    std::cin >> l >> n >> m;
    if(((l==n)&&(l!=m))||((l==m)&&(l!=n))||((m==n)&&(l!=m))){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    return 0;
}