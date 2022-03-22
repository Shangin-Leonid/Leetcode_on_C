


//static void Shaker_sort(int *array, int len);
static void Merge(int *array, int *buff, int left, int mid, int right);
static void Merge_iterative_alg(int *array, int *buff, int len);
static int int_min(int a, int b); //Стандартная min() для int

int minPairSum(int* nums, int numsSize)
{
    int *buff = (int *) malloc(numsSize * sizeof(int)); //Буферный массив для Merge
    Merge_iterative_alg(nums, buff, numsSize);
    int max_pair_sum = 0;
    for(int i = 0; i < numsSize/2; ++i)
        if(nums[i] + nums[numsSize-i-1] > max_pair_sum)
            max_pair_sum = nums[i] + nums[numsSize-i-1];
    return max_pair_sum;
}

/* Функция реализации алгоритма итеративной сортировки слиянием */
static void Merge_iterative_alg(int *array, int *buff, int len)
{
    for(int i = 1; i < len; i *= 2)
        for(int j = 0; j < len - i; j += 2*i)
            Merge(array, buff, j, j+i, int_min(j + 2*i, len));
}

/*  Функция слияния двух смежных подмассивов (по возр.): [left; mid) и [mid; right) */
static void Merge(int *array, int *buff, int left, int mid, int right)
{
    int  l_pos = 0,
            r_pos = 0;

    while((left + l_pos < mid) && (mid + r_pos < right)) //Формируем из двух (сортированных) подмассивов один упорядоченный буферный
    {
        if(array[left + l_pos] < array[mid + r_pos])
        {
            buff[l_pos + r_pos] = array[left + l_pos];
            l_pos++;
        }
        else
        {
            buff[l_pos + r_pos] = array[mid + r_pos];
            r_pos++;
        }
    }

    while(left + l_pos < mid) //Добавляем в буфер из левого (отсортированного) подмассива оставшиеся элементы
    {
        buff[l_pos + r_pos] = array[left + l_pos];
        l_pos++;
    }
    while(mid + r_pos < right) // Добавляем в буфер оставшиеся отправого подмассива элементы
    {
        buff[l_pos + r_pos] = array[mid + r_pos];
        r_pos++;
    }

    for(int i = 0; i < l_pos + r_pos; i++) //Заменяем два подмассива на их отсортированное объединение
        array[left + i] = buff[i];
}

/* Возвращает меньшее из двух int чисел */
static int int_min(int a, int b)
{
    return ((a < b) ? a : b);
}



/*void Shaker_sort(int *array, int len)
{
    int  left = 0,
         right = len - 1;
    while(left < right)
    {
        for(int pos = left; pos < right; ++pos)
            if(array[pos] > array[pos+1])
            {
                int tmp = array[pos+1];
                array[pos+1] = array[pos];
                array[pos] = tmp;
            }
        --right;
        for(int pos = right; pos > left; --pos)
            if(array[pos-1] > array[pos])
            {
                int tmp = array[pos-1];
                array[pos-1] = array[pos];
                array[pos] = tmp;
            }
        ++left;
    }
    return ;
}*/
