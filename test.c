# include <stdlib.h>
# include <unistd.h>

int main(int argc, char **argv, char **envp)
{
    char **arr;
    int i;

    (void)argc;
    (void)argv;
    arr = malloc (4 * sizeof(char *));
    i = 0;
    while (i < 3)
    {
        arr[i] = malloc (34234 * sizeof(char));
        i++;
    }
    arr[0] = "/usr/bin/ls";
    arr[1] = "/usr/bin/ls";
    arr[2] = "wer";
    arr[3] = NULL;
    execve(arr[0], arr, envp);
}