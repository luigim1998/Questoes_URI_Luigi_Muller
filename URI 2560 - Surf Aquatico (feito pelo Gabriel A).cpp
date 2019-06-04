#include <stdio.h>
#include <limits.h>

using namespace std;

int vector[200000];
int max[800000];
int min[800000];
int soma[800000];

void build(int pos, int l, int r);


int search_max(int l, int r, int lq, int rq, int pos);

int search_min(int l, int r, int lq, int rq, int pos);

int search_soma(int l, int r, int lq, int rq, int pos);

int main(){

	int n, b;

	int register i;

	long long int soma;
	int aux_min, aux_max, aux_soma;

	while(scanf("%d %d",&n, &b) != EOF){

		soma = 0;

		for (i = 0; i < n; ++i)
		{
			scanf("%d", &vector[i]);
		}

		build(0, 0, n-1);


		for (i = 0; i < (n-b+1); ++i)
		{
			
			aux_min  = search_min(0,n-1,i,(b+i)-1,0);
			aux_max  = search_max(0,n-1,i,(b+i)-1,0);
			aux_soma = search_soma(0,n-1,i,(b+i)-1,0);

			soma = soma + aux_soma - aux_min - aux_max;

		}
		
		printf("%lld\n",soma);

	}
	return 0;
}

void build(int pos, int l, int r)
{
	
	if (l == r){

		min[pos] = max[pos] = soma[pos] = vector[l];
		return;
	}

	int mid = (l + r)/2;

	build(2*pos+1, l, mid);
	build(2*pos+2, mid+1, r);

	if(min[2*pos+1] < min[2*pos+2]){

		min[pos] = min[2*pos+1];
	}
	else
	{
		min[pos] = min[2*pos+2];
	}

	if(max[2*pos+1] > max[2*pos+2]){

		max[pos] = max[2*pos+1];
	}
	else
	{
		max[pos] = max[2*pos+2];
	}

	soma[pos]= (soma[2*pos+1] + soma[2*pos+2]);
}


int search_min(int l, int r, int lq, int rq, int pos)
{

	if (lq <= l && rq >= r){

		return(min[pos]);

	}
	if (lq > r || rq < l){

		return INT_MAX;//Vai depender da função aqui

	}

	int mid = (l + r)/2;

	int a = search_min(l, mid, lq, rq, 2*pos+1);
	int b = search_min(mid+1, r, lq, rq, 2*pos+2);

	if(a < b){
		return a;
	}
	else
		return b;
}

int search_max(int l, int r, int lq, int rq, int pos)
{
	if (lq <= l && rq >= r){

		return(max[pos]);

	}
	if (lq > r || rq < l){

		return INT_MIN;//Vai depender da função aqui

	}
	int mid = (l + r)/2;

	int a = search_max(l, mid, lq, rq, 2*pos+1);
	int b = search_max(mid+1, r, lq, rq, 2*pos+2);
	
	if(a > b){
		return a;
	}
	else
		return b;
}

int search_soma(int l, int r, int lq, int rq, int pos)
{
	if (lq <= l && rq >= r){

		return(soma[pos]);

	}
	if (lq > r || rq < l){

		return 0;//Vai depender da função aqui

	}
	int mid = (l + r)/2;

	int a = search_soma(l, mid, lq, rq, 2*pos+1);
	int b = search_soma(mid+1, r, lq, rq, 2*pos+2);
	
	return (a + b);
}