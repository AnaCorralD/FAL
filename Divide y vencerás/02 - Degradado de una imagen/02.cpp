// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
	 Coste: O(n) -> siendo n el numero de elementos del vector
		T(n) = {
			c si n=0
			 2T(n/2) + c 	En cualquier otro caso.
		}
*/


// función que resuelve el problema
bool resolver(std::vector<int> const& v, int ini, int fin, int & acumulado) {

	if (ini >= fin) return true;
	else if (ini + 1 == fin) { 
		acumulado = v[ini] + v[fin];
		if (v[ini] < v[fin]) return true;
		else return false;
	}

	else {
		int m = (ini + fin) / 2;
		int acIz = 0, acDr = 0;

		bool ladoIzq = resolver(v, ini, m, acIz);
		bool ladoDer = resolver(v, m + 1, fin, acDr);

		if (ladoIzq && ladoDer && acIz < acDr) {
			acumulado = acIz + acDr;
			return true;
		}
		else return false;
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int filas;
	std::cin >> filas;

	if (!std::cin) return false;

	int col;
	std::cin >> col;

	//Declaramos la matriz:
	std::vector<std::vector<int>> v(filas);

	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < col; ++j) {
			int aux;
			std::cin >> aux;
			v[i].push_back(aux);
		}
	}

	bool sol = true;

	for (int i = 0; sol && (i < filas); ++i) {
		int acumulado = 0;
		sol = resolver(v[i], 0, col - 1, acumulado);
	}

	// escribir sol
	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";

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