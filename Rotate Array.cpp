void swap(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
void rotate(int* nums, int numsSize, int k) {
    int n = numsSize;
    k %= n;
    for(int i = 0, j = n - k - 1; i < j; i++, j--)
        swap(nums, i, j);
    for(int i = n - k, j = n - 1; i < j; i++, j--)
        swap(nums, i, j);
    for(int i = 0, j = n - 1; i < j; i++, j--)
        swap(nums, i, j);
}