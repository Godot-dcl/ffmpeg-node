#!/usr/bin/env python
import os
import sys
import platform

env = SConscript("godot-cpp/SConstruct")

arch = env["arch"] if "arch" in env and env["arch"] else platform.machine()
if arch == "x64":
    arch = "x86_64"

platform = ""
if env["platform"] == "linux" or env["platform"] == "freebsd":
    platform = "linux"
elif env["platform"] == "windows":
    platform = "windows"

env.Append(LIBPATH=["lib/" + platform + "/" + arch + "/lib"])
env.Append(CPPPATH=["lib/" + platform + "/" + arch + "/include"])
env.Append(CPPPATH=["src/"])

sources = Glob("src/*.cpp") + Glob("lib/*.c")

library = env.SharedLibrary("bin/" + platform + "/libffmpegmediadecoder." + arch + env["SHLIBSUFFIX"], source=sources)

env.Prepend(LIBS=["avformat", "avcodec", "avutil", "swresample", "swscale"])

Default(library)
