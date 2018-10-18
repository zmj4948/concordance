//#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int CurrentLine=0;

typedef struct TreeNode_st{
	char *word;                 //word held in this node
	unsigned int frequency;     //how many times it has been seen
	unsigned int refLength;     //capactiy of the reernce list
	unsigned int *references;   //list of references
	struct TreeNode_st *left;   //node's left child
	struct TreeNode_st *right;  //node's right child
}TreeNode;

TreeNode *newNode(char *word){
        //hi i'm a helper function
        TreeNode *temp=(TreeNode *)malloc(sizeof(TreeNode));
        char *node_word=(char *)malloc(sizeof(char)*strlen(word));
        strcpy(node_word,word);
        temp->word=node_word;
        temp->left=temp->right=NULL;
        temp->frequency=1;
        temp->refLength=3;
        temp->references=malloc(10*sizeof(int));
        temp->references[0]=CurrentLine;
        return temp;
}

void insert_word(TreeNode **root, const char *word){
	//pointer to the variable that contians the pointer 
	//to the root node of the tree
	//point to the NUL-terminated array of character containing
	//a word that is to be inserted into the tree 
	if(*root==NULL){
		//just insert here
		char *pleaseWork=(char *)word;
		*root= newNode(pleaseWork);
	}else{
		if(strcasecmp(word,(*root)->word)<0){
			//left
			insert_word(&((*root)->left),word);
		}else if(strcasecmp(word,(*root)->word)>0){
			//right
			insert_word(&((*root)->right),word);
		}else{
			//WE FOUND A GOD-DAMN MATCH 
			if((*root)->frequency<(*root)->refLength){
				(*root)->frequency+=1;
				(*root)->references[((*root)->frequency)-1]=CurrentLine;		
			}else{
				(*root)->references=realloc((*root)->references,(3*sizeof(int))+3);
				(*root)->refLength+=3;
				(*root)->references[((*root)->frequency)-1]=CurrentLine;
			}
		
		}
	}	
}

void traverse_tree(const TreeNode *root){
	//pointer to the first node in a tree
	if(root==NULL)
		return;
	traverse_tree(root->left);
	printf("%s ( %d): ",root->word, root->frequency);
	for(int i=0;i<root->frequency;i++){
		printf("%d, ",root->references[i]);
	}
	printf("\n");
	traverse_tree(root->right); 
}

void cleanup_tree(const TreeNode *root){
	//pointer to the root node of a tree which is to be 
	//deallocated. If this is null, the tree is empty
	if(root!=NULL){
		cleanup_tree(root->left);
		cleanup_tree(root->right);
		free(root->word);
		free(root->references);
	}
}

int main(int argc,char *argv[]){
	if(argc>1){
		fprintf(stderr,"useage: concordance\n");
	}else{
		//TO-DO
		//when calling insert, pass the address of the node into it
		TreeNode *root=NULL;
		size_t len=0;
		char *token;
		char *buf=NULL;
		char space[]=" ";
		while(getline(&buf, &len,stdin)>0){
			token=strtok(buf,space);
			while(token!=NULL){
				if(token!="\n"){
					insert_word(&root,token);
				}
				token=strtok(NULL,space);
			}
			CurrentLine++;
			
		}
		if(buf!=NULL){
			free(buf);
		}
		traverse_tree(root);
		cleanup_tree(root);
	}
	return 0;
}
