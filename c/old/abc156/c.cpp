#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    int n;
    std::cin >> n;
    std::vector<int> x;
    int i;
    for(i = 0; i < n; i++){
        int p;
        std::cin >> p;
        x.push_back(p);
    }
    std::sort(x.begin(), x.end());
    int cost = 0;
    for(i = 0; i < n-1; i++){
        cost += (x[i+1] - x[i])*(x[i+1] - x[i]);
    }
    std::cout << cost << std::endl;
    return 0;

}