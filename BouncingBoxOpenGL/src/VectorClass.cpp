/*
 * Disciplina: Constru��o de Software Gr�fico 3D
 * Professor: Luiz Ant�nio Pav�o
 * Aluno: Jo�o Pedro Rodrigues de Lima
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