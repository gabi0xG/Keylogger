#include <iostream>
#include <fstream>
#include <ctime>

int main() {
    std::cout << "Aplicación de registro de teclas dentro de la aplicación.\n";
    std::cout << "Escribe SI para comenzar: ";

    std::string ok;
    std::cin >> ok;
    std::cin.ignore();

    if (ok != "SI") {
        std::cout << "Consentimiento no dado.\n";
        return 0;
    }

    std::ofstream file("registro.csv");
    if (!file.is_open()) {
        std::cout << "Error al crear el archivo.\n";
        return 1;
    }

    file << "seq,timestamp,key\n";

    std::cout << "Modo interactivo activo. Escribe 'q' para salir.\n";

    int seq = 1;
    char c;

    while (true) {
        c = std::cin.get();
        if (c == '\n') continue;

        long timestamp = std::time(nullptr);

        std::cout << seq << " " << timestamp << " " << c << "\n";
        file << seq << "," << timestamp << "," << c << "\n";

        if (c == 'q') break;
        seq++;
    }

    file.close();
    std::cout << "Registro finalizado correctamente.\n";
    return 0;
}
