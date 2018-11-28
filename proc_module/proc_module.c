#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>   
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include "proc_test.h" 
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Cheng Chung Lee");
MODULE_DESCRIPTION("Demo for NIUEE");
 
static int irq=20;
module_param(irq,int,0660);

static int mode=1;
module_param(mode,int,0660);
 
static struct proc_dir_entry *ent;
 
static ssize_t proc_test_write(struct file *file, const char __user *ubuf, size_t count, loff_t *ppos) 
{
	int num,c,i,m;
	char buf[BUFSIZE];
	if(*ppos > 0 || count > BUFSIZE)
		return -EFAULT;
	if(copy_from_user(buf, ubuf, count))
		return -EFAULT;
	num = sscanf(buf,"%d %d",&i,&m);
	if(num != 2)
		return -EFAULT;
	irq = i; 
	mode = m;
	c = strlen(buf);
	*ppos = c;
	return c;
}
 
static ssize_t proc_test_read(struct file *file, char __user *ubuf,size_t count, loff_t *ppos) 
{
	char buf[BUFSIZE];
	int len=0;
	if(*ppos > 0 || count < BUFSIZE)
		return 0;
	len += sprintf(buf,"irq = %d\n",irq);
	len += sprintf(buf + len,"mode = %d\n",mode);
	
	if(copy_to_user(ubuf,buf,len))
		return -EFAULT;
	*ppos = len;
	return len;
}
 
static struct file_operations proc_test_ops = 
{
	.owner = THIS_MODULE,
	.read = proc_test_read,
	.write = proc_test_write,
};
 
static int proc_test_init(void)
{
	ent = proc_create("proc_test", 0660, NULL, &proc_test_ops);
	printk(KERN_ALERT "Hello proc tester...\n");
	return 0;
}
 
static void proc_test_cleanup(void)
{
	proc_remove(ent);
}
 
module_init(proc_test_init);
module_exit(proc_test_cleanup);

