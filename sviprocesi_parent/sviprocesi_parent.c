#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("jacob6707");
MODULE_DESCRIPTION("sviprocesi_parent");

static int __init sviprocesi_init(void) {
    struct task_struct *task;

    printk(KERN_INFO "Modul pokrenut...\n");
    printk(KERN_INFO "Lista procesa:\n");

    for_each_process(task) {
        printk(KERN_INFO "Ime procesa: %s | PID: %d | Roditelj procesa: %s\n", task->comm, task->pid, task->parent ? task->parent->comm : "Nepoznato");
    }

    return 0;
}

static void __exit sviprocesi_exit(void) {
    printk(KERN_INFO "Uklanjanje modula...\n");
}
module_init(sviprocesi_init);
module_exit(sviprocesi_exit);
