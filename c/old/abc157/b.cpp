#include <iostream>
int main(){
    int a[9], match[9];
    int i, j, n;
    for(i=0;i<9;i++){
        std::cin >> a[i];
        match[i]=0;
    }
    std::cin >> n;
    int b;
    for(i=0;i<n;i++){
        std::cin >> b;
        for(j=0;j<9;j++){
            if(a[j]==b){
                match[j]=1;
                break;
            }
        }
    }
    int bingo[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6},
    };
    for(i=0;i<8;i++){
        int m = 0;
        for(j=0;j<3;j++)m+=match[bingo[i][j]];
        if(m==3){
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    
    std::cout << "No" << std::endl;
    return 0;


}