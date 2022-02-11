#ifndef WRAPPER_H
#define WRAPPER_H

#ifdef WIN32
#include <windows.h>
#endif

#include "ViveMediaDecoder.h"

#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class FFMPEGMediaDecoder : public RefCounted {
	GDCLASS(FFMPEGMediaDecoder, RefCounted);

protected:
	static void _bind_methods();

public:
	FFMPEGMediaDecoder();

public:
	// Utils
	void clean_all();
	//	Decoder
	/*
	int create_decoder(const char* file_path, int& id);
	int create_decoder_async(const char* file_path, int& id);
	int decoder_state(int id);
	bool start_decoding(int id);
	void destroy_decoder(int id);
	bool is_eof(int id);
	void grab_video_frame(int id, void** frame_data, bool& frame_ready);
	void release_video_frame(int id);
	//	Video
	bool is_video_enabled(int id);
	void set_video_enable(int id, bool is_enable);
	void get_video_format(int id, int& width, int& height, float& total_time);
	void set_video_time(int id, float current_time);
	bool is_content_ready(int id);
	bool is_video_buffer_full(int id);
	bool is_video_buffer_empty(int id);
	//	Audio
	bool is_audio_enabled(int id);
	void set_audio_enable(int id, bool is_enable);
	void set_audio_all_ch_data_enable(int id, bool is_enable);
	void get_audio_format(int id, int& channel, int& frequency, float& total_time);
	float get_audio_data(int id, unsigned char** audio_data, int& frame_size);
	void free_audio_data(int id);
	//	Seek
	void set_seek_time(int id, float sec);
	bool is_seek_over(int id);
	//  Utility
	int get_meta_data(const char* file_path, char*** key, char*** value);
	*/
};

#endif // ! WRAPPER_H
