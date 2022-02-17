/* Rabia Nur Özdemir - 191180066 - Data Structures Assignment 3 */

#include <stdio.h>
#include <stdlib.h> // for rand() function
#include <time.h> // for srand(time()) function

typedef struct treeNode {
    int data;
    struct treeNode *leftPtr;
    struct treeNode *rightPtr;
}TreeNode;

// insert
TreeNode *insertNode(TreeNode *treePtr, int value){ // function that takes value and adds it to the tree
    
    if(treePtr == NULL){ // if the tree is empty
        TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode)); // open an empty box in memory
        root -> leftPtr = NULL; // make root's left null
        root -> rightPtr = NULL; // make root's right null
        root -> data = value; // set root's data to value
        return root; // return stuffed tree
    }
    if(treePtr -> data < value){ // if the tree's data is less than the value
        treePtr -> rightPtr = insertNode(treePtr -> rightPtr, value); // (recursive) add to the right of the tree and set it as the new right of the tree
        return treePtr;
    }

    treePtr -> leftPtr = insertNode(treePtr -> leftPtr, value); // (recursive) add to the left of the tree and set it as the new left of the tree
        return treePtr;
}

// inorder traversal
void inorder(TreeNode *treePtr){
    // the code that writes first the left, then the data, then the right of the tree, sorts it from smallest to largest
    // if there was a code that first wrote the right, then the data, then the left of the tree, it would sort them from largest to smallest
    if(treePtr == NULL){ // do nothing if the tree is empty
        return;
    }
    inorder(treePtr -> leftPtr); // (recursive)
    printf("%d ", treePtr -> data); // print tree's data to screen
    inorder(treePtr -> rightPtr); // (recursive)
    }

// preorder traversal
void preorder(TreeNode *treePtr){
    
    if(treePtr != NULL){
        printf("%d ",treePtr -> data);
        preorder(treePtr -> leftPtr);
        preorder(treePtr -> rightPtr);
    }
}

// postorder traversal
void postorder(TreeNode *treePtr){
    
    if(treePtr != NULL){
        
        postorder(treePtr -> leftPtr);
        postorder(treePtr -> rightPtr);
        printf("%d ", treePtr -> data);
    }
}

int main() {
    
    TreeNode *treePtr = NULL;
    int i;
    int randomNumber;
    int temporaryArray[10]; // we have defined a temporary array so that the same number does not appear
    printf("\nThe numbers being placed in the tree are: ");
    srand(time(NULL)); // We added this command and the <time.h> library to get different numbers each time
    
    for(i=0; i<10; i++){
    	temporaryArray[i] = NULL;
	}
	
	while(temporaryArray[9] == NULL){
		randomNumber = 1 + rand() % 25; // random number generating function [1-25]
		for(i=0; i<10; i++){
    		if(temporaryArray[i] == randomNumber){ // do not add the same number back to the array if the element i is equal to the generated random number
    			break; 
			}
			else if(temporaryArray[i] == NULL){ // if the element of the array is empty, add the generated random number directly
				temporaryArray[i] = randomNumber; 
				printf("%d ",temporaryArray[i]); // print the elements of the array to the screen (each one different)
    			treePtr = insertNode(treePtr,temporaryArray[i]); // add the elements of the array to the tree
				break;
			}
		}
	}
    
    printf("\nThe preorder traversal is: ");
    preorder(treePtr);
    printf("\nThe inorder traversal is: ");
    inorder(treePtr);
    printf("\nThe postorder traversal is: ");
    postorder(treePtr);
    
    return 0;
}
