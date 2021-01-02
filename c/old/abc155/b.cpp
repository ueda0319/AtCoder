#include <iostream>
#include <string>
#include <math.h>
#include    <algorithm>
#include    <vector>
int main(){
    int n, m;
    std::cin >> n;
    std::string s[n];
    std::string cu;
    int len = 0, count_max=1;
    int count[n];
    int i, j;
    for(i=0;i<n;i++){
        std::cin>>cu;
        bool flg = true;
        for(j = 0; j < len;j++){
            if(s[j]==cu){
                count[j]++;
                count_max = (count_max < count[j]) ? count[j] : count_max;
                flg=false;
                break;
            }
        }
        if(flg){
            s[len]=cu;
            count[len]=1;
            len++;
        }
    }
    std::vector<std::string> data;
    for(i=0;i<len;i++){
        if(count[i]==count_max) data.push_back(s[i]);
    }
    sort(data.begin(), data.end());
    for(i=0; i<data.size();i++){
        std::cout << data[i] << std::endl;
    }
    return 0;
}