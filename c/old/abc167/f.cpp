#include <iostream>
#include <string>
#include <math.h>
#include<algorithm>
using namespace std;
struct visitedList{
    int id;
    // 右の空席への参照
    visitedList *before, *after;
    visitedList(int nid){
        id=nid;
        before = NULL;
        after = NULL;
    }
};
int dfs(int N, int c, visitedList *visited, int *kmin, int *ksum, int nsum) {
    if(visited==NULL)return 0;
    visitedList *current;
    int i;
    for(current=visited; current != NULL; current = current->after){
        if(current->before!=NULL)current->before->after=current->after;
        if(current->after!=NULL)current->after->before = current->before;
        i=current->id;
        if(nsum + kmin[i]<0){
            //iのフラグを取り消す
            if(current->before!=NULL)current->before->after=current;
            if(current->after!=NULL)current->after->before = current;
            continue;
        }
        if((c+1==N)&&(nsum+ksum[i]==0)) return 1;
        if(current==visited){
            if(dfs(N,c+1,visited->after, kmin, ksum, nsum+ksum[i])==1) return 1;
        }else{
            if(dfs(N,c+1,visited, kmin, ksum, nsum+ksum[i])==1) return 1;
        }
		//iのフラグを取り消す
        if(current->before!=NULL)current->before->after=current;
        if(current->after!=NULL)current->after->before = current;

    }
	return 0;
}
int main(){
    int n;
    cin >> n;
    int kmin[n], ksum[n];
    bool visited[n]={false};
    int i, j ,l;
    int ssum = 0;
    string s;
    visitedList root(0);
    visitedList *cl = &root;
    for(i=1;i<n;i++){
        cl->after = new visitedList(i);
        cl->after->before=cl;
        cl=cl->after;
    }
    for(i=0;i<n;i++){
        cin >> s;
        l = s.length();
        int cmin=0,csum=0;
        for(j=0;j<l;j++){
            if(s[j]=='('){
                csum++;
            }else{
                csum--;
                if(csum<cmin){
                    cmin=csum;
                }
            }
        }
        kmin[i]=cmin;
        ksum[i]=csum;
        ssum+=csum;
    }
    if(ssum!=0){
        cout << "No" << endl;
        return 0;
    }
    int ans=dfs(n, 0, &root, kmin,ksum, 0);
    if(ans==1){
        cout << "Yes" << endl;
    return 0;
    }
    cout << "No" << endl;
    return 0;
}