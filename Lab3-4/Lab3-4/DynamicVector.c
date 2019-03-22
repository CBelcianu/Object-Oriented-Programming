#include "DynamicVector.h"
#include <stdlib.h>

DynamicVector* createDynamicVector(int capac, int(*cmp)(TElem, TElem), void(*distr)(TElem))
{
	DynamicVector* vd = (DynamicVector*)malloc(sizeof(DynamicVector));
	vd->dim = 0;
	vd->capac = capac;
	vd->cmp = cmp;
	vd->distr = distr;
	vd->elems = (TElem*)malloc(sizeof(TElem)*vd->capac);
	return vd;
}

void resize(DynamicVector* vd) 
{
	int ncapac = vd->capac * 2;
	TElem* nelems = (TElem*)malloc(sizeof(TElem)*ncapac);
	int i = 0;
	for (; i < vd->dim; i++)
		nelems[i] = vd->elems[i];
	free(vd->elems);
	vd->elems = nelems;
	vd->capac = ncapac;
}

void addV(DynamicVector* vd, TElem el)
{
	if (vd->capac == vd->dim)
		resize(vd);
	vd->elems[vd->dim] = el;
	vd->dim++;
}

TElem delV(DynamicVector* vd, TElem el)
{
	int pos = searchV(vd, el);
	if (pos >= 0) 
	{
		int i = pos;
		TElem e = vd->elems[pos];
		for (; i < vd->dim - 1; i++)
			vd->elems[i] = vd->elems[i + 1];
		vd->dim--;
		return e;
	}
	return NULL;
}

int searchV(DynamicVector* vd, TElem el)
{
	int i = 0;
	for (; i < vd->dim; i++)
	{
		if (vd->cmp(vd->elems[i], el) == 0)
			return i;
	}
	return -1;
}

void destroyDynamicVector(DynamicVector* vd)
{
	free(vd->elems);
	free(vd);
}