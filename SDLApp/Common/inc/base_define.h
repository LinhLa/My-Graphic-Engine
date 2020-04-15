#pragma once
#ifndef BASE_DEFINE
#define BASE_DEFINE
#include <cstdint>
#include <utility>
#include <memmgr.h>
#include <argument_define.h>
#include <function_define.h>
#include <message_struct.h>
#include <error_info.h>

#define SCHEDULER_INTERVAL	uint32_t(300)
#define DEFAULT_ASSETS_PATH			".\\Asset"
#define CONFIG_FILE					".\\config.ini"

enum SERVICE_ID
{
	TEST_SERVICE_ID = 0,
	MEMORY_TRACKER_SERVICE_ID,
	SCENE_SERVICE_ID,
	RENDER_SERVICE_ID,
	CONFIG_SERVICE_ID,
	FRAME_SERVICE_ID,
	CONTENT_SERVICE_ID,
	LOG_SERVICE_ID,
	SERVICE_ID_MAX
};

enum MESSAGE_ID
{
	SERVICE_START = 0,

	MEMORY_START = 0x00000100,
	MEMORY_REPORT,
	MEMORY_END,

	TEST_START = 0x00000200,
	TEST_MEMORY,

	LOG_START = 0x00000300,
	LOG_DATA_IN,

	RENDER_START = 0x00000400,
	RENDER_SCREEN,
	RENDER_SCREEN_DONE,
	RENDER_SCREEN_RESOLUTION,
	RENDER_CONFIG_LOADED,
	RENDER_INSTANCE_UPDATE,
	SCREEN_SURFACE_UPDATE,
	RENDER_INSTANCE_UPDATED,
	RENDER_REGISTER_CALLBACK,
	RENDER_UNREGISTER_CALLBACK,
	RENDER_END,

	SCENE_START = 0x00000500,
	SCENE_LOAD_RESOURCE_DONE,
	SCENE_QUERRY_RESOURCE_SYNC,
	SCENE_QUERRY_RESOURCE_ASYNC,
	SCENE_QUERRY_RESOURCE_DONE,
	SCENE_ADD_RESOURCE,
	SCENE_REMOVE_RESOURCE,
	SCENE_LOAD_RESOURCE,
	SCENE_UNLOAD_RESOURCE,
	SCENE_INIT_DONE,

	CONFIG_START =0x00000600,
	CONFIG_LOAD,
	CONFIG_UPDATE_LOG_LEVEL,
	CONFIG_UPDATE_FULL_SCREEN,
	CONFIG_UPDATE_SCREEN_HEIGHT,
	CONFIG_UPDATE_SCREEN_WIDTH,
	CONFIG_UPDATE_POOL_SIZE,
	CONFIG_UPDATE_CHUNK_SIZE,
	CONFIG_UPDATE_DATA_FILE,
	CONFIG_UPDATE_ASSET_PATH,
	CONFIG_UPDATE_VERSION,
	CONFIG_UPDATE_FPS,
	CONFIG_LOADED,

	TASK_START = 0x00000700,
	TASK_STARTED,
	TASK_STOPPED,
	TASK_DONE,

	CONTENT_START = 0x00000800,

	SERVICE_END,
};


#define RENDER_REGISTER_CALLBACK(pServiceMgr, Callable, Event) \
(pServiceMgr->sendMessage({ RENDER_REGISTER_CALLBACK, message_function(Callable, int32_t(Event)) }) )

#define RENDER_UNREGISTER_CALLBACK(pServiceMgr, Callable, Event) \
(pServiceMgr->sendMessage({ RENDER_UNREGISTER_CALLBACK, message_function(Callable, int32_t(Event))}) )


#endif