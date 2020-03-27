// Ana Laura Corral Descargue
// E14


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// funcio?n que resuelve el problema
void resolver(std::vector<int> const & datos, std::vector<int> &salida, int const &L) {

	int i = 0;
	int cont = 1;
	while (i < datos.size() - 1) {
		if (datos[i] == datos[i + 1] || datos[i] + 1 == datos[i + 1] || datos[i] - 1 == datos[i + 1])
			cont++;
		else {
			if (cont >= L)
				salida.push_back(i - cont + 1);
			
			cont = 1;
		}
		i++;
	}
	if (cont >= L) 
		salida.push_back(i - cont + 1);
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int dim = 0, L = 0;
	std::cin >> dim >> L;
	if (dim == 0 && L == 0)
		return false;
	std::vector <int> datos(dim);
	for (int i = 0; i < dim; i++)
		std::cin >> datos[i];

	std::vector <int> salida;

	resolver(datos, salida, L);

	std::cout << salida.size() << " ";
	for (int i = 0; i < salida.size(); i++) {
		if (i == salida.size() - 1)
			std::cout << salida[i];
		else
			std::cout << salida[i] << " ";
	}
	std::cout << "\n";

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