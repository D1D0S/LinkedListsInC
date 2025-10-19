/**************************************************************************
 * L3Informatique						C/Unix
 * TP linked lists
 *
 * Group 	:
 * Name 1 :
 * Name 2 :
 *
 **************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "list.h"

/* Compute the number of elements of the list */
int
list_size(list_elem_t * p_list)
{
  int nb = 0;
  while (p_list != NULL) {
    nb += 1;
    p_list = p_list->next;
  }
  return nb;
}

/* Print the elements of the list */
void
print_list(list_elem_t* p_list) {
  list_elem_t * pl = p_list;
  printf("The list contains %d element(s)\n", list_size(p_list));
  while(pl != NULL) {
    printf("[%d]",pl->value);
    pl = pl->next;
    if (pl != NULL) {
      printf("->");
    }
  }
  printf("\n"); // Ajout d'un retour à la ligne pour la clarté
}

int
main(int argc, char **argv)
{
  list_elem_t * head = NULL;	// The pointer to the head of the list
  char menu[] =
    "\n Program of chained list \n"\
    "  'h/t' : Insert an element to the head/tail of the list\n"\
    "  'f'   : search of a list element\n"\
    "  's'   : suppression of a list element\n"\
    "  'r'   : reverse the order of the list elements\n"\
    "  'x'   : exit the program\n"\
    " What is your choice ?";
  int choice=0;				// choice from the menu
  int value=0;				// inserted value
  int pos=0;                    // position for find_element
  list_elem_t *found_elt = NULL; // pointeur pour find_element

  printf("%s",menu);
  fflush(stdout);

  while(1) {
    fflush(stdin);
    choice = getchar();
    printf("\n");

    switch(choice) {
    case 'H' :
    case 'h' :
      printf("Value of the new element ? ");
      scanf("%d",&value);
      if (insert_head(&head,value)!=0) {
	printf("Error : impossible to add the element %d\n",value);
      };
      break;

    case 'T' :
    case 't' :
      // ------------------------------------
      // COMPLÉTÉ : Insert at the tail
      printf("Value of the new element ? ");
      scanf("%d",&value);
      if (insert_tail(&head,value)!=0) {
	printf("Error : impossible to add the element %d at the tail\n",value);
      };
      // ------------------------------------
      break;


    case 'F' :
    case 'f' :
      // ------------------------------------
      // COMPLÉTÉ : Find element
      printf("Position of the element to find (0 is first) ? ");
      scanf("%d",&pos);
      found_elt = find_element(head, pos);
      if (found_elt != NULL) {
          printf("SUCCESS: Element at position %d found. Value = %d\n", pos, found_elt->value);
      } else {
          printf("ERROR: Element at position %d not found.\n", pos);
      }
      // ------------------------------------
      break;


    case 's' :
    case 'S' :
      // ------------------------------------
      // COMPLÉTÉ : Remove element
      printf("Value of the element to suppress ? ");
      scanf("%d",&value);
      if (remove_element(&head, value) == 0) {
	    printf("SUCCESS: Element with value %d suppressed.\n", value);
      } else {
	    printf("ERROR: Element with value %d not found in the list.\n", value);
      }
      // ------------------------------------
      break;


    case 'r' :
    case 'R' :
      // ------------------------------------
      // COMPLÉTÉ : Reverse list
      printf("Reversing the list order...\n");
      reverse_list(&head);
      // ------------------------------------
      break;


    case 'x' :
    case 'X' :
     // ------------------------------------
     // COMPLÉTÉ : Exit (needs to erase the list first to avoid memory leak)
      printf("Exiting program. Erasing list...\n");
      erase_list(&head);
      // ------------------------------------
      return 0;

    default:
      break;
    }
    print_list(head);

    getchar(); // to consume a return character and avoid double display of the menu
    printf("%s\n",menu);
  }
  return 0;
}