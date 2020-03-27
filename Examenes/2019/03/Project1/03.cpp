// Ana Laura Corral Descargue
// TAIS19


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



using tMatriz = std::vector<std::vector<int>>;

bool esValida(int const k, const int i,std::vector<int> const& edadRecomendadaJ, std::vector<int> const& edadNinos) {

	if (edadRecomendadaJ[k] > edadNinos[i]) return false;

	return true;
}

bool esSolucionValida(std::vector<int> const& contJugue, const int minJugue) {
	for (int i = 0; i < contJugue.size(); i++) {
		if (contJugue[i] < minJugue) return false;
	}
	return true;
}
void resolver(int k, int const juguetes, int const ninos, const int minJugue, std::vector<int> const& edadRecomendadaJ, std::vector<int> const& edadNinos, tMatriz const & satifacion,
			std::vector<int> &contJugueEnNino, int actual,
			int &max, std::vector<int>sol) {

	for (int i = 0; i < ninos; i++) {
		actual += satifacion[i][k];
		contJugueEnNino[i]++;
		sol[k] = i;
		if (esValida(k, i, edadRecomendadaJ, edadNinos)) {
			if (k == juguetes - 1) { //esSolucion
				if (esSolucionValida(contJugueEnNino,minJugue)) {
					if(actual > max)
						max = actual;
				}
			}
			else {
				resolver(k+1, juguetes, ninos, minJugue, edadRecomendadaJ, edadNinos, satifacion,
					contJugueEnNino, actual,
					max, sol);
			}
		}
		actual -= satifacion[i][k];
		contJugueEnNino[i]--;

	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int juguetes, ninos, minJugue;
	std::cin >> juguetes >> ninos >> minJugue;

	if (juguetes == 0, ninos==0, minJugue == 0)
		return false;

	std::vector<int> edadRecomendadaJ(juguetes);
	for (int i = 0; i < juguetes; i++)
		std::cin >> edadRecomendadaJ[i];

	std::vector<int> edadNinos(ninos);
	for (int i = 0; i < ninos; i++)
		std::cin >> edadNinos[i];

	tMatriz satifacion(ninos, std::vector<int>(juguetes));
	for (int i = 0; i < ninos; i++) {
		for (int j = 0; j < juguetes; j++)
			std::cin >> satifacion[i][j];
	}

	std::vector<int> contJugueEnNino(ninos);
	std::vector<int> sol(juguetes);

	/*Recorrer en diagional*/
	int actual = 0;
	int max = 0;
	int j = 0;
	int cont = 0;
	int i = 0;
	while(i < ninos){
		if (edadRecomendadaJ[j] <= edadNinos[i]) {
			if (cont < minJugue) {
				cont++;
				max += satifacion[i][j];
				j++;
			}
			if (cont == minJugue) {
				cont = 0;
				i++;
			}
		}
	}
	


	resolver(0, juguetes, ninos, minJugue, edadRecomendadaJ, edadNinos, satifacion,
		contJugueEnNino, actual,
		max, sol);

	std::cout << max << "\n";

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