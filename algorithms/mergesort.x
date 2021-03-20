def inteiro programa(){
    vetor inteiro[] num = [2,5,9,3,6,1,0,7,4,8];
    vetor inteiro[] aux; 
    mergesort(num, 0, 9, aux);
    para(inteiro i = 0; i < 10; i += 1)
    {
        escreva(num[i]);
    }
    retorne 0;
}

def vazio merge(vetor inteiro[] a, inteiro p, inteiro q, inteiro r, vetor inteiro[] aux)
{
    inteiro i, j, k;
    para (inteiro i = q+1; i > p; i-=1) {
       inteiro temp = i - 1;
       aux[temp] = a[temp];
    }
    para (inteiro j = q; j < r; j+=1) {
       inteiro temp = r + q - j;
       inteiro temp2 = j + 1;
       aux[temp] = a[temp2];
    }
    para (inteiro k = p; k <= r; k+=1) {
       se (aux[j] < aux[i]) {
           a[k] = aux[j];
       }
       senao {
        i += 1;
        a[k] = aux[i];
       }
    }
}

def vazio mergesort(vetor inteiro[] a, inteiro p, inteiro r, vetor inteiro[] aux) {
    se (p < r) {
       inteiro q = (p + r) / 2;
       inteiro temp = q + 1;
       mergesort(a, p, q, aux);  
       mergesort(a, temp, r, aux);
       merge(a, p, q, r, aux);
    };
}
