// Ana Laura Corral Descargue
// e17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
predicate consecutivos ( s: seq<int>, ini: int, fin: int) : 
forall k:: ini <= k <= fin ==> S[k-1] + 1 == S[k]

predicate secuenciaMax ( s: seq<int>, long: int)


*/

/*
Invariante: 0<= i < v.Lenght
Invariante: consecutivos (v[..i], .. , i)
Decress: v.Lenght - i
*/

struct tDatos{
	int ini;
	int cont;
};

tDatos resolver(std::vector<int> const& numeros) {
	tDatos datos{};
	int contA = 1;
	for (int i = 1; i < numeros.size(); i++) {
		if (numeros[i - 1] + 1 == numeros[i])
			contA++;
		else {
			if (contA > datos.cont) {
				datos.cont = contA;
				datos.ini = i - contA;
			}
			contA = 1;
		}
	}

	if (contA > datos.cont) {
		datos.cont = contA;
		datos.ini = numeros.size() - contA;
	}
	return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int dim;
	std::cin >> dim;
	if (dim == 0)
		return false;

	std::vector<int> numeros(dim);
	for (int i = 0; i < dim; i++)
		std::cin >> numeros[i];

	tDatos sol = resolver(numeros);
	std::cout << sol.ini << " " << sol.cont << "\n";
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