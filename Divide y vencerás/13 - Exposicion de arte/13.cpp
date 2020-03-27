// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


void resolver(const std::vector<int> &v, int ini, int fin) {
	
	int m = (ini + fin) / 2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int numobras, maxViajes;

	std::cin >> numobras;

	if (numobras == 0)
		return false;

	std::cin >> maxViajes;

	int maximo;
	std::vector <int> v(numobras);
	for (int i = 0; i < numobras; i++) {
		std::cin >> v[i];
		maximo += v[i];
	}

	 resolver(v,1,maximo);

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