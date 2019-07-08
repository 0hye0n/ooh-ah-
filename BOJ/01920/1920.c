#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node* pNode;
typedef struct Node
{
   int data;
   pNode left;
   pNode right;
}Node; 

pNode tree = NULL;

int kvget(int key)
{  
   pNode compareNode;
   compareNode = tree;
   
   while(compareNode != NULL){
   if(key>(compareNode->data))
   {
      compareNode = compareNode->right;
   }
   
   else if(key<(compareNode->data))
   {
      compareNode = compareNode->left;
   }
   
   else if(key==(compareNode->data))
   {
      return 0;
   }
	}     
    return 1;
}

void kvput(int key)
{
   pNode compareNode = tree;
   pNode newNode = (pNode)malloc(sizeof(Node));
   
   newNode->data = key;
   newNode->left = NULL;
   newNode->right = NULL;
   if(compareNode == NULL)  
   {
      tree = newNode;
      return; 
   }
   
   while(1){
   if(key<compareNode->data) 
   {
      if(compareNode->left==NULL)
      {
         compareNode->left = newNode;
         return; 
       }
        
       else
      {
       compareNode = compareNode->left; 
      }
   }
   
   else if(key>compareNode->data)
   {
      if(compareNode->right==NULL)
      {
         compareNode->right = newNode; 
         return; 
      }
      
      else
      {
      compareNode = compareNode->right; 
      }
   }
   
   else if(key==compareNode->data)  
   {  
	  return;
   }
}
    return; 
}

int kvdel(int key)
{
 	pNode parent, node, root;
	pNode succ, succ_parent, child;
	int compare;
	parent = NULL;
	root = tree;
	node = root;
	

	while(node != NULL)
	{
    	
		if(key==node->data)
    		break;
    	
    	parent = node;
    	
    	if(key<node->data)
			node = node->left;
    	else node = node->right;
	} 
	
	if(node == NULL)
	{ 
    	return 1; 
	} 
   
	if((node->left == NULL) && (node->right == NULL)) 
	{ 
    	if(parent != NULL)
    	{ 
        	if(parent->left == node)
        		parent->left = NULL;
        	else
				parent->right = NULL;
    	} 
    	else 
			tree = NULL;
	} 
	else if((node->left == NULL) || (node->right == NULL)) 
	{ 
    	if(node->left != NULL)
			child = node->left; 
    	else
			child = node->right; 
    	if(parent != NULL) 
    	{ 
        	if(parent->left == node)
        		parent->left = child;
        	else
				parent->right = child;  
    	} 
    	else
			tree = child;
	} 
	else
	{ 
    	succ_parent = node; 
    	succ = node->left;  
    	
		while(succ->right != NULL)  
    	{
        	succ_parent = succ;
        	succ = succ->right;
    	}
    	

    	if(root == node)
    	{
    		if(succ_parent == root) 
    		{
                tree = succ;
    			succ->right = node->right;	
            }
            else
            { 
    		    tree = succ;
    		    succ_parent->right = succ->left; 
                succ->left = node->left;
                succ->right = node->right;
            }
		}
		else
		{
			if(succ==node->left)
			{
                succ->right = node->right;
                if(parent->left == node)
                    parent->left = succ;
                else
                    parent->right = succ;
            }
            else
            {
                succ_parent->right = succ->left; 
			    succ->left = node->left;
    		    succ->right = node->right;
    		    if(parent->left == node)
                    parent->left = succ;
                else
                    parent->right = succ;
            }
		}

	} 
	
	free(node);
	return 0;
}

int main()
{
	int n, m, cnt=0, i;scanf("%d", &n);
	while(n--){
		int temp;scanf(" %d", &temp);
		kvput(temp);
	}
	scanf("%d", &m);
	for(i = 0; i<m; i++)
	{
		int temp;scanf(" %d", &temp);
		if(kvget(temp)==0)printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}