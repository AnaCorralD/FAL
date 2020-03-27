// Ana Laura Corral Descargue
// E17 o TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int> &numeros) {

	int j = 0;
	for (int i = 0; i < numeros.size(); i++) {
		if (numeros[i] % 2 == 0) {
			numeros[j] = numeros[i];
			j++;
		}
	}
	numeros.resize(j);

	return numeros;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int dim;
	std::cin >> dim;

	std::vector<int> numeros(dim);

	for (int i = 0; i < dim; i++)
		std::cin >> numeros[i];

	std::vector<int> sol = resolver(numeros);
	
	for (int i = 0; i < sol.size(); i++) {
		if (i == 0) std::cout << sol[i];
		else std::cout << " " << sol[i];
	}
	std::cout << "\n";


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