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
char* make_address(char*,char*);
int find_repo(char*);
void init(char ** );
int compareFileTimes(char *, char *);
void creat_config_global(char *,char*);
void creat_config(char*,char *);
void alias(char*,char*);
int is_valid(char*);
char** is_alias(char*);
void alias_global(char*,char*);

#endif