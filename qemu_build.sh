#!/bin/bash

compiler_path=~/2build/qemu/linux/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi/bin
kernel_path=~/2build/qemu/linux/linux-5.4.124
export PATH=$compiler_path:$PATH

if [ $# -eq 0 ]; then
	echo "run [$0 build] or [$0 clean]"
	exit
fi


if [ $1 == 'clean' ]; then
	echo "**********clean***********"
	rm -rf temp build	
	rm -f *.ko *.o *.mod *.mod.c *.symvers *.order .*.cmd
	find -name *.o | xargs -i rm {}
	find -name .*.cmd | xargs -i rm {}

elif [ $1 == 'build' ]; then
	echo "**********build***********"
	#make TOOL_PATH=$compiler_path ARCH=arm TOOLPREFIX=arm-linux-gnueabi- TARGET_NAME=arm-linux-gnueabi GCC_VERSION=4.9.4 KVER=5.4 SYS_PATH=$kernel_path SWCONFIG_FEATURE=disable CHIP_TYPE=ALL_CHIP
	make TOOL_PATH=$compiler_path ARCH=arm TOOLPREFIX=arm-linux-gnueabi- TARGET_NAME=arm-linux-gnueabi GCC_VERSION=4.9.4 KVER=5.4 SYS_PATH=$kernel_path SWCONFIG_FEATURE=disable CHIP_TYPE=ISISC
	$compiler_path/arm-linux-gnueabi-strip --strip-debug build/bin/qca-ssdk.ko 
else
	echo "run [$0 build] or [$0 clean]"
fi