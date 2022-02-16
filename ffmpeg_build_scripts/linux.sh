#!/bin/sh

cd ../ffmpeg

Arch=$(uname -m)

./configure \
	--prefix=./../lib/linux/${Arch} \
	--enable-pthreads \
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
	--disable-yasm \
	--arch=${Arch}

make clean
make install
