#include "Wrapper.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

FFMPEGMediaDecoder::FFMPEGMediaDecoder() {}

void FFMPEGMediaDecoder::_bind_methods() {
	ClassDB::bind_method(D_METHOD("clean_all"), &FFMPEGMediaDecoder::clean_all);
	ClassDB::bind_method(D_METHOD("create_decoder", "id"), &FFMPEGMediaDecoder::create_decoder);
	ClassDB::bind_method(D_METHOD("create_decoder_async", "id"), &FFMPEGMediaDecoder::create_decoder_async);
	ClassDB::bind_method(D_METHOD("decoder_state", "id"), &FFMPEGMediaDecoder::decoder_state);
	ClassDB::bind_method(D_METHOD("start_decoding", "id"), &FFMPEGMediaDecoder::start_decoding);
	ClassDB::bind_method(D_METHOD("destroy_decoder", "id"), &FFMPEGMediaDecoder::destroy_decoder);
	ClassDB::bind_method(D_METHOD("is_eof", "id"), &FFMPEGMediaDecoder::is_eof);
	ClassDB::bind_method(D_METHOD("release_video_frame", "id"), &FFMPEGMediaDecoder::release_video_frame);
	ClassDB::bind_method(D_METHOD("is_video_enabled", "id"), &FFMPEGMediaDecoder::is_video_enabled);
	ClassDB::bind_method(D_METHOD("set_video_enable", "id", "is_enable"), &FFMPEGMediaDecoder::set_video_enable);
	ClassDB::bind_method(D_METHOD("get_video_format", "id"), &FFMPEGMediaDecoder::get_video_format);
	ClassDB::bind_method(D_METHOD("set_video_time", "id", "current_time"), &FFMPEGMediaDecoder::set_video_time);
	ClassDB::bind_method(D_METHOD("is_content_ready", "id"), &FFMPEGMediaDecoder::is_content_ready);
	ClassDB::bind_method(D_METHOD("is_video_buffer_full", "id"), &FFMPEGMediaDecoder::is_video_buffer_full);
	ClassDB::bind_method(D_METHOD("is_video_buffer_empty", "id"), &FFMPEGMediaDecoder::is_video_buffer_empty);
	ClassDB::bind_method(D_METHOD("is_audio_enabled", "id"), &FFMPEGMediaDecoder::is_audio_enabled);
	ClassDB::bind_method(D_METHOD("set_audio_enable", "id", "is_enable"), &FFMPEGMediaDecoder::set_audio_enable);
	ClassDB::bind_method(D_METHOD("set_audio_all_ch_data_enable", "id", "is_enable"), &FFMPEGMediaDecoder::set_audio_all_ch_data_enable);
	ClassDB::bind_method(D_METHOD("get_audio_format", "id"), &FFMPEGMediaDecoder::get_audio_format);
	ClassDB::bind_method(D_METHOD("free_audio_data", "id"), &FFMPEGMediaDecoder::free_audio_data);
	ClassDB::bind_method(D_METHOD("set_seek_time", "id", "sec"), &FFMPEGMediaDecoder::set_seek_time);
	ClassDB::bind_method(D_METHOD("is_seek_over", "id"), &FFMPEGMediaDecoder::is_seek_over);
}

void FFMPEGMediaDecoder::clean_all() {
	nativeCleanAll();
}

int FFMPEGMediaDecoder::create_decoder(String file_path) {
	CharString utf8 = file_path.utf8();
	const char *cstr = utf8.get_data();

	int result;
	nativeCreateDecoder(cstr, result);
	return result;
}

int FFMPEGMediaDecoder::create_decoder_async(String file_path) {
	CharString utf8 = file_path.utf8();
	const char *cstr = utf8.get_data();

	int result;
	return nativeCreateDecoderAsync(cstr, result);
	return result;
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

bool FFMPEGMediaDecoder::is_video_enabled(int id) {
	return nativeIsVideoEnabled(id);
}

void FFMPEGMediaDecoder::set_video_enable(int id, bool is_enable) {
	nativeSetVideoEnable(id, is_enable);
}

Array FFMPEGMediaDecoder::get_video_format(int id) {
	int width;
	int height;
	float total_time;

	nativeGetVideoFormat(id, width, height, total_time);

	Array results;
	results.resize(3);

	results[0] = width;
	results[1] = height;
	results[2] = total_time;

	return results;
}

void FFMPEGMediaDecoder::set_video_time(int id, float current_time) {
	nativeSetVideoTime(id, current_time);
}

bool FFMPEGMediaDecoder::is_content_ready(int id) {
	return nativeIsContentReady(id);
}

bool FFMPEGMediaDecoder::is_video_buffer_full(int id) {
	return nativeIsVideoBufferFull(id);
}

bool FFMPEGMediaDecoder::is_video_buffer_empty(int id) {
	return nativeIsVideoBufferEmpty(id);
}

bool FFMPEGMediaDecoder::is_audio_enabled(int id) {
	return nativeIsAudioEnabled(id);
}

void FFMPEGMediaDecoder::set_audio_enable(int id, bool is_enable) {
	nativeSetAudioEnable(id, is_enable);
}

void FFMPEGMediaDecoder::set_audio_all_ch_data_enable(int id, bool is_enable) {
	nativeSetAudioAllChDataEnable(id, is_enable);
}

Array FFMPEGMediaDecoder::get_audio_format(int id) {
	int channel;
	int frequency;
	float total_time;

	nativeGetAudioFormat(id, channel, frequency, total_time);

	Array results;
	results.resize(3);

	results[0] = channel;
	results[1] = frequency;
	results[2] = total_time;

	return results;
}

void FFMPEGMediaDecoder::free_audio_data(int id) {
	nativeFreeAudioData(id);
}

void FFMPEGMediaDecoder::set_seek_time(int id, float sec) {
	nativeSetSeekTime(id, sec);
}

bool FFMPEGMediaDecoder::is_seek_over(int id) {
	return nativeIsSeekOver(id);
}
