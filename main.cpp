#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int opcion = 0;
    int cantconctactos = 0;

    struct Contacto {
        char nombre[50];
        char apellido[50];
        char direccion[50];
        int dni;
    };

    struct Contacto lista[50];
    ifstream archivoLectura("agenda.txt");
    if (archivoLectura.is_open()) {
        archivoLectura >> cantconctactos;
        for (int i = 0; i < cantconctactos; i++) {
            archivoLectura >> lista[i].nombre;
            archivoLectura >> lista[i].apellido;
            archivoLectura >> lista[i].direccion;
            archivoLectura >> lista[i].dni;
        }
        archivoLectura.close();
    }
    do {
        cout << "\n  opciones de la agenda \n";
        cout << "1. Crear contacto\n";
        cout << "2. Mostrar todos los contactos\n";
        cout << "3. Eliminar contactos\n";
        cout << "4. Buscar\n";
        cout << "5. Salir\n";
        cout << "a partir de no pongas espacio , separa con mayusculass. Escribi que queres: ";
        cin >> opcion;
        switch(opcion) {
        case 1:
            cout << "escribe el nombre del contacto: ";
            cin >> lista[cantconctactos].nombre;
            cout << "Escribi el apellido: ";
            cin >> lista[cantconctactos].apellido;
            cout << "escribi la direccion: ";
            cin >> lista[cantconctactos].direccion;
            cout << "escribi el dni: ";
            cin >> lista[cantconctactos].dni;
            cout << "\n contacto agregado \n";
            cantconctactos++;
            {
                ofstream archivoEscritura("agenda.txt");
                archivoEscritura << cantconctactos << "\n";
                for (int i = 0; i < cantconctactos; i++) {
                    archivoEscritura << lista[i].nombre << " "
                                     << lista[i].apellido << " "
                                     << lista[i].direccion << " "
                                     << lista[i].dni << "\n";
                }
                archivoEscritura.close();
            }
            break;

        case 2:
            if (cantconctactos == 0) {
                cout << "no hay contactos guardados.\n";
            } else {
                for(int i = 0; i < cantconctactos; i++) {
                    cout << "\nContacto numero: " << i + 1 << "\n";
                    cout << "nombre: " << lista[i].nombre << "\n";
                    cout << "apellido: " << lista[i].apellido << "\n";
                    cout << "direccion: " << lista[i].direccion << "\n";
                    cout << "dni: " << lista[i].dni << "\n";
                }
            }
            break;

        case 3: {
            if (cantconctactos == 0) {
                cout << "No hay contactos para eliminar.\n";
            } else {
                int pos;
                cout << "Ingresa el numero de contacto a eliminar (1 a " << cantconctactos << "): ";
                cin >> pos;
                if (pos >= 1 && pos <= cantconctactos) {
                    int indice = pos - 1;
                    for (int i = indice; i < cantconctactos - 1; i++) {
                        lista[i] = lista[i + 1];
                    }
                    cantconctactos--;
                    cout << "Contacto eliminado correctamente.\n";
                } else {
                    cout << "Posicion invalida.\n";
                }
            }
            ofstream archivoEscritura("agenda.txt");
            archivoEscritura << cantconctactos << "\n";
            for (int i = 0; i < cantconctactos; i++) {
                archivoEscritura << lista[i].nombre << " "
                                 << lista[i].apellido << " "
                                 << lista[i].direccion << " "
                                 << lista[i].dni << "\n";
            }
            archivoEscritura.close();
            break;
        }
        case 4: {
            if (cantconctactos == 0) {
                cout << "no hay contactos para buscar.\n";
            } else {
                int dniBuscar;
                bool encontrado = false;

                cout << "ingresa el dni del contacto a buscar: ";
                cin >> dniBuscar;

                for (int i = 0; i < cantconctactos; i++) {
                    if (lista[i].dni == dniBuscar) {
                        cout << "\n CONTACTO ENCONTRADO: \n";
                        cout << "posicion: " << i + 1 << "\n";
                        cout << "nombre: " << lista[i].nombre << "\n";
                        cout << "apellido: " << lista[i].apellido << "\n";
                        cout << "direccion: " << lista[i].direccion << "\n";
                        cout << "dni: " << lista[i].dni << "\n";
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "no se encontro ningun contacto con ese dni \n";
                }
            }
            break;
        }
        case 5:
            cout << "saliste\n";
            break;

        default:
            cout << "no esta esa opcion pone otra.\n";
            break;
        }

    } while(opcion != 5);

    return 0;
}
/*
#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "agenda1_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    struct Contracto{
        char nombre[50];
        char apellido[50];
        char direccion[50];
        char email[80]:
        int dni;
    };

    // Set up code that uses the Qt event loop here.
    // Call QCoreApplication::quit() or QCoreApplication::exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to QCoreApplication::exec() or use the Non-Qt Plain C++ Application template.

    return QCoreApplication::exec();
}
*/