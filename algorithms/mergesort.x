inteiro programa{
    inteiro num[] = {2,5,9,3,6,1,0,7,4,8};
    inteiro aux[10]; 
    mergesort(num, 0, 9, aux);
    para(inteiro i = 0; i < 10; i += 1)
    {
        escreva(num[i]);
    }
    retorne 0;
}


void merge(inteiro a[10], inteiro p, inteiro q, inteiro r, inteiro aux[10]) 
{

    inteiro i, j, k;
    para (i = q+1; i > p; i-=1) {
       inteiro temp = i - 1;
       aux[temp] = a[temp];
    }
    para (j = q; j < r; j+=1) {
       inteiro temp = r + q - j;
       inteiro temp2 = j + 1;
       aux[temp] = a[temp2];
    }
    para (k = p; k <= r; k+=1) {
       se (aux[j] < aux[i]) {
           a[k] = aux[j];
       }
       senao {
        i += 1;
        a[k] = aux[i];
       }
    }
}

void mergesort(inteiro a[], inteiro p, inteiro r, inteiro aux[10]) {
    if (p < r) {
       inteiro q = (p + r) / 2;
       inteiro temp = q + 1;
       mergesort(a, p, q, aux);  
       mergesort(a, temp, r, aux);
       merge(a, p, q, r, aux);
    }
}
