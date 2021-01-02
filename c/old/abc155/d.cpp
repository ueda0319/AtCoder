#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
void
dump(std::vector<int>& v)
{
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }
}
int main(){
    int n, k;
    std::cin >> n >> k;
    int a[n];
    int i, j, id;
    for(i=0;i<n;i++){
        std::cin>>a[i];
    }
    int pair[(n*(n-1))/2];
    std::vector<int> v;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            v.push_back (a[i]*a[j]);

        }
    }
    std::sort(v.begin(), v.end());
    std::cout << v[k] << std::endl;
    return 0;
}