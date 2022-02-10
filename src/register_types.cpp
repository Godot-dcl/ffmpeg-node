#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "wrapper.h"

using namespace godot;

void register_ffmpeg_media_decoder_types() {
	ClassDB::register_class<FFMPEGMediaDecoder>();
}

void unregister_ffmpeg_media_decoder_types() {}

extern "C" {
	GDNativeBool GDN_EXPORT ffmpeg_media_decoder_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
		godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

		init_obj.register_scene_initializer(register_ffmpeg_media_decoder_types);
		init_obj.register_scene_terminator(unregister_ffmpeg_media_decoder_types);

		return init_obj.init();
	}
}
