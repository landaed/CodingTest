#include "../header/bst.h"
#include <iostream>

// Default Constructor definition.
BST::BST()
    : data(Rectangle2D(vec2(-9999,-9999),vec2(1,1),0))
    , left(NULL)
    , right(NULL)
{
}
Rectangle2D BST::getData(){
  return data;
}
// Parameterized Constructor definition.
BST::BST(Rectangle2D value)
{
    data = value;
    left = right = NULL;
}
// Insert function definition.
BST* BST::Insert(BST* root, Rectangle2D value, char side)
{

    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
    if(side == 'X'){
      // Insert data.
      if (value.getPos().x > root->data.getPos().x)
      {
          // Insert right node data, if the 'value'
          // to be inserted is greater than 'root' node data.

          // Process right nodes.
          root->right = Insert(root->right, value, side);
      }
      else
      {
          // Insert left node data, if the 'value'
          // to be inserted is greater than 'root' node data.

          // Process left nodes.
          root->left = Insert(root->left, value, side);
      }
    }
    else{
      // Insert data.
      if (value.getPos().y > root->data.getPos().y)
      {
          // Insert right node data, if the 'value'
          // to be inserted is greater than 'root' node data.

          // Process right nodes.
          root->right = Insert(root->right, value, side);
      }
      else
      {
          // Insert left node data, if the 'value'
          // to be inserted is greater than 'root' node data.

          // Process left nodes.
          root->left = Insert(root->left, value, side);
      }
    }


    // Return 'root' node, after insertion.
    return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST::Inorder(BST* root, char side)
{
    if (!root) {
        return;
    }
    Inorder(root->left, side);
    if(side == 'X'){
      std::cout << root->data.getPos().x << std::endl;
    }
    else{
      std::cout << root->data.getPos().y << std::endl;
    }

    Inorder(root->right, side);
}


BST* BST::getMin(BST* root)
{
    BST* current = root;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
      current = current->left;
    }
    return(current);
}

BST* BST::deleteMin(BST* root, char side){
  // base case
  if (root == NULL)
      return root;
  Rectangle2D key = getMin(root)->data;
  if(side == 'X'){
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key.getPos().x < root->data.getPos().x)
        root->left = deleteMin(root->left, side);

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key.getPos().x > root->data.getPos().x)
        root->right = deleteMin(root->right, side);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;

        // node with only one child or no child
        else if (root->left == NULL) {
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BST* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        BST* temp = getMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteMin(root->right, side);
    }
  }
    else{
      // If the key to be deleted is
      // smaller than the root's
      // key, then it lies in left subtree
      if (key.getPos().y < root->data.getPos().y)
          root->left = deleteMin(root->left, side);

      // If the key to be deleted is
      // greater than the root's
      // key, then it lies in right subtree
      else if (key.getPos().y > root->data.getPos().y)
          root->right = deleteMin(root->right, side);

      // if key is same as root's key, then This is the node
      // to be deleted
      else {
          // node has no child
          if (root->left==NULL and root->right==NULL)
              return NULL;

          // node with only one child or no child
          else if (root->left == NULL) {
              BST* temp = root->right;
              free(root);
              return temp;
          }
          else if (root->right == NULL) {
              BST* temp = root->left;
              free(root);
              return temp;
          }

          // node with two children: Get the inorder successor
          // (smallest in the right subtree)
          BST* temp = getMin(root->right);

          // Copy the inorder successor's content to this node
          root->data = temp->data;

          // Delete the inorder successor
          root->right = deleteMin(root->right, side);
    }
  }

  return root;
}



// C function to search a given key in a given BST
BST* BST::search(BST* root, Rectangle2D key, char side)
{
    if(side=='X'){
      // Base Cases: root is null or key is present at root
      if (root == NULL || root->data.getPos().x == key.getPos().x)
         return root;

      // Key is greater than root's key
      if (root->data.getPos().x < key.getPos().x)
         return search(root->right, key, side);
    }
    else{
      // Base Cases: root is null or key is present at root
      if (root == NULL || root->data.getPos().y == key.getPos().y)
         return root;

      // Key is greater than root's key
      if (root->data.getPos().y < key.getPos().y)
         return search(root->right, key, side);
    }


    // Key is smaller than root's key
    return search(root->left, key, side);
}
