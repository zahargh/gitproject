#include "header.h"
#include "file_processing.h"
#include <sys/stat.h>
#include <dirent.h>
int find_repo(char* cwd){
    if(!getcwd(cwd,sizeof(cwd))){
        return 1;
    }
    char tmp_cwd[1024];
    struct  dirent * entry;
    bool exists=false;
    do{
        DIR* dir=opendir(".");
        if(dir==NULL){
            perror("error opening current directory\n");
            return 1;
        }
        while ((entry = readdir(dir)) != NULL) {
            if (/*entry->d_type =="DT_DIR" && */strcmp(entry->d_name, ".neogit") == 0){
                exists = true;
                // return getcwd(entry->d_name,sizeof(entry->d_name));
                return 1;
                //break;
                }
        }
        closedir(dir);
        if(exists)break;
        if(!getcwd(tmp_cwd,sizeof(tmp_cwd))){perror("");return 1;}
        if(strcmp(tmp_cwd,"/")!=0){
            if(!chdir("..")){
               // perror("error\n");
                return 1;
            }
        }
    }while(strcmp(tmp_cwd,"/")!=0);
    if(chdir(cwd)!=0) return 1;
    if(!exists){
        return 1;
    }

}
///////////////////////////////////////////////////////
void init(char * argv[]){
    char cwd[1024];
    if(find_repo(getcwd(cwd,sizeof(cwd)))){
        perror("neogit repo already exists\n");
        return ;
    }
   else{
        if(mkdir(".neogit",0755)!=0){
            perror("unable to make the repo\n");
            return ;
       }
    }
     
}
//////////////////////////////////////////////////////
// char* compareFileTimes(char *file1, char *file2) {
//     struct stat stat1, stat2;
//     // if (stat(file1, &stat1) != 0) {
//     //     perror("Error getting information about file 1");
//     //     return NULL;
//     // }
//     // if (stat(file2, &stat2) != 0) {
//     //     perror("Error getting information about file 2");
//     //     return NULL;
//     // }
//     if(!file1) return file2;
//     if(!file2) return file1;
//     if (stat1.st_mtime > stat2.st_mtime) {
//         return file1;
//     } else if (stat1.st_mtime < stat2.st_mtime) {
//     return file2;
//     }
// }
// //////////////////////////////////////////////////////
// void creat_config_global(char name[100],char email[100]){
//     char* file_global,file_local;
//     if(find_repo(".neogit/config_global.txt")){
//         file_global=find_repo(".neogit/config_global.txt");
//     }
//     else 
//         file_global=NULL;
//     if(find_repo(".neogit/config_local.txt")){
//         file_local=find_repo(".neogit/config_local.txt");
//     }
//     else
//         file_local=NULL;
//     char* file_name=compareFileTimes(file_global,file_local);
//     FILE* file=fopen(file_name,"w");
//     if(strcmp(name,NULL)){
//         fprintf(file,"username:%s\n",name);
//     }
//     if(strcmp(email,NULL)){
//         fprintf(file,"email:%s\n",email);
//     }
//     fclose(file);
// }
// ////////////////////////////////////////////////////
// void creat_config(char name[100],char email[100]){
//     char file_name[100]=find_repo(".neogit/config_local.txt");
//     FILE* file=fopen(file_name,"w");
//     if(strcmp(name,NULL)){
//         fprintf(file,"username:%s\n",name);
//     }
//     if(strcmp(email,NULL)){
//         fprintf(file,"email:%s\n",email);
//     }
 
// }
// ///////////////////////////////////////////////////