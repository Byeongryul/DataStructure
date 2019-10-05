#ifndef QUIZ_H
#define QUIZ_H
#include "Tree.h"

#define NUM_RANGE_MAX 9
#define NUM_RANGE_MIN 0

//MAX_INPUT <= NUM_RANGE_MAX - NUM_RANGE_MIN + 1
#define MAX_INPUT 10
//MAX_OUTPUT <= MAX_INPUT
#define MAX_OUTPUT 3

bool define_is_ok();

void insert_tree(Node **root);

void delete_tree(Node **root);

#endif
