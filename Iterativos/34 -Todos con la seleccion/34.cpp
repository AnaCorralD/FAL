// Ana Laura Corral Descargue
// E17 o TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos{
	int dimMax;
	int numVeces;
	int partidosUltimos;
};

tDatos resolver(std::vector<int> const& v) {
	tDatos datos{0,0,v.size()};
	int cont = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > 0) {
			if (cont == -1) cont = 0;
			cont++;
		}
		else {
			if (cont > datos.dimMax) {
				datos.dimMax = cont;
				datos.numVeces = 0;
			}
			if (cont == datos.dimMax) {
				datos.numVeces++;
				datos.partidosUltimos = v.size() - i;
			}
			cont = -1;
		}
	}

	if (cont > datos.dimMax) {
		datos.dimMax = cont;
		datos.numVeces = 0;
	}
	if (cont == datos.dimMax) {
		datos.numVeces++;
		datos.partidosUltimos = 0;
	}

	return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int dim;
	std::cin >> dim;

	if (!std::cin)
		return false;

	std::vector<int> v(dim);
	for (int i = 0; i < dim; i++) std::cin >> v[i];

	tDatos sol = resolver(v);

	std::cout << sol.dimMax << " " << sol.numVeces << " " << sol.partidosUltimos << "\n";


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