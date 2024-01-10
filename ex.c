/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:24:04 by brandebr          #+#    #+#             */
/*   Updated: 2023/12/14 14:28:33 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		len(int nbr)
{
		int		i;

		i = 0;
		if (nbr == -2147483648)
				return (11);
		if (nbr < 0)
		{
				i++;
				nbr *= -1;
		}
		while (nbr > 0)
		{
				nbr /= 10;
				i++;
		}
		return (i);
}

char	*ft_itoa(int nbr)
{
		char	*res;
		int		length;

		length =  len(nbr);
		res = malloc(sizeof(char) * (length + 1));
		if (!res)
				free(res);
		res[length] = '\0';
		length--;
		if (nbr == -2147483648)
		{
				res = "-2147483648";
				return (res);
		}
		if (nbr < 0)
		{
				res[0] = '-';
				nbr *= -1;
		}
		while (nbr > 9)
		{
				res[length] = (nbr % 10) + '0';
				nbr /= 10;
				length--;
		}
		res[length] = (nbr % 10) + '0';
		return (res);


}
int		 fprime(int	n)
{
		int		i;

		i = 2;
		if (n == 1)
		{
				printf("1");
				return (0);
		}
		while (i <= n)
		{
				if (i == n)
				{
						printf("%i", i);
						return (0);
				}
				if (n % i == 0)
				{
						printf("%i", i);
						printf("*");
						n /= i;
						i = 1;					
				}
				i++;
		}
		return (0);
}

int		ok(char c)
{
		if (c > ' ' && c < 127)
				return (1);
		return (0);
}

void	rev_wstr(char *str)
{
		int		i;
		int		start;
		int		end;
		int		wc;

		i = 0;
		wc = 0;
		while (str[i])
		{
				if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i - 1])))
						wc++;
				i++;
		}
		i--;
		while (i >= 0)
		{
				if ((ok(str[i]) && str[i + 1] == '\0') || (!ok(str[i + 1]) && ok(str[i])))
				{
						end = i;
						start = end;
						while (ok(str[start]))
								start--;
						start++;
						while (start <= end)
						{
								printf("%c", str[start]);
								start++;
						}
						wc--;
						if (wc > 0)
								printf(" ");
				}
				i--;
		}
}

int		main(int argc, char **argv)
{
	//	char *res = NULL;
		if (argc == 2)
		{
		//		int		number = atoi(argv[1]);
		//		res = ft_itoa(number);
		//		fprime(number);
		rev_wstr(argv[1]);
				printf("\n");
		//		printf("%s\n", res);
		}
		return (0);
}






























/*
typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
		int		swap;
		t_list	*start;

		start = lst;
		while (lst->next)
		{
				if ((*cmp)(lst->data, lst->next->data) == 0)
				{
						swap = lst->data;
						lst->data = lst->next->data;
						lst->next->data = swap;
						lst = start;
				}
				else
						lst = lst->next;
			}
	//	lst = start;
		return (lst);
}

int		cmp(int a, int b)
{
		if (a > b)
				return (0);
		return (1);
}

int		main(void)
{
		t_list	*lst; 
		t_list	*tmp;
		int		numb[] = {15, 13, 1, 16, 14, 3, 13};

		lst = malloc(sizeof(t_list));
		lst->data = numb[0];
		lst->next = malloc(sizeof(t_list));
		lst->next->data = numb[1];
		lst->next->next = malloc(sizeof(t_list));
		lst->next->next->data = numb[2];
		lst->next->next->next = malloc(sizeof(t_list));
		lst->next->next->next->data = numb[3];
		lst->next->next->next->next = malloc(sizeof(t_list));
		lst->next->next->next->next->data = numb[4];
		lst->next->next->next->next->next = malloc(sizeof(t_list));
		lst->next->next->next->next->next->data = numb[5];
		lst->next->next->next->next->next->next = malloc(sizeof(t_list));
		lst->next->next->next->next->next->next->data = numb[6];
		lst->next->next->next->next->next->next->next = NULL;
		tmp = lst;
		while (lst)
		{
				printf("%d\n", lst->data);
				lst = lst->next;
		}
		lst = tmp;
		sort_list(lst, cmp);
		while (lst)
		{
				printf("%d\n", lst->data);
				lst = lst->next;
		}
		return (0);
}
*/

/*
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
		int		counter;
		t_list	*aux;

		counter = 0;
		aux = begin_list;
		while (aux)
		{
				counter++;
				aux = aux->next;
		}
		return (counter);
}


int		main(void)
{
		t_list	*ls;
		int	data[] = {13 , 42, 13};

		ls = malloc(sizeof(t_list*));
		ls->data = &data[0];  
		ls->next = malloc(sizeof(t_list));
		ls->next->data = &data[1];
		ls->next->next = malloc(sizeof(t_list));
		ls->next->next->data = &data[2];
		printf("amount fo nodes: %i\n", ft_list_size(ls));
}
*/
/*
int		ok(char c)
{
		if (c != ' ' && c != '\t' && c != '\0' && c != '\n')
				return (1);
		return (0);
}

int		wc(char *s)
{
		int		i;
		int		ws;

		i = 0;
		ws = 0;
		while (s[i])
		{
				if ((i == 0 && ok(s[i]))  || (ok(s[i]) && !ok(s[i - 1])))
						ws++;
				i++;
		}
		return (ws);
}

char    **ft_split(char *str)
{
		char	**res;
		int		words;
		int		w;
		int		i;
		int		j;
		int		start;
		int		end;

		words = wc(str);
		w = 0;
		i = 0;
		res = (char **)malloc(sizeof(char *) * (words + 1));
		if (!res)
				free(res);
		while (w < words)
		{
				if ((i == 0 && ok(str[i])) || (ok(str[i]) && !ok(str[i - 1])))
				{
						j = 0;
						start = i;
						end = start;
						while (ok(str[end]))
								end++;
						res[w] = (char *)malloc(sizeof(char) * ((end - start) + 1));
						if (!res[w])
								free(res[w]);
						while (start < end)
						{
								res[w][j] = str[start];
								start++;
								j++;
						}
						res[w][j] = '\0';
						w++;								
				}
				i++;
		}
		res[words] = NULL;
		return (res);
}

int		length(int	nbr)
{
		int		len;

		len = 0;
		if (nbr == -2147483648)
				return (11);
		if (nbr < 0)
		{
				len++;
				nbr *= -1;
		}
		while (nbr > 0)
		{
				nbr /= 10;
				len++;
		}
		return (len);
}
char	*ft_itoa(int nbr)
{
		char	*res;
		int		len;

		len = length(nbr);
		res = malloc(sizeof(char) * (len + 1));
		if (!res)
				free(res);
		res[len] = '\0';
		if (nbr == -2147483648)
		{
				res = "-2147483648";
				return (res);
		}
		if (nbr < 0)
		{
				res[0] = '-';
				nbr = nbr * -1;
		}
		len--;
		while (nbr > 9)
		{
				res[len] = (nbr % 10) + '0';
				nbr /= 10;
				len--;
		}
		res[len] = (nbr % 10) + '0';
		return (res);
}

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
		t_list	*aux;

		aux = begin_list;
		while (aux)
		{
				(*f)(aux->data);
				aux = aux->next;
		}
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
		t_list	*aux;
		t_list	*del;
		t_list	*prev;

		aux = *begin_list;
		prev = NULL;
		while (aux)
		{
				if ((*cmp)(aux->data, data_ref) == 0)
				{
						del = aux;
						if (prev == NULL)
								*begin_list = aux->next;
						else
								prev->next = aux->next;
						aux = aux->next;
						free(del);
				}
				else
				{
						prev = aux;
						aux = aux->next;
				}
		}
}

int		cmp(void *one, void *two)
{
		int *a = (int *)one;
		int *b = (int *)two;
		return (*a - *b);
}

int		main(int argc, char **argv)
{
		char	*res;
		int		i;
		int		len;
		int		numb;
		i = 0;
		t_list	*lst;
		t_list	*ls;
		t_list	*au;
		int		numbs[] = {13, 13 ,12};
		int		delete = 13;

		lst = malloc(sizeof(t_list));
		lst->data = ("Follow ");
		lst->next = malloc(sizeof(t_list));
		lst->next->data = ("the white ");
		lst->next->next = malloc(sizeof(t_list));
		lst->next->next->data = ("Rabbi.");
		ft_list_foreach(lst, (void *)printf);	
		printf("\n");
		ls = malloc(sizeof(t_list));
		ls->data = &numbs[0];
		ls->next = malloc(sizeof(t_list));
		ls->next->data = &numbs[1];
		ls->next->next = malloc(sizeof(t_list));
		ls->next->next->data = &numbs[2];
		res = NULL;
		au = ls;
		while (ls)
		{
				printf("%d\n",*(int *)ls->data);
				ls = ls->next;
		}
		ls = au;
		ft_list_remove_if(&ls, &delete, cmp); 
		while (ls)
		{
				printf("%d\n",*(int *)ls->data);
			//	printf("%i\n", *((int *)(ls->data)));
				ls = ls->next;
		}
		if (argc == 2)
		{
				numb = atoi(argv[1]);
				len = length(numb);
				res = ft_itoa(numb);
				printf("stringed number: %s\n", res);
		}
		//		printf("amount of words: %i\n",wc(argv[1]));
		return (0);
}

*/
























/*
typedef struct    s_list // struct for the others
{
    struct s_list *next;
    void          *data;
}                 t_list;

int		comp(void *n1, void *n2)
{
		int *a = (int *)n1;
		int *b = (int *)n2;
		return (*a - *b);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
		t_list	*aux;
		t_list	*del;
		t_list	*prev;

		aux = *begin_list;
		prev = NULL;
		while (aux)
		{
				if ((*cmp)(aux->data, data_ref) == 0)
				{
						del = aux;
						if (prev == NULL)
								*begin_list = aux->next;
						else
								prev->next = aux->next;
						aux = aux->next;
						free(del);
				}
				else 
				{
						prev = aux;
						aux = aux->next;
				}
		}
		
}

int		main(void)
{
		t_list	*ls;
		int tbd = 13;
		int	data[] = {13 , 42, 13};

		ls = malloc(sizeof(t_list*));
		ls->data = &data[0];  
		ls->next = malloc(sizeof(t_list));
		ls->next->data = &data[1];
		ls->next->next = malloc(sizeof(t_list));
		ls->next->next->data = &data[2];
		ls->next->next->next = NULL;
		t_list	*temp;
		temp = ls;
		while (ls)
		{
				printf("%i\n", *((int*)(ls->data)));
				ls = ls->next;
		}
		ls = temp;
		ft_list_remove_if(&ls, &tbd, comp);
		printf("\n");	
		while (ls)
		{
				printf("%i\n", *((int *)(ls->data)));
				ls = ls->next;
		}
		printf("\n");
		return (0);
}*/
