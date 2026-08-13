#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void) {
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Pan", 200, 3};  /* 200 * 3 = 600 */
    Producto p2 = {"Leche", 350, 2};      /* 350 * 2 = 700 */
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    int total = carrito_total(&c);      /* total = 1300 */
    int total_con_descuento = carrito_descuento(total, 10); /* descuento del 10% */
    ASSERT_IGUAL(1300, total);
    ASSERT_IGUAL(1170, total_con_descuento);
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void) {
    Carrito c;
    carrito_init(&c);
    Producto p = {"Galletitas", 150, 1};
    for (int i = 0; i < MAX_ITEMS; i++) {
        ASSERT_IGUAL(1, carrito_agregar(&c, p));   /* devuelve 1 = exito */
    }
    ASSERT_IGUAL(0, carrito_agregar(&c, p));   /* devuelve 0 = fallo */
}

int main(void) {
    printf("=== Tests de integracion ===");
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
