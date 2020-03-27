// Ana Laura Corral Descargue
// E17 o TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> const & numeros, int const p) {

	bool ok = true;
	int max = numeros[0];

	for (int i = 0; i <= p; ++i) {
		if (numeros[i] > max) max = numeros[i];
	}

	for (int i = p + 1; i < numeros.size() && ok; ++i) {
		if (max >= numeros[i]) ok = false;
	}

	return ok;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int dim, p;
	std::cin >> dim >> p;

	std::vector<int> numeros(dim);

	for (int i = 0; i < dim; i++)
		std::cin >> numeros[i];


	bool sol = resolver(numeros, p);
	
	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";


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