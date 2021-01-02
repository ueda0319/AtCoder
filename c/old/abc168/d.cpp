#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    bool visited[n]={false};
    int refs[n];
    vector<vector<int>> graph(n);
    int i,j, a, b;
    for(i=0;i<m;i++){
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    visited[0]=true;
    vector<int> v;
    v.push_back(0);
    for(i=0;i<n;i++){
        for(j=0;j<graph[v[i]].size();j++){
            //cout << i << "," << graph[v[i]][j] << endl;
            if(!visited[graph[v[i]][j]]){
                visited[graph[v[i]][j]]=true;
                v.push_back(graph[v[i]][j]);
                refs[graph[v[i]][j]]=v[i];
            }

        }
    }
    cout << "Yes" << endl;
    for(i=1;i<n;i++){
        cout << refs[i]+1 << endl;
    }
    return 0;
}