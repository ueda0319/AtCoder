#include <iostream>
#include <string>
#include <vector>
void
dump(std::vector<int>& v)
{
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }
}
int main(){
    int n, q;
    std::string s;
    std::cin >> n >> s >> q;
    int type, i,j, l, r;
    char c;
    for(i=0;i<q;i++){
        std::cin >> type;
        if(type==1){
            std::cin >> l >> c;
            s[l-1] = c;
        }else{
            std::cin >> l >> r;
            int countflg[26] = {0};
            int count=0;
            for(j=l-1;j<r;j++){
                c = s[j] - 'a';
                if(countflg[c]==0){
                    countflg[c] = 1;
                    count++;
                }
                if(count>=26)break;
            }
            std::cout << count << std::endl;
        }
    }
    return 0;
}