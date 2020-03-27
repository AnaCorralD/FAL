// Ana Laura Corral Descargue
// TAIS19 o E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos{
	int tiempo;
	int satifaccion;

};

void resolver(int k , int const numCanciones, int const tIda, int const tVuelta, std::vector<tDatos> const &datos,
			std::vector<bool> &markedIda, std::vector<bool> &markedVuelta, int contTiempoIda, int contTiempoVuelta, int contPunt,
			int &satSol, std::vector<bool> &markedSolIda, std::vector<bool> &markedSolVuelta) {

	
	markedIda[k] = true;
	contPunt += datos[k].satifaccion;
	contTiempoIda += datos[k].tiempo;
	if (contTiempoIda <= tIda) {
		if (k == numCanciones - 1) {
			if (contTiempoIda == tIda && contTiempoVuelta == tVuelta) {
				if (contPunt > satSol) {
					satSol = contPunt;
					markedSolIda = markedIda;
					markedSolVuelta = markedVuelta;
				}
			}
		}
		else {
			resolver(k + 1, numCanciones, tIda, tVuelta, datos, markedIda, markedVuelta, contTiempoIda, contTiempoVuelta, contPunt,
				satSol, markedSolIda, markedSolVuelta);
		}
	}
	contTiempoIda -= datos[k].tiempo;
	contPunt -= datos[k].satifaccion;
	markedIda[k] = false;

	/*Vuelta*/
	markedVuelta[k] = true;
	contPunt += datos[k].satifaccion;
	contTiempoVuelta += datos[k].tiempo;
	if (contTiempoVuelta <= tVuelta) {
		if (k == numCanciones - 1) {
			if (contTiempoIda == tIda && contTiempoVuelta == tVuelta) {
				if (contPunt > satSol) {
					satSol = contPunt;
					markedSolIda = markedIda;
					markedSolVuelta = markedVuelta;
				}
			}
		}
		else {
			resolver(k + 1, numCanciones, tIda, tVuelta, datos, markedIda, markedVuelta, contTiempoIda, contTiempoVuelta, contPunt,
				satSol, markedSolIda, markedSolVuelta);
		}
	}
	contTiempoVuelta -= datos[k].tiempo;
	contPunt -= datos[k].satifaccion;
	markedIda[k] = false;

	/*  No escuchamos la cancion    */

	if (k == numCanciones - 1) {
		if (contTiempoIda == tIda && contTiempoVuelta == tVuelta) {
			if (contPunt > satSol) {
				satSol = contPunt;
				markedSolIda = markedIda;
				markedSolVuelta = markedVuelta;
			}
		}
	}
	else {
		resolver(k + 1, numCanciones, tIda, tVuelta, datos, markedIda, markedVuelta, contTiempoIda, contTiempoVuelta, contPunt,
			satSol, markedSolIda, markedSolVuelta);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int numCanciones, tIda, tVuelta;
	std::cin >> numCanciones >> tIda >> tVuelta;

	if (numCanciones == 0 && tIda == 0 && tVuelta == 0)
		return false;

	std::vector<tDatos> datos(numCanciones);
	int aux1, aux2;
	for (int i = 0; i < numCanciones; i++) {
		std::cin >> aux1 >> aux2;
		datos[i] = { aux1,aux2 };
	}
	std::vector<bool> markedIda(numCanciones);
	std::vector<bool> markedVuelta(numCanciones);
	std::vector<bool> markedSolIda(numCanciones);
	std::vector<bool> markedSolVuelta(numCanciones);
	int satSol = 0;
	resolver(0, numCanciones, tIda, tVuelta, datos, markedIda, markedVuelta, 0, 0, 0,
		satSol, markedSolIda, markedSolVuelta);

	if (satSol == 0) std::cout << "Imposible\n";
	else std::cout << satSol << "\n";
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