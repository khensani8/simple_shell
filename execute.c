#include "shell.h"

int sh_cd(char **args);
int sh_exit(char **args);
int sh_env(char **args);

/*
 * List of builtin commands, followed by their corresponding functions.
 */
char *builtin_cmd[] = {"cd", "exit", "env"};

int (*builtin_fun[]) (char **) = {&sh_cd, &sh_exit, &sh_env};

/**
 * lsh_num_builtins - size
 * Return: size
 */

int no_builtins(void)
{
	return (sizeof(builtin_cmd) / sizeof(char *));
}

/*
 * Builtin function implementations.
*/

/**
 * lsh_cd - builtin to change dirs
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: 1 on success
 */
int sh_cd(char **ar)
{

	if (ar[1] == NULL)
	{
		ar[1] = getenv("HOME");
		if (ar[1] == NULL)
			fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(ar[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}
/**
 * sh_exit - builtin to exit the shell
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int sh_exit(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}

/**
 * lsh_ctrld - builtin to handle "^D" call
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int sh_env(char **args)
{
	(void) args;
	print_env();
	return (200);
}
/**
 * process - Execute a shell command in a new process
 *
 * @ar: array of arguments
 * @path: path to the executable file
 *
 * Return:...
 */

int process(char *path, char **ar)
{
	pid_t child;
	int status = 0, i;

	if (ar[0] == NULL)
		return (1);
	for (i = 0; i < no_builtins(); i++)
	{
		if (_strcmp(ar[0], builtin_cmd[i]) == 0)
			return (builtin_fun[i](ar));
	}

	child = fork();
	if (child == 0)
	{
		if (execve(path, ar, environ) == -1)
		{
			perror("hsh");
			free(ar);
			free(path);
			exit(EXIT_FAILURE);
		}
	}
	else if (child == -1)
	{
		perror(ar[0]);
		free(ar);
	}
	else
	{
		wait(&status);
		return (status);
	}

	return (0);
}
