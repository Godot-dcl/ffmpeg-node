#!/usr/bin/env python

import os
import sys
import platform

env = SConscript("godot-cpp/SConstruct")

arch = env["arch"] if "arch" in env and env["arch"] else platform.machine()
if arch == "x64":
    arch = "x86_64"

if env["platform"] == "freebsd":
    env["platform"] = "linux"
elif env["platform"] == "windows":
    env["CXX"] = "x86_64-w64-mingw32-g++-posix"
    env["LINK"] = "x86_64-w64-mingw32-g++-posix"

    env["SHLIBSUFFIX"] = ".dll.a"
    env.Append(LIBPATH=["lib/" + env["platform"] + "/" + arch + "/bin"])

env.Append(LIBPATH=["lib/" + env["platform"] + "/" + arch + "/lib"])
env.Append(CPPPATH=["lib/" + env["platform"] + "/" + arch + "/include"])
env.Append(CPPPATH=["src/"])

sources = Glob("src/*.cpp") + Glob("lib/*.c")

suffix = env["SHLIBSUFFIX"]
if env["platform"] == "windows":
    suffix = ".dll"

library = env.SharedLibrary("bin/" + env["platform"] + "/libffmpegmediadecoder." + arch + suffix, source=sources)

env.Prepend(LIBS=["avformat", "avcodec", "avutil", "swresample", "swscale"])

Default(library)
