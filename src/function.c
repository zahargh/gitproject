#include "header.h"
#include "file_processing.h"
#include <sys/stat.h>
#include <dirent.h>
#include<stdlib.h>
char * global_address="/mnt/f/project/";
char* make_address(char dir[30],char file[30]){
    char  address[100];
    memset(address,'\0',strlen(address));
    strcat(address,global_address);
    if(dir!=NULL) strcat(address,dir);
    strcat(address,file);
    return address;
}

int find_repo(char* cwd){
    getcwd(cwd,sizeof(cwd));
   
    char tmp_cwd[1024];
    struct  dirent * entry;
    int exists=0;    
    do{
        DIR* dir=opendir(".");
        while ((entry = readdir(dir)) != NULL) {
           // printf("%s\n",entry->d_name);
            if (/*!strcmp(entry->d_type ,"DT_DIR") && */strcmp(entry->d_name,".neogit") == 0){     
                exists = 1;
            }
        }
        closedir(dir);
        if(exists)break; 
        getcwd(tmp_cwd,sizeof(tmp_cwd));
        if(strcmp(tmp_cwd,"/")==0){
            break;
        }
        chdir("..");
 
    }while(strcmp(tmp_cwd,"/")!=0);
    chdir(cwd) ;
    if(exists){
        return 0;
    }
    if(!exists){
        return 1;
    }
}
///////////////////////////////////////////////////////
int find_repo_con_gol(char* cwd,char* name,char* email){
    getcwd(cwd,sizeof(cwd));
    char tmp_cwd[1024];
    struct  dirent * entry;
    int exists=0;    
    do{
        DIR* dir=opendir(".");
        while ((entry = readdir(dir)) != NULL) {
            if (/*!strcmp(entry->d_type ,"DT_DIR") && */strcmp(entry->d_name,".neogit") == 0){
                bool global=false,local=false; 
                chdir(".neogit");  
                char file_n_g[100];
                memset(file_n_g,'\0',sizeof(file_n_g));
                strcat(file_n_g,global_address);
                strcat(file_n_g,"config_g_n.txt");
                char file_e_g[100];
                memset(file_e_g,'\0',sizeof(char));
                strcat(file_e_g,global_address);
                strcat(file_e_g,"config_g_e.txt");
                if(name){
                    if (access(file_n_g,F_OK) == 0){
                        global= true;
                    }
                    if (access("config_l_n.txt",F_OK) == 0){
                        local= true;
                    }
                    FILE* file;
                    // if(global&&local){
                    //     int which=compareFileTimes(file_n_g,"config_l_n.txt");
                
                    //     switch (which){
                    //         case 1:
                    //             file=fopen(file_n_g,"w");
                    //         break;
                    //         case 2:{
                    //             file=fopen("config_l_n.txt","w");
                    //             FILE* f=fopen(file_n_g,"w");
                    //             fprintf(f,"username:%s\n",name);
                    //             fclose(f);
                    //         }
                                
                    //         break;
                    //     }
                    // }
                    // else{
                        file=fopen(file_n_g,"w");
                    // }
                    fprintf(file,"username:%s\n",name);
                    fclose(file);

                    
                } 
                if(email){if (access(file_e_g,F_OK) == 0){
                        global= true;
                    }
                    if (access("config_l_e.txt",F_OK) == 0){
                        local= true;
                    }
                    FILE* file;
                    char tmp[1024];getcwd(tmp,sizeof(tmp));
                    strcat(tmp,"config_l_e.txt");
                    // if(global&&local){
                    //     int which=compareFileTimes(file_e_g,tmp);
                
                    //     switch (which){
                    //         case 1:
                    //             file=fopen(file_e_g,"w");
                    //         break;
                    //         case 2:
                    //             file=fopen("config_l_e.txt","w");
                    //             // FILE* f=fopen(file_e_g,"w");
                    //             // fprintf(f,"email:%s\n",email);
                    //             // fclose(f);
                            
                    //         break;
                    //     }
                    // }
                    // else{
                        file=fopen(file_e_g,"w");
                    // }
                    fprintf(file,"email:%s\n",email);
                    fclose(file);            
                }
                exists = 1;
                break;
            }
        }
        closedir(dir);
        if(exists)break; 
        getcwd(tmp_cwd,sizeof(tmp_cwd));
        if(strcmp(tmp_cwd,"/")==0){
            break;
        }
        chdir("..");
 
    }while(strcmp(tmp_cwd,"/")!=0);
    chdir(cwd) ;
    if(exists){
        return 0;
    }
    if(!exists){
        return 1;
    }
}
////////////////////////////////////////////////////////
int find_repo_con_loc(char* cwd,char* name,char* email){
    getcwd(cwd,sizeof(cwd));
   
    char tmp_cwd[1024];
    struct  dirent * entry;
    int exists=0;    
    do{
        DIR* dir=opendir(".");
        while ((entry = readdir(dir)) != NULL) {
            if (/*!strcmp(entry->d_type ,"DT_DIR") && */strcmp(entry->d_name,".neogit") == 0){
                bool global=false,local=false; 
                chdir(".neogit");
                if(name){
                    FILE* file;
                    file=fopen("config_l_n.txt","w");
                    fprintf(file,"username:%s\n",name);
                    fclose(file);         
                } 
                if(email){
                    FILE* file;
                    file=fopen("config_l_e.txt","w");
                    fprintf(file,"email:%s\n",email);
                    fclose(file);        
                }
                exists = 1;
                break;
            }
        }
        closedir(dir);
        if(exists)break; 
        getcwd(tmp_cwd,sizeof(tmp_cwd));
        if(strcmp(tmp_cwd,"/")==0){
            break;
        }
        chdir("..");
 
    }while(strcmp(tmp_cwd,"/")!=0);
    chdir(cwd) ;
    if(exists){
        return 0;
    }
    if(!exists){
        return 1;
    }
}
///////////////////////////////////////////////////////
void init(char * argv[]){
    char cwd[1024];
    if(!find_repo(getcwd(cwd,sizeof(cwd)))){
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
////////////////////////////////////////////////////////////////////////////////////////
int compareFileTimes(char *file1, char *file2) {
    struct stat stat1, stat2;
    stat(file1,&stat1);
    stat(file2,&stat2);
    if(!file1) return 2;
    if(!file2) return 1;
    if (stat1.st_mtime < stat2.st_mtime) {
        return 1;
    } else if (stat1.st_mtime < stat2.st_mtime) {
        return 2;
    }
    else
     return 0;
}
// //////////////////////////////////////////////////////
void creat_config_global(char name[100],char email[100]){
    char cwd[1024];
    if(find_repo_con_gol(cwd,name,email)){
        perror("you don't have a repo yet\n");
        return;
    }
}
// ////////////////////////////////////////////////////
void creat_config(char name[100],char email[100]){  
    char cwd[1024];
    if(find_repo_con_loc(cwd,name,email)){
        perror("you don't have a repo yet\n");
        return;
    }
}
// ///////////////////////////////////////////////////
void alias(char* filename,char*command){
    char cwd[1024];
    strcat(filename,".txt");
    getcwd(cwd,sizeof(cwd));
    char tmp_cwd[1024];
    struct  dirent * entry;
    int exists=0;    
    do{
        DIR* dir=opendir(".");
        while ((entry = readdir(dir)) != NULL) {
            if (/*!strcmp(entry->d_type ,"DT_DIR") && */strcmp(entry->d_name,".neogit") == 0){     
                exists = 1;
                chdir(".neogit");
                FILE* file=fopen(filename,"w");
                fprintf(file,"%s\n",command);
                fclose(file);
            }
        }
        closedir(dir);
        if(exists)break; 
        getcwd(tmp_cwd,sizeof(tmp_cwd));
        if(strcmp(tmp_cwd,"/")==0){
            break;
        }
        chdir(".."); 
    }while(strcmp(tmp_cwd,"/")!=0);
    chdir(cwd) ;
    if(!exists)perror("there ain't a repo yet\n");
    return;
}
///////////////////////////////////////////////////////////////////
void alias_global(char* filename,char*command){
    char cwd[1024];
    getcwd(cwd,sizeof(cwd));
    strcat(filename,".txt");
    char tmp_cwd[1024];
    struct  dirent * entry;
    int exists=0;    
    do{
        DIR* dir=opendir(".");
        while ((entry = readdir(dir)) != NULL) {
            if (/*!strcmp(entry->d_type ,"DT_DIR") && */strcmp(entry->d_name,".neogit") == 0){     
                exists = 1;
                char file_address[100];
                memset(file_address,'\0',strlen(file_address));
                strcat(file_address,global_address);
                strcat(file_address,"alias/");
                strcat(file_address,filename);
                FILE* file=fopen(file_address,"w");
                fprintf(file,"%s\n",command);
                fclose(file);
                return;
            }
        }
        closedir(dir);
        if(exists)break; 
        getcwd(tmp_cwd,sizeof(tmp_cwd));
        if(strcmp(tmp_cwd,"/")==0){
            break;
        }
        chdir(".."); 
    }while(strcmp(tmp_cwd,"/")!=0);
    chdir(cwd) ;
    if(!exists)perror("there ain't a repo yet\n");
    return;
}
/////////////////////////////////////////////////////////////
int is_valid(char*command){
    if(!strncmp(command,"neogit add",10)) return 1;
    if(!strncmp(command,"neogit revert",13)) return 1;
    if(!strncmp(command,"neogit tag",10)) return 1;
    if(!strcmp(command,"neogit tree")) return 1;
    if(!strncmp(command,"neogit stash",12)) return 1;
    if(!strcmp(command,"neogit pre-commit hooks list")) return 1;
    if(!strcmp(command,"neogit pre-commit applied hooks")) return 1;
    if(!strncmp(command,"neogit pre-commit add hook",26)) return 1;
    if(!strncmp(command,"neogit pre-commit remove hook",29)) return 1;
    if(!strncmp(command,"neogit pre-commit",17)) return 1;
    if(!strncmp(command,"neogit pre-commit -u",20)) return 1;
    if(!strncmp(command,"neogit pre-commit -f",20)) return 1;
    if(!strncmp(command,"neogit grep -f",14)) return 1;
    if(!strncmp(command,"neogit diff -",13)) return 1;
    if(!strncmp(command,"neogit merge",12)) return 1;
    if(!strncmp(command,"neogit config -global user.name ",32)) return 1;
    if(!strncmp(command,"neogit config -global user.email ",33)) return 1;
    if(!strncmp(command,"neogit config user.name ",24)) return 1;
    if(!strncmp(command,"neogit config user.email ",25)) return 1;
    if(!strncmp(command,"neogit config alias.",20)) return 1;
    if(!strncmp(command,"neogit config -global alias.",29)) return 1;
    if(!strcmp(command,"neogit init")) return 1;
    if(!strncmp(command,"neogit add ",11)) return 1;
    if(!strncmp(command,"neogit reset ",13)) return 1;
    if(!strcmp(command,"neogit status")) return 1;
    if(!strncmp(command,"neogit commit ",14)) return 1;
    if(!strncmp(command,"neogit set ",11)) return 1;
    if(!strncmp(command,"neogit replace ",15)) return 1;
    if(!strncmp(command,"neogit remove ",14)) return 1;
    if(!strncmp(command,"neogit log ",11)) return 1;
    if(!strncmp(command,"neogit checkout ",16)) return 1;
    if(!strncmp(command,"neogit branch ",14)) return 1;
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char** is_alias(char* filename){
    char* output[30];
    strcat(filename,".txt");
    char cwd[1024];
    getcwd(cwd,sizeof(cwd));
    char tmp_cwd[1024];
    struct  dirent * entry;
    int exists=0;    
    do{
        DIR* dir=opendir(".");
        while ((entry = readdir(dir)) != NULL) {
            if (/*!strcmp(entry->d_type ,"DT_DIR") && */strcmp(entry->d_name,".neogit") == 0){   
                chdir(".neogit");
                FILE* file;
                if(file=fopen(filename,"r")){
                    char word[20][20];
                    exists = 1;
                    char* line;
                    fgets(line,sizeof(line),file);
                    line[strlen(line)-1]='\0';
                    char* token=strtok(line," ");
                    strcpy(word[0],token);
                    int ind=0;
                    while(token){
                        ind++;
                        token=strtok(NULL," ");
                        strcpy(word[ind],token);
                    }
                    fclose(file);
                    chdir(cwd) ;
                    return word;
                }               
            }
        }
        closedir(dir);
        if(exists)break; 
        getcwd(tmp_cwd,sizeof(tmp_cwd));
        if(strcmp(tmp_cwd,"/")==0){
            break;
        }
        chdir(".."); 
    }while(strcmp(tmp_cwd,"/")!=0);
    chdir(cwd) ;
    if(!exists){
        strcat(filename,".txt");
        char file_address[100];
        memset(file_address,'\0',strlen(file_address));
        strcat(file_address,global_address);
        strcat(file_address,"alias/");
        strcat(file_address,filename);
        FILE* file;
        if(file=fopen(file_address,"r")){
            char word[20][20];
            char* line;
            fgets(line,sizeof(line),file);
            line[strlen(line)-1]='\0';
            char* token=strtok(line," ");
            strcpy(word[0],token);
            int ind=0;
            while(token){
                ind++;
                token=strtok(NULL," ");
                strcpy(word[ind],token);
            }
            fclose(file);
            chdir(cwd) ;
            return word;
            }
        } 
     chdir(cwd) ;
    return NULL;
}
/////////////////////////////