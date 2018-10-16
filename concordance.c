#include "tree.h"

typedef struct TreeNode_st{
	char *word;                 //word held in this node
	unsigned int frequency;     //how many times it has been seen
	unsigned int refLength;     //capactiy of the reernce list
	unsigned int *references;   //list of references
	struct TreeNode_st *left;   //node's left child
	struct TreeNode_st *right;  //node's right child
}TreeNode;

void insert_word(TreeNode **root, const char *word){
	//pointer to the variable that contians the pointer 
	//to the root node of the tree
	//point to the NUL-terminated array of character containing
	//a word that is to be inserted into the tree
}

void traverse_tree(const TreeNode *root){
	//pointer to the first node in a tree 
}

void cleanup_tree(const TreeNode *root){
	//pointer to the root node of a tree which is to be 
	//deallocated. If this is null, the tree is empty

}
