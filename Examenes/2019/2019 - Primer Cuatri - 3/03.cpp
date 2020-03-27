// Ana Laura Corral Descargue
// E14


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

struct info {
	int numJu;
	int numNi;
	int minJu;
};

struct nodo {
	int k;
	const std::vector<int> &edadRecomendadaJu;
	const std::vector<int> &edadNi;
	const tMatriz &matriz;
	const struct info& info;

	std::vector <int> juguetesNino;
	std::vector<int> contJuNi;
	int actualMax;

	std::vector<int> &sol;
	int &maximo;
};

bool esValida(struct nodo &n, const int  &j) {

	if (n.edadNi[j] < n.edadRecomendadaJu[n.k]) return false;


	return true;
}

bool esSolucion(struct nodo &n) {
	return n.k == n.info.numJu - 1;

}

bool esSolucionValida(struct nodo &n) {
	int i = 0;
	while (i < n.contJuNi.size()){
		if (n.contJuNi[i] < n.info.minJu)
			return false;
		i++;
	}

	return true;
}
// función que resuelve el problema
void resolver(struct nodo &n) {

	for (int j = 0; j < n.info.numNi; j++) {

		if (esValida(n, j)) {
			n.juguetesNino[n.k] = j;
			n.contJuNi[j]++;
			n.actualMax += n.matriz[j][n.k];
			if (esSolucion(n)) {
				if (esSolucionValida(n)) {
					if (n.actualMax > n.maximo) {
						n.maximo = n.actualMax;
					}
				}
			}
			else {
				nodo siguiente{ n.k +1, n.edadRecomendadaJu, n.edadNi, n.matriz, n.info, n.juguetesNino, n.contJuNi, n.actualMax , n.sol, n.maximo };
				resolver(siguiente);
			}
			n.contJuNi[j]--;
			n.actualMax -= n.matriz[j][n.k];
		}

	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	info info;
	std::cin >> info.numJu >> info.numNi >> info.minJu;
	if (info.numJu == 0 && info.numNi == 0 && info.minJu == 0)
		return false;

	std::vector<int> edadRecomendadaJu(info.numJu);
	std::vector<int> edadNi(info.numNi);
	tMatriz matriz(info.numNi, std::vector<int>(info.numJu));

	for (int i = 0; i < info.numJu; i++)
		std::cin >> edadRecomendadaJu[i];

	for (int i = 0; i < info.numNi; i++)
		std::cin >> edadNi[i];

	for (int i = 0; i < info.numNi; i++) {
		for (int j = 0; j < info.numJu; j++) {
			std::cin >> matriz[i][j];
		}
	}


	std::vector <int> juguetesNino(info.numJu);
	bool haySol = true;
	std::vector<int> contJuNi(info.numNi);

	std::vector<int> sol(info.numJu);
	int maximo = 0;
	nodo inicio{ 0, edadRecomendadaJu, edadNi, matriz, info, juguetesNino, contJuNi,0, sol, maximo };
	resolver(inicio);


	std::cout << maximo << "\n";

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