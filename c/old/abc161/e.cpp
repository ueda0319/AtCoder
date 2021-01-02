#include <iostream>
#include <string>
using namespace std;
//t: index of s
//f: already work
int min_max;
bool sift(char *s, int n, int k, int c, int t, int f){
    int i;
    bool p=false;
    for(i=t;i<n;i++){
        if(s[i]!='x'){
            if(f+1==k){
                p=true;
                min_max = min(min_max, i);
            }else if(sift(s, n, k, c, i+c+1, f+1)){
                p=true;
            }
            if(sift(s, n, k, c, i+1, f)){
                p=true;
                cout << "b: " << i << endl;
                s[i]='b';
            }
        }
    }
    return p;
}
int main(){
    int n, k, c;
    cin >> n >> k >> c;
    char s[n];
    int i;
    for(i=0;i<n;i++) cin >> s[i];
    min_max = n;
    sift(s, n, k, c, 0, 0);

    for(i=0;i<=min_max;i++){
        if(s[i]=='o')cout << i+1 << endl;
    }
    return 0;
}