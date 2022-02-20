#!/bin/sh

cd ../ffmpeg

ARCH=$(uname -m)

./configure \
	--prefix=./../lib/windows/${ARCH} \
	--enable-cross-compile \
	--cross-prefix=${ARCH}-w64-mingw32- \
	--target-os=mingw32 \
	--enable-shared \
	--disable-static \
	--disable-zlib \
	--disable-programs \
	--disable-doc \
	--disable-manpages \
	--disable-podpages \
	--disable-txtpages \
	--disable-ffplay \
	--disable-ffprobe \
	--disable-ffmpeg \
	--disable-x86asm \
	--arch=${ARCH}

make clean
make install
