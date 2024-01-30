#include "header.h"
#include "file_processing.h"
int main(int argc,char * argv[]){
    if(argc<2){
        perror("invalid command\n");
        return 1;
    }
    //  if(is_alias(argv[1])){
    //     argv=is_alias(argv[1]);
    // }
    if(!strcmp(argv[1],"config")&&!strcmp(argv[2],"-global")&&!strncmp(argv[3],"alias.",6)){
        for(int i=0;i<strlen(argv[3])-6;i++){
            argv[3][i]=argv[3][i+6];
        }
        argv[3][strlen(argv[3])-6]='\0';
        if(!is_valid(argv[4])){
            printf("the cammand entered ain't valid\n");
        }
        else
            alias_global(argv[3],argv[4]);  
        return 0;   
    }
    else if(!strcmp(argv[1],"config")&&!strncmp(argv[2],"alias.",6)){
        for(int i=0;i<strlen(argv[2])-6;i++){
            argv[2][i]=argv[2][i+6];
        }
        argv[2][strlen(argv[2])-6]='\0';
        if(!is_valid(argv[3])){
            printf("the cammand entered ain't valid\n");
        }
        else 
            alias(argv[2],argv[3]);
        return 0;     
    } 
    else if(strcmp(argv[1],"config")==0){
        if(!strcmp(argv[2],"-global")){
            if(!strcmp(argv[3],"user.name")){
                creat_config_global(argv[4],NULL);
            }
            else if(!strcmp(argv[3],"user.email")){
                creat_config_global(NULL,argv[4]);
            }
        }
        else{
            if(!strcmp(argv[2],"user.name")){
                creat_config(argv[3],NULL);
            }
            else if(!strcmp(argv[2],"user.email")){
                creat_config(NULL,argv[3]);
            }
        }

    }
    else if(!strcmp(argv[1],"init")){
        init(argv);
    }
    /////////////////////////////////////////////////////
    else if(!strcmp(argv[1],"add")){ 
        if(!strcmp(argv[2],"-f")){
            for(int i=3;i<argc;i++){
                char str[60];
                strcpy(str,argv[i]);
                if(strstr(str,"*")){
                    char* result=wild_card(argv[i]);
                    memset(argv[i],'\0',strlen(argv[i]));
                    strcpy(argv[i],result);
                }
                add_to_staging_type(argv[i]);
            }
        }
        else if(!strcmp(argv[2],"-n")){
            int depth;
            if(argc>3) 
                depth=(argv[3]-'0');
            else
                depth=1;
            //show dir and file heres with state of them staging or not 
            show_file_staged(depth);     
        }
        else if(!strcmp(argv[2],"-redo")){
            add_redo();
        }
        else{
            char str[50];
            strcpy(str,argv[2]);
            if(strstr(str,"*")){
                char* result=wild_card(argv[2]);
                memset(argv[2],'\0',strlen(argv[2]));
                strcpy(argv[2],result);
            }
            add_to_staging_type(argv[2]);
        }
    }
    // else if(argv[1]=="reset"){
    //     if(argv[2]=="-undo"){

    //     }
    //     else if(argv[2]=="-f"){

    //     }
    //     else{

    //     }
    // }
    // else if(argv[1]=="status"){

    // }
    else
        perror ("invalid command\n");
    printf("\n");
    for(int i=0;i<argc;i++)
    printf("%s\n",argv[i]);
    return 0;
    
}
