#pragma once

typedef void* TElem;

typedef struct {
	int dim;
	int capac;
	TElem* elems;
	int(*cmp)(TElem, TElem);
	void(*distr)(TElem);
} DynamicVector;

DynamicVector* createDynamicVector(int capac, int(*cmp)(TElem, TElem), void(*distr)(TElem));

void addV(DynamicVector*, TElem);
TElem delV(DynamicVector*, TElem);
int searchV(DynamicVector*, TElem);
void destroyDynamicVector(DynamicVector*);