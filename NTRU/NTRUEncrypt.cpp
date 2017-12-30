#include"Funtion.h"

//����ʽLf�ĳ�ʼ��
void initF(int Lf[], int num) {
	srand(time(NULL));
	int temp;
	int roll;
	//Lf[0] = 1;
	for (int i = 1; i <= num; i++)
		Lf[i] = p;
	for (int i = num + 1; i <= num * 2 ; i++)
		Lf[i] = -p;

	for (int i = 1; i < N; i++) {
		roll = rand() % (N-1) +1;
		temp = Lf[roll];
		Lf[roll] = Lf[i];
		Lf[i] = temp;
	}
	Lf[0] += 1;
}

//��ʼ���������ʽ
void init(int arr[], int num) {
	srand(time(NULL));
	arr[0] = 1;
	int temp;
	int roll;
	for (int i = 1; i < num; i++)
		arr[i] = 1;
	for (int i = num+1; i < num + num+1; i++)
		arr[i] = -1;

	for (int i = 1; i < N; i++) {
		roll = rand() % N;
		while(roll == 0) {
			roll = rand() % N;
		}
		temp = arr[roll];
		arr[roll] = arr[i];
		arr[i] = temp;
	}
}

//�������ʽ
void print(int Arr[]) {
	{
		cout << "        ϵ��    " << " ָ��" << endl;
		for (int i = 0; i <N; i++)
			cout << "��" << i << "��:   " << Arr[i] << "        " << i << endl;
	}
	cout << endl;
}

//����ʽ�ӷ�
void Add(int a1[], int a2[], int a3[]) {
	for (int i = 0; i <N; i++)
		a3[i] = a1[i] + a2[i];
}

//����ʽģ��
void ModAdd(int a1[], int a2[], int a3[], int mod) {
	for (int i = 0; i < N; i++) {
		a3[i] = (a1[i] + a2[i]) % mod;
		if (a3[i] < 0)
			a3[i] += mod;
	}
}

//����ʽ����
void Minus(int a1[], int a2[], int a3[]) {
	for (int i = 0; i <N; i++)
		a3[i] = a1[i] - a2[i];
}

//����ʽģ��
void ModMinus(int a1[], int a2[], int a3[], int mod) {
	for (int i = 0; i < N; i++) {
		a3[i] = (a1[i] - a2[i]) % mod;
		if (a3[i] < 0)
			a3[i] += mod;
	}
}

//����ʽ�˷�
void Mul(int a1[], int a2[], int a3[]) {
	for (int i = 0; i < N; i++)
		a3[i] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int expon = (i + j);
			int coef = a1[i] * a2[j];
			a3[expon] += coef;
		}
}

//����ʽ�볣�����
void ConstMul(int a1[], int con, int a3[]) {
	for (int i = 0; i < N; i++)
		a3[i] = a1[i] * con;
}

//����ʽ���ϵĳ˷�
void RingMul(int a1[], int a2[], int a3[]) {
	for (int i = 0; i < N; i++)
		a3[i] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int expon = (i + j) % N;
			int coef = a1[i] * a2[j];
			a3[expon] += coef;
		}
}

//����ʽ���ϵ�ģ��
void ModRingMul(int a1[], int a2[], int a3[], int mod) {
	for (int i = 0; i < N; i++)
		a3[i] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int expon = (i + j) % N;
			int coef = a1[i] * a2[j];
			a3[expon] += coef;
		}
	for (int i = 0; i < N; i++) {
		a3[i] = a3[i] % mod;
		if (a3[i] < 0)
			a3[i] += mod;
	}
}

//�ж϶���ʽ�����
int MaxExpon(int a[]) {
	int max = N;
	while (a[max] == 0) {
		max--;
	}
	return max;
}

//����ʽ�ĳ���   
void Divine(int a1[], int a2[], int quotient[], int remainder[]) {
	int t2[M] = { 0 };
	Copy(t2, a1);
	int max1 = MaxExpon(t2);
	int max2 = MaxExpon(a2);
	if (max1 < max2) {
		Copy(remainder, a1);
	}
	while (max1 >= max2) {
		quotient[max1 - max2] = t2[max1] / a2[max2];
		int t3[M] = { 0 };
		Copy(t3, a2);
		//����ʽ����
		for (int i = N; i >= (max1 - max2); i--)
			t3[i] = t3[i - (max1 - max2)] * (t2[max1] / a2[max2]);
		for (int i = 0; i < (max1 - max2); i++)
			t3[i] = 0;
		Minus(t2, t3, remainder);
		Copy(t2, remainder);
		max1 = MaxExpon(t2);
	}
}

//����ʽ�ĸ���
void Copy(int a1[], int a2[]) {
	for (int i = 0; i <= N; i++)
		a1[i] = a2[i];
}

//����ʽȡģ
void mod(int a1[], int mod) {
	for (int i = 0; i < N; i++) {
		a1[i] = a1[i] % mod;
		if (a1[i] < 0)
			a1[i] += mod;
	}
}

//����ʽ����    �����ǰ
int Inverse(int a1[], int a2[], int inverse[], int inv) {
	int A1[M];		Copy(A1, a1);
	int A2[M];		Copy(A2, a2);
	int quotient[M] = { 0 };//��
	int remainder[M] = { 0 };
	int temp[M] = { 0 };
	int T0[M] = { 0 };
	int T1[M] = { 0 };
	T1[0] = 1;
	int flag = 0;
	mod(A2, inv);
	//��һ��
	Divine(A1, A2, quotient, remainder);
	mod(quotient, inv);
	mod(remainder, inv);
	ModRingMul(quotient, T1, temp, inv);
	ModMinus(T0, temp, inverse, inv);
	

	if (MaxExpon(remainder) == 0 && remainder[0] == 1 || (MaxExpon(remainder) == 0 && remainder[0] == 1-inv)) {
		cout << "��Զ���ʽ����" << endl;
		flag = 1;
		return flag;
	}

	while (MaxExpon(remainder) != -1) {
		Copy(A1, A2);
		Copy(A2, remainder);
		Copy(T0, T1);
		Copy(T1, inverse);

		for (int i = 0; i < N; i++) {
			remainder[i] = 0;
			quotient[i] = 0;
			temp[i] = 0;
		}

		Divine(A1, A2, quotient, remainder);
		mod(quotient, inv);
		mod(remainder, inv);


		ModRingMul(quotient, T1, temp, inv);

		ModMinus(T0, temp, inverse, inv);

		if (MaxExpon(remainder) == 0 && remainder[0] == 1 || (MaxExpon(remainder) == 0 && remainder[0] == 1-inv)) {
			cout << "��Զ���ʽ����" << endl;
			flag = 1;
			return flag;
		}
	}
	return flag;
}

//�������
void Update(int Lf[], int inverse[], int fq[], int q) {
	int two[M] = { 0 };	two[0] = 2;
	int t[M] = { 0 };
	int T[M] = { 0 };
	int c = 2;
	while (c <q) {
		ModRingMul(Lf, inverse, t, q);
		Minus(two, t, T);
		mod(T, q);
		ModRingMul(T, inverse, fq, q);
		Copy(inverse, fq);
		c = c*c;
	}
}

//��Կ����
void KeyGeneration(int Lf[], int U[],int g[], int h[]) {
	int aaa[M] = { 0 };
	int inverse[M] = { 0 };
	int Fq[M] = { 0 };
	int temp[M] = { 0 };

	Inverse(U, Lf, inverse, 2);
	Update(Lf, inverse, Fq, q);

	RingMul(Fq, g, temp);
	ConstMul(temp, p, h);
	mod(h, q);
	cout << "��Կ: " << endl;
	print(h);
}

//���ܹ���
void Encryption(int h[], int Lr[], int m[], int e[]) {
	int t[M] = { 0 };
	ModRingMul(h, Lr, t, q);
	ModAdd(t, m, e, q);
	cout << "����: " << endl;
	print(e);
}

//���ܹ���
void Decryption(int e[], int Lf[], int a[], int Fp[]) {
	int b[M] = { 0 };
	int sb[M] = { 0 };
	ModRingMul(Lf, e, a, q);
	for (int i = 0; i < N; i++) {
		if (a[i] < (-q / 2))
			a[i] += q;
		if (a[i] > (q / 2))
			a[i] -= q;
	}
	
	mod(a, p);
	for (int i = 0; i < N; i++) {
		if (a[i] < (-p / 2))
			a[i] += p;
		if (a[i] > (p / 2))
			a[i] -= p;
	}
	
	ModRingMul(a, Fp, b, p);
	for (int i = 0; i < N; i++) {
		if (b[i] < (-p / 2))
			b[i] += p;
		if (b[i] > (p / 2))
			b[i] -= p;
	}
	cout << "���ܺ�õ�: " << endl;
	print(b);
	/*
	ModRingMul(fp, a, b, p);
	cout << "c" << endl;
	print(b);
	*/

}

int main() {
	while (cin >> N >> p >> q) {
		//������ʼ��
		int Lf[M] = { 0 };
		int Lg[M] = { 0 };
		int t[M] = { 0 };
		int h[M] = { 0 };
		int Lr[M] = { 0 };
		int e[M] = { 0 };
		int a[M] = { 0 };
		int U[M] = { 0 };	U[0] = -1;		U[N] = 1;
		int m[M] = { 0 };
		int Fp[M] = { 0 };
		int newa[M] = { 0 };
			
		//�Զ�����
		int num;
		cout << "������Lf��-1�ĸ���: ";
		cin >> num;
		initF(Lf, num);

		int numG;
		cout << "������Lg��1��-1�ĸ���: ";
		cin >> numG;
		init(Lg, numG);

		int numR;
		cout << "������Lr��1��-1�ĸ���: ";
		cin >> numR;
		init(Lr, numR);

		//�ֶ�����
		/*
		for (int i = 0; i < N; i++) {
			cout << "������lf��" << i << "���ϵ��: ";
			cin >> Lf[i];
		}
		for (int i = 0; i < N; i++) {
			cout << "������Lg��" << i << "���ϵ��: ";
			cin >> Lg[i];
		}
		for (int i = 0; i < N; i++) {
		cout << "������r��" << i << "���ϵ��: ";
		cin >> Lr[i] ;
		}
		for (int i = 0; i < N; i++) {
		cout << "������fp��" << i << "���ϵ��: ";
		cin >> fp[i];
		}
		*/

		//��Կ����
		int Flag = Inverse(U, Lf, t,2);
		while(!Flag) {
		cout << "����ʽ�����أ����������룡" << endl;
		cout << "������Lf��-1�ĸ���:" << endl;
		cin >> num;
		initF(Lf, num);
		Flag = Inverse(U, Lf, t, 2);
		}
		KeyGeneration(Lf, U,Lg, h);
		//����
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0)
				m[i] = 1;
			else
				m[i] = 0;
		}
		cout << "����" << endl;
		print(m);
		Encryption(h , Lr, m, e);
		//����
		Inverse(U, Lf, Fp, p);
		Decryption(e, Lf, a, Fp);
	}
}