#include <iostream>
#include <string>
#include <math.h>
#include<algorithm>
using namespace std;
struct spaceList{
    int id;
    // 右の空席への参照
    spaceList *after;
    spaceList(int nid){
        id=nid;
        after = NULL;
    }
};
int dfs(int N, int c, bool *visited, int *kmin, int *ksum, int nsum) {
	//すべての遷移先について調べる
	for (int i = 0; i < N; i++) {
		if (visited[i])continue;
        if(nsum + kmin[i]<0) continue;
		visited[i] = true;
        if((c+1==N)&&(nsum+ksum[i]==0)) return 1;
        if(dfs(N,c+1,visited, kmin, ksum, nsum+ksum[i])==1) return 1;
		//iのフラグを取り消す
		visited[i] = false;
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
    for(i=0;i<n;i++){
        ids[i]=i;
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
    int ans=dfs(n, 0, visited, kmin,ksum, 0);
    if(ans==1){
        cout << "Yes" << endl;
    return 0;
    }
    cout << "No" << endl;
    return 0;
}