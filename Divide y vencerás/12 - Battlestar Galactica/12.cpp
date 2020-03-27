// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema
int resolver(std::vector<int> &v , int ini , int fin) {
	
	if (ini >= fin) return 0;
	else {
		int m = (ini + fin) / 2;

		int iz = resolver(v, ini, m); //O (log n)
		int der = resolver(v, m + 1, fin); // O (log n)

		int i = ini;
		int j = m + 1;
		int cont = 0;

		while (i <= m && j <= fin) {
			if (v[i] > v[j]) {
				cont += (m - i + 1);
				j++;
			}
			else i++;
		}

		std::sort(v.begin() + ini, v.begin() + fin + 1); // O(n log(n))
		return iz + der + cont;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	int dim;

	std::cin >> dim;

	if (!std::cin)
		return false;

	std::vector<int> v(dim);

	for (int i = 0; i < dim; i++)
		std::cin >> v[i];

	std::cout << resolver(v, 0, dim - 1) << "\n";
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