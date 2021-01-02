#include <iostream>
#include <string>
#include <math.h>

int main(){
    int n, m;
    std::cin >> n >> m;
    int a[n];
    int i, k, count=0;
    for(i=0;i<n;i++){
        std::cin>>a[i];
    }
    for(i = 0; i < m;i++){
        bool flg = true;
        for(k = 0; k < n;k++){
            float p = float(i) / a[k] - 0.5;
            if((p!=floor(p))||(p<0)) flg=false;
        }
        if(flg){
            std::cout << i << std::endl;
            count++;
        }
    }
    std::cout << count;
    return 0;
}