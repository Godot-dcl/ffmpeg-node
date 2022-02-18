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
	enum State {
		LOADING,
		UNINITIALIZED,
		INITIALIZED,
		DECODING,
		SEEK,
		BUFFERING,
		END_OF_FILE,
	};

	Ref<ImageTexture> texture;
	Ref<Image> image;

	int id = 0;
	int state = UNINITIALIZED;

	bool first_frame = true;
	bool paused = false;
	bool looping = false;

	int width = 0;
	int height = 0;
	float length = 0;
	int data_size = 0;

	double global_start_time = 0.0f;
	double hang_time = 0.0f;
	double current_time = 0.0f;

protected:
	void _notification(int p_what);
	static void _bind_methods();

public:
	bool load(String path);
	void load_async(String path);

	void stop();
	void play();

	bool is_playing() const;

	void set_paused(bool p_paused);
	bool is_paused() const;

	void set_loop(bool p_enable);
	bool has_loop() const;

	float get_length() const;

	float get_playback_position() const;
	void seek(float p_time);

	void _process(float delta);

	FFmpegRect();
	~FFmpegRect();
};
