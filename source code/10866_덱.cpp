#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;

typedef struct Deque {
	int data;
	struct Deque *front, *back;
}Deque, *pDeque;

bool empty(pDeque head)
{
	if (head == NULL)
		return true;
	return false;
}

void push_front(pDeque *head, pDeque *tail, int x)
{
	pDeque node = new Deque();
	node->data = x;
	node->front = node->back = NULL;

	if (empty(*head))
		*head = *tail = node;
	else
	{
		(*head)->front = node;
		node->back = *head;
		*head = node;
	}
}

void push_back(pDeque *head, pDeque *tail, int x)
{
	pDeque node = new Deque();
	node->data = x;
	node->front = node->back = NULL;

	if (empty(*tail))
		*head = *tail = node;
	else
	{
		(*tail)->back = node;
		node->front = *tail;
		*tail = node;
	}
}

void pop_front(pDeque *head, pDeque *tail)
{
	if (empty(*head))
		cout << -1 << endl;
	else
	{
		if (*head == *tail)
		{
			cout << (*head)->data << endl;
			delete(*head);
			*head = *tail = NULL;
		}
		else
		{
			pDeque temp = *head;
			*head = (*head)->back;
			(*head)->front = NULL;
			cout << temp->data << endl;
			delete(temp);
		}
	}
}

void pop_back(pDeque *head, pDeque *tail)
{
	if (empty(*tail))
		cout << -1 << endl;
	else
	{
		if (*head == *tail)
		{
			cout << (*tail)->data << endl;
			delete(*tail);
			*head = *tail = NULL;
		}
		else
		{
			pDeque temp = *tail;
			*tail = (*tail)->front;
			(*tail)->back = NULL;
			cout << temp->data << endl;
			delete(temp);
		}
	}
}

void size(pDeque head, pDeque tail)
{
	if (empty(head))
	{
		cout << 0 << endl;
		return;
	}

	int cnt = 1;
	while (head != tail)
	{
		cnt++;
		head = head->back;
	}
	cout << cnt << endl;
}

void front(pDeque head)
{
	if (empty(head))
		cout << -1 << endl;
	else
		cout << head->data << endl;
}

void back(pDeque tail)
{
	if (empty(tail))
		cout << -1 << endl;
	else
		cout << tail->data << endl;
}

int main(void)
{
	pDeque head = NULL, tail = NULL;
	
	int n;
	cin >> n;

	while (n--)
	{
		string str;
		cin >> str;

		if (str == "push_front")
		{
			int x;
			cin >> x;
			push_front(&head, &tail, x);
		}
		else if (str == "push_back")
		{
			int x;
			cin >> x;
			push_back(&head, &tail, x);
		}
		else if (str == "pop_front")
			pop_front(&head, &tail);
		else if (str == "pop_back")
			pop_back(&head, &tail);
		else if (str == "size")
			size(head, tail);
		else if (str == "empty")
			cout<< (empty(head) ? 1 : 0) <<endl;
		else if (str == "front")
			front(head);
		else
			back(tail);
	}

	return 0;
}