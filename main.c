#include <cr_section_macros.h>
#include <NXP/crp.h>

__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

#include "lpc17xx.h"
#include "FreeRTOS.h"
#include "task.h"

#include "basic_io.h"

void short_delay(unsigned long n);
void short_delay(unsigned long n)
{
    volatile unsigned long delay;

    for(delay = 0; delay < n * 1000; delay++)
    {
        {;
        }
    }

}

void initialization(){

    LPC_GPIO0 -> FIODIR |=(1<<9)|(1<<8)|(1<<7);


}

void displayseven(uint32_t valuePos){
    int i,m;
    int latchPin = 9;
    int dataPin = 8;
    int clockPin = 7;

    for(m=0;m<1000;m++)
    {
    for (i = 0; i< 8; i++)
                {
                    if(((0x80>>i)& valuePos))
                        LPC_GPIO0 -> FIOSET |= (1<< dataPin);

                    else
                        LPC_GPIO0 -> FIOCLR |= (1<< dataPin);
                    LPC_GPIO0->FIOSET |=(1<< clockPin);

                    LPC_GPIO0 -> FIOCLR |= (1<< clockPin);

                }
    LPC_GPIO0 -> FIOSET |= (1<< latchPin);

    LPC_GPIO0 -> FIOCLR |= (1<< latchPin);

    }
}

void Timer( void *pvParameters )
{

int second,Tensecond,Minutes,Tenminutes,secondfinisher;
initialization();

	while(1){


    for(Tenminutes=0;Tenminutes<6;Tenminutes++)
  {
     for(Minutes=0;Minutes<=9;Minutes++)
   {
     for(Tensecond=0;Tensecond<6;Tensecond++)
    {
     for(second=0;second<=9;second++)
       {
         for(secondfinisher=0;secondfinisher<=40;secondfinisher++)
         {
    	 if(second==0)
            {
    		 displayseven (0x08);
            }
    	 else if(second==1)
    		 {displayseven (0x18);
    		 }
    	 else if(second==2)
    	     		 {displayseven (0x28);}
    	 else if(second==3)
    	     		 {displayseven (0x38);
    	     		 }
    	 else if(second==4)
    	     		 {displayseven (0x48);
    	     		 }
    	 else if(second==5)
    	     		 {displayseven (0x58);
    	     		 }
    	 else if(second==6)
    	     		 {displayseven (0x68);
    	     		 }
    	 else if(second==7)
    	     		 {displayseven (0x78);
    	     		 }
    	 else if(second==8)
    	     		 {displayseven (0x88);
    	     		 }
    	 else
    	     		 {displayseven (0x98);
    	     		 }




            if(Tensecond==0){   displayseven (0x04);}

            else if(Tensecond==1) { displayseven (0x14);}

            else if(Tensecond==2) { displayseven (0x24);}
            else if(Tensecond==3) {displayseven (0x34);}
            else if(Tensecond==4) {displayseven (0x44);}
            else  {displayseven (0x54);}




             if(Minutes==0) {displayseven (0x02);}
             else if(Minutes==1){displayseven (0x12);}
             else if(Minutes==2)  {displayseven (0x22);}
             else if(Minutes==3)  {displayseven (0x32);}
             else if(Minutes==4)  {displayseven (0x42);}
             else if(Minutes==5)  {displayseven (0x52);}
             else if(Minutes==6)  {displayseven (0x62);}
             else if(Minutes==7) {displayseven (0x72);}
             else if(Minutes==8)  {displayseven (0x82);}
             else   {displayseven (0x92);}



              if(Tenminutes==0){displayseven (0x01);}
              else if(Tenminutes==1){displayseven (0x11);}
              else if(Tenminutes==2){displayseven (0x21);}
              else if(Tenminutes==3){ displayseven (0x31);}
              else if(Tenminutes==4){displayseven (0x41);}
              else {displayseven (0x51);}

  }
    }
   }
  }
  }
}





}

int main( void )

{

printf( "\n" );

xTaskCreate(Timer , "Task 1", 240, NULL, 2, NULL );

vTaskStartScheduler();

for( ;; );

return 0;

}

void vApplicationMallocFailedHook( void )
{
/* This function will only be called if an API call to create a task, queue
or semaphore fails because there is too little heap RAM remaining. */
for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char
*pcTaskName )
{
/* This function will only be called if a task overflows its stack.  Note
that stack overflow checking does slow down the context switch
implementation. */
for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
/* This example does not use the idle hook to perform any processing. */
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
/* This example does not use the tick hook to perform any processing. */
}
