//√∞≈›≈≈–Ú

void BubbleSort(int *t,int len)
{
    int i,j,temp;
    for(i = 0;i < len - 1;i++)
        for(j = 0;j < len - i - 1;j++)
            if(t[j] > t[j+1])
            {
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
}


//√∞≈›∏ƒΩ¯

void BubbleSortPro(int *t,int len)
{
    int i,j,temp;
    for(i = 0;i < len - 1;i++)
    {
        int mark = 0;
        for(j = 0;j < len - i - 1;j++)
            if(t[j] > t[j+1])
            {
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
                mark = 1;
            }
        if(mark == 0)
            break;
    }
}



//øÏÀŸ≈≈–Ú

int QuickSort(int *t,int left,int right)
{
    int temp = t[left];
    while(left<right)
    {
        while(left<right&&t[right]>temp)
            right--;
        t[left] = t[right];
        while (left<right&&t[left]<=temp)
            left++;
        t[right] = t[left];
    }
    t[left] = temp;
    return left;
}



//≤Â»Î≈≈–Ú

void InsertSort(int *t,int len)
{
    int i ,j;
    for(i = 1;i < len;i++)
    {
        int temp = t[i];
        j = i - 1;
        while(j >= 0&& t[j] > temp)
        {
            t[j+1] = t[j];
            j--;
        }
        t[j+1] = temp;
    }
}



//’€∞Î≈≈–Ú

void HalfInsertSort(int *t,int n)
{
    int left,right,middle,p;
    for(p = 1;p < n;p++)
    {
        int temp = t[p];
        left = 0;right = p - 1;
        while (left <= right)
        {
            middle = (left + right)/2;
            if(t[middle] > temp)
                right = middle - 1;
            else
                left = middle + 1;
        }
        for(int i = p - 1;i >= left;i--)
        {
            t[i + 1] = t[i];
            t[left] = temp;
        }
    }
}



//œ£∂˚≈≈–Ú

void ShellSort(int *t, int n)
{
    int d = n / 2;
    while (d > 0)
    {
        for (int i = d; i < n; i++)
        {
            int x = t[i];
            int j = i - d;
            while (j >= 0 && x < t[j])
            {
                t[j + d] = t[j];
                j = j - d;
            }
            t[j + d] = x;
        }
        d = d / 2;
    }
}



//—°‘Ò≈≈–Ú


void SelectSort(int *t,int len)
{

	for (int i = 0; i < len; i++)
    {
		int temp;
		for (int j = i; j < len; j++)
		{
			if (t[j] < t[i])
			{
				temp = t[j];
				t[j] = t[i];
				t[i] = temp;
			}
		}
	}
}


//∂—≈≈–Ú



void Sift(int *t, int k, int len)
{
    int x = t[k];
    int i = k;
    int j = 2*i;
    bool fininshed = false;
    while (j <= len && !fininshed)
    {
        if (j < len && t[j] < t[j + 1])
            j = j + 1;

        if (x >= t[j])
            fininshed = true;
        else
        {
            t[i] = t[j];
            i = j;
            j = 2 * i;
        }
    }
    t[i] = x;
}
void HeapSort(int *t, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        sift(t, i, n);
    }

    for (int i = n; i > 1; i--)
    {
        int x = t[1];
        t[1] = t[i];
        t[i] = x;
        sift(t, 1, i - 1);
    }
}


//Õ∞≈≈–Ú


void BucketSort(int *t,int n,int max)
{
  int i,j,x;
  int *buckets;

  if (t == NULL || n<1 || max<1)
    return ;
  int *buckets = new int[max];
  for(x = 0;x < max;x++)
    buckets[x] = 0;
  for(i = 0;i < n;i++)
    buckets[a[i]]++;
  for (i = 0,j = 0;i < max;i++)
    while((buckets[i]--) > 0)
      t[j++] = i;
  delete(buckets);
}


//πÈ≤¢≈≈–Ú


void merge(int *t, int low, int mid, int high, int *temp)
{
    int i = low;
    int j = mid + 1;
    int x = 0;
    while (i <= mid && j <= high)
    {
        if (t[i] < t[j])
            temp[x++] = t[i++];
        else
            temp[x++] = t[j++];
    }
    while (i <= mid)
        temp[x++] = t[i++];
    while (j <= high)
        temp[x++] = t[j++];
    t = 0;
    while (low <= high)
    {
        t[low++] = temp[x++];
    }
}
void MergeSort(int *t, int low, int high, int *temp)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MSort(t,low, mid, temp);
        MSort(t,mid + 1,high,temp);
        merge(t,low,mid,high,temp);
    }
}
