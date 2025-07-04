# Libft

## Tabla de Contenidos
- [Descripción](#descripción)
- [Funciones](#funciones)
- [Compilación](#compilación)
- [Pruebas](#pruebas)
- [Comprobación de Memoria con Valgrind](#comprobación-de-memoria-con-valgrind)

## Descripción

El proyecto `libft` es una implementación personal de una biblioteca C que recrea funciones estándar de la biblioteca de C, así como otras funciones de utilidad. El objetivo es comprender en profundidad cómo funcionan las funciones estándar de C implementándolas desde cero.

## Funciones

La biblioteca incluye las siguientes categorías de funciones:

1. Funciones de caracteres:
   - `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
   - `ft_toupper`, `ft_tolower`

2. Funciones de cadenas:
   - `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`
   - `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`
   - `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
   - `ft_strmapi`, `ft_striteri`

3. Funciones de memoria:
   - `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
   - `ft_memchr`, `ft_memcmp`, `ft_calloc`

4. Funciones de conversión:
   - `ft_atoi`, `ft_itoa`

5. Funciones de descriptor de archivo:
   - `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`



## Compilación

Para compilar la biblioteca, sigue estos pasos:

1. Clona el repositorio:
   ```bash
   git clone git@github.com:Iportill2/Libft.git
   cd libft
   ```

2. Compila la biblioteca:
   ```bash
   make
   ```
   Esto creará el archivo `libft.a`.



3. Para limpiar los archivos objeto:
   ```bash
   make clean
   ```

4. Para limpiar todos los archivos generados:
   ```bash
   make fclean
   ```

5. Para reconstruir la biblioteca:
   ```bash
   make re
   ```

## Pruebas

Se proporciona un archivo de prueba completo (`test.c`) para probar todas las funciones de la biblioteca.

1. Asegúrate de haber compilado la biblioteca primero:
   ```bash
   make
   ```

2. Compila el archivo de prueba con la biblioteca:
   ```bash
   gcc -Wall -Wextra -Werror test.c -L. -lft -o test_libft
   ```
   
   **¡Importante!** No olvides incluir `-L. -lft` para enlazar con tu biblioteca libft.a. 
   - `-L.` indica al compilador que busque bibliotecas en el directorio actual
   - `-lft` indica que enlace con la biblioteca `libft.a`

3. Ejecuta la prueba:
   ```bash
   ./test_libft
   ```

4. Para probar las funciones bonus, compila con:
   ```bash
   gcc -Wall -Wextra -Werror -DBONUS test.c -L. -lft -o test_libft
   ```

Los resultados de las pruebas se mostrarán en la terminal, y las funciones de descriptor de archivo escribirán su salida en `test_output.txt`.

### Errores comunes

Si al compilar el test obtienes errores como "referencia a `ft_isalpha' sin definir", significa que no estás enlazando correctamente con la biblioteca. Asegúrate de:

1. Haber compilado la biblioteca con `make`
2. Incluir los parámetros `-L. -lft` en el comando de compilación
3. Si sigues teniendo problemas, verifica que `libft.a` exista en tu directorio

## Comprobación de Memoria con Valgrind

Para asegurarte de que no haya fugas de memoria, puedes usar Valgrind:

1. Instala Valgrind si aún no está instalado:
   ```bash
   sudo apt-get install valgrind
   ```

2. Ejecuta el programa de prueba con Valgrind:
   ```bash
   valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_libft
   ```

### Pruebas Específicas con Valgrind

Para pruebas específicas de funciones propensas a problemas de memoria:

```bash
gcc -Wall -Wextra -Werror test.c -L. -lft -o test_libft
valgrind --leak-check=full ./test_libft
```

Las funciones más propensas a problemas de memoria son:
- `ft_split` (asegúrate de liberar todas las cadenas asignadas y el array)
- `ft_substr` (verifica casos límite como cadenas vacías o solicitudes fuera de límites)
- `ft_strjoin` (verifica la asignación adecuada y el manejo de casos límite)


Al probar con Valgrind, puedes garantizar que tus funciones manejen la memoria correcta y eficientemente.
