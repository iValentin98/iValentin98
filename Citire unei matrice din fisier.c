#include <stdio.h>
#include <malloc.h>

int nrNegative(float** a, int m, int n);

int main() 
{
    //declarare variabile

    char numef[256]; // D:\myFile.txt
    FILE *f;
    int m,n, nr;
    float **a;
    //citire 0 - introduceti calea catre fisier.
    printf("Introduceti calea (numele) fisierului:");
    scanf("%s", numef);

    // deschidem fisierul.
    f = fopen(numef, "rb");
    if(f==NULL)
    {
        printf("Fisierul %s nu a putut fi deschis.", numef);
        return 1;
    }

    //citire 1
    fscanf(f,"%d%d", &m, &n);

    //alocare memorie 1
    a = (float*) malloc(m*sizeof(float));

    if(a==NULL) 
    {
        perror("Memorie insuficienta!");
        return 1;
    }


    //alocare memorie 2
    for(int i = 0; i<m; i++) 
    {
        a[i] = (float*) malloc(n*sizeof(float));
        if(a[i]==NULL) 
        {
            perror("Memorie insuficienta!");
            return 1;
        }
    }

    //citire 2-elementele matricii
    for(int i = 0; i<m; i++) 
    {
        for(int j = 0; j<n; j++) 
        {
            fscanf(f,"%f", &a[i][j]);
        }
    }

    //calcul
    nr = nrNegative(a, m, n);

    //afisare rezultat
    for(int i = 0; i<m; i++) 
    {
        for(int j = 0; j<n; j++) 
        {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }

    printf("Dintre elemen(e) %d sunt negative.", nr);

    //eliberare memorie
    for(int i = 0; i<m; i++) 
    {
        free(a[i]);
    }
    free(a);
    fclose(f);
    return 0;
}

int nrNegative(float** a, int m, int n) 
{
    int nr = 0;
    for(int i = 0; i<m; i++) 
    {
        for(int j = 0; j<n; j++) 
        {
            if(a[i][j]<0)
                nr++;
        }
    }
    return nr;
}


/*int main()
{
    char numef[256]; // D:\myFile.txt
    FILE *f;
    int m,n;
    printf("Introduceti calea (numele) fisierului:");
    scanf("%s", numef);
    f = fopen(numef, "rb");
    if(f==NULL)

    {
        printf("Fisierul %s nu a putut fi deschis.", numef);
        return 1;
    }

    fscanf(f, "%d%d", &m, &n);
    printf("Hello, am citit doua numere din fisier: %d si %d", m, n);
    fclose(f);
    return 0;
}*/