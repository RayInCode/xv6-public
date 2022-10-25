#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int
main(int argc, char *argv[])
{
   struct pstat st;
   int pid = getpid();
   int defaulttickets = 0;
   printf(1, "getpinfo(&st)=%d getpid()=%d\n", getpinfo(&st),getpid());
   if(getpinfo(&st) == 0)
   {
      for(int i = 0; i < NPROC; i++) {
         printf(1, "pid:%d,\tticket:%d\n", st.pid[i], st.tickets[i]);
         if (st.inuse[i]) {
            if(st.pid[i] == pid) {
               defaulttickets = st.tickets[i];
            }
         }
      }
      printf(1,"defaulttickets = %d\n",defaulttickets);
   }
  else
  {
   printf(1, "XV6_SCHEDULER\t FAILED1\n");
   exit();
  }

  
  if(defaulttickets == 1)
  {
   printf(1, "XV6_SCHEDULER\t SUCCESS\n");
  }
  else
  {
   printf(1, "XV6_SCHEDULER\t FAILED2\n");
  }
   exit();
}
