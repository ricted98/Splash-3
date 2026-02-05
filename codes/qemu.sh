#!/bin/env bash
qemu-system-riscv64 -M virt -smp 2 -bios none -nographic -kernel $1
