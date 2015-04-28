#ifndef __SPEEDC_MACROS_H
#define __SPEEDC_MACROS_H

#ifdef DPRINT
	#define dprintf(...) printf(__VA_ARGS__)
#else
	#define dprintf(...)
#endif


#define COPY_SPEEDCODEPART_SPEC(src, dest)\
	(dest).Parameters = (src).Parameters;\
	(dest).Setup = (src).Setup;\
	(dest).Callback = (src).Callback;\
	(dest).Teardown = (src).Teardown;\
	(dest).Repeats = (src).Repeats;\
	(dest).Size = (src).Size;\
	(dest).AssemblyCode = (src).AssemblyCode;

#define COPY_SPEEDCODE_SPEC(src, dest)\
	(dest).PartSpec = (src).PartSpec;\
	(dest).Max.Part = (src).Max.Part;\
	(dest).Max.x = (src).Max.x;\
	(dest).Max.y= (src).Max.y;\
	(dest).Max.z = (src).Max.z;

#endif
