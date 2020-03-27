// Ana Laura Corral Descargue
// TAIS19 o E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector<int> const& v, int ini, int fin) {

	if (v[ini] == v[fin]) return 1;
	else if (ini == fin) return 1;
	
	else {
		int m = (ini + fin) / 2;
		int iz = resolver(v, ini, m);
		int der = resolver(v, m+1, fin);
		if (v[m] == v[m + 1]) return iz + der - 1;
		else return iz + der;
		
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int dim;
	std::cin >> dim;

	if (dim == 0)
		return false;

	std::vector<int> v(dim);
	for (int i = 0; i < dim; i++)
		std::cin >> v[i];
	int cont = resolver(v, 0, dim - 1);
	std::cout << cont << "\n";
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