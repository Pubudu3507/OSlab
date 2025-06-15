#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     
#include <sys/types.h>  
#include <sys/wait.h>   

int main() {
    int n;

    printf("Enter the number of terms in Fibonacci sequence: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Error:Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    pid_t pid = fork(); 

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process ID: %d\n", getpid());
        printf("Fibonacci Sequence: ");

        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            printf("%d ", a);
            int next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
    } else {
        wait(NULL); 
        printf("Parent process finished waiting.\n");
    }

    return 0;
}
