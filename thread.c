#include <stdio.h> 
#include <unistd.h> 
#include <pthread.h> 

void* do_loop(void *data)
{
    int i;
    int me = *((int *)data);

    for (i = 0; i < 10; i++)
    {
        printf("%d - Got %d\n", me, i);
        sleep(1);
    }
}

int main()
{
    int thr_id;
    pthread_t p_thread[3];
    int status;
    int a = 1;
    int b = 2;      
    int c = 3;      

    thr_id = pthread_create(&p_thread[0], NULL, do_loop, (void *)&a);
    thr_id = pthread_create(&p_thread[1], NULL, do_loop, (void *)&b);
    thr_id = pthread_create(&p_thread[2], NULL, do_loop, (void *)&c);

    pthread_join(p_thread[0], (void **) &status);
    pthread_join(p_thread[1], (void **) &status);
    pthread_join(p_thread[2], (void **) &status);

    printf("programing is end\n");
    return 0;
}

/*===============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h> // gcc  test.c -o test -lpthread


void* My(void* Para)
{
    int i;
     for(i=0;i<10;i++)
     {
        printf("[+] Child : Hello World ! \n");
        sleep(2);
     }
}


int main()
{
    pthread_t re;
    int a;
    void* s;

    a = pthread_create(&re,NULL,My,NULL);
    

    while(1)
    {
        printf("[+] Parent : Hello World !\n");
        sleep(1);
    }
    pthread_join(re,&s);
    printf("%s\n",s);

    return 0;
}*/
