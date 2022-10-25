#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{

	int *p = (int *)atoi(argv[1]);
	printf(1, "%d\n", *p);
      
   exit();
}
