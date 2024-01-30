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
#include <string.h>
#include<limits.h>
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
void copy_file(char* ,char*);
void add_to_staging_file(char*);
void add_redo();
int is_dir(char*);
void add_to_staging_type(char*);
char* wild_card(char* );
int is_wild(char *,char *);
void show_file_staged(int);
int find_file_in_stage(char*, char*);
int compareFiles(char* , char* ); 

#endif