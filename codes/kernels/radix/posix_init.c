#include <stdlib.h>
#include <rtems.h>

#define _STR(x) #x
#define STR(x) _STR(x)

int main(int argc, char **argv);

void *POSIX_Init(void *arg)
{
    int argc = 3;
    char *argv[] = { "radix", "-p" STR(NUM_PROCS), "-n1048576", NULL };
    int rc = main(argc, argv);
    exit(rc);
    return NULL; // not reached
}

/* Drivers needed */
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

/* POSIX configuration */
#define CONFIGURE_POSIX_APPLICATION
#define CONFIGURE_MAXIMUM_PROCESSORS NUM_PROCS
#define CONFIGURE_MAXIMUM_POSIX_THREADS NUM_PROCS
#define CONFIGURE_POSIX_INIT_THREAD_TABLE
#define CONFIGURE_USE_IMFS_AS_BASE_FILESYSTEM
#define CONFIGURE_MAXIMUM_FILE_DESCRIPTORS 32
#define CONFIGURE_INIT
#include <rtems/confdefs.h>
