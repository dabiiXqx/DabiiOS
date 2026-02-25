#!/bin/bash

qemu-system-i386 -cpu qemu32 -drive format=raw,file=disk.img -no-reboot -d int --full-screen
