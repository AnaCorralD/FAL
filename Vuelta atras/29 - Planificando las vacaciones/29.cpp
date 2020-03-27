// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;


void resolver(int k, tMatriz const& matriz,
			  int actual, std::vector<bool> marked,
			  int& min, std::vector<int>sol) {

	for (int i = 0; i < matriz.size(); i++) {
		sol[k] = i;
		actual += matriz[sol[k - 1]][i];
		if (!marked[sol[k]]) { //esvalida()
			marked[sol[k]] = true;
			if (k == matriz.size() - 1) {
				if (actual + matriz[sol[k]][0] < min)
					min = actual + matriz[sol[k]][0];
			}
			else {
				resolver(k + 1, matriz,
					actual, marked,
					min, sol);
			}
			marked[sol[k]] = false;
		}
		actual -= matriz[sol[k - 1]][i];
	}

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int dim;
	std::cin >> dim;
	if (dim == 0)
		return false;

	tMatriz matriz(dim, std::vector<int>(dim));
	for(int i = 0; i < dim;i++){
		for (int j = 0; j < dim; j++)
			std::cin >> matriz[i][j];
	}
	int actual = 0;
	int min = 1000000000;
	std::vector<bool>marked(dim);
	std::vector<int>sol(dim);
	marked[0] = true;
	sol[0] = 0;
	resolver(1, matriz,actual, marked,min, sol);
	std::cout << min << "\n";
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