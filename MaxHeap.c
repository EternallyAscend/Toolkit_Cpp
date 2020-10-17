#include <stdio.h>
#include <stdlib.h>
#include "MaxHeap.h"

// MaxHeap.

int isEmptyMaxHeap(struct MaxHeap* maxHeap) {
	if (NULL == maxHeap) {
		return 1;
	}
	if (NULL == maxHeap->maxHeap) {
		return 1;
	}
	return 0;
}

void initMaxHeap(struct MaxHeap* maxHeap) {
	maxHeap->size = 16;
	maxHeap->tail = 0;
	maxHeap->maxHeap = (int*)malloc(sizeof(int) * 16);
}

void extendMaxHeap(struct MaxHeap* maxHeap) {
	if (isEmptyMinHeap(maxHeap)) {
		return;
	}
	int newSize = maxHeap->size;
	newSize = newSize << 1;
	int *temporary = (int*)malloc(sizeof(int) * newSize);
	int cursor = 0;
	for (; cursor < maxHeap->size; cursor++) {
		temporary[cursor] = maxHeap->maxHeap[cursor];
	}
	maxHeap->size = newSize;
	printf("size: %d\n", maxHeap->size);
	free(maxHeap->maxHeap);
	maxHeap->maxHeap = temporary;
}

void pushMaxHeap(struct MaxHeap* maxHeap, int value) {
	if (isEmptyMinHeap(maxHeap)) {
		return;
	}
	if (maxHeap->tail == maxHeap->size) {
		extendMinHeap(maxHeap);
	}
	maxHeap->maxHeap[maxHeap->tail++] = value;
	// Adjust the maxHeap.
	if (1 == maxHeap->tail) {
		return;
	}
	else {
		int current = maxHeap->tail - 1;
		while ((current - 1) >> 1) {
			if (maxHeap->maxHeap[current] > maxHeap->maxHeap[(current - 1) >> 1]) {
				int temporary = maxHeap->maxHeap[current];
				maxHeap->maxHeap[current] = maxHeap->maxHeap[(current - 1) >> 1];
				maxHeap->maxHeap[(current - 1) >> 1] = temporary;
				current = ((current - 1) >> 1);
			}
			else {
				return;
			}
		}
		if (maxHeap->maxHeap[current] > maxHeap->maxHeap[0]) {
			int temporary = maxHeap->maxHeap[current];
			maxHeap->maxHeap[current] = maxHeap->maxHeap[0];
			maxHeap->maxHeap[0] = temporary;
		}
	}
}

// Unmodified.
int popMaxHeap(struct MaxHeap* maxHeap) {
	if (NULL == maxHeap) {
		return -65535;
	}
	if (NULL == maxHeap->maxHeap) {
		return -65535;
	}
	if (0 >= maxHeap->tail) {
		return -65534;
	}
	int result = maxHeap->maxHeap[0];
	if (1 == maxHeap->tail) {
		maxHeap->tail = 0;
		return result;
	}
	// Adjust the maxHeap.
	maxHeap->maxHeap[0] = maxHeap->maxHeap[--maxHeap->tail];
	int current = 0;
	while (1) {
		int left = 0;
		int right = 0;
		int leftValue;
		int rightValue;
		if ((current << 1) + 1 < maxHeap->tail) {
			left = 1;
			leftValue = maxHeap->maxHeap[(current << 1) + 1];
			if ((current << 1) + 2 < maxHeap->tail) {
				right = 1;
				rightValue = maxHeap->maxHeap[(current << 1) + 2];
			}
		}
		if (left || right) {
			if (right) {
				if (leftValue < rightValue) {
					if (rightValue > maxHeap->maxHeap[current]) {
						int temporary = maxHeap->maxHeap[current];
						maxHeap->maxHeap[current] = maxHeap->maxHeap[(current << 1) + 2];
						maxHeap->maxHeap[(current << 1) + 2] = temporary;
						current = (current << 1) + 2;
					}
					else {
						break;
					}
				}
				else {
					if (leftValue > maxHeap->maxHeap[current]) {
						int temporary = maxHeap->maxHeap[current];
						maxHeap->maxHeap[current] = maxHeap->maxHeap[(current << 1) + 1];
						maxHeap->maxHeap[(current << 1) + 1] = temporary;
						current = (current << 1) + 1;
					}
					else {
						break;
					}
				}
			}
			else {
				if (leftValue > maxHeap->maxHeap[current]) {
					int temporary = maxHeap->maxHeap[current];
					maxHeap->maxHeap[current] = maxHeap->maxHeap[(current << 1) + 1];
					maxHeap->maxHeap[(current << 1) + 1] = temporary;
				}
				break;
			}
		}
		else {
			break;
		}
	}
	return result;
}

void destoryMaxHeap(struct MaxHeap* maxHeap) {
	if (NULL == maxHeap) {
		return;
	}
	if (NULL == maxHeap->maxHeap) {
		return;
	}
	free(maxHeap->maxHeap);
}

void displayMaxHeap(struct MaxHeap* maxHeap) {
	if (isEmptyMinHeap(maxHeap)) {
		printf("\nEmpty MinHeap.\n");
		return;
	}
	printf("\nLength: %d\n", maxHeap->tail);
	printf("\nSize: %d\n", maxHeap->size);
	int cursor = 0;
	for (; cursor < maxHeap->tail; cursor++) {
		printf("%d ", maxHeap->maxHeap[cursor]);
	}
	printf("\n");
}

void testMaxHeap() {
	struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
	initMaxHeap(maxHeap);
	int cursor = 0;
	for (; cursor < 33; cursor++) {
		pushMaxHeap(maxHeap, 100 - cursor);
		displayMaxHeap(maxHeap);
	}
	displayMaxHeap(maxHeap);
	for (; cursor > 0; cursor--) {
		printf("%d ", popMaxHeap(maxHeap));
		displayMaxHeap(maxHeap);
	}
	destoryMaxHeap(maxHeap);
	free(maxHeap);
	printf("\n--");
}
