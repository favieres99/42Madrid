/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:33:25 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 16:42:07 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_home_sign(t_struct *xpt, t_token *tk)
{
	char	*extend;

	tk->new = ft_substr(xpt->line, tk->init, tk->len - 1);
	tk->end = ft_strjoin(tk->end, tk->new);
	free(tk->new);
	extend = xpt->home;
	tk->end = ft_strjoin(tk->end, extend);
	tk->i++;
	tk->len = 1;
	tk->init = tk->i;
}

void	get_dollar_sign(t_struct *xpt, t_token *tk)
{
	char	*extend;
	char	*n_env;

	tk->new = ft_substr(xpt->line, tk->init, tk->len - 1);
	tk->end = ft_strjoin(tk->end, tk->new);
	free (tk->new);
	tk->posic = tokenizer_find_char(&xpt->line[tk->i + 1], ' ');
	n_env = ft_substr(xpt->line, tk->i + 1, tk->posic);
	if (xpt->line[tk->i + 1] != '?' && find_env(xpt, n_env))
		extend = ft_strdup(find_env(xpt, n_env));
	else if (xpt->line[tk->i + 1] == '?')
		extend = ft_itoa(xpt->ret_number);
	else
		extend = NULL;
	if (extend)
		tk->end = ft_strjoin(tk->end, extend);
	free(extend);
	tk->i += ft_strlen(n_env) + 1;
	free (n_env);
	tk->len = 1;
	tk->init = tk->i;
}

t_token	*init_tk(void)
{
	t_token	*tk;

	tk = (t_token *)malloc(sizeof(t_token));
	tk->end = NULL;
	tk->new = NULL;
	tk->to_exec = NULL;
	tk->to_print = NULL;
	tk->quote = '\0';
	tk->i = 0;
	tk->init = 0;
	tk->len = 1;
	tk->posic = 0;
	return (tk);
}

void	free_tk(t_token *tk)
{
	if (tk->end != NULL)
	{
		free(tk->end);
		tk->end = NULL;
	}
	if (tk->new != NULL)
	{
		free(tk->new);
		tk->new = NULL;
	}
	if (tk->to_exec != NULL)
	{
		free(tk->to_exec);
		tk->to_exec = NULL;
	}
	if (tk->to_print != NULL)
	{
		free(tk->to_print);
		tk->to_print = NULL;
	}
	free(tk);
}

void	finish_tokenizer(t_struct *xpt, t_token *tk)
{
	tk->new = ft_substr(xpt->line, tk->init, tk->len);
	tk->end = ft_strjoin(tk->end, tk->new);
	tk->posic = tokenizer_find_char(tk->end, ' ');
	xpt->token.to_print = ft_strtrim(&(tk->end)[tk->posic], " ");
	xpt->token.to_exec = ft_substr(tk->end, tk->i + 1, tk->posic);
	tokenizer_clean_quotes(xpt, xpt->token.to_print, 0, 0);
	xpt->tokens = ft_split(tk->end, ' ');
	free_tk(tk);
	free (xpt->line);
}
