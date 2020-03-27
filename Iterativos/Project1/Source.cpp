//*****************
// IMPORTANTE
//
// Ana Laura Corral y Natalia Rodriguez-Peral
// E17 y E62
// E75
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


/*
	Coste: O (n) siendo n el numero de elementos del vector
	En el primer for se dan x vueltas
	En el siguiente while se dan v.size() - x
	Por tanto tiene coste lineal
	En los bucles correspondientes se hacen comprobaciones con los if de conste constante y 
	de asignaciones de valores que tiene coste constante
*/


// Aqui la función implementada por el alumno
int resolver(std::vector<int> const& v, int const x) {

	int contCeros = 0;
	int pos = -1;

	/*Calculamos el primer intervalo de tamaño x más lejos de casa
	y obtenemos el maximo provisional de 0's*/
	for (int i = v.size() - x; i < v.size(); i++) {
		if (v[i] == 0 && pos == -1) 
			pos = i;
		if (v[i] == 0) contCeros++;
	}
	int max = contCeros;
	int j = v.size() - 1;
	int i = v.size() - x - 1;
	
	/*Nos movemos una posicon hacia la izquierda, restando el ultimo valor mas lejos de la casa
	y si es un cero el siguiente valor a la casa lo sumamos a nuestro contador de 0's o no*/
	while ( i >= 0) {
		if (v[j] == 0)contCeros--;
		if (v[i] == 0)contCeros++;
		if (contCeros > max) {
			max = contCeros;
			pos = i;
		}
		i--;
		j--;
	}

	return pos;
}



bool resuelveCaso() {
	int numElem, x;
	std::cin >> numElem; // Longitud de la valla
	if (numElem == 0) return false;
	std::cin >> x; // Longitud de la tela metalica
	std::vector<int> v(numElem);
	for (int& n : v)  // Lectura de los datos del vector
		std::cin >> n;

	
	// LLamada a la funcion que resuelve el problema
	int sol = resolver(v, x);
	if (sol == -1)
		std::cout << "No hace falta\n";
	else std::cout << sol << "\n";
	// Escribir el resultado


	return true;
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso())
		;

	// Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}