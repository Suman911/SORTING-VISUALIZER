int partition(int low, int high)
{
    int pivot = s_ort[high]; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) 
    {
        if (s_ort[j] < pivot) {
            i++;
            swap(s_ort[i], s_ort[j]);
        }
        draw_element(j, 0x80ff00, false);
        draw_element(i, 0xffaec8);
        d(2);
    }
    swap(s_ort[i + 1], s_ort[high]);
    draw_arry();
    return (i + 1);
}

void quickSort(int low, int high)
{
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void quick_sort()
{
    d(1000);
    creatr_arry();
    d(1000);
    quickSort(0, width - 1);
    d(2000);
}