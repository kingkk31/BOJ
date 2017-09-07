#include <iostream>
using namespace std;

typedef struct _tree{
	char data;
	_tree *left;
	_tree *right;

}tree,*ptree;

ptree createNode(char a)
{
	ptree node = new tree;

	node->data = a;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void insert(ptree head, char parent, char child1, char child2)
{
	if(head == NULL)
	{
		return;
	}

	if(head->data == parent)
	{
		if(child1 != '.')
		{
			head->left = createNode(child1);
		}
		if(child2 != '.')
		{
			head->right = createNode(child2);
		}
		return;
	}//parent가 아닐 경우
	insert(head->left, parent, child1, child2);
	insert(head->right, parent, child1, child2);
}

void prePrint(ptree head)
{
	if(head == NULL)
	{
		return;
	}
	cout<<head->data;
	prePrint(head->left);
	prePrint(head->right);
}

void midPrint(ptree head)
{
	if(head == NULL)
	{
		return;
	}
	midPrint(head->left);
	cout<<head->data;
	midPrint(head->right);
}

void backPrint(ptree head)
{
	if(head == NULL)
	{
		return;
	}
	backPrint(head->left);
	backPrint(head->right);
	cout<<head->data;
}


int main(void)
{
	ptree node = createNode('A');

	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		char a,b,c;
		cin>>a>>b>>c;
	
		insert(node,a,b,c);
	}

	prePrint(node);
	cout<<endl;
	midPrint(node);
	cout<<endl;
	backPrint(node);
	cout<<endl;
	
	return 0;
}