#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("jacob6707");
MODULE_DESCRIPTION("Mojmodul");
MODULE_VERSION("0.1");

static int __init mojmodul_init(void) {
    unsigned long UkJiffies = jiffies;
    unsigned long sekundeOdPokretanja = UkJiffies / HZ; //broj jiffiesa u sekundi

printk(KERN_INFO "HZ = %d\n", HZ);
    printk(KERN_INFO "MojModul učitan.\n");
    printk(KERN_INFO "Broj Jiffiesa = %lu\n", UkJiffies);
    printk(KERN_INFO "Sekunde od pokretanja = %lu\n", sekundeOdPokretanja);

    return 0;
}

//Funkcija kod uklanjanja modula
static void __exit mojmodul_exit(void) {
    unsigned long UkJiffies = jiffies;
    unsigned long sekundeOdPokretanja = UkJiffies / HZ;

    printk(KERN_INFO "mojmodul: Modul uklonjen.\n");
    printk(KERN_INFO "mojmodul: Jiffies = %lu\n", UkJiffies);
    printk(KERN_INFO "mojmodul: Sekunde od pokretanja = %lu\n", sekundeOdPokretanja);
}

module_init(mojmodul_init);
module_exit(mojmodul_exit);
