//실행됨

int ibs(int a[], int n, int f, int l) {
	while (f <= l) {
		int mid = (f + l) / 2;
		if (n == a[mid])return 1;
		if (n > a[mid]) f = mid + 1;
		else l = mid - 1;
	}
	return -1;
}

int rbs(int a[], int n, int f, int l) {
	while (f <= l) {
		int mid = (f + l) / 2;
		if (n == a[mid])return 1;
		if (n > a[mid]) return rbs(a,n,mid+1,l);
		else return rbs(a,n,f,l-1);
	}
	return -1;

}


void main()
{
	FILE* fp= fopen("in.txt", "r");
	int arr[9], i, in;
	
	if (fp == NULL){
		printf("파일 없음 ㅅㄱ\n");
		exit(1);}

	for (i = 0; i < 9; i++)
		fscanf(fp, "%d", &arr[i]);

	fclose(fp);
	
	while (1) {
		printf("Input number: ");
		scanf("%d", &in);
		if (in < 0) {
			printf("Exit");
			return;
		}

		int ibsn = ibs(arr, in, 0, 9);
		int rbsn = rbs(arr, in, 0, 9);


		printf("interative binary search: ");
		if (ibsn == -1)printf("없음\n");
		else printf("있음\n");
		printf("recursive binary search: ");
		if (rbsn == -1)printf("없음\n");
		else printf("있음\n");
	}
	
}
