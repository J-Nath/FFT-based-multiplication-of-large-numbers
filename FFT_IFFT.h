#pragma once
#include "Complex.h"
#ifndef FFT_IFFT_H
#define FFT_IFFT_H

class FFT_IFFT {
public:
	static void fft(Complex* dist, Complex* src, int N) {
		int n = 0;
		for (int i = 1; i < N; i *= 2) {//求N的二进制位数
			n++;
		}
		for (int i = 0; i <= N - 1; i++) {//进行位反转置换
			int a = i;
			int b = 0;
			for (int j = 0; j < n; j++) {//生成a的反转b
				b = (b << 1) + (a & 1);
				a >>= 1;
			}
			if (b > i) {//进行置换
				dist[b] = src[b] + src[i];
				dist[i] = dist[b] - src[i];
				dist[b] = dist[b] - dist[i];
			}
		}
		for (int s = 1, m = 1; s <= n; s++) {//进行迭代过程
			m *= 2;
			Complex temp, u, omiga, omigaM = Complex(cos(-2 * M_PI / m), sin(-2 * M_PI / m));
			for (int k = 0; k < N; k = k + m) {
				omiga = Complex(1);
				for (int j = 0; j <= m / 2 - 1; j++) {//蝶形运算
					temp = omiga * dist[k + j + m / 2];
					u = dist[k + j];
					dist[k + j] = u + temp;
					dist[k + j + m / 2] = u - temp;
					omiga = omiga*omigaM;
				}
			}
		}
	}

	static void ifft(Complex* dist, Complex* src, int N) {
		int n = 0;
		for (int i = 1; i < N; i *= 2) {//求N的二进制位数
			n++;
		}
		for (int i = 0; i <= N - 1; i++) {//进行位反转置换
			int a = i;
			int b = 0;
			for (int j = 0; j < n; j++) {//生成a的反转b
				b = (b << 1) + (a & 1);
				a >>= 1;
			}
			if (b > i) {//进行置换
				dist[b] = src[b] + src[i];
				dist[i] = dist[b] - src[i];
				dist[b] = dist[b] - dist[i];
			}
		}
		for (int s = 1, m = 1; s <= n; s++) {//进行迭代过程
			m *= 2;
			Complex temp, u, omiga, omigaM = Complex(cos(2 * M_PI / m), sin(2 * M_PI / m));
			for (int k = 0; k < N; k = k + m) {
				omiga = Complex(1);
				for (int j = 0; j <= m / 2 - 1; j++) {//蝶形运算
					temp = omiga * dist[k + j + m / 2];
					u = dist[k + j];
					dist[k + j] = u + temp;
					dist[k + j + m / 2] = u - temp;
					omiga = omiga*omigaM;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			dist[i] = dist[i] / N;
		}
	}
};


#endif

