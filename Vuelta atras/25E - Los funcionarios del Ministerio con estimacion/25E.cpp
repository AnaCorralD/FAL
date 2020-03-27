// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector<std::vector<int>>;

struct nodo {
	int k;
	const tmatriz& matriz;
	const std::vector<int> &acum;

	int actual;
	std::vector<bool>& marked;
	int& solMejor;
};

void resolver(struct nodo& n, const int num) {

	for (int i = 0; i < num; i++) {
		if (!n.marked[i]) { //esValida()
			n.actual += n.matriz[n.k][i];
			n.marked[i] = true;
			if (n.k == num - 1) {// esSolucion()
				if (n.actual < n.solMejor)
					n.solMejor = n.actual;
			}
			else {
				if (n.actual + n.acum[n.k + 1] < n.solMejor) {
					nodo siguiente{ n.k + 1, n.matriz,n.acum, n.actual,n.marked,n.solMejor };
					resolver(siguiente, num);
				}
			}
			n.actual -= n.matriz[n.k][i];
			n.marked[i] = false;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int num;
	std::cin >> num;
	if (num == 0)
		return false;

	tmatriz matriz(num, std::vector<int>(num));
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			std::cin >> matriz[i][j];
	}
	std::vector<bool> marked(num);


							//Para estimacion//
	std::vector<int> acum(num);
	for (int i = 0; i < num; i++) {
		int auxMin = matriz[i][0];
		for (int j = 1; j < num; j++) {
			if (auxMin > matriz[i][j])
				auxMin = matriz[i][j];
		}
		acum[i] = auxMin;
	}

	for (int i = (int)acum.size() - 1; i > 0; i--)
		acum[i - 1] += acum[i];

	int solMejor = 0;
	for (int i = 0; i < num; i++)
		solMejor += matriz[i][i];

	nodo inicio{ 0, matriz,acum,0,marked,solMejor };
	resolver(inicio, num);
	std::cout << solMejor << "\n";

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