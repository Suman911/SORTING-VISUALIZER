void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];

    for (i = 0; i < n1; i++)
    {
        L[i] = s_ort[l + i];
        draw_element(l + i);
        d(1);
    }
    int* R = new int[n2];

    for (j = 0; j < n2; j++)
    {
        R[j] = s_ort[m + 1 + j];
        draw_element(m + 1 + j);
        d(1);
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            s_ort[k] = L[i];
            i++;
            d(3);
            draw_arry();
        }
        else
        {
            s_ort[k] = R[j];
            j++;
            d(3);
            draw_arry();
        }
        k++;
    }
    while (i < n1)
    {
        s_ort[k] = L[i];
        i++;
        k++;
        d(3);
        draw_arry();
    }
    while (j < n2)
    {
        s_ort[k] = R[j];
        j++;
        k++;
        d(3);
        draw_arry();
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

void marge_sort()
{
    d(1000);
    creatr_arry();
    d(1000);
    mergeSort(0, width - 1);
    d(2000);
}