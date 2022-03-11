# Building

```
git submodule update --init --recursive

cd ffmpeg_build_scripts
./[Platform Name].sh

cd ..
scons target=release
```
# Windows

Precompiled ffmpeg libraries (version 4.4.1) can be found here:

https://www.gyan.dev/ffmpeg/builds/#libraries

Unpack the package in the root and run:

```
scons target=release ffmpeg-path=ffmpeg-4-shared
```

Copy all dlls from ffmpeg-4-shared/bin to bin/windows:

```
$ cp ffmpeg-4-shared/bin/*.dll bin/windows/

$ ls bin/windows
avcodec-58.dll*  avdevice-58.dll*  avfilter-7.dll*  avformat-58.dll*  avutil-56.dll*  libffmpegmediadecoder.64.dll*  libffmpegmediadecoder.64.exp  libffmpegmediadecoder.64.lib  postproc-55.dll*  swresample-3.dll*  swscale-5.dll*
```

## Common problems

When starting the editor, it might crash with this output on the console:

```
$ ./godot-4.0.exe -e

Godot Engine v4.0.alpha.custom_build.256069eaf - https://godotengine.org
Vulkan API 1.2.148 - Using Vulkan Device #0: Intel - Intel(R) UHD Graphics 630


================================================================
CrashHandlerException: Program crashed
Engine version: Godot Engine v4.0.alpha.custom_build (256069eaf00be2340259f896695014d92b1e22ed)
Dumping the backtrace. Please include this when reporting the bug on https://github.com/godotengine/godot/issues
[0] init
[1] init
[2] MethodBind::_generate_argument_types (D:\code\godot\core\object\method_bind.cpp:118)
[3] NativeExtension::_register_extension_class_method (D:\code\godot\core\extension\native_extension.cpp:173)
[4] init
[5] <couldn't map PC to fn name>
[6] <couldn't map PC to fn name>
[7] initialize_level
[8] NativeExtensionManager::initialize_extensions (D:\code\godot\core\extension\native_extension_manager.cpp:100)
[9] register_scene_types (D:\code\godot\scene\register_scene_types.cpp:1072)
[10] Main::setup2 (D:\code\godot\main\main.cpp:1892)
[11] Main::setup (D:\code\godot\main\main.cpp:1484)
[12] widechar_main (D:\code\godot\platform\windows\godot_windows.cpp:158)
[13] _main (D:\code\godot\platform\windows\godot_windows.cpp:193)
[14] main (D:\code\godot\platform\windows\godot_windows.cpp:205)
[15] __scrt_common_main_seh (d:\agent\_work\4\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl:288)
[16] BaseThreadInitThunk
-- END OF BACKTRACE --
================================================================
Segmentation fault
```

This is caused by a mismatch in the `target` parameter when compiling the main godot exacutable and this extension. For example godot compiled with `target=debug` and extension compiled with `target=release`.

Try compiling the extension with `target=debug`
