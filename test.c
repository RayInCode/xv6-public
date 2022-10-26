#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "spinlock.h"
#include "pstat.h"
#define PGSIZE 4096

#


int 
main(void){
    const uint PAGES_NUM = 5;
    
    // Allocate 5 pages
    char *ptr = sbrk(PGSIZE * PAGES_NUM * sizeof(char));
    printf(1, "ptr = %x\n", ptr);
    mprotect(ptr, PAGES_NUM);
    int ppid = getpid();

    if (fork() == 0) {
        // Should page fault as normally here
        printf(1, "ptr + 2 * PGSIZE = %x\n", &ptr[2 * PGSIZE]);
        ptr[2 * PGSIZE] = 0xAA;
        printf(1, "XV6_TEST_OUTPUT Seg fault failed to trigger\n");
        // Shouldn't reach here
        kill(ppid);
        exit();
    } else {
        wait();
    }

    printf(1, "XV6_TEST_OUTPUT TEST PASS\n");

    exit();
}