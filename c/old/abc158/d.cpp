#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string s, c;
    int q, t, f;
    int i;
    bool rev = false;
    cin >> s >> q;
    //StringBuilder sb = new StringBuilder();
    //sb.append(s);
    s.reserve(q);
    for(i=0;i<q;i++){
        cin >> t;
        if(t==1){
            rev = !rev;
            //reverse(s.begin(), s.end());
        }else{
            cin >> f >> c;
            if((f==1)!= rev){
                s.insert(0, c);
            }else{
                s.append(c);
            }
        }
    }
    if(rev) reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}