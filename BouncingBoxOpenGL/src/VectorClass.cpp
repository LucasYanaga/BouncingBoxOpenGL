/*
 * Disciplina: Construção de Software Gráfico 3D
 * Professor: Luiz Antônio Pavão
 * Aluno: João Pedro Rodrigues de Lima
 */

#include <math.h>

class Vector
{
public:
	double xCoord, yCoord, zCoord;

public:
	Vector(double vectorX, double vectorY, double vectorZ)
	{
		xCoord = vectorX;
		yCoord = vectorY;
		zCoord = vectorZ;
	}

	void vectorSum(Vector newVector)
	{
		xCoord += newVector.xCoord;
		yCoord += newVector.yCoord;
		zCoord += newVector.zCoord;
	}
};