#include "linkedlist.h"

LLNODE* createfirstnode (size_t data) {
	LLNODE *node = (LLNODE*) malloc(sizeof(LLNODE));
	node->data = data;
	node->nextnode = NULL;
	return node;
}

LLNODE* accessnode (LLNODE *firstnode, size_t index) {
	if ((int)index < 0) return NULL;
	LLNODE *currnode = firstnode;
	for (size_t i = 0; i < index; ++i) {
		if (currnode->nextnode != NULL) {
			currnode = currnode->nextnode;
		}
		else return NULL;
	}
	return currnode;
}

LLNODE* create_node_at (LLNODE *firstnode, size_t index, size_t data) {
	if ((int)index < 0) return NULL;
	
	if (index == 0) {
		LLNODE *node = createfirstnode(data);
		node->nextnode = firstnode;
		return node;
	}
	
	LLNODE *prevnode = accessnode(firstnode, index-1);
	LLNODE *nextnode = accessnode(firstnode, index);
	
	if ( (prevnode != NULL) && (nextnode == NULL) ) {
		LLNODE *node = (LLNODE*) malloc(sizeof(LLNODE));
		prevnode->nextnode = node;
		node->data = data;
		node->nextnode = NULL;
		return node;
	}
	
	if ( (prevnode == NULL) && (nextnode == NULL) ) return NULL;
	
	LLNODE *node = (LLNODE*) malloc(sizeof(LLNODE));\
	prevnode->nextnode = node;
	node->data = data;
	node->nextnode = nextnode;
	return node;
}

int deleteandfreenode(LLNODE *firstnode, size_t index) {
	
	if ((int)index < 0) return -1;
	if (index == 0) {
		free((void*)firstnode);
		firstnode = NULL;
		return 0;
	}
	
	LLNODE *node = accessnode(firstnode, index);
	LLNODE *prevnode = accessnode(firstnode, index-1);
	LLNODE *nextnode = accessnode(firstnode, index+1);
	
	prevnode->nextnode = nextnode;
	free((void*)node);
	node = NULL;
	return 0;
}

LLNODE* createlinkedlist(size_t length, ...) {
	if (length <= 0) return NULL;
	
	LLNODE *firstnode;
	LLNODE *currnode;
	
	va_list args;
	va_start(args, length);
	
	for (size_t i = 0; i < length; ++i) {
		LLNODE *node = (LLNODE*)malloc(sizeof(LLNODE));
		node->data = va_arg(args, size_t);
		node->nextnode = NULL;
		if (i == 0) {firstnode = node; currnode = node;}
		else {currnode->nextnode = node; currnode = node;}
	}
	
	va_end(args);
	
	return firstnode;
}

void deletelinkedlist(LLNODE *firstnode) {
	size_t i = 0;
	while (firstnode) {
		LLNODE *nextnode = firstnode->nextnode;
		free((void*)firstnode);
		firstnode = nextnode;
		++i;
	}
}

void print_full_linkedlist(LLNODE *firstnode) {
	size_t i = 0;
	//didn't use a currnode variable here because i hate consistency woo! (still works because the actual pointer is passed by value)
	//i could've done LLNODE *currnode = firstnode; (like in the other functions) and then used currnode instead of firstnode in the loop
	//but it's redundant and doesn't even help readability like in the other functions
	while (firstnode) {
		printf("Data: %zu, index: %zu\n", firstnode->data, i);
		firstnode = firstnode->nextnode;
		++i;
	}
}

void print_linkedlist_section(LLNODE *firstnode, size_t startindex, size_t endindex) {
	if (firstnode == NULL) return;
	LLNODE *currnode = accessnode(firstnode, startindex);
	if (currnode == NULL) return;
	for (; startindex < (endindex+1); ++startindex) {
		printf("Data: %zu, index: %zu\n", currnode->data, startindex);
		currnode = currnode->nextnode;
		if (currnode == NULL) break;
	}
}
