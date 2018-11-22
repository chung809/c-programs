#include<stdio.h> 
#include<stdlib.h>
  
struct treeNode {
  int val;
  struct treeNode *left;
  struct treeNode *right;
};
typedef struct treeNode TreeNode;
 
int HasPathSum(TreeNode *root, int sum);
  
int HasPathSum(TreeNode *root, int sum) 
{ 
	int ans = 0;
	int subSum;
	
	if (root == NULL) { 
		return (sum == 0); 
	} else { 
		subSum = sum - root->val;
		if (subSum == 0 && root->left == NULL && root->right == NULL ) 
			return 1; 
		if (root->left) 
			ans = ans || HasPathSum(root->left, subSum); 
		if (root->right) 
			ans = ans || HasPathSum(root->right, subSum); 
		return ans; 
  	} 
} 
  
TreeNode *newnode(int val) 
{ 
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode)); 
	node->val = val; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 
  
int main() 
{ 
	int sum = 22; 
  
	/* Constructed binary tree is
		5
	       / \
	      4   8
	     /   / \
	    11  13  4
	   /  \      \
	  7    2      1
	*/
	TreeNode *root		= newnode(5); 
	root->left		= newnode(4); 
	root->right		= newnode(8); 
	root->left->left	= newnode(11); 
	root->right->left	= newnode(13);
	root->right->right	= newnode(4);
	root->left->left->left	= newnode(7);
	root->left->left->right	= newnode(2);
	
	if(HasPathSum(root, sum)) 
		printf("There is a root-to-leaf path with sum %d\n", sum); 
	else
		printf("There is no root-to-leaf path with sum %d\n", sum); 

	return 0; 
} 
