#include <stdio.h>
#include <stdlib.h>

/* Implements a linked list of integers

 A list is comprised of a single header and zero or more elements. The
 header contains pointers to the first and last elements in the list,
 or NULL if the list is empty. The first element contains a pointer to
 the next element, and so on. The last element in the list has its
 "next" pointer set to NULL.

 ** Global Precondition **

 Functions that operate on an existing list require a valid pointer to
 a list_t header as their first argument.
*/

#include "list.h"

list_t* list_create( void )
{
  list_t* l = malloc( sizeof(list_t) );
  if( l )
    {
      l->head = NULL;
      l->tail = NULL;
    }
  return l;
}

void list_destroy( list_t* list )
{
  element_t* el = list->head;
  while( el )
    {
      element_t* next = el->next;
      free( el );
      el = next;
    }      
  
  free( list );
}

element_t* element_create( int i )
{
  element_t* el = malloc( sizeof(element_t) );
  if( el )
    {
      el->val = i;
      el->next = NULL;
    }
  return el;
}

int list_append( list_t* list, int i )
{
  element_t* el = element_create( i );
  if( el == NULL )
    return 1;
 
  if( list->head == NULL )
    list->head = el;
  
  if( list->tail )
    list->tail->next = el;

  list->tail = el;
  return 0;
}

int list_prepend( list_t* list, int i )
{
  element_t* el = element_create( i );
  if( el == NULL )
    return 1;

  if( list->tail == NULL )
    list->tail = el;
  
  if( list->head )
    el->next = list->head;

  list->head = el;
  
  return 0;
}

element_t* list_index( list_t* list, unsigned int i )
{
  if( list->head == NULL )
    return NULL;
  
  element_t* el = list->head;
  unsigned int now = 0;
  
  while( now < i )
    {
      if( el->next == NULL )
	return NULL;

      now++;
      el = el->next;
    }     
  
  return el;
}

void list_print( list_t* list )
{
  printf( "{" );
  
  for( element_t* el = list->head;
       el;
       el = el->next )
    printf( " %d", el->val );

  printf( " }\n" );
}


