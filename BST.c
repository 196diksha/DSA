#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
  struct nodetype *left;
  int info;
  struct nodetype *right;
} BST;
void insertion (BST ** root, int m);
void preorder_traversal (BST * root);
void inorder_traversal (BST * root);
void postorder_traversal (BST * root);
void
main ()
{
  BST *root = NULL;
  while (1)
    {
      int n, m;
      printf ("enter choice ");
      scanf ("%d", &n);
      switch (n)
	{
	case 1:
	  printf ("enter value to insert ");
	  scanf ("%d", &m);
	  insertion (&root, m);
	  break;
	case 2:
	  if (root == NULL)
	    {
	      printf ("tree is empty\n");
	      return;
	    }
	    printf("\n preorder traversal: ");
	  preorder_traversal (root);
	   printf("\n inorder traversal: ");
	  inorder_traversal (root);
	   printf("\n postorder traversal: ");
	  postorder_traversal (root);
	  break;
	case 6:
	  exit (0);
	}
    }
}

void
preorder_traversal (BST * root)
{

  if (root != NULL)
    {
      printf ("%d ", root->info);
      preorder_traversal (root->left);
      preorder_traversal (root->right);
    }
}

void
inorder_traversal (BST * root)
{

  if (root != NULL)
    {

     inorder_traversal (root->left);
      printf ("%d ", root->info);
      inorder_traversal (root->right);
    }
}

void
postorder_traversal (BST * root)
{

  if (root != NULL)
    {
      postorder_traversal (root->left);
      postorder_traversal (root->right);
      printf ("%d ", root->info);
    }
}

void
insertion (BST ** root, int item)
{
  BST *ptr, *parent, *loc;
  ptr = (BST *) malloc (sizeof (BST));
  ptr->info = item;
  ptr->left = NULL;
  ptr->right = NULL;
  if (*root == NULL)
    {
      *root = ptr;
    }
  else
    {
      loc = *root;
      while (loc != NULL)
	{
	  parent = loc;
	  if (item > loc->info)
	    loc = loc->right;
	  else
	    loc = loc->left;
	}
      if (item > parent->info)
	parent->right = ptr;
      else
	parent->left = ptr;
    }
}
