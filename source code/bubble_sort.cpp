void bubbleSort()
{
    bool update;
    for (int i = 0; i < width - 1; i++)
    {
        for (int j = 0; j < width - 1 - i; j++)
        {
            if (s_ort[j + 1] < s_ort[j])
            {
                swap(s_ort[j + 1], s_ort[j]);
                draw_element(j + 1, 0x80ff00, false);
                draw_element(j, 0xffaec8);
            }
        }
        draw_arry();
    }
}

void bubble_sort()
{
    d(1000);
    creatr_arry(3);
    d(1000);
    bubbleSort();
    d(2000);
}