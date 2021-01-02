#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    std::map<std::string,int> ss;
    int n;
    cin >> n;
    string s, k;
    int i,p;
    for(i=0;i<n;i++){
        cin >> s;
        if(s[0]=='!'){
            k=s.substr(1);
            p=1;
        }else{
            k=s;
            p=-1;
        }
        switch(ss[k]){
            case 0:
                ss[k]=p;
                break;
            case 1:
                if(p==-1)ss[k]=2;
                break;
            case -1:
                if(p==1)ss[k]=2;
                break;
        }
    }
    for (const auto& [key, value] : ss){
        if(value==2){
            cout << key << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}