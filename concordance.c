#include "tree.h"

typedef struct TreeNode_st{
	char *word;                 //word held in this node
	unsigned int frequency;     //how many times it has been seen
	unsigned int refLength;     //capactiy of the reernce list
	unsigned int *references;   //list of references
	struct TreeNode_st *left;   //node's left child
	struct TreeNode_st *right;  //node's right child
}TreeNode;
