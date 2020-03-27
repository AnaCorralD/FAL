// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> const &v, int ini, int fin) {

	if (fin - ini == 0) return true;
	else {
		int m = (ini + fin) / 2;
		bool iz = resolver(v, ini, m);
		bool der = resolver(v, m + 1, fin);
		return (iz && der && v[0] <= v[m] && v[m] <= v[v.size()-1]);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	
	int num;
	std::cin >> num;
	if (num == 0)
		return false;

	std::vector<int> v;
	
	while (num != 0) {
		v.push_back(num);
		std::cin >> num;
	}
	bool sol = resolver(v, 0, v.size() -1 );
	
	if (sol)
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
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