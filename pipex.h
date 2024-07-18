#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "LIBFT/libft.h"
#include <fcntl.h>

//typedef struct s_pipex pipex;


typedef struct s_pipex
{
    char    **cmd;
    char    **env;
    char    *infile;
    char    *outfile;
    int     fd[2];
    int     in;
    int     out;

}   t_pipex;

#endif