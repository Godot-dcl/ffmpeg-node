#include "RegisterTypes.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "Wrapper.h"

using namespace godot;

void register_scenes_types() {
	ClassDB::register_class<FFMPEGMediaDecoder>();
}

void unregister_scenes_types() {}

extern "C" {

GDNativeBool GDN_EXPORT ffmpeg_media_decoder_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_scene_initializer(register_scenes_types);
	init_obj.register_scene_terminator(unregister_scenes_types);

	return init_obj.init();
}

}
