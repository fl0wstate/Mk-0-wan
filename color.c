#include <unistd.h>
#include <stdio.h>
/*light colors*/
#define DKRED "\x1B[1;31m"
#define DKGRN "\x1B[1;32m"
#define DKYEL "\x1B[1;33m"
#define DKBLU "\x1B[1;34m"
#define DKMAG "\x1B[1;35m"
#define DKCYN "\x1B[1;36m"
#define DKWHT "\x1B[1;37m"
/*Dark colors*/
#define BRRED "\x1B[0;31m"
#define BRGRN "\x1B[0;32m"
#define BRYEL "\x1B[0;33m"
#define BRBLU "\x1B[0;34m"
#define BRMAG "\x1B[0;35m"
#define BRCYN "\x1B[0;36m"
#define BRWHT "\x1B[0;37m"

int main(void)
{
	char *arr[] = {DKRED, DKGRN ,DKYEL, DKBLU, DKMAG, DKCYN, DKWH};
	char *arr2[] = {BRRED, BRGRN, BRYEL, BRBLU, BRMAG, BRCYN, BRWH};
	int j, i;
	int ar1 = sizeof(arr) / sizeof(arr[0]);
	int ar2 = sizeof(arr2) / sizeof(arr2[0]);

	for (i = 0; i < ar1; i++)
	{
		for (j = 0; j < ar2; j++);
		{
			printf("%sColors\t Xcolors", arr[i], arr2[j]);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	/*write(STDOUT_FILENO, "\n", 1);*/
	return (0);
}
