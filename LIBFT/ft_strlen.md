# STRLEN-Libft
## code
```
#include "libft.h"

size_t ft_strlen(const char *s)
{
	size_t i;
	
	i = 0;
	if (s == NULL)
		return 0;
	while(s[i] != '\0')
		i++;
	return i;
}
```
## Problemas encontrados 
- size_t no enxiste en por defecto hay que importarlo desde `#include <stddef.h>`  que lo que hace es que el entero maximo positivo sea mayor ya que solo es positivo 
- Si es NULL nos produce un segmentation faul por lo que hay que hay que hacer que si es NULL que retorne 0 para que no haga nada

## Explicacion del codigo
incluios la libreria libft.h que es la que llama a `#include <stddef.h>` luego llamamos a la funcion y declaramos un contador con size_t luego o del null y un while en el que recorremos s con el untero i y al final retornamos i como resultado