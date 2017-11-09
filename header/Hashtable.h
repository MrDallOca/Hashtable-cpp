#ifndef HASHTABLE
#define HASHTABLE

#include "Arvore.h"
#include "IHashble.h"

using namespace std;

class Hashtable{

 public:
	 Hashtable();
	 Hashtable(	unsigned int initial_length,
					unsigned int initial_growth_rate,
					unsigned int initial_max_occupation_rate,
					unsigned int initial_max_tree_size,
					unsigned int initial_max_exceeded_trees);
	 ~Hashtable();
	 
	 void insert();
	 IHashble* get();
	 char remove(IHashble* o);

 private:
	 unsigned int length; //vector length
	 unsigned int count;  //quantity of elements inside the list
	 
	 unsigned int growth_rate; //list percentage of growing when needed
	 unsigned int max_occupation_rate;//max rate of occupied positions in the list
	 unsigned int max_tree_size;//max number of elements inside a tree
	 unsigned int max_exceeded_trees;//max number of trees that exceed the max_tree_size
	 
	 Arvore<IHashble*>* the_array;//array of trees that represents the hashtable
};

#endif //HASHTABLE
