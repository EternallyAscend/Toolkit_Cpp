#pragma once
#ifndef MAXHEAP_H
#define MAXHEAP_H

// MaxHeap.

struct MaxHeap {
	int size;
	int tail;
	int* maxHeap;
};

int isEmptyMaxHeap(struct MaxHeap* maxHeap);

void initMaxHeap(struct MaxHeap* maxHeap);

void extendMaxHeap(struct MaxHeap* maxHeap);

void pushMaxHeap(struct MaxHeap* maxHeap, int value);

int popMaxHeap(struct MaxHeap* maxHeap);

void destoryMaxHeap(struct MaxHeap* maxHeap);

void displayMaxHeap(struct MaxHeap* maxHeap);

void testMaxHeap();

#endif
