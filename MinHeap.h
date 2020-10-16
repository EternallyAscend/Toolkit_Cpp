#pragma once
#ifndef MINHEAP_H
#define MINHEAP_H

// MinHeap.
struct MinHeap {
	int size;
	int tail;
	int* minHeap;
};

int isEmptyMinHeap(struct MinHeap* minHeap);

void initMinHeap(struct MinHeap* minHeap);

void extendMinHeap(struct MinHeap* minHeap);

void pushMinHeap(struct MinHeap* minHeap, int value);

int popMinHeap(struct MinHeap* minHeap);

void destoryMinHeap(struct MinHeap* minHeap);

void displayMinHeap(struct MinHeap* minHeap);

void testMinHeap();

#endif
