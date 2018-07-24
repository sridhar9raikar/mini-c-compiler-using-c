#ifndef abs
#define abs
typedef struct node
{
    struct node *left;
    struct node *right;
    char *token;
} node;
node *mknode(node *left, node *right, char *token);

node *mknode(node *left, node *right, char *token)
{
  /* malloc the node */
  node *newnode = (node *)malloc(sizeof(node));
  char *newstr = (char *)malloc(strlen(token)+1);
  strcpy(newstr, token);
  newnode->left = left;
  newnode->right = right;
  newnode->token = newstr;
  return(newnode);
}

void printtree(node *tree)
{
  int i;
  if (tree->left !=NULL || tree->right != NULL)
    printf("(");

  printf(" %s ", tree->token);

  if (tree->left)
    printtree(tree->left);
  if (tree->right)
    printtree(tree->right);

  if (tree->left || tree->right)
    printf(")");
}

#endif
