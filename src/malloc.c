/*
** main.c for  in /home/aube_a/Documents/projet/malloc
** 
** Made by Anthony Aube
** Login   <aube_a@epitech.net>
** 
** Started on  Thu Feb 13 22:15:49 2014 Anthony Aube
** Last update Sat Feb 15 18:09:30 2014 Mehdi Chouag
*/

#include "malloc.h"

t_ptr		*list = NULL;
void		*start = NULL;
void		*end = NULL;

void		*malloc(size_t size)
{
  void		*ptr;

  ptr = NULL;
  if ((int)size < 0)
    return (ptr);
  if (start == NULL)
    {
      start = sbrk(0);
      ptr = sbrk(size);
      my_put_bot_list(ptr, size);
      end = sbrk(0);
    }
  else
    ptr = put_memory(ptr, size);
  return (ptr);
}

void		free(void *ptr)
{
  if (ptr != NULL && list != NULL)
    {
      if (modif_list2(ptr) != 0)
      	check_last_element(ptr);
      clear_memory();
    }
  else if (list == NULL)
    {
      brk(start);
      end = sbrk(0);
    }
}

void		*realloc(void *ptr, size_t size)
{
  size_t	size_ptr;
  char		*tmp;
  char		*nptr;
  size_t	i = 0;

  if (ptr == NULL)
    return (malloc(size));
  else if (ptr != NULL && size == 0)
    free(ptr);
  else if (verif_if_place(ptr, size) == 1)
    return (ptr);
  else
    {
      size_ptr = found_size(ptr);
      tmp = ptr;
      nptr = malloc(size);
      while (i <= size && i <= size_ptr)
	{
	  *(nptr + i) = *(tmp + i);
	  i++;
	}
      free(ptr);
      return (nptr);
    }
  return (ptr);
}

void		*put_memory(void *ptr, size_t size)
{
  void		*tmp;

  tmp = get_place(size);
  if (tmp != NULL)
    {
      ptr = tmp;
      modif_list(ptr, size);
    }
  else
    {
      ptr = sbrk(size);
      my_put_bot_list(ptr, size);
      end = sbrk(0);
    }
  return (ptr);
}
