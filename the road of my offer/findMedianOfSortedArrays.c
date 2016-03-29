double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int isMedian = (nums1Size + nums2Size) % 2;
    if(isMedian == 0)
        return (double)(getMedian(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size)/2) 
            + getMedian(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size)/2 + 1)) 
            / 2;
   return getMedian(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size)/2 + 1);
}

int getMedian(int* nums1, int len1, int*nums2, int len2, int key)
{
    if(len1 > len2)//永远将长的放后面
        return getMedian(nums2, len2, nums1, len1, key);
    if(len1 == 0)
        return nums2[key - 1];
    if(key == 1)
        return nums1[0] < nums2[0]?nums1[0]:nums2[0];
    
    int p1 = (key / 2) < len1 ? (key / 2):len1;
    int p2 = key - p1;
    if (nums1[p1 - 1] < nums2[p2 - 1])  
        return getMedian(nums1 + p1, len1 - p1, nums2, len2, key - p1);  
    else if (nums1[p1 - 1] > nums2[p2 - 1])  
        return getMedian(nums1, len1, nums2 + p2, len2 - p2, key - p2);  
    else  
        return nums1[p1 - 1];  
}