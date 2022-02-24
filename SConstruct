#!/usr/bin/env python

import os
import sys
import platform

env = SConscript("godot-cpp/SConstruct")

arch = "x86"
if env["arch_suffix"] == "64":
    arch = "x86_64"

if env["platform"] == "freebsd":
    env["platform"] = "linux"

"""
elif env["platform"] == "windows":
    env["CXX"] = "x86_64-w64-mingw32-g++-posix"
    env["LINK"] = "x86_64-w64-mingw32-g++-posix"

    env["SHLIBSUFFIX"] = ".dll.a"
    env.Append(LIBPATH=["lib/" + env["platform"] + "/" + arch + "/bin"])
"""

env.Append(LIBPATH=["lib/" + env["platform"] + "/" + arch + "/lib", "#ffmpeg-4-shared/lib"])
env.Append(CPPPATH=["lib/" + env["platform"] + "/" + arch + "/include", "#ffmpeg-4-shared/include"])
env.Append(CPPPATH=["src/"])

sources = Glob("src/*.cpp") + Glob("lib/*.c")

suffix = env["SHLIBSUFFIX"]
#if env["platform"] == "windows":
#    suffix = ".dll"

library = env.SharedLibrary("bin/" + env["platform"] + "/libffmpegmediadecoder." + env["arch_suffix"] + suffix, source=sources)

env.Prepend(LIBS=["avformat", "avcodec", "avutil", "swresample", "swscale"])

Default(library)
