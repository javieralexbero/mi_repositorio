
int main() {
    int opcion, indiceCliente, operaciones;
    int numeroCuenta;
    char contrasena[20];
    operaciones = 0;
    do {
        printf("Ingrese su número de cuenta: ");
        scanf("%d", &numeroCuenta);
        printf("Ingrese su contraseña: ");
        scanf("%s", contrasena);
        indiceCliente = iniciarSesion(numeroCuenta, contrasena);
    } while (indiceCliente == -1);
    do {
        printf("Seleccione una opción:\n");
        printf("1. Depósito\n");
        printf("2. Extracción\n");
        printf("3. Consultar saldo\n");
        printf("4. Mostrar cantidad de operaciones y saldo actual\n");
        printf("5. Salir\n");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                if (operaciones >= 10) {
                    printf("Llegó al límite de operaciones. Fin. Gracias!\n");
                    return 0;
                }
                depositar(indiceCliente);
                operaciones++;
                break;
            case 2:
                if (operaciones >= 10) {
                    printf("Llegó al límite de operaciones. Fin. Gracias!\n");
                    return 0;
                }
                extraer(indiceCliente);
                operaciones++;
                break;
            case 3:
                consultarSaldo(indiceCliente);
                break;
            case 4:
                mostrarOperaciones(indiceCliente, operaciones);
                break;
            case 5:
                printf("Hasta luego, %s\n", clientes[indiceCliente].nombre);
                break;
            default:
                printf("Opción inválida\n");
                break;
        }
    } while (opcion != 5);
    return 0;
}
