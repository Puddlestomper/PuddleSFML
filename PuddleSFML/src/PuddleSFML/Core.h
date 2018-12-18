#pragma once

#ifdef PUDL_BUILD_DLL
	#define PUDL_API _declspec(dllexport)
#else
	#define PUDL_API _declspec(dllimport)
#endif

