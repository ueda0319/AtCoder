#include <iostream>
int main(){
    int n, m;
    std::cin >> n >> m;
    int vals[n];
    int i;
    for(i=0;i<n;i++)vals[i] = -1;
    for(i=0; i < m;i++){
        int s, c;
        std::cin >> s >> c;
        if((vals[s-1]!=-1)&&(vals[s-1]!=c)){
            std::cout << -1 << std::endl;
            return 0;
        }
        vals[s-1] = c;
    }
    if((n>1)&&(vals[0]==0)){
        std::cout << -1 << std::endl;
        return 0;
    }
    if(vals[0]==-1){
        vals[0] = (n==1) ? 0 : 1;
    }
    std::cout << vals[0];
    for(i=1;i<n;i++){
        if(vals[i]==-1)vals[i]=0;
        std::cout << vals[i];
    }
    std::cout << std::endl;
    return 0;

}