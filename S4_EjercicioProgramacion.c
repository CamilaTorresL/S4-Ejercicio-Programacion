/*
Integrantes: Camila Torres, David Narvaez, Jean Zambrano, Erick Guamani
Fecha de entrega: 11 - 10 - 2026
Descripción:
Programa en C para gestionar un inventario de hasta 10 productos, almacenando sus nombres y precios 
en arreglos. Permite ingresar los datos, calcular el precio total y promedio del inventario, 
identificar el producto más caro y el más barato, y realizar búsquedas de productos por nombre para 
mostrar su precio.
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>

int main (int argc, char *argv[]) {

    char nombreProductos[10][20], buscar[20], nombreCaro[20], nombreBarato[20];
    float precios[10], total = 0, caro = 0, prom = 0, barato;
    int opcion, i, n, respuesta, productosIngresados = 0;

    do{
        system("cls"); //Para que la interfaz se vea más limpia al ejecutar en el cmd
        //Menú principal
        printf("Seleccione una opción: \n");
        printf("1. Ingresar el nombre y precio de los productos: \n");
        printf("2. Información sobre el precio total del inventario: \n");
        printf("3. Información sobre el producto más caro y barato del inventario: \n");
        printf("4. Información sobre el precio promedio de los productos: \n");
        printf("5. Buscar un producto por su nombre e identificar su precio: \n");
        printf(">>");
        scanf(" %d", &opcion);

        switch (opcion)
        {
        
         //Nombre de los productos
        case 1:

            do{
                printf("¿Cuantos productos desea ingresar? (máximo 10): \n");
                scanf(" %d", &n);

                if (n > 10){
                    printf("La cantidad de productos ingresada no es válida\n");
                }

            } while (n > 10);

            for (i=0; i<n; i++){
                printf("Ingrese el nombre del producto %d: \n", i+1);
                scanf(" %s", nombreProductos[i]);

                do{
                    printf("Ingrese el precio del producto %d: \n", i+1);
                    scanf(" %f", &precios[i]);
                    if (precios[i] <= 0){
                        printf("El precio ingresado no es válido\n");
                    }
                } while (precios[i] <= 0);

                //Calculo general del total para su uso en el caso 3 y 5
                total+=precios[i];

            }

            productosIngresados = 1;

            break;
         
         //Precio total del inventario
        case 2:

            if (productosIngresados != 1) {
                printf("Primero debe ingresar los productos y sus respectivos precios\n");
                opcion = 1;
                break;
            }
            
            printf("El precio total del inventario es de %.2f dólares\n", total);
            break;

         //Producto más caro y más barato
        case 3:

            if (productosIngresados != 1) {
                printf("Primero debe ingresar los productos y sus respectivos precios\n");
                opcion = 1;
                break;
            }

            barato = precios[0];

            for (i=0; i<n; i++){

                if (precios[i] >= caro){
                    caro = precios[i];
                    strcpy(nombreCaro, nombreProductos[i]);
                }

                if (precios[i] <= barato){
                    barato = precios[i];
                    strcpy(nombreBarato, nombreProductos[i]);
                }
            }

            printf("El producto más caro es %s\n", nombreCaro);
            printf("El producto más barato es %s\n", nombreBarato);

            break;

         //Precio promedio
        case 4:

           if (productosIngresados != 1) {
                printf("Primero debe ingresar los productos y sus respectivos precios\n");
                opcion = 1;
                break;
            }

            prom = total/n;

            printf("El precio promedio de los productos es de: %.2f dólares\n", prom);

            break;

         //Buscar producto e identificar su precio
        case 5:

            if (productosIngresados != 1) {
                printf("Primero debe ingresar los productos y sus respectivos precios\n");
                opcion = 1;
                break;
            }

            printf("Ingrese el nombre del producto para conocer su precio: \n");
            scanf(" %s", buscar);

            int encontrar = 0;

            for (i=0; i<n; i++){

                if (strcmp(buscar, nombreProductos[i]) == 0){
                    printf("El precio de %s es %.2f dólares\n", nombreProductos[i], precios[i]);

                    encontrar = 1;
                }
            }

            if (encontrar == 0){
                printf("Producto no encontrado\n");
            }

            break;

        default:
            printf("La opción ingresada no es válida\n");

            break;
        }

        printf("¿Desea seleccionar otra opción?: (1=si/2=no)\n");
        scanf(" %d", &respuesta); 

    } while (respuesta == 1);

}