#!/bin/bash

set -e

qemu-system-i386 -monitor stdio -soundhw pcspk -drive file=build/gunwos.img,index=0,if=floppy,format=raw
