#include "header.h"
#include "file_processing.h"
 int main(int argc,char * argv[]){
    if(argc<2){
        perror("invalid command\n");
        return 1;
    }
    // if(strcmp(argv[1],"config")==0){
    //     if(!strcmp(argv[2],"-global")){
    //         if(!(argv[3],"user.name")){
    //             creat_config_global(argv[4],NULL);
    //         }
    //         else if(!strcmp(argv[3],"user.email")){
    //             creat_config_global(NULL,argv[4]);
    //         }
    //         else if(!strncmp(argv[3],"alias.",6)){

    //         }
    //     }
    //     else{
    //         if(!strcmp(argv[2],"user.name")){
    //             creat_config(argv[4],NULL);
    //         }
    //         else if(!strcmp(argv[2],"user.email")){
    //             creat_config(NULL,argv[4]);
    //         }
    //         else if(!strncmp(argv[2],"alias.",6)){

    //         }
    //     }

    // }
    else if(!strcmp(argv[1],"init")){
        init(argv);
    }
    // else if(argv[1]=="add"){  
    //     if(argv[2]=="-f"){
    //         for(int i=3;i<argc;i++){
    //             add_to_staging(argv[i]);
    //         }
    //     }
    //     else if(argv[2]=="-n"){
    //         int depth=argv[3];
    //         //show dir and file heres with state of them staging or not 
    //     }
    //     else if(argv[2]=="-redo"){
    //         //search for files and add to staging
    //     }
    //     else{
    //         add_to_staging(argv[2]);
    //     }
    // }
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
    printf("hello\n");
    for(int i=0;i<argc;i++)
    printf("%s\n",argv[i]);
    return 0;
    
}
