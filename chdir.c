#include "shell.h"

/**
 * change_dir - Changes the current working directory
 * @cmd: Parsed command with arguments
 * @st: Status of the last command executed (unused in this function)
 *
 * Return: 0 on success,-1 if failed(For OLDPWD, always 0 in case of no OLDPWD)
 */
int change_dir(char **cmd, __attribute__((unused)) int st)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
	{
		value = chdir(getenv("HOME"));
	}
	else if (strcmp(cmd[1], "-") == 0)
	{
		const char *oldpwd = getenv("OLDPWD");

		if (oldpwd == NULL)
		{
			const char *msg = "cd: OLDPWD not set\n";

			write(STDERR_FILENO, msg, strlen(msg));
			return (-1);
		}
		value = chdir(oldpwd);
	}
	else
	{
		value = chdir(cmd[1]);
	}
	if (value == -1)
	{
		const char *msg = "cd: Error changing directory\n";

		write(STDERR_FILENO, msg, strlen(msg));
		return (-1);
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

