#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
int main(){
    int n, k;
    std::cin >> n >> k;
    int x[n], y[n], c[n];
    int x_min, x_max, y_min, y_max;
    int xn, yn, cn, i, p, q;
    std::cin >> xn>> yn>> cn;
    x_min = xn;
    x_max = xn;
    y_min = yn;
    y_max = yn;
    x[0] = xn;
    y[0] = yn;
    c[0] = cn;
    std::cout << "pos[0]: " << xn << ", " << yn << std::endl; 
    for(i=1;i<n;i++){
        std::cin >> xn >> yn >> cn;
        x_min = std::min(x_min, xn);
        x_max = std::max(x_max, xn);
        y_min = std::min(y_min, yn);
        y_max = std::max(y_max, yn);
        x[i] = xn;
        y[i] = yn;
        c[i] = cn;
        std::cout << "pos[" << i << "]: " << xn << ", " << yn << std::endl; 
    }
    float max_cost = 10000000;
    std::cout << x_min << ", " << x_max << ", " << y_min << ", " << y_max << std::endl;
    for(p=x_min;p<=x_max; p++){
        for(q=y_min;q<=y_max;q++){
            std::cout << "pos: " << p << ", " << q << std::endl;
            int cost_over=0;
            std::vector<float> costs;
            for(i=0;i<n;i++){
                float cost = c[i]*sqrt((x[i]-p)*(x[i]-p) + (y[i]-q)*(y[i]-q));
                std::cout << "target pos: " << x[i] << ", " << y[i] << ", " << c[i] << " : " << cost << std::endl;
                if(cost < max_cost){
                    costs.push_back(cost);
                }else{
                    cost_over++;
                    if(cost_over > n - k)break;
                }
            }
            if(costs.size() > k){
                std::sort(costs.begin(), costs.end());
                max_cost = costs[k];
                std::cout << "min: (" << p << ", " << q << "), cost:" << max_cost << std::endl; 
            }
        }
    }
    std::cout << max_cost << std::endl;
    return 0;
}