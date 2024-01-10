/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nosilvesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandebr <brandebr@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:24:08 by brandebr          #+#    #+#             */
/*   Updated: 2023/11/29 13:05:20 by brandebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//contar paraules DONE
//malloc grande DONEtte
//malloc chiquitico donettes
//copiar paraules en cada malloc donettes
//'\0' al ultim malloc
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int		vale(char c)
{
		if (c > 32 && c < 127)
				return (1);
		return (0);
}

int		word_cunt(char *str)
{
		int		i;
		int		wds;

		i = 0;
		wds = 0;
		while (str[i])
		{
				if ((i == 0 && vale(str[i])) || (i > 0 &&  (!vale(str[i -1]) && vale(str[i]))))
						wds++;
				i++;
		}
		return (wds);
}

int		wdlen(int i, char *s)
{
		while (s[i] && vale(s[i]))
				i++;
		return (i);

}

void	ft_substr(char *willy, char *s, int start, int end)
{
		int		i;
		printf("substr\n");
		i = 0;
		while (start <= end)
		{
				willy[i] = s[start];
				i++;
				start++;
		}
		willy[i] = '\0';
}

char    **flit(char *str)
{
		int		wc;
		int		wl;
		char	**words;
		int		i;
		int		j;

		wc = word_cunt(str);
		i = 0;
		j = 0;
		words = malloc(sizeof(char *) * (wc + 1));
		if (!words)
				return (NULL);
		while (str[i])
		{
				if ((i == 0 && vale(str[i])) || (i > 0 &&  (!vale(str[i -1]) && vale(str[i]))))
				{
						printf("0\n");
						wl = wdlen(i, str);
						words[j] = malloc(sizeof(char) * (wl + 1  -i));
						if (!words[j])//falta liberar malloc
								return (0);
						printf("1\n");
						ft_substr(words[j] ,str, i, wl);
						printf("%s\n", words[j]);
						j++;
				}
				i++;
		}
		printf("cierro en %d\n", j);
		words[j] = NULL;
		return (words);
}
/*
int main(void)
{
		int		idx;
		char	**tab;

		idx = 0;
		tab = flit("The prophecy is true");
		printf("back to main\n");
		while (tab[idx])
		{
				printf("String %d : %s\n", idx, tab[idx]);
				idx++;
		}
		printf("\n");
		return(0);
}*/
// https://github.com/ComlanGiovanni/42-Exam-Rank-02/blob/main/Level/Level%204/ft_split/ft_split.c
// https://github.com/pasqualerossi/42-School-Exam-Rank-02/blob/main/Level%202/ft_strrev/ft_strrev.c
