#include <stdlib.h>
#include <rtems.h>

int main(int argc, char **argv);

void *POSIX_Init(void *arg)
{
    int argc = 11;
    char *argv[] = { "radiosity", "-p", "2", "-ae", "5000", "-bf", "0.1", "-en", "0.05", "-room", "-batch", NULL };
    int rc = main(argc, argv);
    exit(rc);
    return NULL; // not reached
}

/* Drivers needed */
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

/* POSIX configuration */
#define CONFIGURE_POSIX_APPLICATION
#define CONFIGURE_MAXIMUM_PROCESSORS 2
#define CONFIGURE_MAXIMUM_POSIX_THREADS 2
#define CONFIGURE_POSIX_INIT_THREAD_TABLE
#define CONFIGURE_USE_IMFS_AS_BASE_FILESYSTEM
#define CONFIGURE_MAXIMUM_FILE_DESCRIPTORS 32
#define CONFIGURE_INIT
#include <rtems/confdefs.h>
