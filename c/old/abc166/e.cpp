#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Tree{
public:
    int p;
    int count;
    Tree *left = NULL, *right = NULL;
    Tree(int u){
        p=u;
        count=1;
    }
    int search(int word){
        if(word == p){
            return count;
        }else if(word < p){
            if(left == NULL){
                return 0;
            }else{
                return left->search(word);
            }
        }else{
            if(right == NULL){
                return 0;
            }else{
                return right->search(word);
            }
        }
    }
    void check(int word){
        if(word == p){
            count++;
            return;
        }else if(word < p){
            if(left == NULL){
                left =new Tree(word);
                return;
            }else{
                left->check(word);
                return;
            }
        }else{
            if(right == NULL){
                right = new Tree(word);
                return;
            }else{
                right->check(word);
                return;
            }
        }
    }
    long co(Tree tgt){
        long c=tgt.search(p)*count;
        if(right != NULL){
            c+=right->co(tgt);
        }
        if(left != NULL){
            c+=left->co(tgt);
        }
        return c;
    }
};
int main(){
    int n;
    cin >> n;
    int i,j;
    int u[n];
    long long count=0;
    for(i=0;i<n;i++){
        cin >> u[i];
        for(j=0;j<i;j++){
            if(u[i]+u[j]==i-j)count++;
        }
    }
    cout << count <<endl;
    return 0;
}