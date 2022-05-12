/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:31:20 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 16:42:23 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	fixing_for_norminette(t_struct *xpt, char c, char *aux, int nbr)
{
	if (xpt->token.quote == 0 && (c == QUOTE || c == D_QUOTE))
		xpt->token.quote = c;
	else
	{
		if (xpt->token.quote == c)
			xpt->token.quote = 0;
		else
		{
			aux[nbr] = c;
			nbr++;
		}
	}
	return (nbr);
}

int	tokenizer_find_char(char *string, char needle)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == needle || string[i] == D_QUOTE || string[i] == QUOTE)
			return (i);
		if (string[i] == '?')
			return (i + 1);
		i++;
	}
	return (i);
}

void	tokenizer_clean_quotes(t_struct *xpt, char *in, int i, int c)
{
	char	*aux;

	xpt->token.quote = 0;
	aux = ft_strtrim(in, " ");
	xpt->has_flag = false;
	if (in[0] == '-' && in[1] == 'n')
	{
		xpt->has_flag = true;
		i += 2;
	}
	while (in[i] == ' ')
		i++;
	while (in[i])
	{
		c = fixing_for_norminette(xpt, in[i], aux, c);
		i++;
	}
	aux[c] = '\0';
	free(xpt->token.to_print);
	xpt->token.to_print = aux;
}

void	tokenizer(t_struct *xpt)
{
	t_token	*tk;

	tk = init_tk();
	xpt->token.quote = 0;
	tk->end = ft_strdup("");
	if (xpt->line)
	{
		while ((int)ft_strlen(xpt->line) > tk->i)
		{
			if (xpt->token.quote == 0 && (xpt->line[tk->i] == QUOTE))
				xpt->token.quote = xpt->line[tk->i];
			else
			{
				if (xpt->token.quote == xpt->line[tk->i])
					xpt->token.quote = 0;
				if (xpt->line[tk->i] == '~' && xpt->token.quote == 0)
					get_home_sign(xpt, tk);
				else if (xpt->line[tk->i] == '$' && xpt->token.quote == 0)
					get_dollar_sign(xpt, tk);
			}
			tk->len++;
			tk->i++;
		}
		finish_tokenizer(xpt, tk);
	}
}
