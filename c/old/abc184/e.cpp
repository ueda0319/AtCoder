#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int h,w;
    int i,j;
    cin >> h >> w;
    char **map;
    bool **visited;
    map = (char**)malloc(sizeof(char *) * h);
    visited = (bool**)malloc(sizeof(bool *) * h);
    for (i=0;i<h;i++) {
        map[i] = (char*)malloc(sizeof(char) * w);
        visited[i] =(bool*) malloc(sizeof(bool) * w);
    }
    bool alphabet_used[28]={false};
    char c;
    int sx,sy,gx,gy;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            visited[i][j]=false;
            cin >> map[i][j];
            if(map[i][j]=='S'){
                sx=i;
                sy=j;
            }else if(map[i][j]=='G'){
                gx=i;
                gy=j;
            }
        }
    }
    int tgt_len=1;
    int *tgt_x;
    int *tgt_y;
    int *tgt_c;
    tgt_x = (int*)malloc(sizeof(int) * (h+1)*(w+1));
    tgt_y = (int*)malloc(sizeof(int) * (h+1)*(w+1));
    tgt_c = (int*)malloc(sizeof(int) * (h+1)*(w+1));

    tgt_x[0]=sx;
    tgt_y[0]=sy;
    tgt_c[0]=0;
    visited[sx][sy]=true;
    int lx,ly,lc;
    for(i=0;i<tgt_len;i++){
        
        lx=tgt_x[i];
        ly=tgt_y[i];
        lc=tgt_c[i];
        if(lx==gx&&ly==gy){
            cout << lc << endl;
            return 0;
        }
        if(map[lx][ly]>='a'&&map[lx][ly]<='z'){
            c=map[lx][ly]-'a';
            if(alphabet_used[c]){

            }else{
                int px,py;
                for(px=0;px<h;px++){
                    for(py=0;py<w;py++){
                        if(map[px][py]==map[lx][ly] && !visited[px][py]){
                            tgt_x[tgt_len] = px;
                            tgt_y[tgt_len] = py;
                            tgt_c[tgt_len]=lc+1;
                            tgt_len++;
                            visited[px][py]=true;
                        }
                    }
                }
                alphabet_used[c]=true;
            }
        }
        if(lx>0&&map[lx-1][ly]!='#'&&!visited[lx-1][ly]){
            tgt_x[tgt_len] = lx-1;
            tgt_y[tgt_len] = ly;
            tgt_c[tgt_len]=lc+1;
            tgt_len++;
            visited[tgt_x[tgt_len-1]][tgt_y[tgt_len-1]]=true;
        }
        if(lx<h-1&&map[lx+1][ly]!='#'&&!visited[lx+1][ly]){
            tgt_x[tgt_len] = lx+1;
            tgt_y[tgt_len] = ly;
            tgt_c[tgt_len]=lc+1;
            tgt_len++;
            visited[tgt_x[tgt_len-1]][tgt_y[tgt_len-1]]=true;
        }
        if(ly>0&&map[lx][ly-1]!='#'&&!visited[lx][ly-1]){
            tgt_x[tgt_len] = lx;
            tgt_y[tgt_len] = ly-1;
            tgt_c[tgt_len]=lc+1;
            tgt_len++;
            visited[tgt_x[tgt_len-1]][tgt_y[tgt_len-1]]=true;
        }
        if(ly<w-1&&map[lx][ly+1]!='#'&&!visited[lx][ly+1]){
            tgt_x[tgt_len] = lx;
            tgt_y[tgt_len] = ly+1;
            tgt_c[tgt_len]=lc+1;
            tgt_len++;
            visited[tgt_x[tgt_len-1]][tgt_y[tgt_len-1]]=true;
        }
    }
    cout << -1 << endl;
    return 0;
}