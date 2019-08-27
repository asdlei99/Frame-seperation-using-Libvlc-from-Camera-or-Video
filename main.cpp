#include <stdio.h>
#include <stdlib.h>
#include <vlc/vlc.h>
#include<Windows.h>
#include<iostream>
#include <string>
#include <iostream>
#include <filesystem>
#include<string>
#include <windows.h>
#include <iostream>
using namespace std;
libvlc_instance_t* libvlc_new(
	int argc,               // 引数の数
	const char* const* argv // 引数のリスト (VLC media playerへ渡すコマンドと同じ)
);


int libvlc_video_take_snapshot(
	libvlc_media_player_t* p_mi, // 
	unsigned num,                // number of video outputs 
	const char* psz_filepath,    // path to save screenshot
	unsigned int i_width,        // 
	unsigned int i_height        // 
);
void ShowConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

int main(int argc, char* argv[])
{

	ShowConsole();


	libvlc_instance_t* inst;
	libvlc_media_player_t* mp;
	libvlc_media_t* m;

	char smem_options[1000];

	const char* const vlc_args[] = {
			"--intf", "dummy",                  /* no interface                   */
           "--vout", "dummy",                  /* we don't want video (output)   */
		 
	};

	/* Load the VLC engine */
	//const char* args = "vlc-Idummy";
	//inst = libvlc_new(0,args);
	inst = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);

	/* Create a new item */
	m = libvlc_media_new_location(inst, "rtsp address or video file path");
	//m = libvlc_media_new_path (inst, "/path/to/test.mov");

	/* Create a media player playing environement */
	mp = libvlc_media_player_new_from_media(m);

	/* No need to keep the media now */
	libvlc_media_release(m);

#if 0
	/* This is a non working code that show how to hooks into a window,
	 * if we have a window around */
	 //libvlc_media_player_set_xwindow(mp, xid);
	 /* or on windows */
	libvlc_media_player_set_hwnd(mp, hwnd);

	/* or on mac os */
	libvlc_media_player_set_nsobject(mp, view);
#endif

	//libvlc_media_player_set_hwnd(mp, hwnd);

	/* ?????????????? */
	//libvlc_media_player_play(media_player);
	/* play the media_player */
	libvlc_media_player_play(mp);
	//Stealth(); //to hide console window

	Sleep(100);


	int index = 1;

	while (1) {

		Sleep(100); /* Let it play a bit */




		const char* image_path = "E:\\frames\\image.jpg";

		int result = libvlc_video_take_snapshot(mp, 0, image_path, 0, 0);




	}

	/* Stop playing */
	libvlc_media_player_stop(mp);

	/* Free the media_player */
	libvlc_media_player_release(mp);

	libvlc_release(inst);

	return 0;
}