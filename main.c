#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/kthread.h>
#include<linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Arun S Nair");
MODULE_DESCRIPTION("simple module using kthread");


struct task_struct * ts;
struct task_struct * ts1;
{

        pr_alert("In thread 1");
        while(!kthread_should_stop())
        {
                pr_alert("In thread loop %d ",*((int *)ptr));
                ssleep(1);
        }
        return 0;
}


int thread2(void * ptr)
{
        while(!kthread_should_stop())
        {
                pr_alert("In thread 2");
                ssleep(2);
        }
        return 0;
}

int __init startFun(void)
{
        printk(KERN_INFO "\nHello world\n");
        ts = kthread_create(mythread,(void *)(&abc),"mythread1");
        ts1 = kthread_create(thread2,NULL,"mythread2");
        if(ts && ts1)
        {                                                                                                         
        wake_up_process(ts1);                                                                                     
        return 0;                                                                                                 
}                                                                                                                 
                                                                                                                  
void __exit endFun(void)                                                                                          
{                                                                                                                 
        printk(KERN_INFO "\nbye world\n");                                                                        
        kthread_stop(ts);                                                                                         
        kthread_stop(ts1);                                                                                        
}                                                                                                                 
                                                                                                                  
module_init(startFun);                                                                                            
module_exit(endFun);
