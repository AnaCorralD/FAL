// Ana Laura Corral Descargue
// E17 o TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct salida{
	int ini;
	int ganancia;
};

// función que resuelve el problema
salida resolver(std::vector<int> const & vagones, int const tiempo) {
	salida sal{0,vagones[0]};
	int ganacia = vagones[0];
	for (int i = 1; i < tiempo; i++) {
		ganacia += vagones[i];
	}
	sal.ini = 0;
	sal.ganancia = ganacia;

	int j = 0;
	for (int i = tiempo; i < vagones.size(); i++) {
		ganacia += vagones[i] - vagones[j];
		if (ganacia >= sal.ganancia) {
			sal.ini = j + 1;
			sal.ganancia = ganacia;
		}
		j++;
	}
	return sal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int dim, tiempo;
	std::cin >> dim >> tiempo;
	std::vector<int> vagones(dim);
	
	for (int i = 0; i < dim; i++)
		std::cin >> vagones[i];

	salida sol = resolver(vagones, tiempo);
	
	std::cout << sol.ini << " " << sol.ganancia << "\n";


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