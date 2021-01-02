#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int l = s.length();
    bool diva = false;
    if(l==1){
        if(s[0]=='8')diva=true;
    }else if(l==2){
        int ts[2];
        ts[0] = (s[0]-'0')*10 + (s[1]-'0');
        ts[1] = (s[1]-'0')*10 + (s[0]-'0');
        int i;
        for(i=0;i<2;i++){
            if(ts[i]%8==0)diva=true;
        }
    }else if(l==3){
        int ts[6];
        ts[0] = (s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0');
        ts[1] = (s[0]-'0')*100 + (s[2]-'0')*10 + (s[1]-'0');
        ts[2] = (s[1]-'0')*100 + (s[0]-'0')*10 + (s[2]-'0');
        ts[3] = (s[1]-'0')*100 + (s[2]-'0')*10 + (s[0]-'0');
        ts[4] = (s[2]-'0')*100 + (s[0]-'0')*10 + (s[1]-'0');
        ts[5] = (s[2]-'0')*100 + (s[1]-'0')*10 + (s[0]-'0');
        int i;
        for(i=0;i<6;i++){
            if(ts[i]%8==0)diva=true;
        }
    }else{
        int eights[112][10];
        int i,j;
        for(i=0;i<112;i++){
            for(j=0;j<10;j++){
                eights[i][j]=0;
            }
        }
        int t1,t2,t3;
        for(i=0;i<112;i++){
            j=(i+13)*8;
            t1= j/100;
            t2=(j%100)/10;
            t3=j%10;
            eights[i][t1]++;
            eights[i][t2]++;
            eights[i][t3]++;
        }
        int counts[10]={0};
        for(i=0;i<l;i++){
            counts[s[i]-'0']++;
        }
        bool flg;
        for(i=0;i<112;i++){
            flg=true;
            for(j=0;j<10;j++){
                if(counts[j]<eights[i][j]){
                    flg=false;
                    continue;
                }
            }
            if(flg){
                diva=true;
                break;
            }
        }

    }
    if(diva){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}