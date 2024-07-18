#include "libft.h" 

#include <string.h>

//PARA COMPILAR
//gcc main.c -L. -lft && ./a.out 
int main()
{
/*     //isalpha
    char i = 'a';
    char o = '7';
    int result = ft_isalpha(i);
    if(result == 0)
        printf("si\n");
    else
        printf("no\n");
    result = ft_isalpha(o);
    if(result == 0)
        printf("si\n");
    else
        printf("no\n");
    return(0); */


    //FDS
/*     #include <fcntl.h> */
    /* int fd = open("text",O_WRONLY);
    printf("FD=%i\n",fd);

 */
/*     //ft_putchar_fd
    ft_putchar_fd('a',fd);
    printf("\n");
    //ft_putstr_fd
    char *s = "pepe";
    ft_putstr_fd(s,fd);
    //ft_putendl_fd
    char *z = "jose";
    ft_putendl_fd(z,fd);
    ft_putendl_fd(z,fd);
    //ft_putnbr_fd */
    
    //ft_putnbr_fd(777,1);  

/* 
    strlcat
	char *dest;
	size_t cont;

	dest = malloc(sizeof(char)* 50);
	if (dest == NULL)
		return 1;
	ft_strlcpy(dest, "rrrrrr", 15);
	cont = ft_strlcat(dest, "lorem ipsum dolor sit amet", 1);
	printf("%zu - %s\n", cont, dest);

	ft_strlcpy(dest, "rrrrrr", 15);
	cont = strlcat(dest, "lorem ipsum dolor sit amet", 1);
	printf("%zu - %s\n", cont, dest);
 */
/* 
    char *s1 = "hola";
    char *s2 = " buenos dias";
    
    s1 = ft_strjoin( s1,  s2);
    printf("%s", s1);
 */
    /* char *c = "                  olol"; */
    int i = -1;
    char **split = ft_split("                  olol", ' ');
    
    while(split[++i])
        printf("%s",split[i]);

    return 0;

}