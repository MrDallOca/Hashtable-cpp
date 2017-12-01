#ifndef ARVORE
#define ARVORE

#include <stdlib.h>
#include <string>
#include <iostream>
#include "IHashble.h"

#define max(n1,n2) (n1 > n2 ? n1 : n2)
#define height(n) (n == NULL ? 0 : n->h)
#define bf(n) (height(n->l) - height(n->r))

using namespace std;

class Arvore {

	struct NodeA {
		IHashble* info;
		NodeA *l;
		NodeA *r;
		NodeA *p;

		unsigned int h;
	};
public:
	Arvore();
	~Arvore();
	void arvore_Destrutor(struct NodeA* raiz);
	Arvore(const Arvore *a);
	unsigned int getCount() const;
	unsigned int getInd() const;
	unsigned int getHeight() const;
	IHashble** getElements();
	IHashble* get(IHashble* o) const;

	void insert(IHashble* o);
	void remove(IHashble* o);


	int remove_Node(NodeA *raiz, IHashble* o) {
		if (raiz == NULL)
			return 0;
		int res;
		if (o->hashcode() < raiz->info->hashcode())
		{
			if ((res = remove_Node(raiz->l, o)) == 1) {
				raiz->h = max(height(raiz->l), height(raiz->r)) + 1;
				int befao = bf(raiz);
				if (befao < -1)
				{
					if (height(raiz->r->l) <= height(raiz->r->r))
						rotateLeft(raiz);
					else
					{
						rotateRight(raiz->r);
						rotateLeft(raiz);
					}
				}
			}

		}

		if (o->hashcode() > raiz->info->hashcode())
		{
			if ((res = remove_Node(raiz->r, o)) == 1) {
				raiz->h = max(height(raiz->l), height(raiz->r)) + 1;
				int befao = bf(raiz);
				if (befao > 1)
				{
					if (height(raiz->l->r) <= height(raiz->l->l))
						rotateLeft(raiz);
					else
					{
						rotateRight(raiz->r);
						rotateLeft(raiz);
					}
				}
			}
		}

		if (raiz->info->hashcode() == o->hashcode())
		{
			if (raiz->l == NULL || raiz->r == NULL)
			{
				struct NodeA *old = raiz;
				if (raiz->l != NULL)
					raiz = raiz->l;
				else
				{
					NodeA* pai = raiz->p;
					raiz = raiz->r;
					if (raiz != NULL)
					{
						raiz->h = max(height(raiz->l), height(raiz->r)) + 1;
						raiz->p = pai;
					}
				}

				freeNode(old, raiz);

			}
			else
			{
				struct NodeA *no1 = raiz->r;
				struct NodeA *no2 = raiz->r->l;
				while (no2 != NULL) {
					no1 = no2;
					no2 = no2->l;
				}
				struct NodeA* temp = no1;
				raiz->info = temp->info;
				remove_Node(raiz->r, temp->info);
				int befao = bf(raiz);
				if (befao > 1)
				{
					if (height(raiz->l->r) <= height(raiz->l->l))
						rotateRight(raiz);
					else
					{
						rotateLeft(raiz->l);
						rotateRight(raiz);
					}
				}
				raiz->h = max(height(raiz->l), height(raiz->r)) + 1;
			}
			return 1;
		}
		return res;
	}
	std::string toString() const;
	NodeA *root;

protected:

	unsigned int count;
	unsigned int ind;
	std::string toStringAux(const NodeA *no) const;
	void getElementsAux(const NodeA* no, IHashble** aux);
	void rotateLeft(NodeA *x);
	void rotateRight(NodeA *y);
	void copyNode(NodeA *n1, NodeA *n2);
	void freeNode(NodeA *n1, NodeA* noR);
};

#endif
