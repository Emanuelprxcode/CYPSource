#include <stdio.h>
int main() {

	int temp;
	float tempcal;
	int i, g; //Contadores para repeticione
	int iDatos; // Numero de datos que van a ingresar
	int iCuentas; //Numero de cuentas sin repeticion

	scanf_s("%i", &iDatos);

	int* cuenta = new int[iDatos]; //Cuentas ingresadas
	float* calificacion = new float[iDatos]; //Calificaciones ingresadas
	int* cuentanr = new int[iDatos]; //Cuentas sin repeticion

	//Lee los datos de entrada
	for (g = 0; g < iDatos; g++) {
		scanf_s("%i", &cuenta[g]);
		scanf_s("%f", &calificacion[g]);
	}

	//Acomodar las cuentas mayor a menor
	for (g = 0; g < iDatos; g++) {
		for (i = 0; i < iDatos; i++) {
			if (cuenta[i] < cuenta[i + 1]) {
				temp = cuenta[i + 1];
				tempcal = calificacion[i + 1];
				cuenta[i + 1] = cuenta[i];
				calificacion[i + 1] = calificacion[i];
				cuenta[i] = temp;
				calificacion[i] = tempcal;
			}
		}
	}

	i = 0;
	g = 0;
	cuentanr[i] = cuenta[i];
	//Contador de cuentas diferentes
	for (g = 0; g < iDatos; g++) {
		if (cuentanr[i] != cuenta[g]) {
			i++;
			cuentanr[i] = cuenta[g];
		}
	}
	//asigna a iCuentas el valor de cuentas sin repeticion
	iCuentas = i;

	float* fCalifnr = new float[iCuentas];

	//asigna valor de 0 a las calificaciones
	for (g = iCuentas; g >= 0; g--) {
		fCalifnr[g] = 0;
	}

	//Obtiene la calificacion maxima de cada cuenta
	for (i = iCuentas; i >= 0; i--) {
		for (g = 0; g < iDatos; g++) {
			if (cuentanr[i] == cuenta[g]) {
				if (calificacion[g] > fCalifnr[i]) {
					fCalifnr[i] = calificacion[g];
				}
			}
		}
	}

	//imprimir todo
	if (iDatos > 0) {
		printf("%i\n", (iCuentas + 1));
		for (g = iCuentas; g >= 0; g--) {
			printf("%i ", cuentanr[g]);
			if (g > 0) {
				printf("%f\n", fCalifnr[g]);
			}
			else {
				printf("%f", fCalifnr[g]);
			}
		}
	}
	else {
		printf("%i", 0);
	}

	return 0;

}