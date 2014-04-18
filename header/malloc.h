/*
** malloc.h for malloc.h in /home/chouag_m/rendu/PSU_2013_malloc/test
** 
** Made by Mehdi Chouag
** Login   <chouag_m@epitech.net>
** 
** Started on  Fri Feb 14 21:30:18 2014 Mehdi Chouag
** Last update Sat Feb 15 18:05:11 2014 Mehdi Chouag
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_ptr
{
  char		ok;
  size_t	size;
  size_t	psize;
  void		*ptr;
  struct s_ptr	*next;
}		t_ptr;

void		*malloc(size_t size);
void		free(void *ptr);
void		*realloc(void *ptr, size_t size);
void		*get_place(size_t size);
t_ptr		*supprimerElement(t_ptr *liste, void *valeur);
int             my_put_bot_list(void *ptr, size_t size);
void		modif_list(void *ptr, size_t size);
int		modif_list2(void *ptr);
int             verif_if_place(void *ptr, size_t size);
void	        clear_memory();
void		check_last_element(void *ptr);
size_t          found_size(void *ptr);
void            show_alloc_mem();
int		verif_if_place(void *ptr, size_t size);
void		*put_memory(void *ptr, size_t size);

#endif /* !MALLOC_H_ */
