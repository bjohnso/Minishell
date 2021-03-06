/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nullfinder <mail.brandonj@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:37:16 by Nullfinder        #+#    #+#             */
/*   Updated: 2020/01/14 15:42:08 by Nullfinder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

/*
**Constructor
*/

t_shell			*new_shell(char *alias)
{
	extern char		**environ;
	t_shell			*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	shell->alias = alias;
	shell->dir = (char**)malloc(sizeof(char *) * 3);
	shell->dir[2] = NULL;
	shell->dir[1] = NULL;
	shell->dir[0] = getcwd(NULL, 0);
	shell->exit = false;
	shell->debug = false;
	shell->environ = environ_init(environ);
	return (shell);
}

void			shell_destroy(t_shell *shell)
{
	size_t		c;

	c = -1;
	if (shell->environ)
	{
		while (++c < ft_sstrlen(shell->environ))
			if (shell->environ[c])
				free(shell->environ[c]);
		free(shell->environ);
	}
	if (shell->dir)
	{
		c = -1;
		while (++c < ft_sstrlen(shell->dir))
			if (shell->dir[c])
				free(shell->dir[c]);
		free(shell->dir);
	}
	free(shell);
}

/*
**Directory
*/

char			*file_search(char *dir, char *alias)
{
	char	*file;

	file = build_file_path(dir, alias);
	if (file)
	{
		if (access(file, F_OK) == 0)
			return (file);
	}
	free(file);
	return (NULL);
}

char			*build_file_path(char *dir, char *alias)
{
	size_t		len;
	size_t		counter;
	char		*file;

	len = build_file_path_init(dir, alias);
	counter = -1;
	file = (char *)malloc(sizeof(char) * (len + 1));
	while (++counter <= len)
	{
		if (counter < ft_strlen(dir))
			file[counter] = dir[counter];
		else
		{
			if (dir[ft_strlen(dir) - 1] != '/' && counter == ft_strlen(dir))
				file[counter] = '/';
			else
			{
				if (dir[ft_strlen(dir) - 1] != '/')
					file[counter] = alias[counter - ft_strlen(dir) - 1];
				else
					file[counter] = alias[counter - ft_strlen(dir)];
			}
		}
	}
	return (file);
}

size_t			build_file_path_init(char *dir, char *alias)
{
	size_t		len;

	len = ft_strlen(dir) + ft_strlen(alias);
	if (dir[ft_strlen(dir) - 1] != '/')
		len++;
	return (len);
}
