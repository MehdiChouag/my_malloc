/*
** function_list.c for function_list in /home/chouag_m/rendu/PSU_2013_malloc/test
** 
** Made by Mehdi Chouag
** Login   <chouag_m@epitech.net>
** 
** Started on  Fri Feb 14 21:33:10 2014 Mehdi Chouag
** Last update Sat Feb 15 17:13:28 2014 Mehdi Chouag
*/

#include "malloc.h"

extern t_ptr		*list;
extern void		*start;
extern void		*end;

t_ptr          *supprimerElement(t_ptr *liste, void *valeur)
{
  t_ptr        *tmp;

  if (liste == NULL)
    return (NULL);
  if (liste->ptr == valeur)
    {
      tmp = liste->next;
      liste -= sizeof(liste);
      tmp = supprimerElement(tmp, valeur);
      return (tmp);
    }
  else
    {
      liste->next = supprimerElement(liste->next, valeur);
      return (liste);
    }
}

int             my_put_bot_list(void *ptr, size_t size)
{
  t_ptr        *elem;
  t_ptr        *temp;

  elem = sbrk(sizeof(*elem));
  if (elem == NULL)
    return (-1);
  elem->ptr = ptr;
  elem->psize = size;
  elem->ok = '1';
  elem->size = size;
  elem->next = NULL;
  if (list == NULL)
    list = elem;
  else
    {
      temp = list;
      while(temp->next != NULL)
        temp = temp->next;
      temp->next = elem;
    }
  return (0);
}

void		*get_place(size_t size)
{
  t_ptr		*tmp = list;

  while (tmp != NULL)
    {
      if (tmp->psize >= size && tmp->ok == '0')
	return (tmp->ptr);
      tmp = tmp->next;
    }
  return (NULL);
}

void		modif_list(void *ptr, size_t size)
{
  t_ptr		*tmp = list;

  while (tmp != NULL)
    {
      if (tmp->ptr == ptr)
	{
	  tmp->psize = size;
	  tmp->ok = '1';
	}
      tmp = tmp->next;
    }
}

int		modif_list2(void *ptr)
{
  t_ptr		*tmp = list;

  while (tmp != NULL)
    {
      if (tmp->ptr == ptr)
	{
	  tmp->ok = '0';
	  return (tmp->size);
	}
      tmp = tmp->next;
    }
  return (0);
}
