#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct linkedlistnode {
	size_t data;
	struct linkedlistnode *nextnode;
} LLNODE;

LLNODE* createfirstnode (size_t data);

LLNODE* accessnode (LLNODE *firstnode, size_t index);

LLNODE* create_node_at (LLNODE *firstnode, size_t index, size_t data);

int deleteandfreenode(LLNODE *firstnode, size_t index);

LLNODE* createlinkedlist(size_t length, ...);

void deletelinkedlist(LLNODE *firstnode);

void print_full_linkedlist(LLNODE *firstnode);

void print_linkedlist_section(LLNODE *firstnode, size_t startindex, size_t endindex);

#endif /* LINKEDLIST_H */