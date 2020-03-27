// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const &v1, std::vector<int> const &v2, int ini, int fin) {

	if (ini == fin) return v1[ini];
	if (ini + 1 == fin){
		if (v1[ini] == v2[ini]) return v1[fin];
		else return v1[ini];
	}
	else {
		int m = (ini + fin) / 2;
		if (v1[m] != v2[m]) return resolver(v1, v2, ini, m); //izquierda
		else return resolver(v1, v2, m, fin); //derecha
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	int dim = 0;
	
	std::cin >> dim;

	std::vector <int> v1(dim);
	std::vector <int> v2(dim);

	for (int i = 0; i < dim; i++)
		std::cin >> v1[i];

	for (int i = 0; i < (dim - 1); i++)
		std::cin >> v2[i];

	std::cout << resolver(v1,v2,0,dim-1) << "\n";
	// escribir sol


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