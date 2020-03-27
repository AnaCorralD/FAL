// Ana Laura Corral Descargue
// TAIS19 o E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void resolver(std::vector<int>& v) {
	int j = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) {
			v[j] = v[i];
			j++;
		}
	}
	v.resize(j);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int dim;
	std::cin >> dim;

	if (dim == -1)
		return false;

	std::vector<int> v(dim);
	for (int i = 0; i < dim; i++)
		std::cin >> v[i];

	resolver(v);
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) std::cout << v[i];
		else std::cout << " " << v[i];
	}

	std::cout << "\n";
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