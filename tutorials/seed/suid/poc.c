#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//reference: https://www.pentestpartners.com/security-blog/exploiting-suid-executables/
int main(int argc, char **argv, char **env)
{
  int i=0;
  char *cmd;while (env[i] != NULL)
  {
  if (!strcmp(strsep(&env[i],"="),"BAD_PATH"))
  {
    cmd=malloc(strlen(env[i])+20);
    if (cmd==NULL) exit(1);
    sprintf(cmd,"%s/malicious",env[i]);
    setuid(0);
    system(cmd);
  }
  i++;
  }
}
