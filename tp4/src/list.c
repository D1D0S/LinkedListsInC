/**************************************************************************
 * L3Informatique						C/Unix
 * 			TP linked lists
 *
 * Group 	:G3.1
 * Name 1 :Didier
 * Name 2 :Kadiatou
 *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * SYNOPSYS    :
 *   list_elem_t * create_element(int value)
 * DESCRIPTION :
 *   creates a new element, whose field next is initialized with NULL and the field
 *   value is initialized with the integer passed as argument.
 * PARAMETERS :
 *   value : value of the element
 * RESULT :
 *   NULL in case of error, otherwise a pointer over one strusture of type list_elem_t
 */
static list_elem_t *
create_element (int value)
{
  list_elem_t * newelt = malloc (sizeof (list_elem_t));
  if (newelt != NULL) {
    newelt->value = value;
    newelt->next = NULL;
  }
  return newelt;
}

/*
 * SYNOPSYS :
 *   int insert_head(list_elem_t * * l, int value)
 * DESCRIPTION :
 *   Insert an element at the head of the list
 *   *l points the new head of the list.
 * PARAMETERS :
 *   list_elem_t ** l : pointer to the pointer of the head of the list
t tail (list elem t * * l, int val) : ins`ere un ´el´ement `a la fin de la liste (* l pointe
vers la tˆete *   int value : value of the element that is added
 * RESULT :
 *    0 in case of successful insertion
 *   -1 if the insertion is impossible
 */
int
insert_head (list_elem_t * * l, int value)
{
  if (l == NULL) { return -1; }
  list_elem_t * new_elt = create_element (value);
  if (new_elt == NULL) { return -1; }

  new_elt->next = *l;
  *l = new_elt;
  return 0;
}

/*
 * SYNOPSYS :
 *   int insert_tail(list_elem_t * * l, int value)
 * DESCRIPTION :
 *   Insert an element at the tail of the list (* l points the head of the list)
 * PARAMETERS :
 *   list_elem_t ** l : pointer to the pointer of the head of the list
 *   int value : value of the element that is added
 * RESULT :
 *    0 in case of successful insertion
 *   -1 if the insertion is impossible
 */
int
insert_tail(list_elem_t * * l, int value) {
  // TO BE COMPLETED
  list_elem_t *newelement;
  list_elem_t *current;
  newelement = create_element(val);
 if(newelement==NULL){
	return -1;
  }
 if(*l==NULL){
	*l=newelement;
	return 0;
  }
 current= *l;
 while(current->next!=NULL){
	current=current->next;
 }
 current->next=newelement;
 return 0;
}
/*
 * SYNOPSYS :
 *   list_elem_t * find_element(list_elem_t * l, int index)
 * DESCRIPTION :
 *   Return a pointer of the element at the position n°i of the list
 *   (The first element is situated at the position 0).
 * PARAMETERS :
 *   int index : position of the element to be found
 *   list_elem_t * l : pointer of the head of the list
 * RESULTAT :
 *   - a pointer to the element of the list in cas of success
 *   - NULL in case of error
 */
list_elem_t *
find_element(list_elem_t * l, int index) {
  // TO BE COMPLETED
list_elem_t *current=l;
int i(0);
if(l==NULL || index<0){
	return NULL;
}
while(current!=NULL){
	if(i=index){
		return current;
	}
	current=current->next();
	i++;
}
 return NULL
}

/*
 * SYNOPSYS :
 *   int remove_element(list_elem_t * * ppl, int value)
 * DESCRIPTION :
 *   Removes from the list the first element with a value equal to the argument value and 
 *   frees the memory space reserved by this element.
 *   Attention : Depending on the position, the head of the list may need to be modified
 * PARAMETERS :
 *   list_elem_t ** ppl : pointer to the pointer of the head of the list
 *   int value  : value to be removed from the list
 * RESULT :
 *    0 in case of success
 *   -1 in case of error
 */
int
remove_element(list_elem_t * * ppl, int value) {
  // TO BE COMPLETED
  return -1;
}


/*
 * SYNOPSYS :
 *   void reverse_list(list_elem_t * * l)
 * DESCRIPTION :
 *   Modifies the list by inversing the order of the elements.
 *   So the 1st element becomes the last element, the 2nd becomes the before last element, etc.)
 * PARAMETRES :
 *   list_elem_t ** l : pointer to the pointer of the head of the list
 * RESULTAT :
 *   aucun 
 */
void
reverse_list(list_elem_t * * l) {
  // TO BE COMPLETED
}

/*
 * SYNOPSYS :
 *   void erase_list(list_elem_t * * ppl)
 * DESCRIPTION :
 *   Before exiting the program, it erases the elements of the list 
 * PARAMETRES :
 *   list_elem_t ** l : pointer to the pointer of the head of the list
 * RESULTAT :
 *   aucun 
 */
void
erase_list(list_elem_t * * ppl) {
  // TO BE COMPLETED

}

