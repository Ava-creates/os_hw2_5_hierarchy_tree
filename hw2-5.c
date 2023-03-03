#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    //fucntions getpid(),getppid());

    printf("ROOT %i \n", getpid());
    int a= getpid();
    int pid1 = fork(); 

    if(pid1 == 0)
    {
        //first child ==2

        printf("myid %i\tparent id %i\n", getpid(), getppid());
        int b= getpid();

        int pid2 = fork();   //first child of 2 

    
        if(pid2 == 0 )   //in child of the first child 
        {
              printf("myid %i\tparent id %i\tgrandparentparent id%i\n", getpid(), getppid(),a); 

              // 2 more kids
              int pid3 = fork(); 
              if(pid3==0) 
              {
                  printf("myid %i\tparent id %i\tgrandparentparent id%i\n", getpid(), getppid(),b); 
              }

              else{
                int pid4= fork(); 
                if(pid4==0)
                {
                 printf("myid %i\tparent id %i\tgrandparentparent id%i\n", getpid(), getppid(),b); 
              }
              }


        }

    }

        //creating second child of the first node 
        else
        {
            int pid5 = fork();   // secoind child 

            if(pid5==0)
            {
                 printf("myid %i\tparent id %i\n", getpid(), getppid()); 
                 int c = getpid();
                 int pid6 = fork(); 

                 if(pid6==0)
                 {
                     printf("myid %i\tparent id %i\tgrandparentparent id%i\n", getpid(), getppid(),a); 

                     int pid7 = fork(); 

                     if(pid7==0)
                     {
                        printf("myid %i\tparent id %i\tgrandparentparent id%i\n", getpid(), getppid(),c); 
                     }
            
                 }
            }

            else{
                int pid8 = fork();       
                 if(pid8 ==0)
                 {
                    printf("myid %i\tparent id %i\n", getpid(), getppid()); 
                    int pid9 = fork(); 
                    if(pid9 ==0 )
                    {
                         printf("myid %i\tparent id %i\tgrandparentparent id%i\n", getpid(), getppid(),a); 
                    }
                    else{

                         int pid10= fork(); 

                         if(pid10==0)
                         {
                     printf("myid %i\tparent id %i\tgrandparentparent id%i\n", getpid(), getppid(),a);
                         }
                    }
                 }


            }

        }

   sleep(5);
     
}

