#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w,ch,cw,dh,dw;
    cin >> h >> w >> ch >> cw >> dh >> dw;
    int i,j;
    char **map;
    map = (char**)malloc(sizeof(char *) * h);
    for (i=0;i<h;i++) {
        map[i] = (char*)malloc(sizeof(char) * w);
    }
    string s;
    for(i=0;i<h;i++){
        cin >> s;
        for(j=0;j<w;j++){
            map[i][j]= (s[j]=='.') ? 1 : 0;
        }
    }
    short *lut;
    lut = (short*)malloc(sizeof(short) * h * w);
    short **labels;    
    labels = (short**)malloc(sizeof(short *) * h);
    for (i=0;i<h;i++) {
        labels[i] = (short*) malloc(sizeof(short) * w);
    }
    labels[0][0]=0;
    lut[0]=0;
    int labelCount=1;
    for(j=1;j<w;j++){
        if(map[0][j]==0){
            labels[0][j]=-1;
        }else if(labels[0][j-1]==-1){
            labels[0][j]=labelCount;
            lut[labelCount]=labelCount;
            labelCount++;
        }else{
            labels[0][j]=labels[0][j-1];
        }
    }
    for(i=1;i<h;i++){
        if(map[i][0]==0){
            labels[i][0]=-1;
        }else if(labels[i-1][0]==-1){
            labels[i][0]=labelCount;
            lut[labelCount]=labelCount;
            labelCount++;
        }else{
            labels[i][0]=labels[i-1][0];
        }
        for(j=1;j<w;j++){
            if(map[i][j]==0){
                labels[i][j]=-1;
            }else if((labels[i][j-1]==-1)&&(labels[i-1][j]==-1)){
                labels[i][j]=labelCount;
                lut[labelCount]=labelCount;
                labelCount++;
            }else if((labels[i][j-1]!=-1)&&(labels[i][j-1]<labels[i-1][j])){
                lut[labels[i-1][j]]=lut[labels[i][j-1]];
                labels[i][j]=labels[i][j-1];
            }else if((labels[i-1][j]!=-1)&&(labels[i][j-1]>labels[i-1][j])){
                lut[labels[i][j-1]]=lut[labels[i-1][j]];
                labels[i][j]=labels[i][j-1];
            }else{
                labels[i][j]=(labels[i][j-1]!=-1) ? labels[i][j-1] : labels[i-1][j];
            }
        }
    }
    /*
    int gtl = 0;
    for(i=0;i<labelCount;i++){
        if(lut[i]!=i){
            lut[i] = lut[lut[i]];
        }else{
            gtl++;
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(labels[i][j]>=0) labels[i][j]=lut[labels[i][j]];
        }
    }
    char **co;
    co = (char**)malloc(sizeof(char *) * gtl);
    for (i=0;i<gtl;i++) {
        co[i] = (char*)malloc(sizeof(char) * gtl);
    }
    for(i=0;i<gtl;i++){
        for(j=0;j<gtl;j++){
            co[i][j]=(i==j) ? 1 : 0;
        }
    }
    int ii,jj;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(map[i][j]!=0){
                for(ii=i;ii<=i+2;ii++){
                    for(jj=j-2;jj<=j+2;jj++){
                        if(ii<0) continue;
                        if(jj<0) continue;
                        if(ii>=h) continue;
                        if(jj>=w) continue;
                        if(labels[ii][jj]!=-1){
                            co[labels[ii][jj]][labels[i][j]]=1;
                            co[labels[i][j]][labels[ii][jj]]=1;
                        }
                    }
                }
            }
        }
    }

    int c_label = labels[ch-1][cw-1];
    int d_label = labels[dh-1][dw-1];
    if(c_label==d_label){
        cout << 0 << endl;
    }else{
        int found[gtl]={0};
        int queue[gtl];
        queue[0]=c_label;
        found[c_label]=1;
        int ql = 1;
        for(i=0;i<ql;i++){
            for(j=0;j<gtl;j++){
                if(queue[i]==j)continue;
                if(found[j]>0)continue;
                if(co[queue[i]][j]==1){
                    if(j==d_label){
                        cout << found[queue[i]] << endl;
                        return 0;
                    }
                    queue[ql] = j;
                    found[j]=found[queue[i]]+1;
                    ql++;
                }
            }
        }
        cout << -1 << endl;
    }*/
    return 0;
}