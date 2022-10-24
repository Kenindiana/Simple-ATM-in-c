#include<stdio.h>
#include<string.h>
struct database
{
	char nama[21],pin[7];
	long long unsigned int saldo;
}x[101];
int main()
{
	int i,j,error=1,menu;
	long long unsigned int jumlah;
	char name[21],password[7];
	FILE *data=fopen("database.csv","r");
	if(data==NULL)
	{
		printf("error! file tak ditemukan!\n");
		return 1;
	}
	for(i=0;!feof(data);i++)
	{
		fscanf(data,"%[^,],%[^,],%llu%*c",x[i].nama,x[i].pin,&x[i].saldo);
	}
	printf("masukan nama anda:\n=");
	scanf("%[^\n]",name);
	for(j=0;j<i;j++)
	{
		if(strcmp(name,x[j].nama) == 0)
		{
			error=0;
			break;
		}
	}
	if(error == 1)
	{
		printf("error! nama tak ditemukan!\n");
		return 1;
	}
	printf("masukan pin:\n=");
	scanf("%s",password);
	if(strcmp(password,x[j].pin) != 0)
	{
		printf("error! password salah!\n");
		return 1;
	}
	printf("ketik 1 untuk setor dana atau ketik 2 untuk tarik dana:\n=");
	scanf("%d",&menu);
	if(menu == 1)
	{
		printf("masukan jumlah dana yang ingin disetor:\n=");
		scanf("%llu",&jumlah);
		x[j].saldo+=jumlah;
	}else if(menu == 2)
	{
		printf("masukan jumlah dana yang ingin ditarik:\n=");
		scanf("%llu",&jumlah);
		if(x[j].saldo-jumlah < 0)
		{
			printf("saldo tidak cukup\n");
			return 1;
		}
		x[j].saldo-=jumlah;
	}else
	{
		printf("error! input salah!\n");
		return 1;
	}
	fclose(data);
	data=fopen("database.csv","w");
	for(j=0;j<i-1;j++)
	{
		fprintf(data,"%s,%s,%llu\n",x[j].nama,x[j].pin,x[j].saldo);
	}
	fclose(data);
	printf("transaksi telah berhasil\n");
	return 0;
}
