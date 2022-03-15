/*
    NOT accepted
    Time Limit Exceeded
*/

int largestRectangleArea(int* heights, int heightsSize)
{
    int max_area = 0;

    for(int ind = 0; ind < heightsSize; ind++)
    {
        for(int height = 1; height <= heights[ind]; ++height)
        {
            int len;
            for(len = ind+1; (len < heightsSize) && (heights[len] >= height); ++len)
                /* empty */;
            max_area = (max_area > (len-ind) * height ? max_area : (len-ind) * height);
        }
        while((ind < heightsSize-1) && (heights[ind+1] <= heights[ind]))
            ind++;
    }
    return max_area;
}
