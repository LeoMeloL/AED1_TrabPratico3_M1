#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
};

int max( int a, int b );
int getHeight( struct TreeNode* root, int* diameter );
int diameterOfBinaryTree( struct TreeNode* root );
void insert( struct TreeNode** root, int val );

int max( int a, int b ) {
    return a > b ? a : b;
}

int getHeight( struct TreeNode* root, int* diameter ) {
    if ( !root ) {
        return 0;
    }
    int left_height = getHeight( root->left, diameter );
    int right_height = getHeight( root->right, diameter );
    *diameter = max( *diameter, left_height + right_height );
    return max( left_height, right_height ) + 1;
}


int diameterOfBinaryTree( struct TreeNode* root ) {
    int diameter = 0;
    getHeight( root, &diameter );
    return diameter;
}

void insert( struct TreeNode** root, int val ) {
    if ( *root == NULL ) {
        *root = ( struct TreeNode* ) malloc( sizeof ( struct TreeNode ) );
        ( *root )->val = val;
        ( *root )->left = NULL;
        ( *root )->right = NULL;
    } else {
        if ( val < ( *root )->val ) {
            insert( & ( ( *root )->left ), val );
        } else {
            insert( & ( ( *root )->right ), val );
        }
    }
}

int main(){

    struct TreeNode *root = NULL;

    insert( &root, 1 );
    insert( &root, 2 );
    insert( &root, 4 );
    insert( &root, 7 );
    insert( &root, 3 );
    insert( &root, 8 );
    insert( &root, 0 );

    int diametro = diameterOfBinaryTree( root );
    printf("O diametro da arvore é: %d", diametro);
}
