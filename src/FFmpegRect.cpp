#include "FFmpegRect.h"

#include <cstring>

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

bool FFmpegRect::load(String file) {
	CharString utf8 = file.utf8();
	const char *cstr = utf8.get_data();

	nativeCreateDecoder(cstr, id);

	bool is_loaded = nativeGetDecoderState(id) == INITIALIZED;
	if (is_loaded) {
		nativeGetVideoFormat(id, width, height, length);

// 		bool audio_enabled = nativeIsAudioEnabled(id);
// 		if (audio_enabled) {
// 			nativeSetAudioAllChDataEnable(id, true);
// 		}
	}

	return is_loaded;
}

void FFmpegRect::play() {
	if (nativeGetDecoderState(id) == INITIALIZED) {
		nativeStartDecoding(id);
	} else if (paused) {
		paused = false;
	}

	processing = true;
}

void FFmpegRect::stop() {
	if (nativeGetDecoderState(id) != DECODING) {
		return;
	}

	paused = false;
	processing = false;
}

bool FFmpegRect::is_playing() const {
	return !paused && nativeGetDecoderState(id) == DECODING;
}

void FFmpegRect::set_paused(bool p_paused) {
	paused = p_paused;
}

bool FFmpegRect::is_paused() const {
	return paused;
}

float FFmpegRect::get_length() const {
	return length;
}

void FFmpegRect::set_loop(bool p_enable) {
	looping = p_enable;
}

bool FFmpegRect::has_loop() const {
	return looping;
}

void FFmpegRect::seek(float p_time) {
	if (nativeGetDecoderState(id) != DECODING) {
		return;
	}

	if (p_time < 0) {
		p_time = 0;
	} else if (p_time > length) {
		p_time = length;
	}

	nativeSetSeekTime(id, p_time);
	nativeSetVideoTime(id, p_time);

	seeking = true;
}

void FFmpegRect::_process(float delta) {
	if (!processing || paused) {
		return;
	}

	if (seeking) {
		if (nativeIsSeekOver(id)) {
			seeking = false;
		}

		return;
	}

	void* frame_data = nullptr;
	bool frame_ready = false;

	nativeGrabVideoFrame(id, &frame_data, frame_ready);

	if (frame_ready) {
// 		Vector<uint8_t> image_data;
// 		image_data.resize(3);
// 		memcpy(frame_data, image_data.ptrw(), 3);
//
// 		Ref<Image> image = Ref<Image>(memnew(Image(width, height, false, Image::FORMAT_L8, image_data)));
// 		texture->create_from_image(image);

 		nativeReleaseVideoFrame(id);
	} else if (nativeIsEOF(id)) {
		if (looping) {
			seek(0);
		} else {
			processing = false;
		}
	}
}

FFmpegRect::FFmpegRect() {
	texture = Ref<ImageTexture>(memnew(ImageTexture));
	set_texture(texture);
}

FFmpegRect::~FFmpegRect() {
	nativeCleanAll();
}

void FFmpegRect::_bind_methods() {
	ClassDB::bind_method(D_METHOD("load", "file"), &FFmpegRect::load);
	ClassDB::bind_method(D_METHOD("play"), &FFmpegRect::play);
	ClassDB::bind_method(D_METHOD("stop"), &FFmpegRect::stop);
	ClassDB::bind_method(D_METHOD("is_playing"), &FFmpegRect::is_playing);
	ClassDB::bind_method(D_METHOD("set_paused", "paused"), &FFmpegRect::set_paused);
	ClassDB::bind_method(D_METHOD("get_length"), &FFmpegRect::get_length);
	ClassDB::bind_method(D_METHOD("set_loop", "enable"), &FFmpegRect::set_loop);
	ClassDB::bind_method(D_METHOD("has_loop"), &FFmpegRect::has_loop);
	ClassDB::bind_method(D_METHOD("seek", "time"), &FFmpegRect::seek);
	ClassDB::bind_method(D_METHOD("is_paused"), &FFmpegRect::is_paused);
}
