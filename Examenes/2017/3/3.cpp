// Ana Laura Corral Descargue
// TAIS19 o E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

bool esValida(int const i, const int numAzul, const int numRojo, const int numVerde,
				const int contAzul, const int contRojo, const int contVerde,
				std::vector<std::string> const & torre) {

	if (contAzul > numAzul) return false;
	if (contRojo > numRojo) return false;
	if (contVerde > numVerde) return false;

	if (contVerde > contAzul) return false;

	if (torre[i] == "verde" && torre[i - 1] == "verde") return false;
	return true;
}

bool esSolucionValida(const int contAzul, const int contRojo, const int contVerde) {

	if (contRojo <= contAzul + contVerde) return false;
	return true;
}

void resolver(int k, const int altura, const int numAzul, const int numRojo, const int numVerde,
				std::vector<std::string>const &colores,
				int contAzul, int contRojo, int contVerde,
				std::vector<std::string> &torre, int &cont) {
	for (int i = 0; i < colores.size(); i++) {
		torre[k] = colores[i];
		if (i == 0) contAzul++;
		else if (i == 1) contRojo++;
		else if (i == 2) contVerde++;

		if (esValida(i,numAzul,numRojo,numVerde,contAzul,contRojo,contVerde,torre)) {
			if (k == altura - 1) {
				if (esSolucionValida(contAzul, contRojo, contVerde)) {
					cont++;
					for (int i = 0; i < torre.size(); i++) {
						if (i == 0) std::cout << torre[i];
						else std::cout << " " << torre[i];
					}
					std::cout << "\n";
				}
			}
			else {
				resolver(k + 1, altura, numAzul, numRojo, numVerde, colores,
					contAzul, contRojo, contVerde,
					torre,cont);
			}

		}
		if (i == 0) contAzul--;
		else if (i == 1) contRojo--;
		else if (i == 2) contVerde--;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int altura, numAzul, numRojo, numVerde;
	std::cin >> altura >> numAzul >> numRojo >> numVerde;

	if (altura == 0 && numAzul == 0 && numRojo == 0 && numVerde == 0)
		return false;
	std::vector<std::string> colores(3);
	colores[0] = "azul";
	colores[1] = "rojo";
	colores[2] = "verde";
	std::vector<std::string> torre(altura);
	torre[0] = "rojo";

	int contAzul = 0, contRojo = 1, contVerde = 0;
	int cont = 0;
	resolver(1,altura, numAzul, numRojo, numVerde,colores,contAzul,contRojo,contVerde, torre,cont);

	if (cont == 0)
		std::cout << "SIN SOLUCION\n";

	std::cout << "\n";
	// escribir sol

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}