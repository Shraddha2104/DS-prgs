#include<stdio.h>
#include<malloc.h>


struct tree
{
    char data;
    struct tree *left,*right;
};

int top=-1;
struct tree *stack[20];
struct tree *node;
void push(struct tree *node)
{
	top++;
	stack[top]=node;
}
struct tree* pop()
{
	return (stack[top--]);
}

int check(char ch)
{
	if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
	return 2;
	else
	return 1;
}


void inorder(struct tree *node)
{
    if(node!=NULL)
    {
    inorder(node->left);
    printf("%c",node->data);
    inorder(node->right);
    }
}
void operand(char b)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=b;
    node->left=NULL;
    node->right=NULL;
    push(node);
}


void operators(char a)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=a;
    node->right=pop();
    node->left=pop();
    push(node);
}
int main()
{
	int i,p;
	char postfix[20];
	printf("enter the expression in postfix form");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
		{
            p=check(postfix[i]);
            if(p==1)
            operand(postfix[i]);
            else if(p==2)
            operators(postfix[i]);
        }
    printf("\nThe inorder traversal of the tree is \n");
    inorder(stack[top]);
 return 0;
}
