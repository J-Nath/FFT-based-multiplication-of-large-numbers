#include<stdio.h>
#include "Complex.h"
#include "FFT_IFFT.h"

using namespace std;
int main()
{
	char inputfile[] = "input.txt";
	char outputfile[] = "output.txt";    // 将结果输出到文件 output.txt 中
	FILE *myInput, *myOutput;
	int line = 0;
	int N = 1, n = 0;
	if ((fopen_s(&myInput,inputfile, "r"))!=0) {
		printf("Cannot open input file. ");
		exit(1);
	}
	if ((fopen_s(&myOutput,outputfile, "w"))!=0) {
		printf("Cannot open file. ");
		exit(1);
	}
	char ch;
	while ((ch = getc(myInput)) != EOF) {
		if (ch == '\n') {
			line++;
		}
	}
	fclose(myInput);

	for (int i = 1; i < line; i *= 2) {
		N *= 2;
	}

	Complex* src = new Complex[N];
	double real = 0, image = 0;
	if ((fopen_s(&myInput,inputfile, "r"))!=0) {
		printf("Cannot open input file. ");
		exit(1);
	}
	for (int i = 0; (fscanf_s(myInput, "%lf%lf", &real, &image)) != EOF; i++) {//double对应于%lf,float对应于%f，负责不能正常读写
		src[i] = Complex(real, image);
	}
	fopen_s(&myInput, inputfile, "r");
	if (fclose(myInput)) {
		printf("File close error. ");
		exit(1);
	}
	

	fprintf_s(myOutput, "\n\nInput:    i     real    imag \n");
	for (int i = 0; i < line; i++) {
		fprintf_s(myOutput, "%4d    %8.4f    %8.4f \n", i, src[i].getReal(), src[i].getImage());
	}
	FFT_IFFT::fft(src, src, N);//傅里叶变换FFT
	fprintf_s(myOutput, "\n\nFFT:    i       real    imag \n");
	for (int i = 0; i < N; i++) {
		fprintf_s(myOutput, "%4d    %8.4f    %8.4f \n", i, src[i].getReal(), src[i].getImage());
	}
	fprintf_s(myOutput, "===========================================================\n\n ");
	FFT_IFFT::ifft(src, src, N);//傅里叶反变换IFFT
	fprintf_s(myOutput, "\n\nIFFT:    i      real    imag \n");
	for (int i = 0; i < line; i++) {
		fprintf_s(myOutput, "%4d    %8.4f    %8.4f \n", i, src[i].getReal(), src[i].getImage());
	}
	fprintf(myOutput, "===========================================================\n\n ");

	if (fclose(myOutput)) {
		printf("File close error. ");
		exit(1);
	}

	return 0;
}