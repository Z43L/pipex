#include "pipex.h"
int ft_init_pipex(t_pipex *pipex, int argc, char **argv)
{
    int i;

    i = 0;
    int fd = open(argv[2], O_RDONLY);
    
    pipex->cmd = ft_split(argv[2], ' ');
    pipex->infile = argv[1];
    pipex->outfile = argv[4];
    pipex->env = ft_split("/home/davmoren/bin:/home/davmoren/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", ':');
    while(pipex->env[i])
    {
        char *comando = ft_strjoin(pipex->env, "/");
        comando = ft_strjoin(comando, pipex->cmd);
        i++;
    }
    if (pipex->cmd == NULL || pipex->env == NULL)
        return (-1);
    if (argc == 6)
        pipex->env = ft_split(argv[5], ':');
    if (pipex->env == NULL)
        return (-1);
    return (0);
}

int ft_pipe(t_pipex *pipex)
{
    int pid;
    int status;
    if (pipe(pipex->fd) == -1)
        return (-1);
    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0)
    {
        pipex->in = open(pipex->infile, O_RDONLY);
        if (pipex->in == -1)
            return (-1);
        dup2(pipex->in, STDIN_FILENO);
        dup2(pipex->fd[1], STDOUT_FILENO);
        close(pipex->fd[1]);
        close(pipex->fd[0]);
        execve(pipex->cmd[0], pipex->cmd, pipex->env);
        perror("execve");
        close(pipex->in);
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
        close(pipex->fd[1]);
        pipex->out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (pipex->out == -1)
            return (-1);
        dup2(pipex->fd[0], STDIN_FILENO);
        dup2(pipex->out, STDOUT_FILENO);
        execve(pipex->cmd[0], pipex->cmd, pipex->env);
        perror("execve");
        close(pipex->out);
        exit(EXIT_FAILURE);
    }
    return (0);
}

int ft_error(char *str)
{
    ft_putstr_fd(str, 2);
    return (-1);
}

int main(int argc, char **argv)
{
    t_pipex pipex;

    if (argc != 4)
        return (ft_error("Error: Invalid number of arguments\n"));
    if (ft_init_pipex(&pipex, argc, argv) == -1)
        return (ft_error("Error: Invalid arguments\n"));
    if (ft_pipe(&pipex) == -1)
        return (ft_error("Error: Pipe failed\n"));

    return (0);
}