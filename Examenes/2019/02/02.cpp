// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos {
	bool ok;
	int arriba;
	int abajo;
};

tDatos resolver(std::vector<int>const& creciente, std::vector<int>const& decreciente, int ini, int fin) {

	if (creciente[0] > decreciente[0]) {
		return { false, -1,0 };
	}

	else if (ini == fin) {
		if (creciente[ini] < decreciente[ini]) {
			return { false, ini, ini+1 };
		}
		else if (creciente[ini] > decreciente[ini]) {
			return { false, ini-1, ini };
		}
		else {
			return { true, ini, ini };
		}

	}
	else {
		int m = (fin + ini) / 2;

		if (creciente[m] == decreciente[m]) {
			return { true, m, m };
		}
		else if (abs(creciente[ini] - decreciente[ini])  <= abs(creciente[fin] - decreciente[fin])) //hacia la izquierda
			return resolver(creciente, decreciente, ini, m);
		else //hacia la derecha
			return resolver(creciente, decreciente, m+1, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int dim;
	std::cin >> dim;

	if (dim == 0)
		return false;

	std::vector<int> creciente(dim);
	std::vector<int> decreciente(dim);

	for (int i = 0; i < dim; i++)
		std::cin >> creciente[i];
	for (int i = 0; i < dim; i++)
		std::cin >> decreciente[i];

	tDatos sol = resolver(creciente, decreciente, 0, dim-1);

	if (sol.ok)
		std::cout << "SI " << sol.arriba << "\n";
	else
		std::cout << "NO " << sol.arriba << " " << sol.abajo << "\n";

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