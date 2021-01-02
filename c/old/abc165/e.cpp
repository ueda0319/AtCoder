#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Tree{
public:
    long p;
    int count;
    Tree *left = NULL, *right = NULL;
    Tree(long u){
        p=u;
        count=1;
    }
    int search(long word){
        if(word == p){
            return count;
        }else if(word < p){
            if(left == NULL){
                return 0;
            }else{
                return left->check(word);
            }
        }else{
            if(right == NULL){
                return 0;
            }else{
                return right->check(word);
            }
        }
    }
    int check(long word){
        if(word == p){
            count++;
            return count;
        }else if(word < p){
            if(left == NULL){
                left =new Tree(word);
                return 1;
            }else{
                return left->check(word);
            }
        }else{
            if(right == NULL){
                right = new Tree(word);
                return 1;
            }else{
                return right->check(word);
            }
        }
    }
};
int main(){
    int n;
    cin >> n;
    int i;
    int u, count=0;
    cin >> u;
    Tree root(u+1);
    for(i=1;i<n;i++){
        cin >> u;
        count += root.search(i+1-u);
        root.check(u+i+1);
    }
    cout << count <<endl;
    return 0;
}