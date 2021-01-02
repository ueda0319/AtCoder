#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main(){
    int h, w, k;
    cin >> h >> w >> k;
    int c[h][w];
    int i,j, ii, jj;
    int sum=0;
    char inp;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin >> inp;
            c[i][j] = (inp=='#') ? 1 : 0;
            sum += c[i][j];
        }
    }
    int p;
    int res = 0;

    for(i=0;i<(1<<h);i++){
        for(j=0;j<(1<<w);j++){
            p=0;
            for(ii=0;ii<h;ii++){
                if((1<<ii)&i)continue;
                for(jj=0;jj<w;jj++){
                    if((1<<jj)&j)continue;
                    if(c[ii][jj]==1)p++;
                }
            }
            if(p==k){
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}