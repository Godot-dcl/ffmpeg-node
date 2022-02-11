#!/usr/bin/env python
import os
import sys
import platform

env = SConscript("godot-cpp/SConstruct")

arch = env["arch"] if "arch" in env and env["arch"] else platform.machine()
if arch == "x64":
    arch = "x86_64"

env.Append(CPPPATH=["lib/all/include"])

if env["platform"] == "linux" or env["platform"] == "freebsd":
    env.Append(LIBPATH=["lib/linux/%s/lib" % arch])

env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp") + Glob("lib/*.c")

library = env.SharedLibrary("bin/libffmpegmediadecoder" + env["SHLIBSUFFIX"], source=sources)

env.Prepend(LIBS=["avformat", "avcodec", "avutil", "swresample", "swscale"])

Default(library)
