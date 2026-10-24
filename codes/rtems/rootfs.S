/*
 * Embeds rootfs.tar (from the benchmark's build directory) for
 * rtems_tarfs_load().
 */

	.section .rodata.rootfs, "a"
	.balign 16
	.global rootfs_tar_start
rootfs_tar_start:
	.incbin "rootfs.tar"
	.global rootfs_tar_end
rootfs_tar_end:

	.section .note.GNU-stack, "", %progbits
