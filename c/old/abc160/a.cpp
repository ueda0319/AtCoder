#include <iostream>
#include <string>
using namespace std;
int main(){
    std::string s;
    cin >> s;
    if((s[2]==s[3])&&(s[4]==s[5])){
        cout << "Yes" <<endl;
    }else{
        cout << "No" <<endl;
    }
    return 0;
}