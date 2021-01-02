#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int i,j;
    long long t[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> t[i][j];
        }
    }
    vector<int> nums;
    for(i=1;i<n;i++){
        nums.push_back(i);
    }
    j=0;
    do {
        long long cost=0;
        cost += t[0][nums[0]];
        for(i=0;i<n-2;i++){
            cost+=t[nums[i]][nums[i+1]];
        }
        cost += t[nums[n-2]][0];
        if(cost==k)j++;
    } while (next_permutation(nums.begin(), nums.end()));
    cout << j << endl;
    return 0;
}