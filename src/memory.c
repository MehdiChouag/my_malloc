/*
** memory.c for memory.c in /home/chouag_m/rendu/PSU_2013_malloc/test
** 
** Made by Mehdi Chouag
** Login   <chouag_m@epitech.net>
** 
** Started on  Fri Feb 14 21:46:25 2014 Mehdi Chouag
** Last update Sat Feb 15 18:08:54 2014 Mehdi Chouag
*/

#include "malloc.h"

extern t_ptr		*list;
extern void		*start;
extern void		*end;

void	        clear_memory()
{
  t_ptr		*tmp = list;
  int		i = 0;
  int		is_free = 0;

  while (tmp != NULL)
    {
      if (tmp->ok == '0')
	is_free++;
      i++;
      tmp = tmp->next;
    }
  if (is_free == i)
    {
      tmp = list;
      while (tmp != NULL)
	{
	  list = supprimerElement(list, tmp->ptr);
	  tmp = tmp->next;
	}
      brk(start);
      end = sbrk(0);
    }
}

void		check_last_element(void *ptr)
{
  t_ptr		*tmp = list;
  int		i = 0;

  while (tmp != NULL)
    {
      if (tmp->ptr == ptr && tmp->next == NULL)
	{
	  list = supprimerElement(list, ptr);
	  i++;
	}
      tmp = tmp->next;
    }
  if (i == 1)
    {
      brk(ptr);
      end = sbrk(0);
    }
}

size_t          found_size(void *ptr)
{
  t_ptr        *tmp = list;

  while (tmp != NULL)
   {
      if (ptr == tmp->ptr)
        return (tmp->size);
      tmp = tmp->next;
    }
  return (0);
}

void            show_alloc_mem()
{
  t_ptr        *tmp;

  tmp = list;
  if (tmp == NULL)
    write(1, "No memory allocated\n", 20);
  while (tmp != NULL)
    {
      printf("%p - %p : %ld octets\n",tmp->ptr, tmp->ptr + tmp->psize, tmp->psize);
      tmp = tmp->next;
    }
}

int		verif_if_place(void *ptr, size_t size)
{
  t_ptr        *tmp = list;

  while (tmp != NULL)
   {
      if (ptr == tmp->ptr)
	if (tmp->size >= size)
	  return (1);
      tmp = tmp->next;
    }
  return (0);
}
