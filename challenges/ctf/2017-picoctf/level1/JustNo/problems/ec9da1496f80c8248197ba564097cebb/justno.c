#include <stdio.h>                                                    
#include <stdlib.h>                                                   
#include <string.h>                                                   
#include <unistd.h>                                                   
#include <sys/types.h>                                                

int main(int argc, char **argv){                                      
  FILE* authf = fopen("../../problems/ec9da1496f80c8248197ba564097cebb/auth","r"); //access auth file in ../../../problems/ec9da1496f80c8248197ba564097cebb                                                       
  if(authf == NULL){                                                  
    printf("could not find auth file in ../../problems/ec9da1496f80c8248197ba564097cebb/\n");                                               
    return 0;                                                         
  }                                                                   
  char auth[8];                                                       
  fgets(auth,8,authf);                                                
  fclose(authf);                                                      
  int result = strcmp(auth, "no");
  printf("[%d]\n", result);
  if(result!=0){                                           
    FILE* flagf;                                                      
    flagf = fopen("../../problems/ec9da1496f80c8248197ba564097cebb/flag","r");                                                                   
    char flag[64];                                                    
    fgets(flag,64,flagf);                                             
    printf("Oh. Well the auth file doesn't say no anymore so... Here's the flag: %s",flag);                                                 
    fclose(flagf);                                                    
  }else{                                                              
    printf("auth file says no. So no. Just... no.\n");                
  }                                                                   
  return 0;                                                           
}
