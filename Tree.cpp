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

//I believe this is taking a tree and making a subtree on the left if 
//there are numbers less than or equal to variable n, and making
//a subtree on the right if it is more than variable n.
void insert(Tree* &tree, int n){ //I know that this is pointing to a reference of tree. 
    if ( tree == NULL ){ //if tree is equal to the value of NULL which means nothing/0/empty. 
        tree = new Tree{n, NULL, NULL}; //then a new branch(Tree) with a new item is created and "pointed to" 
                                        //and the left and right subtrees are set to NULL.
                                        //I am honestly confused here. Does this mean that a new branch is made but isn't connected to the whole tree??
    } else if ( n <= tree->value ){ //if n is less than or equal to the value of tree
                                    // then it goes into subtree left. 
        insert( tree->left, n ); 
    } else {
        insert( tree->right, n);//if n is more than the value of tree
                                // then it goes into subtree right. 
    }
}

// I believe this function will print out the left side of a tree until it hits a NULL value, then print out the
//right side of a tree. So it will keep going down the tree until there is a NULL value
//then it will print out those values starting from the bottom of the tree. 
void print(Tree* tree){
    if ( tree != NULL ){
        print( tree->left ); //This is printing the items in the left subtree if the 
                             //tree is not empty/NULL. 
        cout << tree->value << " "; // This prints the item value because it is pointing to
                                    //the tree and at the the value of tree. 
        print( tree->right ); //This is printing the items in the right subtree if the 
                             //tree is not empty/NULL.
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