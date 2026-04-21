#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mostrarMenu() {
    cout << "\n=====================================\n";
    cout << " SISTEMA DE CONTROL DE VENTAS\n";
    cout << " Nombre: Bertha Leon\n";
    cout << "=====================================\n";
    cout << "1. Registrar una venta\n";
    cout << "2. Mostrar todas las ventas\n";
    cout << "3. Generar reporte general\n";
    cout << "4. Buscar ventas por monto\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opcion: ";
}

double calcularSubtotal(int cantidad, double precio) {
    return cantidad * precio;
}

double calcularDescuento(double subtotal, int tipoPago) {
    double descuento = 0;

    if (subtotal >= 500)
        descuento = descuento + subtotal * 0.05;

    if (tipoPago == 1 && subtotal >= 300)
        descuento = descuento + subtotal * 0.02;

    return descuento;
}

double calcularTotal(double subtotal, double descuento) {
    return subtotal - descuento;
}

void registrarVenta() {
    string cliente, producto;
    int cantidad, tipoPago;
    double precio, subtotal, descuento, total;

    ofstream archivo("Registro de ventas.txt", ios::app);

    if (!archivo) {
        cout << "Error al abrir archivo.\n";
        return;
    }

    cout << "\n--- REGISTRO DE VENTA ---\n";

    cin.ignore();

    cout << "Nombre del cliente: ";
    getline(cin, cliente);

    cout << "Nombre del producto: ";
    getline(cin, producto);

    do {
        cout << "Cantidad: ";
        cin >> cantidad;

        if (cantidad <= 0)
            cout << "Cantidad invalida.\n";

    } while (cantidad <= 0);

    do {
        cout << "Precio unitario: ";
        cin >> precio;

        if (precio <= 0)
            cout << "Precio invalido.\n";

    } while (precio <= 0);

    do {
        cout << "Tipo de pago (1=Efectivo, 2=Tarjeta, 3=Transferencia): ";
        cin >> tipoPago;

        if (tipoPago < 1 || tipoPago > 3)
            cout << "Tipo de pago invalido.\n";

    } while (tipoPago < 1 || tipoPago > 3);

    subtotal = calcularSubtotal(cantidad, precio);
    descuento = calcularDescuento(subtotal, tipoPago);
    total = calcularTotal(subtotal, descuento);

    archivo << cliente << ","
           << producto << ","
           << cantidad << ","
           << precio << ","
           << subtotal << ","
           << descuento << ","
           << total << ","
           << tipoPago << endl;

    archivo.close();

    cout << "Venta registrada correctamente.\n";
    cout << "Total a pagar: Q" << total << endl;
}

void mostrarVentas() {
    ifstream archivo("Registro de ventas.txt");

    string cliente, producto;
    int cantidad, tipoPago;
    double precio, subtotal, descuento, total;

    if (!archivo) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    cout << "\n--- LISTADO DE VENTAS ---\n";

    while (getline(archivo, cliente, ',') &&
           getline(archivo, producto, ',') &&
           archivo >> cantidad) {

        archivo.ignore();
        archivo >> precio;
        archivo.ignore();
        archivo >> subtotal;
        archivo.ignore();
        archivo >> descuento;
        archivo.ignore();
        archivo >> total;
        archivo.ignore();
        archivo >> tipoPago;
        archivo.ignore();

        cout << "Cliente: " << cliente
             << " | Producto: " << producto
             << " | Cantidad: " << cantidad
             << " | Precio unitario: Q" << precio
             << " | Total: Q" << total
             << endl;
    }

    archivo.close();
}

void generarReporte() {
    ifstream archivo("Registro de ventas.txt");

    string cliente, producto;
    int cantidad, tipoPago;
    double precio, subtotal, descuento, total;

    int totalVentas = 0;
    int efectivo = 0, tarjeta = 0, transferencia = 0, conDescuento = 0;
    double sumaTotal = 0;
    string listaDescuentos = "";
    double sumaDescuentos = 0;

    if (!archivo) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    while (getline(archivo, cliente, ',') &&
           getline(archivo, producto, ',') &&

           archivo >> cantidad) {

        archivo.ignore();
        archivo >> precio;
        archivo.ignore();
        archivo >> subtotal;
        archivo.ignore();
        archivo >> descuento;
        archivo.ignore();
        archivo >> total;
        archivo.ignore();
        archivo >> tipoPago;
        archivo.ignore();

        totalVentas++;
        sumaTotal += total;

        if (tipoPago == 1)
            efectivo++;
        else if (tipoPago == 2)
            tarjeta++;
        else if (tipoPago == 3)
            transferencia++;

        if (descuento > 0) {
            conDescuento++;
            listaDescuentos += "Cliente: " + cliente + " | Producto: " + producto + " | Descuento: Q" + to_string(descuento) + "\n";
            sumaDescuentos += descuento;
        }

    }

    archivo.close();

    cout << "\n--- REPORTE GENERAL ---\n";
    cout << "Total de ventas registradas: " << totalVentas << endl;
    cout << "Suma total vendida: Q" << sumaTotal << endl;

    if (totalVentas > 0)
        cout << "Promedio de venta: Q" << sumaTotal / totalVentas << endl;

    cout << "Ventas en efectivo: " << efectivo << endl;
    cout << "Ventas en tarjeta: " << tarjeta << endl;
    cout << "Ventas en transferencia: " << transferencia << endl;
    cout << "Ventas con descuento: " << conDescuento << endl;

    if (!listaDescuentos.empty()) {
        cout << "\nVentas con descuento aplicado:\n" << listaDescuentos;
        cout << "Suma total de descuentos: Q" << sumaDescuentos << endl;
    }
}

void buscarPorMonto() {
    ifstream archivo("Registro de ventas.txt");

    string cliente, producto;
    int cantidad, tipoPago;
    double precio, subtotal, descuento, total, monto;

    if (!archivo) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    cout << "\nIngrese el monto minimo a buscar: ";
    cin >> monto;

    cout << "\n--- VENTAS ENCONTRADAS ---\n";

    while (getline(archivo, cliente, ',') &&
           getline(archivo, producto, ',') &&
           archivo >> cantidad) {

        archivo.ignore();
        archivo >> precio;
        archivo.ignore();
        archivo >> subtotal;
        archivo.ignore();
        archivo >> descuento;
        archivo.ignore();
        archivo >> total;
        archivo.ignore();
        archivo >> tipoPago;
        archivo.ignore();

        if (total >= monto) {
            cout << "Cliente: " << cliente
                 << " | Producto: " << producto
                 << " | Total: Q" << total
                 << endl;
        }
    }

    archivo.close();
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch(opcion) {
            case 1:
                registrarVenta();
                break;
            case 2:
                mostrarVentas();
                break;
            case 3:
                generarReporte();
                break;
            case 4:
                buscarPorMonto();
                break;
            case 5:
                cout << "\nSaliendo del sistema...\n";
                break;
            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 5);

    return 0;
}