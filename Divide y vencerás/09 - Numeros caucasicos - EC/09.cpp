// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct datos {
	int cont;
	bool ok;
};

datos resolver(std::vector<int> const & v, int ini, int fin) {

	if (ini == fin) {
		if (v[ini] % 2 == 0) return { 1, true };
		else return { 0, true };
	}
	else {
		int m = (ini + fin) / 2;

		datos iz = resolver(v, ini, m);
		datos der = resolver(v, m + 1, fin);

		if (iz.ok && der.ok && std::abs(iz.cont - der.cont) <= 2)
			return { iz.cont + der.cont, true };
		else
			return { iz.cont + der.cont, false };
		
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int dim;
	std::cin >> dim;

	if (dim == 0)
		return false;

	std::vector<int> v(dim);
	for (int i = 0; i < dim; i++)
		std::cin >> v[i];

	datos sol = resolver(v, 0, dim - 1);

	if (sol.ok)
		std::cout << "SI\n";
	else 
		std::cout << "NO\n";
	


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