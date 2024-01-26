#include "header.h"
#include "file_processing.h"
//#define _deb
#ifdef _deb
int main(){
        int argc=;
        char const* argv[]={"",""};
 #else
int main(int argc,char const* argv[]){
#endif
    // if(argv[1]=="config"){
    //     if(argv[2]=="-global"){
    //         if(argv[3]=="user.name"){

    //         }
    //         else if(argv[3]=="user.email"){

    //         }
    //         else if(!strncmp(argv[3]=="alias.",6)){

    //         }
    //     }
    //     else{
    //         if(argv[2]=="user.name"){

    //         }
    //         else if(argv[2]=="user.email"){

    //         }
    //         else if(!strncmp(argv[2],"alias.",6)){

    //         }
    //     }

    // }
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
    printf("hello");
    for(int i=0;i<argc;i++)
    printf("%s\n",argv[i]);
    return 0;
    
}