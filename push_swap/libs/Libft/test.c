#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void test_is_functions(void)
{
    printf("\n----- TESTING IS FUNCTIONS -----\n");
    
    printf("ft_isalpha:\n");
    for (int i = 'A'; i <= 'Z'; i++)
        printf("%c: %d (should be non-zero)\n", i, ft_isalpha(i));
    printf("5: %d (should be 0)\n", ft_isalpha('5'));
    
    printf("\nft_isdigit:\n");
    for (int i = '0'; i <= '9'; i++)
        printf("%c: %d (should be non-zero)\n", i, ft_isdigit(i));
    printf("a: %d (should be 0)\n", ft_isdigit('a'));
    
    printf("\nft_isalnum:\n");
    printf("a: %d (should be non-zero)\n", ft_isalnum('a'));
    printf("5: %d (should be non-zero)\n", ft_isalnum('5'));
    printf("!: %d (should be 0)\n", ft_isalnum('!'));
    
    printf("\nft_isascii:\n");
    printf("a: %d (should be non-zero)\n", ft_isascii('a'));
    printf("127: %d (should be non-zero)\n", ft_isascii(127));
    printf("128: %d (should be 0)\n", ft_isascii(128));
    
    printf("\nft_isprint:\n");
    printf("a: %d (should be non-zero)\n", ft_isprint('a'));
    printf("space: %d (should be non-zero)\n", ft_isprint(' '));
    printf("DEL: %d (should be 0)\n", ft_isprint(127));
}

void test_to_functions(void)
{
    printf("\n----- TESTING TO FUNCTIONS -----\n");
    
    printf("ft_toupper:\n");
    printf("a -> %c (should be A)\n", ft_toupper('a'));
    printf("z -> %c (should be Z)\n", ft_toupper('z'));
    printf("A -> %c (should be A)\n", ft_toupper('A'));
    printf("3 -> %c (should be 3)\n", ft_toupper('3'));
    
    printf("\nft_tolower:\n");
    printf("A -> %c (should be a)\n", ft_tolower('A'));
    printf("Z -> %c (should be z)\n", ft_tolower('Z'));
    printf("a -> %c (should be a)\n", ft_tolower('a'));
    printf("3 -> %c (should be 3)\n", ft_tolower('3'));
}

void test_string_functions(void)
{
    printf("\n----- TESTING STRING FUNCTIONS -----\n");
    
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    
    printf("ft_strlen:\n");
    printf("Length of '%s': %zu (should be 13)\n", str1, ft_strlen(str1));
    printf("Length of empty string: %zu (should be 0)\n", ft_strlen(""));
    
    printf("\nft_strchr:\n");
    printf("Find 'w' in '%s': %s (should be 'world!')\n", str1, ft_strchr(str1, 'w'));
    printf("Find 'z' in '%s': %p (should be NULL)\n", str1, ft_strchr(str1, 'z'));
    
    printf("\nft_strrchr:\n");
    printf("Find last 'l' in '%s': %s (should be 'ld!')\n", str1, ft_strrchr(str1, 'l'));
    printf("Find 'z' in '%s': %p (should be NULL)\n", str1, ft_strrchr(str1, 'z'));
    
    printf("\nft_strncmp:\n");
    printf("Compare '%s' with '%s' (5 chars): %d (should be 0)\n", 
           str1, str2, ft_strncmp(str1, str2, 5));
    printf("Compare '%s' with 'Hello, there!' (7 chars): %d (should be < 0)\n", 
           str1, ft_strncmp(str1, "Hello, there!", 7));
    
    printf("\nft_strnstr:\n");
    printf("Find 'world' in '%s': %s (should be 'world!')\n", 
           str1, ft_strnstr(str1, "world", 13));
    printf("Find 'world' in '%s' (5 chars): %p (should be NULL)\n", 
           str1, ft_strnstr(str1, "world", 5));
    
    printf("\nft_strlcpy:\n");
    char dst1[20];
    size_t len1 = ft_strlcpy(dst1, "Copy this string", 10);
    printf("Copy 'Copy this string' (max 10): '%s', returned %zu (should be 16)\n", 
           dst1, len1);
    
    printf("\nft_strlcat:\n");
    char dst2[20] = "Hello";
    size_t len2 = ft_strlcat(dst2, ", world!", 13);
    printf("Concatenate 'Hello' + ', world!' (max 13): '%s', returned %zu (should be 13)\n", 
           dst2, len2);
}

void test_mem_functions(void)
{
    printf("\n----- TESTING MEMORY FUNCTIONS -----\n");
    
    printf("ft_memset:\n");
    char buf1[20] = "Testing memset";
    ft_memset(buf1, '*', 7);
    printf("After setting 7 bytes to '*': '%s' (should be '*******memset')\n", buf1);
    
    printf("\nft_bzero:\n");
    char buf2[20] = "Testing bzero";
    ft_bzero(buf2, 7);
    printf("After zeroing 7 bytes: '%s' (should be empty or garbage before 'bzero')\n", buf2 + 7);
    
    printf("\nft_memcpy:\n");
    char src1[] = "Source string";
    char dst1[20];
    ft_memcpy(dst1, src1, 13);
    printf("After copying 'Source string': '%s'\n", dst1);
    
    printf("\nft_memmove:\n");
    char str[] = "memmove can handle overlapping";
    ft_memmove(str + 10, str + 8, 11);
    printf("After moving overlapping memory: '%s' (should be 'memmove caan handle lapping')\n", str);
    
    printf("\nft_memchr:\n");
    char str2[] = "Find the character";
    printf("Find 't' in '%s': %s (should be 'the character')\n", 
           str2, (char *)ft_memchr(str2, 't', 17));
    
    printf("\nft_memcmp:\n");
    char str3[] = "Compare this";
    char str4[] = "Compare that";
    printf("Compare '%s' with '%s' (9 chars): %d (should be 0)\n", 
           str3, str4, ft_memcmp(str3, str4, 9));
    printf("Compare '%s' with '%s' (10 chars): %d (should be != 0)\n", 
           str3, str4, ft_memcmp(str3, str4, 10));
}

void test_conversion_functions(void)
{
    printf("\n----- TESTING CONVERSION FUNCTIONS -----\n");
    
    printf("ft_atoi:\n");
    printf("Convert '42': %d (should be 42)\n", ft_atoi("42"));
    printf("Convert '-42': %d (should be -42)\n", ft_atoi("-42"));
    printf("Convert ' +42': %d (should be 42)\n", ft_atoi(" +42"));
    printf("Convert '  -42abc': %d (should be -42)\n", ft_atoi("  -42abc"));
    
    printf("\nft_itoa:\n");
    char *s1 = ft_itoa(42);
    printf("Convert 42: '%s' (should be '42')\n", s1);
    char *s2 = ft_itoa(-42);
    printf("Convert -42: '%s' (should be '-42')\n", s2);
    char *s3 = ft_itoa(0);
    printf("Convert 0: '%s' (should be '0')\n", s3);
    char *s4 = ft_itoa(2147483647);
    printf("Convert INT_MAX: '%s' (should be '2147483647')\n", s4);
    char *s5 = ft_itoa(-2147483648);
    printf("Convert INT_MIN: '%s' (should be '-2147483648')\n", s5);
    
    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(s5);
}

void test_allocation_functions(void)
{
    printf("\n----- TESTING ALLOCATION FUNCTIONS -----\n");
    
    printf("ft_calloc:\n");
    char *mem = (char *)ft_calloc(10, sizeof(char));
    if (mem)
    {
        int is_zeroed = 1;
        for (int i = 0; i < 10; i++)
            if (mem[i] != 0)
                is_zeroed = 0;
        printf("Allocated 10 bytes: %s zeroed\n", is_zeroed ? "correctly" : "incorrectly");
        free(mem);
    }
    else
        printf("Allocation failed\n");
    
    printf("\nft_strdup:\n");
    char *dup = ft_strdup("Duplicate this string");
    printf("Original: 'Duplicate this string', Duplicate: '%s'\n", dup);
    free(dup);
    
    printf("\nft_substr:\n");
    char *sub = ft_substr("Get a substring from this", 6, 9);
    printf("Substring (6, 9) from 'Get a substring from this': '%s' (should be 'substring')\n", sub);
    free(sub);
    
    printf("\nft_strjoin:\n");
    char *join = ft_strjoin("Join ", "these strings");
    printf("Joined 'Join ' and 'these strings': '%s'\n", join);
    free(join);
    
    printf("\nft_strtrim:\n");
    char *trim = ft_strtrim(" \t Hello, world! \n ", " \t\n");
    printf("Trimmed ' \\t Hello, world! \\n ': '%s'\n", trim);
    free(trim);
    
    printf("\nft_split:\n");
    char **splits = ft_split("Split,this,string,by,commas", ',');
    if (splits)
    {
        printf("Split result:\n");
        for (int i = 0; splits[i]; i++)
        {
            printf("  [%d]: '%s'\n", i, splits[i]);
            free(splits[i]);
        }
        free(splits);
    }
}

// Función auxiliar para probar ft_strmapi
char test_toupper(unsigned int i, char c)
{
    (void)i; // Para evitar warning de variable no utilizada
    return toupper((int)c);
}

void test_string_manipulation(void)
{
    printf("\n----- TESTING STRING MANIPULATION -----\n");
    
    printf("ft_strmapi:\n");
    char *mapped = ft_strmapi("abcdef", test_toupper);
    printf("Mapped 'abcdef' to uppercase: '%s'\n", mapped);
    free(mapped);
    
    printf("\nft_striteri:\n");
    char test[] = "test string";
    ft_striteri(test, (void (*)(unsigned int, char *))NULL); // Just testing it doesn't crash
    printf("Called striteri on '%s' (no visible effect)\n", test);
}

void test_fd_functions(void)
{
    printf("\n----- TESTING FD FUNCTIONS -----\n");
    
    printf("Testing ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd:\n");
    printf("Check 'test_output.txt' after running\n");
    
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd != -1)
    {
        ft_putchar_fd('A', fd);
        ft_putchar_fd('\n', fd);
        
        ft_putstr_fd("This is a test string", fd);
        ft_putchar_fd('\n', fd);
        
        ft_putendl_fd("This line should end with a newline", fd);
        
        ft_putnbr_fd(42, fd);
        ft_putchar_fd('\n', fd);
        
        ft_putnbr_fd(-42, fd);
        ft_putchar_fd('\n', fd);
        
        ft_putnbr_fd(2147483647, fd);
        ft_putchar_fd('\n', fd);
        
        ft_putnbr_fd(-2147483648, fd);
        
        close(fd);
    }
}

#ifdef BONUS
void test_list_functions(void)
{
    printf("\n----- TESTING LIST FUNCTIONS -----\n");
    
    // Create new list node
    t_list *node1 = ft_lstnew("First node");
    printf("ft_lstnew: Created node with content: '%s'\n", (char *)node1->content);
    
    // Create and add more nodes
    t_list *node2 = ft_lstnew("Second node");
    t_list *node3 = ft_lstnew("Third node");
    
    // Test ft_lstadd_front
    t_list *list = NULL;
    ft_lstadd_front(&list, node3);
    ft_lstadd_front(&list, node2);
    ft_lstadd_front(&list, node1);
    
    // Test ft_lstsize and ft_lstlast
    printf("ft_lstsize: %d (should be 3)\n", ft_lstsize(list));
    t_list *last = ft_lstlast(list);
    printf("ft_lstlast: '%s' (should be 'Third node')\n", (char *)last->content);
    
    // Test ft_lstadd_back
    t_list *node4 = ft_lstnew("Fourth node");
    ft_lstadd_back(&list, node4);
    last = ft_lstlast(list);
    printf("ft_lstadd_back + ft_lstlast: '%s' (should be 'Fourth node')\n", (char *)last->content);
    
    // Display all nodes
    printf("\nAll nodes in list:\n");
    t_list *current = list;
    int i = 0;
    while (current)
    {
        printf("Node %d: '%s'\n", ++i, (char *)current->content);
        current = current->next;
    }
    
    // Test ft_lstclear (free all nodes)
    ft_lstclear(&list, NULL);
    printf("\nAfter ft_lstclear, list pointer is %s\n", list == NULL ? "NULL" : "not NULL");
}
#endif

int main(void)
{
    printf("===== LIBFT FUNCTION TESTER =====\n");
    
    test_is_functions();
    test_to_functions();
    test_string_functions();
    test_mem_functions();
    test_conversion_functions();
    test_allocation_functions();
    test_string_manipulation();
    test_fd_functions();
    
#ifdef BONUS
    test_list_functions();
#endif
    
    printf("\n===== ALL TESTS COMPLETED =====\n");
    return 0;
}