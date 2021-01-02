#include <iostream>
#include <string>
#include <math.h>
 
int main(){
    std::string s;
    unsigned long l=0;
    std::cin >> s;
    int i, k=0;
    for(i = 0; i < s.size();i++){
        int a = (int)(s[s.size()-i-1] - '0') ;
        if(i==s.size()-1)a+=k;
        
        if(a>5){
            l+=10-a;
            k=1;
        }else{
            l+=a;
            k=0;
        }
    }
    l+=k;
    std::cout << l<<std::endl;
    return 0;
}