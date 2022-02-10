#include "wrapper.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

FFMPEGMediaDecoder::FFMPEGMediaDecoder() {}

void FFMPEGMediaDecoder::_bind_methods() {
	ClassDB::bind_method(D_METHOD("clean_all"), &FFMPEGMediaDecoder::clean_all);
}

void FFMPEGMediaDecoder::clean_all() {
	nativeCleanAll();
}
