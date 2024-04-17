/*****************************************************************************************************************

	두개의 행렬 데이터를 data.txt파일에서 입력 받아, 두 행렬의 +, -, * 연산을 수행하는 프로그램을 작성하시오.

	단, 희소행렬 자료구조와 동적 할당으로 2차원 배열을 생성하여 작성하여야 함. 제출일: 4월 18일(목)

*******************************************************************************************************************/

/*
	* 자료구조 과제 ver 0.1
	* 작성일 : 2024.04.14
	* 작성자 : 20214003학번 최우진
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>


/*
	*matrix_multiply ver 0.1
	*작성일 : 2024.04.14
	*작성자 : 20214003학번 최우진

	-함수 설명
	: A_matrix,B_matrix 희소행렬로 받은 것들을 원래 행렬처럼 바꿔주고 두개의 행렬을 곱한 행렬을 출력하는 함수다.
*/
void matrix_multiply(int** A_matrix, int** B_matrix, int Arow, int Acol, int Brow, int Bcol, int countA, int countB)
{
	//C_matrix 동적할당
	int** C_matrix = (int**)calloc(Arow, sizeof(int*));
	//동적할당 실패하면 종료
	if (C_matrix == NULL) {
		printf("Arow에 대한 메모리 할당에 실패했습니다.\n");
		return 0;
	}
	for (int i = 0; i < Arow; i++)
	{
		C_matrix[i] = (int*)calloc(Acol, sizeof(int));
		if (C_matrix[i] == NULL) {
			printf("Arow의 Acol에 대한 메모리 할당에 실패했습니다. %d.\n", i);
			return 0;
		}
	}
	//D_matrix 동적할당
	int** D_matrix = (int**)calloc(Brow, sizeof(int*));
	//동적할당 실패하면 종료
	if (D_matrix == NULL) {
		printf("Brow에 대한 메모리 할당에 실패했습니다.\n");
		return 0;
	}
	for (int i = 0; i < Brow; i++)
	{
		D_matrix[i] = (int*)calloc(Bcol, sizeof(int));
		if (D_matrix[i] == NULL) {
			printf("Brow의 Bcol에 대한 메모리 할당에 실패했습니다 %d.\n", i);
			return 0;
		}
	}
	//행과열의 곱의 합
	int sum = 0;
	//행과열
	int m = 0, n = 0;
	//C_matrix에 A_matrix로 치환 A_matrix[i][0]에서 0은 행을 의미하고 1은 열을 의미한다.
	for (int i = 0; i < countA; i++)
	{
		m = A_matrix[i][0];
		n = A_matrix[i][1];
		C_matrix[m][n] = A_matrix[i][2];
	}
	//D_matrix에 B_matrix로 치환 B_matrix[i][0]에서 0은 행을 의미하고 1은 열을 의미한다.
	for (int i = 0; i < countB; i++)
	{
		m = B_matrix[i][0];
		n = B_matrix[i][1];
		D_matrix[m][n] = B_matrix[i][2];
	}

	//A행렬 * B행렬 출력
	printf("A 행렬 * B 행렬\n");
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
	//C_matrix 동적할당 해제
	for (int i = 0; i < Arow; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);
	//D_matrix 동적할당 해제
	for (int i = 0; i < Brow; i++) {
		free(D_matrix[i]);
	}
	free(D_matrix);
}

/*
	*matrix_ADD ver 0.1
	*작성일 : 2024.04.14
	*작성자 : 20214003학번 최우진

	-함수 설명
	: A_matrix,B_matrix를 인자로 받아 두개의 행렬을 덧셈해주는 함수다.
*/
void matrix_ADD(int** A_matrix, int** B_matrix, int row, int col, int countA, int countB)
{
	//C_matrix 동적할당
	int** C_matrix = (int**)calloc(row, sizeof(int*));
	//동적할당 실패하면 종료
	if (C_matrix == NULL) {
		printf("Arow에 대한 메모리 할당에 실패했습니다.\n");
		return 1;
	}
	for (int i = 0; i < row; i++)
	{
		C_matrix[i] = (int*)calloc(col, sizeof(int));
		if (C_matrix[i] == NULL) {
			printf("Arow의 Acol에 대한 메모리 할당에 실패했습니다. %d.\n", i);
			return 1;
		}
	}
	//D_matrix 동적할당
	int** D_matrix = (int**)calloc(row, sizeof(int*));
	//동적할당 실패하면 종료
	if (D_matrix == NULL) {
		printf("Brow에 대한 메모리 할당에 실패했습니다.\n");
		return 1;
	}
	for (int i = 0; i < row; i++)
	{
		D_matrix[i] = (int*)calloc(col, sizeof(int));
		if (D_matrix[i] == NULL) {
			printf("Brow의 Bcol에 대한 메모리 할당에 실패했습니다 %d.\n", i);
			return 1;
		}
	}
	//행과열
	int m = 0, n = 0;
	//C_matrix에 A_matrix로 치환 A_matrix[i][0]에서 0은 행을 의미하고 1은 열을 의미한다.
	for (int i = 0; i < countA; i++)
	{
		m = A_matrix[i][0];
		n = A_matrix[i][1];
		C_matrix[m][n] = A_matrix[i][2];
	}
	//D_matrix에 B_matrix로 치환 B_matrix[i][0]에서 0은 행을 의미하고 1은 열을 의미한다.
	for (int i = 0; i < countB; i++)
	{
		m = B_matrix[i][0];
		n = B_matrix[i][1];
		D_matrix[m][n] = B_matrix[i][2];
	}

	printf("A 행렬 + B 행렬\n");
	//A행렬 B행렬을 더해준다.
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%4d ", C_matrix[i][j] + D_matrix[i][j]);
		printf("\n");
	}
	printf("\n\n");
	//C_matrix 동적할당 해제
	for (int i = 0; i < row; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);
	//D_matrix 동적할당 해제
	for (int i = 0; i < row; i++) {
		free(D_matrix[i]);
	}
	free(D_matrix);
}
/*
	*matrix_MINUS ver 0.1
	*작성일 : 2024.04.14
	*작성자 : 20214003학번 최우진

	-함수 설명
	: A_matrix,B_matrix 희소행렬로 받은 것들을 원래 행렬처럼 바꿔주고 두개의 행렬을 빼기한 행렬을 출력하는 함수다.
*/
void matrix_MINUS(int** A_matrix, int** B_matrix, int row, int col, int countA, int countB)
{
	//C_matrix 동적할당
	int** C_matrix = (int**)calloc(row, sizeof(int*));
	//동적할당 실패하면 종료
	if (C_matrix == NULL) {
		printf("Arow에 대한 메모리 할당에 실패했습니다.\n");
		return 1;
	}
	for (int i = 0; i < row; i++)
	{
		C_matrix[i] = (int*)calloc(col, sizeof(int));
		if (C_matrix[i] == NULL) {
			printf("Arow의 Acol에 대한 메모리 할당에 실패했습니다. %d.\n", i);
			return 1;
		}
	}
	//D_matrix 동적할당
	int** D_matrix = (int**)calloc(row, sizeof(int*));
	//동적할당 실패하면 종료
	if (D_matrix == NULL) {
		printf("Brow에 대한 메모리 할당에 실패했습니다.\n");
		return 1;
	}
	for (int i = 0; i < row; i++)
	{
		D_matrix[i] = (int*)calloc(col, sizeof(int));
		if (D_matrix[i] == NULL) {
			printf("Brow의 Bcol에 대한 메모리 할당에 실패했습니다 %d.\n", i);
			return 1;
		}
	}
	//행과열
	int m = 0, n = 0;
	//C_matrix에 A_matrix로 치환 A_matrix[i][0]에서 0은 행을 의미하고 1은 열을 의미한다.
	for (int i = 0; i < countA; i++)
	{
		m = A_matrix[i][0];
		n = A_matrix[i][1];
		C_matrix[m][n] = A_matrix[i][2];
	}
	//D_matrix에 B_matrix로 치환 B_matrix[i][0]에서 0은 행을 의미하고 1은 열을 의미한다.
	for (int i = 0; i < countB; i++)
	{
		m = B_matrix[i][0];
		n = B_matrix[i][1];
		D_matrix[m][n] = B_matrix[i][2];
	}

	printf("A 행렬 - B 행렬\n");
	//A행렬 B행렬을 빼준다.
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%4d ", C_matrix[i][j] - D_matrix[i][j]);
		printf("\n");
	}
	printf("\n\n");
	//C_matrix 동적할당 해제
	for (int i = 0; i < row; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);
	//D_matrix 동적할당 해제
	for (int i = 0; i < row; i++) {
		free(D_matrix[i]);
	}
	free(D_matrix);
}
int main()
{
	// 파일포인터 변수선언
	FILE* fp;

	//A와 B행렬의 행과 열 선언 및 초기화
	int Arow = 0, Acol = 0;
	int Brow = 0, Bcol = 0;

	//희소행렬을 나타내기위해서는 행 열 값만 저장하면 되기때문에 3으로 선언 
	int rare = 3;

	//입력받는 값
	int num = 0;

	//A행렬, B행렬, C행렬 선언
	int** A_matrix, ** B_matrix, ** C_matrix;

	int i = 0;

	//파일 열기
	fp = fopen("data.txt", "r");

	// 만약 fopen함수에서 에러가 발생하여 fp에 NULL값이 저장되었다면 파일열기실패
	if (fp == NULL)
	{
		printf("파일에 열리지 않았습니다.\n");
		return 0;	// 메세지 출력하고 프로그램 종료
	}


	//만약 행 과 열의 크기를 입력받는데 정수가 아닌 숫자가 들어가 있으면 종료
	if (fscanf(fp, "%d%d", &Arow, &Acol) != 2)
	{
		printf("정수가 아닌 것이 들어가 있습니다.\n");
		return 0;
	}
	else if (Arow == 0 || Acol == 0)
	{
		printf("A행렬의 행 또는 열의 개수가 0으로 입력 받았습니다. 자연수를 입력해주세요\n");
		return 0;
	}

	//C_matrix 동적할당
	C_matrix = (int**)malloc(sizeof(int*) * Arow);
	//메모리할당에 실패하면 종료
	if (C_matrix == NULL) {
		printf("m에 대한 메모리 할당에 실패했습니다.\n");
		return 0;
	}
	for (i = 0; i < Arow; i++)
	{
		C_matrix[i] = (int*)malloc(sizeof(int) * Acol);
		if (C_matrix[i] == NULL) {
			printf("Arow의 Acol에 대한 메모리 할당에 실패했습니다.  %d.\n", i);
			return 0;
		}
	}

	//A행렬 입력
	printf("입력행렬 A\n");
	for (int i = 0; i < Arow; i++)
		for (int j = 0; j < Acol; j++) {
			//정수가 아닌 것이 들어가 있으면 종료
			if (fscanf(fp, "%d", &C_matrix[i][j]) != 1)
			{
				printf("정수가 아닌 것이 들어가 있거나 파일에 배열크기 만큼의 숫자가 들어 있지 않습니다.\n");
				return 0;
			}
		}
	//A행렬 출력
	for (int i = 0; i < Arow; i++) {
		for (int j = 0; j < Acol; j++)
			printf("%4d ", C_matrix[i][j]);
		printf("\n");
	}

	//C_matrix 동적할당 해제
	printf("\n\n");
	for (int i = 0; i < Arow; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);



	//B행렬 크기를 받아옴 만약 정수가 아닌 다른 것이 들어있으면 종료
	if (fscanf(fp, "%d%d", &Brow, &Bcol) != 2)
	{
		printf("정수가 아닌 것이 들어가 있습니다.\n");
		return 0;
	}
	else if (Brow == 0 || Bcol == 0)
	{
		printf("B행렬의 행 또는 열의 개수가 0으로 입력 받았습니다. 자연수를 입력해주세요\n");
		return 0;
	}
	//C_matrix 동적할당
	C_matrix = (int**)malloc(sizeof(int*) * Brow);
	//메모리할당에 실패하면 종료
	if (C_matrix == NULL) {
		printf("m에 대한 메모리 할당에 실패했습니다.\n");
		return 0;
	}
	for (i = 0; i < Brow; i++)
	{
		C_matrix[i] = (int*)malloc(sizeof(int) * Bcol);
		if (C_matrix[i] == NULL) {
			printf("Brow의 Bcol에 대한 메모리 할당에 실패했습니다.  %d.\n", i);
			return 0;
		}
	}

	//B행렬 입력
	printf("입력행렬 B\n");
	for (int i = 0; i < Brow; i++)
		for (int j = 0; j < Bcol; j++) {
			//정수가 아닌 것이 들어가있으면 종료
			if (fscanf(fp, "%d", &C_matrix[i][j]) != 1)
			{
				printf("정수가 아닌 것이 들어가 있거나 파일에 배열크기 만큼의 숫자가 들어 있지 않습니다.\n");
				return 0;
			}
		}

	//B행렬 출력
	for (int i = 0; i < Brow; i++) {
		for (int j = 0; j < Bcol; j++)
			printf("%4d ", C_matrix[i][j]);
		printf("\n");
	}

	printf("\n\n");

	//C_matrix 동적할당 해제
	printf("\n\n");
	for (int i = 0; i < Arow; i++) {
		free(C_matrix[i]);
	}
	free(C_matrix);

	//파일 맨 앞으로 이동
	rewind(fp);


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//A행렬 크기 입력(경고문은 앞에서 했기 때문에 굳이 작성 안함)
	fscanf(fp, "%d%d", &Arow, &Acol);

	//행렬의 전체 크기
	int m = Arow * Acol;

	//A_matrix 동적할당
	A_matrix = (int**)malloc(sizeof(int*) * m);
	if (A_matrix == NULL) {
		//메모리 할당에 실패하면 종료
		printf("m에 대한 메모리 할당에 실패했습니다.\n");
		return 0;
	}
	for (i = 0; i < m; i++)
	{
		A_matrix[i] = (int*)malloc(sizeof(int) * rare);
		if (A_matrix[i] == NULL) {
			printf("m의 rare에 대한 메모리 할당에 실패했습니다.  %d.\n", i);
			return 0;
		}
	}

	//A행렬에서 0이 아닌 원소의 개수
	int countA = 0;

	//행렬 원소 개수만큼 반복
	for (int i = 0; i < Arow; i++)
	{
		//희소행렬로 입력받는다.
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

	//B행렬 크기 입력(경고문은 앞에서 했기 때문에 굳이 작성 안함)
	fscanf(fp, "%d%d", &Brow, &Bcol);

	//B행렬 전체크기 각각의 원소들을 나타냄
	m = Brow * Bcol;

	//B_matrix 동적할당
	B_matrix = (int**)malloc(sizeof(int*) * m);
	//동적할당 실패하면 종료
	if (B_matrix == NULL) {
		printf("m에 대한 메모리 할당에 실패했습니다.\n");
		return 0;
	}
	for (i = 0; i < m; i++)
	{
		B_matrix[i] = (int*)malloc(sizeof(int) * rare);
		if (B_matrix[i] == NULL) {
			printf("m의 rare에 대한 메모리 할당에 실패했습니다. %d.\n", i);
			return 0;
		}
	}

	//B행렬의 0이아닌 원소의 개수
	int countB = 0;

	//행렬 원소 개수만큼 반복
	for (int i = 0; i < Brow; i++)
	{
		//희소행렬로 입력받는다.
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

	//두 행렬의 행과 열이 다르면 패스 같으면 출력
	if (Arow != Brow || Acol != Bcol)
		printf("두행렬간 크기가 달라 덧셈 및 빼기는 불가합니다.\n\n");
	else if (Arow == Brow && Acol == Bcol)
	{
		//덧셈
		matrix_ADD((int**)A_matrix, (int**)B_matrix, Arow, Bcol, countA, countB);
		//뺄셈
		matrix_MINUS((int**)A_matrix, (int**)B_matrix, Arow, Bcol, countA, countB);
	}

	//두 행렬의 행과 열이 다르면 패스 같으면 출력
	if (Acol != Brow)
		printf("두 행렬간 행과 열이 달라 곱셈은 불가합니다.\n\n");
	else if (Acol == Brow)
		//곱셈
		matrix_multiply((int**)A_matrix, (int**)B_matrix, Arow, Acol, Brow, Bcol, countA, countB);

	//A_matrix 동적할당 해제
	for (int i = 0; i < Arow; i++) {
		free(A_matrix[i]);
	}
	free(A_matrix);

	//B_matrix 동적할당 해제
	for (int i = 0; i < Brow; i++) {
		free(B_matrix[i]);
	}
	free(B_matrix);

	//파일 닫기
	fclose(fp);

	return 0;

}
