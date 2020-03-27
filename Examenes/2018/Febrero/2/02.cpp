// Ana Laura Corral Descargue
// TAIS19 o E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector<int> const& v, int ini, int fin) {

	if (ini == fin) return v[ini];
	else {
		int m = (ini + fin) / 2;
		if (v[m] % 2 == 1) return v[m];
		else if (v[0] + (m * 2) == v[m]) //derecha
			resolver(v, m+1, fin);
		else
			resolver(v, ini, m);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	 
	int dim;
	std::cin >> dim;
	if (dim == 0)
		return false;

	std::vector<int>numeros(dim);
	for (int i = 0; i < dim; i++)
		std::cin >> numeros[i];

	std::cout << resolver(numeros, 0, dim-1) << "\n";

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