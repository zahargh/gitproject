#ifndef __FILEPROCESS_H__
#define __FILEPROCESS_H__

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <time.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
int find_repo(char*);
void init(char ** );
char* compareFileTimes(char *, char *);
void creat_config_global(char *,char*);
void creat_config(char*,char *);
#endif