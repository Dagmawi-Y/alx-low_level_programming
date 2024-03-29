#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t my_pid;

    my_pid = getpid();
//    parent_pid = getppid();
    printf("My PID: %u\n", my_pid);
//    printf("My Parent's PID: %u\n", parent_pid);
    return (0);
}