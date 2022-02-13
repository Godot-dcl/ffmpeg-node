#pragma once

#include "ViveMediaDecoder.h"

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/classes/texture_rect.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class FFmpegRect : public TextureRect {
	GDCLASS(FFmpegRect, TextureRect);

private:
	enum DecoderState {
		INIT_FAIL = -1,
		UNINITIALIZED,
		INITIALIZED,
		DECODING,
		SEEK,
		BUFFERING,
		DECODE_EOF,
		STOP,
	};

	Ref<ImageTexture> texture;

	int id = 0;

	bool paused = false;
	bool processing = false;
	bool seeking = false;
	bool looping = false;

	int width = 0;
	int height = 0;
	float length = 0;

protected:
	void _notification(int p_what);
	static void _bind_methods();

public:
	bool load(String file);

	void stop();
	void play();

	bool is_playing() const;

	void set_paused(bool p_paused);
	bool is_paused() const;

	void set_loop(bool p_enable);
	bool has_loop() const;

	float get_length() const;

	//float get_playback_position() const;
	void seek(float p_time);

	void _process(float delta);

	FFmpegRect();
	~FFmpegRect();
};
