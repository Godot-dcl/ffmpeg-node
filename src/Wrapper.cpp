#include "Wrapper.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

FFMPEGMediaDecoder::FFMPEGMediaDecoder() {}

void FFMPEGMediaDecoder::_bind_methods() {
	ClassDB::bind_method(D_METHOD("clean_all"), &FFMPEGMediaDecoder::clean_all);
	ClassDB::bind_method(D_METHOD("decoder_state", "id"), &FFMPEGMediaDecoder::decoder_state);
	ClassDB::bind_method(D_METHOD("start_decoding", "id"), &FFMPEGMediaDecoder::start_decoding);
	ClassDB::bind_method(D_METHOD("destroy_decoder", "id"), &FFMPEGMediaDecoder::destroy_decoder);
	ClassDB::bind_method(D_METHOD("is_eof", "id"), &FFMPEGMediaDecoder::is_eof);
	ClassDB::bind_method(D_METHOD("release_video_frame", "id"), &FFMPEGMediaDecoder::release_video_frame);
}

void FFMPEGMediaDecoder::clean_all() {
	nativeCleanAll();
}

int FFMPEGMediaDecoder::decoder_state(int id) {
	return nativeGetDecoderState(id);
}

bool FFMPEGMediaDecoder::start_decoding(int id) {
	return nativeStartDecoding(id);
}

void FFMPEGMediaDecoder::destroy_decoder(int id) {
	return nativeDestroyDecoder(id);
}

bool FFMPEGMediaDecoder::is_eof(int id) {
	return nativeIsEOF(id);
}

void FFMPEGMediaDecoder::release_video_frame(int id) {
	nativeReleaseVideoFrame(id);
}
