/*****************************************************************************************************************

	�ΰ��� ��� �����͸� data.txt���Ͽ��� �Է� �޾�, �� ����� +, -, * ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	��, ������ �ڷᱸ���� ���� �Ҵ����� 2���� �迭�� �����Ͽ� �ۼ��Ͽ��� ��. ������: 4�� 18��(��)

*******************************************************************************************************************/

/*
	* �ڷᱸ�� ���� ver 0.1
	* �ۼ��� : 2024.04.14
	* �ۼ��� : 20214003�й� �ֿ���
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>


/*
	*matrix_multiply ver 0.1
	*�ۼ��� : 2024.04.14
	*�ۼ��� : 20214003�й� �ֿ���

	-�Լ� ����
	: A_matrix,B_matrix �����ķ� ���� �͵��� ���� ���ó�� �ٲ��ְ� �ΰ��� ����� ���� ����� ����ϴ� �Լ���.
*/
void matrix_multiply(int** A_matrix, int** B_matrix, int Arow, int Acol, int Brow, int Bcol, int countA, int countB)
{
	//C_matrix �����Ҵ�
	int** C_matrix = (int**)calloc(Arow, sizeof(int*));
	//�����Ҵ� �����ϸ� ����
	if (C_matrix == NULL) {
		printf("Arow�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 0;
	}
	for (int i = 0; i < Arow; i++)
	{
		C_matrix[i] = (int*)calloc(Acol, sizeof(int));
		if (C_matrix[i] == NULL) {
			printf("Arow�� Acol�� ���� �޸� �Ҵ翡 �����߽��ϴ�. %d.\n", i);
			return 0;
		}
	}
	//D_matrix �����Ҵ�
	int** D_matrix = (int**)calloc(Brow, sizeof(int*));
	//�����Ҵ� �����ϸ� ����
	if (D_matrix == NULL) {
		printf("Brow�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 0;
	}
	for (int i = 0; i < Brow; i++)
	{
		D_matrix[i] = (int*)calloc(Bcol, sizeof(int));
		if (D_matrix[i] == NULL) {
			printf("Brow�� Bcol�� ���� �޸� �Ҵ翡 �����߽��ϴ� %d.\n", i);
			return 0;
		}
	}
	//������� ���� ��
	int sum = 0;
	//�����
	int m = 0, n = 0;
	//C_matrix�� A_matrix�� ġȯ A_matrix[i][0]���� 0�� ���� �ǹ��ϰ� 1�� ���� �ǹ��Ѵ�.
	for (int i = 0; i < countA; i++)
	{
		m = A_matrix[i][0];
		n = A_matrix[i][1];
		C_matrix[m][n] = A_matrix[i][2];
	}
	//D_matrix�� B_matrix�� ġȯ B_matrix[i][0]���� 0�� ���� �ǹ��ϰ� 1�� ���� �ǹ��Ѵ�.
	for (int i = 0; i < countB; i++)
	{
		m = B_matrix[i][0];
		n = B_matrix[i][1];
		D_matrix[m][n] = B_matrix[i][2];
	}

	//A��� * B��� ���
	printf("A ��� * B ���\n");
	for (int i = 0; i < Arow; i++)
	{
		for (int j = 0; j < Bcol; j++)
		{
			for (int k = 0; k < Brow; k++)
			{
				sum += C_matrix[i][k] * D_matrix[k][j];
			}
			printf("%4d ", sum);
			sum = 0;
		}
		printf("\n");
	}
	//C_matrix �����Ҵ� ����
	for (int i = 0; i < Arow; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);
	//D_matrix �����Ҵ� ����
	for (int i = 0; i < Brow; i++) {
		free(D_matrix[i]);
	}
	free(D_matrix);
}

/*
	*matrix_ADD ver 0.1
	*�ۼ��� : 2024.04.14
	*�ۼ��� : 20214003�й� �ֿ���

	-�Լ� ����
	: A_matrix,B_matrix�� ���ڷ� �޾� �ΰ��� ����� �������ִ� �Լ���.
*/
void matrix_ADD(int** A_matrix, int** B_matrix, int row, int col, int countA, int countB)
{
	//C_matrix �����Ҵ�
	int** C_matrix = (int**)calloc(row, sizeof(int*));
	//�����Ҵ� �����ϸ� ����
	if (C_matrix == NULL) {
		printf("Arow�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 1;
	}
	for (int i = 0; i < row; i++)
	{
		C_matrix[i] = (int*)calloc(col, sizeof(int));
		if (C_matrix[i] == NULL) {
			printf("Arow�� Acol�� ���� �޸� �Ҵ翡 �����߽��ϴ�. %d.\n", i);
			return 1;
		}
	}
	//D_matrix �����Ҵ�
	int** D_matrix = (int**)calloc(row, sizeof(int*));
	//�����Ҵ� �����ϸ� ����
	if (D_matrix == NULL) {
		printf("Brow�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 1;
	}
	for (int i = 0; i < row; i++)
	{
		D_matrix[i] = (int*)calloc(col, sizeof(int));
		if (D_matrix[i] == NULL) {
			printf("Brow�� Bcol�� ���� �޸� �Ҵ翡 �����߽��ϴ� %d.\n", i);
			return 1;
		}
	}
	//�����
	int m = 0, n = 0;
	//C_matrix�� A_matrix�� ġȯ A_matrix[i][0]���� 0�� ���� �ǹ��ϰ� 1�� ���� �ǹ��Ѵ�.
	for (int i = 0; i < countA; i++)
	{
		m = A_matrix[i][0];
		n = A_matrix[i][1];
		C_matrix[m][n] = A_matrix[i][2];
	}
	//D_matrix�� B_matrix�� ġȯ B_matrix[i][0]���� 0�� ���� �ǹ��ϰ� 1�� ���� �ǹ��Ѵ�.
	for (int i = 0; i < countB; i++)
	{
		m = B_matrix[i][0];
		n = B_matrix[i][1];
		D_matrix[m][n] = B_matrix[i][2];
	}

	printf("A ��� + B ���\n");
	//A��� B����� �����ش�.
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%4d ", C_matrix[i][j] + D_matrix[i][j]);
		printf("\n");
	}
	printf("\n\n");
	//C_matrix �����Ҵ� ����
	for (int i = 0; i < row; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);
	//D_matrix �����Ҵ� ����
	for (int i = 0; i < row; i++) {
		free(D_matrix[i]);
	}
	free(D_matrix);
}
/*
	*matrix_MINUS ver 0.1
	*�ۼ��� : 2024.04.14
	*�ۼ��� : 20214003�й� �ֿ���

	-�Լ� ����
	: A_matrix,B_matrix �����ķ� ���� �͵��� ���� ���ó�� �ٲ��ְ� �ΰ��� ����� ������ ����� ����ϴ� �Լ���.
*/
void matrix_MINUS(int** A_matrix, int** B_matrix, int row, int col, int countA, int countB)
{
	//C_matrix �����Ҵ�
	int** C_matrix = (int**)calloc(row, sizeof(int*));
	//�����Ҵ� �����ϸ� ����
	if (C_matrix == NULL) {
		printf("Arow�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 1;
	}
	for (int i = 0; i < row; i++)
	{
		C_matrix[i] = (int*)calloc(col, sizeof(int));
		if (C_matrix[i] == NULL) {
			printf("Arow�� Acol�� ���� �޸� �Ҵ翡 �����߽��ϴ�. %d.\n", i);
			return 1;
		}
	}
	//D_matrix �����Ҵ�
	int** D_matrix = (int**)calloc(row, sizeof(int*));
	//�����Ҵ� �����ϸ� ����
	if (D_matrix == NULL) {
		printf("Brow�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 1;
	}
	for (int i = 0; i < row; i++)
	{
		D_matrix[i] = (int*)calloc(col, sizeof(int));
		if (D_matrix[i] == NULL) {
			printf("Brow�� Bcol�� ���� �޸� �Ҵ翡 �����߽��ϴ� %d.\n", i);
			return 1;
		}
	}
	//�����
	int m = 0, n = 0;
	//C_matrix�� A_matrix�� ġȯ A_matrix[i][0]���� 0�� ���� �ǹ��ϰ� 1�� ���� �ǹ��Ѵ�.
	for (int i = 0; i < countA; i++)
	{
		m = A_matrix[i][0];
		n = A_matrix[i][1];
		C_matrix[m][n] = A_matrix[i][2];
	}
	//D_matrix�� B_matrix�� ġȯ B_matrix[i][0]���� 0�� ���� �ǹ��ϰ� 1�� ���� �ǹ��Ѵ�.
	for (int i = 0; i < countB; i++)
	{
		m = B_matrix[i][0];
		n = B_matrix[i][1];
		D_matrix[m][n] = B_matrix[i][2];
	}

	printf("A ��� - B ���\n");
	//A��� B����� ���ش�.
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%4d ", C_matrix[i][j] - D_matrix[i][j]);
		printf("\n");
	}
	printf("\n\n");
	//C_matrix �����Ҵ� ����
	for (int i = 0; i < row; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);
	//D_matrix �����Ҵ� ����
	for (int i = 0; i < row; i++) {
		free(D_matrix[i]);
	}
	free(D_matrix);
}
int main()
{
	// ���������� ��������
	FILE* fp;

	//A�� B����� ��� �� ���� �� �ʱ�ȭ
	int Arow = 0, Acol = 0;
	int Brow = 0, Bcol = 0;

	//�������� ��Ÿ�������ؼ��� �� �� ���� �����ϸ� �Ǳ⶧���� 3���� ���� 
	int rare = 3;

	//�Է¹޴� ��
	int num = 0;

	//A���, B���, C��� ����
	int** A_matrix, ** B_matrix, ** C_matrix;

	int i = 0;

	//���� ����
	fp = fopen("data.txt", "r");

	// ���� fopen�Լ����� ������ �߻��Ͽ� fp�� NULL���� ����Ǿ��ٸ� ���Ͽ������
	if (fp == NULL)
	{
		printf("���Ͽ� ������ �ʾҽ��ϴ�.\n");
		return 0;	// �޼��� ����ϰ� ���α׷� ����
	}


	//���� �� �� ���� ũ�⸦ �Է¹޴µ� ������ �ƴ� ���ڰ� �� ������ ����
	if (fscanf(fp, "%d%d", &Arow, &Acol) != 2)
	{
		printf("������ �ƴ� ���� �� �ֽ��ϴ�.\n");
		return 0;
	}
	else if (Arow == 0 || Acol == 0)
	{
		printf("A����� �� �Ǵ� ���� ������ 0���� �Է� �޾ҽ��ϴ�. �ڿ����� �Է����ּ���\n");
		return 0;
	}

	//C_matrix �����Ҵ�
	C_matrix = (int**)malloc(sizeof(int*) * Arow);
	//�޸��Ҵ翡 �����ϸ� ����
	if (C_matrix == NULL) {
		printf("m�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 0;
	}
	for (i = 0; i < Arow; i++)
	{
		C_matrix[i] = (int*)malloc(sizeof(int) * Acol);
		if (C_matrix[i] == NULL) {
			printf("Arow�� Acol�� ���� �޸� �Ҵ翡 �����߽��ϴ�.  %d.\n", i);
			return 0;
		}
	}

	//A��� �Է�
	printf("�Է���� A\n");
	for (int i = 0; i < Arow; i++)
		for (int j = 0; j < Acol; j++) {
			//������ �ƴ� ���� �� ������ ����
			if (fscanf(fp, "%d", &C_matrix[i][j]) != 1)
			{
				printf("������ �ƴ� ���� �� �ְų� ���Ͽ� �迭ũ�� ��ŭ�� ���ڰ� ��� ���� �ʽ��ϴ�.\n");
				return 0;
			}
		}
	//A��� ���
	for (int i = 0; i < Arow; i++) {
		for (int j = 0; j < Acol; j++)
			printf("%4d ", C_matrix[i][j]);
		printf("\n");
	}

	//C_matrix �����Ҵ� ����
	printf("\n\n");
	for (int i = 0; i < Arow; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);



	//B��� ũ�⸦ �޾ƿ� ���� ������ �ƴ� �ٸ� ���� ��������� ����
	if (fscanf(fp, "%d%d", &Brow, &Bcol) != 2)
	{
		printf("������ �ƴ� ���� �� �ֽ��ϴ�.\n");
		return 0;
	}
	else if (Brow == 0 || Bcol == 0)
	{
		printf("B����� �� �Ǵ� ���� ������ 0���� �Է� �޾ҽ��ϴ�. �ڿ����� �Է����ּ���\n");
		return 0;
	}
	//C_matrix �����Ҵ�
	C_matrix = (int**)malloc(sizeof(int*) * Brow);
	//�޸��Ҵ翡 �����ϸ� ����
	if (C_matrix == NULL) {
		printf("m�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 0;
	}
	for (i = 0; i < Brow; i++)
	{
		C_matrix[i] = (int*)malloc(sizeof(int) * Bcol);
		if (C_matrix[i] == NULL) {
			printf("Brow�� Bcol�� ���� �޸� �Ҵ翡 �����߽��ϴ�.  %d.\n", i);
			return 0;
		}
	}

	//B��� �Է�
	printf("�Է���� B\n");
	for (int i = 0; i < Brow; i++)
		for (int j = 0; j < Bcol; j++) {
			//������ �ƴ� ���� �������� ����
			if (fscanf(fp, "%d", &C_matrix[i][j]) != 1)
			{
				printf("������ �ƴ� ���� �� �ְų� ���Ͽ� �迭ũ�� ��ŭ�� ���ڰ� ��� ���� �ʽ��ϴ�.\n");
				return 0;
			}
		}

	//B��� ���
	for (int i = 0; i < Brow; i++) {
		for (int j = 0; j < Bcol; j++)
			printf("%4d ", C_matrix[i][j]);
		printf("\n");
	}

	printf("\n\n");

	//C_matrix �����Ҵ� ����
	printf("\n\n");
	for (int i = 0; i < Arow; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);

	//���� �� ������ �̵�
	rewind(fp);


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//A��� ũ�� �Է�(����� �տ��� �߱� ������ ���� �ۼ� ����)
	fscanf(fp, "%d%d", &Arow, &Acol);

	//����� ��ü ũ��
	int m = Arow * Acol;

	//A_matrix �����Ҵ�
	A_matrix = (int**)malloc(sizeof(int*) * m);
	if (A_matrix == NULL) {
		//�޸� �Ҵ翡 �����ϸ� ����
		printf("m�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 0;
	}
	for (i = 0; i < m; i++)
	{
		A_matrix[i] = (int*)malloc(sizeof(int) * rare);
		if (A_matrix[i] == NULL) {
			printf("m�� rare�� ���� �޸� �Ҵ翡 �����߽��ϴ�.  %d.\n", i);
			return 0;
		}
	}

	//A��Ŀ��� 0�� �ƴ� ������ ����
	int countA = 0;

	//��� ���� ������ŭ �ݺ�
	for (int i = 0; i < Arow; i++)
	{
		//�����ķ� �Է¹޴´�.
		for (int k = 0; k < Acol; k++) {
			fscanf(fp, "%d", &num);
			if (num != 0) {
				A_matrix[countA][0] = i;
				A_matrix[countA][1] = k;
				A_matrix[countA][2] = num;
				countA++;
			}

		}

	}

	//B��� ũ�� �Է�(����� �տ��� �߱� ������ ���� �ۼ� ����)
	fscanf(fp, "%d%d", &Brow, &Bcol);

	//B��� ��üũ�� ������ ���ҵ��� ��Ÿ��
	m = Brow * Bcol;

	//B_matrix �����Ҵ�
	B_matrix = (int**)malloc(sizeof(int*) * m);
	//�����Ҵ� �����ϸ� ����
	if (B_matrix == NULL) {
		printf("m�� ���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		return 0;
	}
	for (i = 0; i < m; i++)
	{
		B_matrix[i] = (int*)malloc(sizeof(int) * rare);
		if (B_matrix[i] == NULL) {
			printf("m�� rare�� ���� �޸� �Ҵ翡 �����߽��ϴ�. %d.\n", i);
			return 0;
		}
	}

	//B����� 0�̾ƴ� ������ ����
	int countB = 0;

	//��� ���� ������ŭ �ݺ�
	for (int i = 0; i < Brow; i++)
	{
		//�����ķ� �Է¹޴´�.
		for (int k = 0; k < Bcol; k++) {
			fscanf(fp, "%d", &num);
			if (num != 0) {
				B_matrix[countB][0] = i;
				B_matrix[countB][1] = k;
				B_matrix[countB][2] = num;
				countB++;
			}

		}

	}

	//�� ����� ��� ���� �ٸ��� �н� ������ ���
	if (Arow != Brow || Acol != Bcol)
		printf("����İ� ũ�Ⱑ �޶� ���� �� ����� �Ұ��մϴ�.\n\n");
	else if (Arow == Brow && Acol == Bcol)
	{
		//����
		matrix_ADD((int**)A_matrix, (int**)B_matrix, Arow, Bcol, countA, countB);
		//����
		matrix_MINUS((int**)A_matrix, (int**)B_matrix, Arow, Bcol, countA, countB);
	}

	//�� ����� ��� ���� �ٸ��� �н� ������ ���
	if (Acol != Brow)
		printf("�� ��İ� ��� ���� �޶� ������ �Ұ��մϴ�.\n\n");
	else if (Acol == Brow)
		//����
		matrix_multiply((int**)A_matrix, (int**)B_matrix, Arow, Acol, Brow, Bcol, countA, countB);

	//A_matrix �����Ҵ� ����
	for (int i = 0; i < Arow; i++) {
		free(A_matrix[i]);
	}
	free(A_matrix);

	//B_matrix �����Ҵ� ����
	for (int i = 0; i < Brow; i++) {
		free(B_matrix[i]);
	}
	free(B_matrix);

	//���� �ݱ�
	fclose(fp);

	return 0;

}
