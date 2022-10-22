void selectionSort()
{
    int min_idx = 0, min = s_ort[0];
    for (int i = 0; i < width; i++)
    {
        min = s_ort[i];
        min_idx = i;

        for (int j = i; j < width; j++)
        {
            draw_element(i);
            if (min > s_ort[j])
            {
                min_idx = j;
                min = s_ort[j];
                draw_element(min_idx, 0xffaec8);
            }
            d(1);
        }
        d(20);
        swap(s_ort[i], s_ort[min_idx]);
        draw_arry();
    }
}

void selection_sort()
{
    d(1000);
    creatr_arry(3);
    d(1000);
    selectionSort();
    d(2000);
}