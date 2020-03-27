// Ana Laura Corral Descargue
// E17 o TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct salida{
	int ini;
	int fin;
};

// función que resuelve el problema
salida resolver(std::vector<int> const &edificios, int const altura) {
	salida sal{ 0,0 };
	int aux = 0;
	int cont = 0;
	for (int i = 0; i < edificios.size(); i++) {
		if (edificios[i] > altura)
			aux++;
		else {
			if (cont < aux) {
				sal.fin = i - 1;
				sal.ini = sal.fin - aux + 1;
				cont = aux;
			}
			aux = 0;
		}
	}

	if (cont < aux) {
		sal.fin = edificios.size() - 1;
		sal.ini = sal.fin - aux + 1;
	}

	return sal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int dim, altura;
	std::cin >> dim >> altura;

	std::vector<int> edificios(dim);

	for (int i = 0; i < dim; i++)
		std::cin >> edificios[i];


	salida sol = resolver(edificios, altura);
	
	std::cout << sol.ini << " " << sol.fin << "\n";


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