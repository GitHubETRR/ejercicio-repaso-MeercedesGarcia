#include <stdio.h>

#define MAX_EMPLEADOS 5

// definino la estructura Empleado
struct Empleado {
    char nombre[50];
    int edad;
    float salario;
};

//los prototipos
void ingresarDatos(struct Empleado empleados[], int *numEmpleados);
void procesarDatos(struct Empleado empleados[], int numEmpleados);
void mostrarDatos(struct Empleado empleados[], int numEmpleados);

int main() {
    struct Empleado empleados[MAX_EMPLEADOS];
    int opcion, numEmpleados = 0;

    do {
        printf("\nMenú:\n");
        printf("1. Ingresar datos de un empleado\n");
        printf("2. Procesar y mostrar información relevante de los empleados\n");
        printf("3. Salir del programa\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarDatos(empleados, &numEmpleados);
                break;
            case 2:
                procesarDatos(empleados, numEmpleados);
                break;
            case 3:
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    } while(opcion != 3);

    return 0;
}

//ingresar datos de un empleado
void ingresarDatos(struct Empleado empleados[], int *numEmpleados) {
    if (*numEmpleados < MAX_EMPLEADOS) {
        struct Empleado nuevoEmpleado;
        printf("Ingrese el nombre del empleado: ");
        scanf("%s", nuevoEmpleado.nombre);
        printf("Ingrese la edad del empleado: ");
        scanf("%d", &nuevoEmpleado.edad);
        printf("Ingrese el salario del empleado: ");
        scanf("%f", &nuevoEmpleado.salario);

        empleados[*numEmpleados] = nuevoEmpleado;
        (*numEmpleados)++;
    } else {
        printf("No se pueden agregar más empleados. Límite alcanzado.\n");
    }
}

//funcion para procesar y mostrar info relevante de los empleados
void procesarDatos(struct Empleado empleados[], int numEmpleados) {
    if (numEmpleados == 0) {
        printf("No hay empleados ingresados.\n");
        return;
    }

    float promedioSalarios = 0;
    float salarioMaximo = empleados[0].salario;
    char nombreEmpleadoMaximo[50];
    
    for (int i = 0; i < numEmpleados; i++) {
        promedioSalarios += empleados[i].salario;

        if (empleados[i].salario > salarioMaximo) {
            salarioMaximo = empleados[i].salario;
            (nombreEmpleadoMaximo, empleados[i].nombre);
        }
    }

    promedioSalarios /= numEmpleados;

    printf("Promedio de salarios: %.2f\n", promedioSalarios);
    printf("Empleado con el salario más alto: %s\n", nombreEmpleadoMaximo);
}

// funcion para mostrar la info de todos los empleados ingresados
void mostrarDatos(struct Empleado empleados[], int numEmpleados) {
    if (numEmpleados == 0) {
        printf("No hay empleados ingresados.\n");
        return;
    }

    printf("Información de los empleados:\n");
    for (int i = 0; i < numEmpleados; i++) {
        printf("Empleado %d:\n", i+1);
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("Edad: %d\n", empleados[i].edad);
        printf("Salario: %.2f\n", empleados[i].salario);
    }
}
