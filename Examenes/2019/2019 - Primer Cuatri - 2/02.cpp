// Ana Laura Corral Descargue
// E14


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct sol {
	bool correcto;
	std::vector<int> resultado;
};
// función que resuelve el problema
sol resolver(int ini, int fin, std::vector<int> primero, std::vector<int> segundo) {
	std::vector <int> result;
	if (primero.size() == 0 && segundo.size()== 0) {
		if (primero[0] < segundo[0]) {
			result.push_back(0);
			result.push_back(1);
			return { false, result };
		}
		else if (primero[0] > segundo[0]) {
			result.push_back(1);
			result.push_back(0);
			return { false, result };
		}
		else {
			result.push_back(0);
			return { true, result };
		}
	}
	else {
		if (primero[ini] > segundo[ini]) {
			result.push_back(-1);
			result.push_back(0);
			return { false, result };
		}
		else {
			int m = (fin + ini) / 2;
			if (primero[m] == segundo[m]) {
				result.push_back(m);
				return { true, result };
			}
			else {
				if ((primero[ini] - segundo[ini]) < (primero[fin] - segundo[fin])) resolver(ini, m, primero, segundo);
				else
					resolver(m, fin, primero, segundo);
			}

		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	int dim = 0;
	std::cin >> dim;

	if (dim == 0)
		return false;
	std::vector<int> primero(dim);
	std::vector<int> segundo(dim);

	sol sol = resolver(0, dim-1, primero, segundo);



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