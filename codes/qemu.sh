#!/usr/bin/env bash
# Usage: qemu.sh <executable> [cores]
# The benchmarks use every core that is online, so [cores] selects the
# processor count of the run (default: 2).
set -euo pipefail

if [[ $# -lt 1 || $# -gt 2 ]]; then
    echo "usage: $0 <executable> [cores]" >&2
    exit 1
fi

exec qemu-system-riscv64 -M virt -smp "${2:-2}" -bios none -nographic -kernel "$1"
