#include <iostream>
#include<stack>
#include<cmath>
using namespace std;

class Node {
public:
	char data;
	Node* left, * right;
	Node(char data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

bool isOperand(char c)
{
	return (c >= '0' && c <= '9');
}

int calculate(int x, int y, char op)
{
	if (op == '+')
		return x + y;
	if (op == '-')
		return x - y;
	if (op == '*')
		return x * y;
	if (op == '/')
		return x / y;

	return 0;
}

int evaluate(Node* root)
{
	if (root == NULL)
		return 0;

	if (isOperand(root->data))
		return root->data - '0';

	int leftValue = evaluate(root->left);
	int rightValue = evaluate(root->right);

	return calculate(leftValue, rightValue, root->data);
}


int main()
{
	Node* root = new Node('+');

	root->left = new Node('*');
	root->left->left = new Node('+');
	root->left->left->left = new Node('-');
	root->left->left->right = new Node('6');
	root->left->left->left->left = new Node('4');
	root->left->left->left->right = new Node('2');

	root->left->right = new Node('-');
	root->left->right->left = new Node('7');
	root->left->right->right = new Node('+');
	root->left->right->right->left = new Node('1');
	root->left->right->right->right = new Node('2');

	root->right = new Node('-');
	root->right->left = new Node('*');
	root->right->left->left = new Node('4');
	root->right->left->right = new Node('3');

	root->right->right = new Node('*');
	root->right->right->left = new Node('4');
	root->right->right->right = new Node('/');
	root->right->right->right->left = new Node('2');
	root->right->right->right->right = new Node('1');

	cout << "Bieu thuc can tinh la: ((4-2)+6*7-(1+2))+(4*3-4*(2/1))" << endl;
	cout << "Gia tri cua bieu thuc la " << evaluate(root) << endl; 

	return 0;
}


