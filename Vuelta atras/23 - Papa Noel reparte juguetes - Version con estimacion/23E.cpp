// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector<std::vector<int>>;
struct info{
	int juguetes;
	int ninos;
};

struct nodo{
	int k;
	const tmatriz &matriz;
	const std::vector<int> &acum;

	int &mejorSol;
	std::vector<bool> &marked;
	int actual;
};
// función que resuelve el problema
void resolver(struct nodo&n, struct info& info) {

	for (int i = 0; i < info.juguetes; i++) {
		if (!n.marked[i]) { //esValida()
			n.actual += n.matriz[n.k][i];
			n.marked[i] = true;
			if (n.k == info.ninos - 1) { //esSolucion()
				if (n.actual > n.mejorSol)
					n.mejorSol = n.actual; //solucion mejor
			}
			else {
				int aux = n.actual + n.acum[n.k + 1];
				if (n.actual + n.acum[n.k + 1] > n.mejorSol) {
					nodo siguiente{ n.k + 1, n.matriz,n.acum, n.mejorSol, n.marked,n.actual };
					resolver(siguiente, info);
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
	info info;
	std::cin >> info.juguetes >> info.ninos;
	if (!std::cin)
		return false;

	tmatriz matriz(info.ninos, std::vector<int>(info.juguetes));
	for (int i = 0; i < info.ninos; i++) {
		for (int j = 0; j < info.juguetes; j++) {
			std::cin >> matriz[i][j];
		}
	}
	std::vector<bool> marked(info.juguetes, false);

								// Para estimacion //
	// Calcula el vector de máximos
	std::vector<int> acum(info.ninos);
	for (int i = 0; i < info.ninos; i++) {
		int auxMax = matriz[i][0];
		for (int j = 1; j < info.juguetes; j++) {
			if (auxMax < matriz[i][j])
				auxMax = matriz[i][j];
		}
		acum[i] = auxMax;
	}
	//Vector acumulado
	for (int i = (int)acum.size() - 1; i > 0; --i) {
		acum[i - 1] += acum[i];
	}
	// Obtiene una inicialización posible para la solución mejor
	int mejorSol = 0;
	for (int i = 0; i < info.ninos; ++i) {
		mejorSol += matriz[i][i];
	}

	
	nodo inicio{ 0,matriz,acum,mejorSol,marked,0 };
	resolver(inicio, info);
	
	std::cout << mejorSol << "\n";


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