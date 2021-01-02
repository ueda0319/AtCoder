#include <iostream>
int main(){
    int n;
    std::cin >> n;
    int k = n/2;
    if(n>k*2) k++;
    std::cout << k <<std::endl;
    return 0;
}