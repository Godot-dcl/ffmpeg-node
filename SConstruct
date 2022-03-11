#!/usr/bin/env python

import os
import sys
import platform

custom_opts = [
    ("ffmpeg_path", "Path to precompiled ffmpeg library", "ffmpeg"),
]

Export("custom_opts")

env = SConscript("godot-cpp/SConstruct")

arch = "x86"
if env["arch_suffix"] == "64":
    arch = "x86_64"

if env["platform"] == "freebsd":
    env["platform"] = "linux"

elif env["platform"] == "windows":
    if not (env.msvc):
        env["CXX"] = "x86_64-w64-mingw32-g++-posix"
        env["LINK"] = "x86_64-w64-mingw32-g++-posix"

        env["SHLIBSUFFIX"] = ".dll.a"
        env.Append(LIBPATH=["lib/" + env["platform"] + "/" + arch + "/bin"])


env.Append(LIBPATH=["lib/" + env["platform"] + "/" + arch + "/lib", "#$ffmpeg_path/lib"])
env.Append(CPPPATH=["lib/" + env["platform"] + "/" + arch + "/include", "#$ffmpeg_path/include"])
env.Append(CPPPATH=["src/"])

sources = Glob("src/*.cpp") + Glob("lib/*.c")

suffix = env["SHLIBSUFFIX"]
if env["platform"] == "windows" and (not env.msvc):
    suffix = ".dll"

library = env.SharedLibrary("bin/" + env["platform"] + "/libffmpegmediadecoder." + env["arch_suffix"] + suffix, source=sources)

env.Prepend(LIBS=["avformat", "avcodec", "avutil", "swresample", "swscale"])

Default(library)
