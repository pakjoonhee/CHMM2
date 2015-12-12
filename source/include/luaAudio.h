/*----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#------  This File is Part Of : ----------------------------------------------------------------------------------------#
#------- _  -------------------  ______   _   --------------------------------------------------------------------------#
#------ | | ------------------- (_____ \ | |  --------------------------------------------------------------------------#
#------ | | ---  _   _   ____    _____) )| |  ____  _   _   ____   ____   ----------------------------------------------#
#------ | | --- | | | | / _  |  |  ____/ | | / _  || | | | / _  ) / ___)  ----------------------------------------------#
#------ | |_____| |_| |( ( | |  | |      | |( ( | || |_| |( (/ / | |  --------------------------------------------------#
#------ |_______)\____| \_||_|  |_|      |_| \_||_| \__  | \____)|_|  --------------------------------------------------#
#------------------------------------------------- (____/  -------------------------------------------------------------#
#------------------------   ______   _   -------------------------------------------------------------------------------#
#------------------------  (_____ \ | |  -------------------------------------------------------------------------------#
#------------------------   _____) )| | _   _   ___   ------------------------------------------------------------------#
#------------------------  |  ____/ | || | | | /___)  ------------------------------------------------------------------#
#------------------------  | |      | || |_| ||___ |  ------------------------------------------------------------------#
#------------------------  |_|      |_| \____|(___/   ------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#- Licensed under the GPL License --------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#- Copyright (c) Nanni <lpp.nanni@gmail.com> ---------------------------------------------------------------------------#
#- Copyright (c) Rinnegatamante <rinnegatamante@gmail.com> -------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#- Credits : -----------------------------------------------------------------------------------------------------------#
#-----------------------------------------------------------------------------------------------------------------------#
#- Smealum for ctrulib -------------------------------------------------------------------------------------------------#
#- StapleButter for debug font -----------------------------------------------------------------------------------------#
#- Lode Vandevenne for lodepng -----------------------------------------------------------------------------------------#
#- Jean-loup Gailly and Mark Adler for zlib ----------------------------------------------------------------------------#
#- Special thanks to Aurelio for testing, bug-fixing and various help with codes and implementations -------------------#
#-----------------------------------------------------------------------------------------------------------------------*/

// Additional encoding
typedef enum{
	CSND_ENCODING_VORBIS = 4
}CSND_EXTRA_ENCODING;

// Audio structs
struct PurgeTable{
	ndspWaveBuf* pointer;
	PurgeTable* next;
};

struct Music{
	u32 magic;
	u32 samplerate;
	u16 bytepersample;
	u8* audiobuf;
	u8* audiobuf2;
	ndspWaveBuf* wavebuf;
	ndspWaveBuf* wavebuf2;
	u16 lastCheck;
	u32 size;
	u32 mem_size;
	Handle sourceFile;
	u32 startRead;
	char author[256];
	char title[256];
	u32 resumeSample;
	u64 tick;
	bool isPlaying;
	u32 ch;
	u8 audiotype;
	bool streamLoop;
	bool big_endian;
	u8 encoding;
	PurgeTable* blocks;
	u32* thread;
	u32 audio_pointer;
};

struct wav{
	u32 magic;
	u32 samplerate;
	u16 bytepersample;
	u8* audiobuf;
	u8* audiobuf2;
	u32 size;
	u32 mem_size;
	Handle sourceFile;
	u32 startRead;
	char author[256];
	char title[256];
	u32 moltiplier;
	u64 tick;
	bool isPlaying;
	u32 ch;
	u32 ch2;
	bool streamLoop;
	bool big_endian;
	u8 encoding;
	u32* thread;
	u32 audio_pointer;
	u32 package_size;
	u32 total_packages_size;
	u32 loop_index;
};

// Ausiliar audio functions prototypes
void My_CSND_playsound(u32 chn, u32 flags, u32 sampleRate, u32 *data0, u32 *data1, u32 size, float vol, float pan);
void createDspBlock(ndspWaveBuf* waveBuf, u16 bps, u32 size, bool loop, u32* data);
void populatePurgeTable(Music* songFile, ndspWaveBuf* waveBuf);
void purgeTable(PurgeTable* tbl);
