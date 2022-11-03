#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;


struct Tree {
    int value;
    Tree* left;
    Tree* right;
};

void insert(Tree* &tree, int n){
    if ( tree == NULL ){
        tree = new Tree{n, NULL, NULL};
    } else if ( n <= tree->value ){
        insert( tree->left, n );
    } else {
        insert( tree->right, n);
    }
}

void print(Tree* tree){
    if ( tree != NULL ){
        print( tree->left );
        cout << tree->value << " ";
        print( tree->right );
    }
}

int main(){
    Tree* t = NULL;
    
    insert(t, 23);
    insert(t, 10);
    insert(t, 42);
    insert(t, 5);
    insert(t, 2);
    insert(t, 99);

    print(t);

    return 0;
}