#include <stdio.h>
#include "sc_config.h"
#include "sc_object.h"
#include "sc_reader.h"
#include "sc_print.h"
#include "sc_eval.h"
#include "sc_repl.h"
#include "sc_env.h"

static int keep_run = 1;
static object *global_env;

static int init(void) {
    global_env = make_base_env();
    if (global_env == NULL) {
        return -1;
    }

    return 0;
}

int sc_repl(void) {
    object *exp, *val;
    int ret = 0;
    int err_cnt = 0;
    FILE *in, *out;

    if (init() != 0) {
        return -1;
    }

    in = stdin;
    out = stdout;
    printf("%s", WELCOME_STR);
    while (keep_run) {
        if (err_cnt > 0) {
            printf("%d%s", err_cnt, PROMPT);
        } else {
            printf("%s", PROMPT);
        }

        exp = sc_read(in);
        if (exp == NULL) {
            err_cnt++;
            continue;
        }
        if (is_eof_object(exp)) {
            break;
        }

        val = sc_eval(exp, global_env);
        if (val == NULL) {
            err_cnt++;
            continue;
        }

        ret = sc_write(out, val);
        printf("\n");
        if (ret != 0) {
            break;
        }
    }

    return ret;
}

void repl_exit(void) {
    keep_run = 0;
}

object* get_repl_env(void) {
    return global_env;
}

