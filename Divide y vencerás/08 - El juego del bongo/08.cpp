// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const &v, int ini, int fin, int const cantado) {

	if (ini > fin) return -1;
	else {
		int m = (ini + fin) / 2;
		if (v[m] == cantado + m) return v[m];
		else if (cantado + m < v[m])
			return resolver(v, ini, m-1, cantado); //hacia la izquierda
		else
			return resolver(v, m+1, fin, cantado); //hacia la derecha
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	
	int dim, cantado;
	std::cin >> dim >> cantado;

	std::vector<int> v(dim);
	for (int i = 0; i < dim; i++)
		std::cin >> v[i];

	int sol = resolver(v, 0, dim-1,cantado);
	
	if (sol > 0)
		std::cout << sol << "\n";
	else
		std::cout << "NO\n";



}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}