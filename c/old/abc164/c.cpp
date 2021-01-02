#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Tree{
public:
    string s;
    Tree *left = NULL, *right = NULL;
    Tree(string word){
        s = word;
    }
    int check(string word){
        if(word == s){
            return 0;
        }else if(word < s){
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
    string s[n], sc;
    int i, j, p=1;
    cin >> sc;
    Tree root(sc);
    for(i=1; i<n; i++){
        cin >> sc;
        p+=root.check(sc);
    }
    cout << p << endl;
    return 0;
}