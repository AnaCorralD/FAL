// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector<std::vector<int>>;

// función que resuelve el problema
void  resolver(std::vector<std::vector<int>> &matriz, int a, int b) {

	if (b == 0 || a == b) matriz[a][b] = 1;
	else {
		if (matriz[a - 1][b - 1] == -1) resolver(matriz, a - 1, b - 1);
		if (matriz[a - 1][b] == -1) resolver(matriz, a - 1, b);
		matriz[a][b] = matriz[a - 1][b - 1] + matriz[a - 1][b];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int a = 0, b = 0;
	std::cin >> a;
	std::cin >> b;

	if (!std::cin)
		return false;

	tmatriz matriz(a + 1, std::vector<int>(b + 1, -1));
	resolver(matriz, a, b);


	std::cout << matriz[a][b] << "\n";
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