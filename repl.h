#ifndef _SC_REPL_H_
#define _SC_REPL_H_

#include "object.h"

int sc_repl(char *file);
void repl_exit(void);
object* get_repl_env(void);

#endif

