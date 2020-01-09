#include "monty.h"
/**
*main - main fuction
*@ac: arguments counter
*@av: array of arguments
*Return: exit succes
*/

int main(int ac, char **av)
{
FILE *fd;
char *string, *buff;
size_t line_number = 1, i = 0;
stack_t *stack = NULL;

if (ac != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

fd = fopen(av[1], "r");
if (!fd)
{
fprintf(stderr, "Error: Can't open file %s\n", av[1]);
exit(EXIT_FAILURE);
}

for (line_number = 1; getline(&buff, &i, fd) != -1; line_number++)
{
if (*buff)
{
string = strtok(buff, "\n");
gettoken(string, &stack, line_number);
}
}
fclose(fd);
free(buff);

return (EXIT_SUCCESS);
}

/**
*gettoken - function to get tokens
*@string: buffer with file content
*@stack: poiter to structure
*@line_number: size
*/

void gettoken(char *string, stack_t **stack, unsigned int line_number)
{
char *token, *tmp;

token = strtok(string, " ");

if (*token == ' ' || *token == '\n' || token == NULL)
{
return;
}

if (strcmp(token, "push") == 0)
{
tmp = token;
token = strtok(NULL, "");
if (!esnum(token))
{
fprintf(stderr, "ah vaina\n");
exit(EXIT_FAILURE);
}
externalvar.varext = atoi(token);
tan_opcode(tmp, stack, line_number);
}
else
{
tan_opcode(token, stack, line_number);
}
}

/**
*esnum - checks if token is a number
*@token: token to check
*Return: 1
*/

int esnum(char *token)
{
if (!token)
{
return (0);
}

while (*token)
{
if (!isdigit(*token))
{
return (0);
}
token++;
}
token++;
return (1);
}
