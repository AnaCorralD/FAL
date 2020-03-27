// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include  <vector>
#include <algorithm>

/*
	 Coste: O(log n) -> siendo n el numero de elementos del vector
		T(n) = {
			c si n=0
			T(n/2) + c 	En cualquier otro caso.
		}
*/

// función que resuelve el problema
int resolver(std::vector<int> const&v, int ini , int fin) {

	if (ini == fin) return v[ini];
	else if (ini + 1 == fin) return std::min(v[ini], v[fin]);
	else {
		int m = (ini + fin) / 2;
		if (v[m] < v[m + 1] && v[m] < v[m - 1]) return v[m];
		if (v[m] < v[ini]) return resolver(v, m + 1, fin); //hacia la derecha
		else return resolver(v, ini, m - 1); //hacia la izquierda
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	int dim = 0;
	std::cin >> dim;

	std::vector <int> v(dim);
	for (int i = 0; i < dim; i++)
		std::cin >> v[i];
	if (!std::cin)
		return false;

	std::cout << resolver(v, 0, dim - 1) << "\n";

	


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