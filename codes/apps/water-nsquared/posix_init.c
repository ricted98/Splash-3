#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <rtems.h>
#include <rtems/untar.h>

extern char _binary_rootfs_tar_start[];
extern char _binary_rootfs_tar_end[];
extern char _binary_rootfs_tar_size[];

int main(int argc, char **argv);

void *POSIX_Init(void *arg)
{
    // Unpack the embedded tarball into "/"
    size_t tar_size = _binary_rootfs_tar_end - _binary_rootfs_tar_start;
    int status = Untar_FromMemory(_binary_rootfs_tar_start, tar_size);
    if (status != 0) {
        perror("Error: Could not unpack tar filesystem\n");
    } else {
        printf("Filesystem unpacked successfully\n");
    }

    if (freopen("inputs/n512-p2", "r", stdin) == NULL) {
        perror("Error redirecting stdin to input file\n");
        exit(1);
    }

    char *argv[] = { "water-nsquared", NULL };
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
