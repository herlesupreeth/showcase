#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
   time_t now;

   printf("system() in foreground:\n");
   now = time(NULL);
   printf("%s", ctime(&now));
   system("(sleep 1; echo 1)");
   system("(sleep 1; echo 2)");
   system("(sleep 1; echo 3)");
   now = time(NULL);
   printf("%s\n", ctime(&now));

   printf("system() in background:\n");
   now = time(NULL);
   printf("%s", ctime(&now));
   system("(sleep 1; echo 1) &");
   system("(sleep 1; echo 2) &");
   system("(sleep 1; echo 3) &");
   now = time(NULL);
   printf("%s\n", ctime(&now));

   printf("wait for 5s ...\n");
   sleep(5);
   return 0;
}
