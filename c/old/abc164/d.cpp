#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Tree{
public:
    string word;
};
int main(){
    string s;
    cin >> s;
    int l = s.length(), i, j;
    int count = 0;
    int mt[l+4] = {0};
    for(i=0;i<l-3;i++){
        int mod = (s[i]-'0')*1000+(s[i+1]-'0') * 100 + (s[i+2]-'0') * 10 + (s[i+3]-'0');
        mod = mod % 2019;
        if(mod == 0){
            count+=mt[i]+1;
            mt[i+4] += mt[i]+1;
        }else{
            for(j=i+4;j<l;j++){
                mod = mod*10+(s[j]-'0');
                mod = mod % 2019;
                if(mod == 0){
                    count+=mt[i]+1;
                    if(j<l-1) mt[j+1] += mt[i]+1;
                    break;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}