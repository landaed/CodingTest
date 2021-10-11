#ifndef BST_H
#define BST_H
#include "../header/rectangle2D.h"
class BST
{
    int index;
    Rectangle2D data;
    BST *left, *right;

public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(Rectangle2D value);

    // Insert function.
    BST* Insert(BST* root, Rectangle2D value, char side);

    // Inorder traversal.
    void Inorder(BST* root, char side);

    Rectangle2D getData ();
    BST* getMin(BST* root);
    BST* deleteMin(BST* root, char side);
    BST* search(BST* root, Rectangle2D key, char side);
};
#endif
