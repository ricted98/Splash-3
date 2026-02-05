#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <rtems.h>

extern const unsigned char _binary_inputs_input_2_16384_start[];
extern const unsigned char _binary_inputs_input_2_16384_end[];
extern char _binary_inputs_input_2_16384_size;

int main(int argc, char **argv);

static void redirect_stdin_memory(const unsigned char *data, size_t len) {
    FILE *memfp = fmemopen((void*)data, len, "r");
    if (!memfp) { perror("fmemopen"); exit(1); }
    stdin = memfp;
}

void *POSIX_Init(void *arg)
{
    redirect_stdin_memory(_binary_inputs_input_2_16384_start, (size_t)&_binary_inputs_input_2_16384_size);

    char *argv[] = { "fmm", NULL };
    int rc = main(1, argv);
    exit(rc);
    return NULL;
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
