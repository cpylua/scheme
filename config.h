#ifndef _SC_CONFIG_H_
#define _SC_CONFIG_H_

#define WELCOME_STR \
    "acs Copyright (C) 2012 cpylua<zombiefml@gmail.com>\n" \
    "Type (exit) to quit\n"

#define PROMPT "> "

/* comment this line to turn off logging */
#define ENABLE_LOG

/* uncomment this line to enable hash table debugging info */
/* #define DEBUG_HASHTBL */

/* hash table bucket size */
#define DEFAULT_BUCKET_NUM 4099

/* integer cache, inclusive */
#define INT_CACHE_HIGH 127
#define INT_CACHE_LOW -128


/* objects in a segment */
#define SEGMENT_SIZE    1024 * 128

/* default number of segments in heap */
#define DEFAULT_HEAP_SIZE   128

/* extend free_list if availale objects is less than this */
#define EXTEND_THRESHOLD    1024 * 32

/* triger gc if available objects is less than this */
#define GC_THRESHOLD    1024 * 5 

/* enable gc debugging info */
/*  #define GC_DEBUG_INFO */

/* enable rb-tree verification after each insertion */
/* #define VERIFY_RB_TREE */

/* application fold */
#define APP_DIR "/usr/share/asc/"

#endif

