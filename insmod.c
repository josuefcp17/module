#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tu Nombre");


static float peso = 0;
static float talla = 1;  
static char *genero = "desconocido";


module_param(peso, float, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(peso, "Peso de la persona (en kg)");

module_param(talla, float, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(talla, "Talla de la persona (en metros)");

module_param(genero, charp, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(genero, "Género de la persona (hombre/mujer)");

static int __init modulo_imc_init(void) {
    float imc = peso / (talla * talla);
    printk(KERN_INFO "IMC calculado: %.2f\n", imc);
    printk(KERN_INFO "Género: %s\n", genero);
    return 0;
}

static void __exit modulo_imc_exit(void) {
    printk(KERN_INFO "Módulo de IMC removido.\n");
}

module_init(modulo_imc_init);
module_exit(modulo_imc_exit);
