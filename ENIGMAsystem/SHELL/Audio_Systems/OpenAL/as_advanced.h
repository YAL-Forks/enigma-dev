/** Copyright (C) 2008-2013 Josh Ventura, Robert B. Colton
***
*** This file is a part of the ENIGMA Development Environment.
***
*** ENIGMA is free software: you can redistribute it and/or modify it under the
*** terms of the GNU General Public License as published by the Free Software
*** Foundation, version 3 of the license or any later version.
***
*** This application and its source code is distributed AS-IS, WITHOUT ANY
*** WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
*** FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
*** details.
***
*** You should have received a copy of the GNU General Public License along
*** with this code. If not, see <http://www.gnu.org/licenses/>
**/

// ***** New Sound System *****

enum { 
  audio_falloff_exponent_distance,
  audio_falloff_exponent_distance_clamped,
  audio_falloff_inverse_distance,
  audio_falloff_inverse_distance_clamped,
  audio_falloff_linear_distance,
  audio_falloff_linear_distance_clamped,
  audio_falloff_none,
  audio_old_system,
  audio_new_system
};


bool audio_exists(int index);
bool audio_is_playing(int index);

void audio_play_music(int index, bool loop);
void audio_pause_music();
void audio_resume_music();
void audio_stop_music(); 

int audio_play_sound(int index, double priority, bool loop);
int audio_play_sound_at(int sound, double x, double y, double z, int falloff_ref, double falloff_max, double falloff_factor, bool loop, double priority);
void audio_pause_sound(int index);
void audio_resume_sound(int index);
void audio_stop_sound(int index);
void audio_pause_all();
void audio_resume_all();
void audio_stop_all();

void audio_music_seek(double offset);
void audio_sound_seek(int index, double offset);
double audio_music_offset();
double audio_sound_offset(int index);

void audio_listener_orientation(double lookat_x, double lookat_y, double lookat_z, double up_x, double up_y, double up_z);
void audio_listener_position(double x, double y, double z);
void audio_listener_velocity(double vx, double vy, double vz);

double audio_sound_length(int index);
void audio_master_gain(float volume, double time);
void audio_music_gain(int index, float volume, double time);
void audio_sound_gain(int index, float volume, double time);

int audio_get_type(int index);
void audio_channel_num(int num);

int audio_system();
int audio_add(string fname, int type);
void audio_delete(int sound);
void audio_falloff_set_model(int model);

int audio_emitter_create();
bool audio_emitter_exists(int index);
void audio_emitter_falloff(int emitter, double falloff_ref, double falloff_max, double falloff_factor);
void audio_emitter_free(int emitter);
void audio_emitter_gain(int emitter, double gain);
void audio_emitter_pitch(int emitter, double pitch);
void audio_emitter_position(int emitter, double x, double y, double z);
void audio_emitter_velocity(int emitter, double vx, double vy, double vz);
void audio_play_sound_on(int emitter, int sound, bool loop, double priority);

