/**
 * @file linux_wrapper_cerence.c
 * @author your name (vaibhav.pandey@germanautolabs.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "linux_wrapper_cerence.h"
#include  "asr_cerence_api.h"


char *result2;
/*int main(int argc, char *argv[])
{
  int result = 0;
  result = liwr_initConfig();
  printf("Result of liwr_initconig<%d>",result);
  if(result != 0)
  {
      liwr_startRecogniser();
  }
 return 0;
}*/


int liwr_initConfig(void)
{
    int result = 0;
    result = init_configuration();
    return result;

}

int liwr_startRecogniser(void)
{
    int result = 0;
    result = cerence_Start_Recognizer();
    return result;
}

void liwr_recogResult(const char* result)
{

   result2 = malloc(sizeof(result));
   memcpy(result2,result,sizeof(result));
   printf("Cerence Recognizer result<%s>\n",result2);
//   handleIncomingEvents(result2);
//   parseResult(result2);

}


void liwr_recogEvent(li_asr5_RecogEvent event)
{
   printf("Cerence Recognizer Event\n");

}


void liwr_executeCommands(const char *CommandStr)
{
 int result = 0;
 printf("Hymmer API commands to Excute<%s>\n",CommandStr);
 if(strcmp ("INIT_ASR",CommandStr) == 0)
 {
   printf("Init the configuration\n");
   result = liwr_initConfig();
   if(result != 0)
   {
     liwr_startRecogniser();
   }

 }
 else if(strcmp ("START_ASR",CommandStr) == 0)
 {
   printf("Start the Recogniser\n");

 }
 else
 {
   printf("Wrong state\n");
 }

	 
}
